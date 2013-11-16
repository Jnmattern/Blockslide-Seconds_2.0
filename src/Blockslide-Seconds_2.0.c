#include <pebble.h>

#include "Blockslide-Seconds_2.0.h"

#define NUMSLOTS 6
#define TILEW 20
#define TILEH 10
#define HSPACE 8
#define VSPACE 8
#define DIGIT_CHANGE_ANIM_DURATION 100
#define CX 72
#define CY 84

typedef struct {
	Layer    *layer;
	int      prevDigit;
	int      curDigit;
	uint32_t normTime;
} digitSlot;

Window *window;

int startDigit[6] = {	START_TOP_LEFT, START_TOP_RIGHT,
						START_MIDDLE_LEFT, START_MIDDLE_RIGHT,
						START_BOTTOM_LEFT, START_BOTTOM_RIGHT };

digitSlot slot[6];
bool clock_12 = false;

AnimationImplementation animImpl;
Animation *anim;

GRect slotFrame(int i) {
	int x, y;
	int w = TILEW*3;
	int h = TILEH*5;

	if (i%2) {
		x = CX + HSPACE/2;
	} else {
		x = CX - HSPACE/2 - w;
	}

	if (i<2) {
		y = CY - VSPACE - h*3/2;
	} else if (i<4) {
		y = CY - h/2;
	} else {
		y = CY + VSPACE + h/2;
	}

	return GRect(x, y, w, h);
}

digitSlot *findSlot(Layer *layer) {
	int i;
	for (i=0; i<NUMSLOTS; i++) {
		if (slot[i].layer == layer) {
			return &slot[i];
		}
	}
	
	return NULL;
}

void updateSlot(Layer *layer, GContext *ctx) {
	int t, tx1, tx2, ty1, ty2, ox, oy;
	GRect bounds;
	digitSlot *slot;

	slot = findSlot(layer);
	graphics_context_set_fill_color(ctx, GColorBlack);
	bounds = layer_get_bounds(slot->layer);
	graphics_fill_rect(ctx, GRect(0, 0, bounds.size.w, bounds.size.h), 0, GCornerNone);

	for (t=0; t<13; t++) {
		if (digits[slot->curDigit][t][0] != digits[slot->prevDigit][t][0]
			|| digits[slot->curDigit][t][1] != digits[slot->prevDigit][t][1]) {
			if (slot->normTime == ANIMATION_NORMALIZED_MAX) {
				ox = digits[slot->curDigit][t][0]*TILEW;
				oy = digits[slot->curDigit][t][1]*TILEH;
			} else {
				tx1 = digits[slot->prevDigit][t][0]*TILEW;
				tx2 = digits[slot->curDigit][t][0]*TILEW;
				ty1 = digits[slot->prevDigit][t][1]*TILEH;
				ty2 = digits[slot->curDigit][t][1]*TILEH;

				ox = slot->normTime * (tx2-tx1) / ANIMATION_NORMALIZED_MAX + tx1;
				oy = slot->normTime * (ty2-ty1) / ANIMATION_NORMALIZED_MAX + ty1;
			}
		} else {
			ox = digits[slot->curDigit][t][0]*TILEW;
			oy = digits[slot->curDigit][t][1]*TILEH;
		}
		
		graphics_context_set_fill_color(ctx, GColorWhite);
		graphics_fill_rect(ctx, GRect(ox, oy, TILEW, TILEH-1), 0, GCornerNone);
	}
}

void initSlot(int i, Layer *parent) {
	slot[i].normTime = ANIMATION_NORMALIZED_MAX;
	slot[i].prevDigit = 0;
	slot[i].curDigit = startDigit[i];
	slot[i].layer = layer_create(slotFrame(i));
	layer_set_update_proc(slot[i].layer, updateSlot);
	layer_add_child(parent, slot[i].layer);
}

void deinitSlot(int i) {
	layer_destroy(slot[i].layer);
}

void animateDigits(struct Animation *anim, const uint32_t normTime) {
	int i;

	for (i=0; i< NUMSLOTS; i++) {
		if (slot[i].curDigit != slot[i].prevDigit) {
			slot[i].normTime = normTime;
			layer_mark_dirty(slot[i].layer);
		}
	}
}


void handle_tick(struct tm *now, TimeUnits units_changed) {
	int h, m, s, i;
	
	if (animation_is_scheduled(anim))
		animation_unschedule(anim);
		
	h = now->tm_hour;
	m = now->tm_min;
	s = now->tm_sec;
	if (clock_12) {
		h = h%12;
		if (h == 0) {
			h = 12;
		}
	}
	
	for (i=0; i<NUMSLOTS; i++) {
		slot[i].prevDigit = slot[i].curDigit;
	}
	
	slot[0].curDigit = h/10;
	slot[1].curDigit = h%10;
	slot[2].curDigit = m/10;
	slot[3].curDigit = m%10;
	slot[4].curDigit = s/10;
	slot[5].curDigit = s%10;
	
	animation_schedule(anim);
}


void handle_init() {
	Layer *rootLayer;
	int i;

	window = window_create();
	window_stack_push(window, true);
	window_set_background_color(window, GColorBlack);
	
	rootLayer = window_get_root_layer(window);

	for (i=0; i<NUMSLOTS; i++) {
		initSlot(i, rootLayer);
	}

	clock_12 = !clock_is_24h_style();

	animImpl.setup = NULL;
	animImpl.update = animateDigits;
	animImpl.teardown = NULL;

	anim = animation_create();
	animation_set_delay(anim, 0);
	animation_set_duration(anim, DIGIT_CHANGE_ANIM_DURATION);
	animation_set_implementation(anim, &animImpl);
		
	tick_timer_service_subscribe(SECOND_UNIT, handle_tick);
}

void handle_deinit() {
	int i;
	
	tick_timer_service_unsubscribe();
	
	for (i=0; i<NUMSLOTS; i++) {
		deinitSlot(i);
	}
	
	window_destroy(window);
}
int main(void) {
	handle_init();
	app_event_loop();
	handle_deinit();
}
