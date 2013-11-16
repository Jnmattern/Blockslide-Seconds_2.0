//
// Tiles coordinates & numbers
//
//  00 10 20    00 01 02
//  01 11 21    03    04
//  02 12 22    05 06 07
//  03 13 23    08    09
//  04 14 24    10 11 12
//

#define START_TOP_LEFT		43
#define START_TOP_RIGHT		44
#define START_MIDDLE_LEFT	45
#define START_MIDDLE_RIGHT	46
#define START_BOTTOM_LEFT	47
#define START_BOTTOM_RIGHT	48

int digits[][13][2] = {
    // Tiles
    // 00     01     02     03     04     05     06     07     08     09     10     11     12
    { {0,0}, {1,0}, {2,0}, {0,1}, {2,1}, {0,2}, {2,2}, {2,2}, {0,3}, {2,3}, {0,4}, {1,4}, {2,4} },    // 0 // ASCII 48
    { {1,0}, {1,0}, {1,0}, {0,1}, {1,1}, {1,2}, {1,2}, {1,2}, {1,3}, {1,3}, {0,4}, {1,4}, {2,4} },    // 1
    { {0,0}, {1,0}, {1,0}, {2,1}, {2,1}, {0,2}, {1,2}, {2,2}, {0,3}, {0,3}, {0,4}, {1,4}, {2,4} },    // 2
    { {0,0}, {1,0}, {2,0}, {2,1}, {2,1}, {0,2}, {1,2}, {2,2}, {2,3}, {2,3}, {0,4}, {1,4}, {2,4} },    // 3
    { {0,0}, {0,0}, {2,0}, {0,1}, {2,1}, {1,2}, {1,2}, {2,2}, {2,3}, {2,3}, {2,4}, {2,4}, {2,4} },    // 4
    { {0,0}, {1,0}, {2,0}, {0,1}, {0,1}, {0,2}, {1,2}, {2,2}, {2,3}, {2,3}, {0,4}, {1,4}, {1,4} },    // 5
    { {0,0}, {1,0}, {2,0}, {0,1}, {0,1}, {0,2}, {1,2}, {2,2}, {0,3}, {2,3}, {0,4}, {1,4}, {2,4} },    // 6
    { {0,0}, {1,0}, {2,0}, {2,1}, {2,1}, {1,2}, {1,2}, {1,2}, {1,3}, {1,3}, {1,4}, {1,4}, {1,4} },    // 7
    { {0,0}, {1,0}, {2,0}, {0,1}, {2,1}, {0,2}, {1,2}, {2,2}, {0,3}, {2,3}, {0,4}, {1,4}, {2,4} },    // 8
    { {0,0}, {1,0}, {2,0}, {0,1}, {2,1}, {0,2}, {1,2}, {2,2}, {2,3}, {2,3}, {0,4}, {1,4}, {2,4} },    // 9 // ASCII 57

    { {1,1}, {1,1}, {1,1}, {1,1}, {1,1}, {1,1}, {1,3}, {1,1}, {1,3}, {1,3}, {1,3}, {1,3}, {1,3} },    // : // 10 // ASCII 58
    { {1,1}, {1,1}, {1,1}, {1,1}, {1,1}, {1,1}, {1,3}, {1,1}, {1,3}, {1,3}, {0,4}, {0,4}, {0,4} },    // ;
    { {2,0}, {2,0}, {2,0}, {1,1}, {1,1}, {0,2}, {0,2}, {0,2}, {1,3}, {1,3}, {2,4}, {2,4}, {2,4} },    // <
    { {0,1}, {1,1}, {2,1}, {0,1}, {2,1}, {0,1}, {1,3}, {2,1}, {0,3}, {2,3}, {0,3}, {1,3}, {2,3} },    // =
    { {0,0}, {0,0}, {0,0}, {1,1}, {1,1}, {2,2}, {2,2}, {2,2}, {1,3}, {1,3}, {0,4}, {0,4}, {0,4} },    // >
    { {0,0}, {1,0}, {2,0}, {2,1}, {2,1}, {1,2}, {1,2}, {1,2}, {1,4}, {1,4}, {1,4}, {1,4}, {1,4} },    // ?
    { {1,0}, {1,0}, {2,0}, {0,1}, {2,1}, {0,2}, {1,1}, {1,2}, {0,3}, {0,3}, {1,4}, {1,4}, {2,4} },    // @ // 16 // ASCII 64

    { {1,0}, {1,0}, {1,0}, {0,1}, {2,1}, {0,2}, {2,2}, {2,2}, {0,3}, {2,3}, {0,4}, {2,4}, {2,4} },    // A // 17 // ASCII 65
    { {0,0}, {1,0}, {1,0}, {0,1}, {2,1}, {0,2}, {1,2}, {2,2}, {0,3}, {2,3}, {0,4}, {1,4}, {1,4} },    // B
    { {1,0}, {1,0}, {2,0}, {0,1}, {0,1}, {0,2}, {0,2}, {0,2}, {0,3}, {0,3}, {1,4}, {1,4}, {2,4} },    // C
    { {0,0}, {1,0}, {1,0}, {0,1}, {2,1}, {0,2}, {0,2}, {2,2}, {0,3}, {2,3}, {0,4}, {1,4}, {1,4} },    // D // 20
    { {0,0}, {1,0}, {2,0}, {0,1}, {0,1}, {0,2}, {1,2}, {2,2}, {0,3}, {0,3}, {0,4}, {1,4}, {2,4} },    // E
    { {0,0}, {1,0}, {2,0}, {0,1}, {0,1}, {0,2}, {1,2}, {2,2}, {0,3}, {0,3}, {0,4}, {0,4}, {0,4} },    // F
    { {1,0}, {1,0}, {2,0}, {0,1}, {0,1}, {0,2}, {0,2}, {0,2}, {0,3}, {2,3}, {1,4}, {1,4}, {2,4} },    // G
    { {0,0}, {2,0}, {2,0}, {0,1}, {2,1}, {0,2}, {1,2}, {2,2}, {0,3}, {2,3}, {0,4}, {2,4}, {2,4} },    // H
    { {0,0}, {1,0}, {2,0}, {1,1}, {1,1}, {1,2}, {1,2}, {1,2}, {1,3}, {1,3}, {0,4}, {1,4}, {2,4} },    // I // 25
    { {0,0}, {1,0}, {2,0}, {2,1}, {2,1}, {2,2}, {2,2}, {2,2}, {0,3}, {2,3}, {1,4}, {1,4}, {2,4} },    // J
    { {0,0}, {2,0}, {2,0}, {0,1}, {2,1}, {0,2}, {1,2}, {1,2}, {0,3}, {2,3}, {0,4}, {2,4}, {2,4} },    // K
    { {0,0}, {0,0}, {0,0}, {0,1}, {0,1}, {0,2}, {0,2}, {0,2}, {0,3}, {0,3}, {0,4}, {1,4}, {2,4} },    // L
    { {0,0}, {1,0}, {2,0}, {0,1}, {2,1}, {0,2}, {2,2}, {2,2}, {0,3}, {2,3}, {0,4}, {2,4}, {2,4} },    // M
    { {0,0}, {1,0}, {1,0}, {0,1}, {2,1}, {0,2}, {0,2}, {2,2}, {0,3}, {2,3}, {0,4}, {2,4}, {2,4} },    // N // 30
    { {1,0}, {1,0}, {1,0}, {0,1}, {2,1}, {0,2}, {2,2}, {2,2}, {0,3}, {2,3}, {1,4}, {1,4}, {1,4} },    // O
    { {0,0}, {1,0}, {1,0}, {0,1}, {2,1}, {0,2}, {1,2}, {1,2}, {0,3}, {0,3}, {0,4}, {0,4}, {0,4} },    // P
    { {1,0}, {1,0}, {1,0}, {0,1}, {2,1}, {0,2}, {2,2}, {2,2}, {0,3}, {2,3}, {1,4}, {1,4}, {2,4} },    // Q
    { {0,0}, {1,0}, {1,0}, {0,1}, {2,1}, {0,2}, {1,2}, {1,2}, {0,3}, {1,3}, {0,4}, {0,4}, {2,4} },    // R
    { {1,0}, {1,0}, {2,0}, {0,1}, {0,1}, {1,2}, {1,2}, {1,2}, {2,3}, {2,3}, {0,4}, {1,4}, {1,4} },    // S // 35
    { {0,0}, {1,0}, {2,0}, {1,1}, {1,1}, {1,2}, {1,2}, {1,2}, {1,3}, {1,3}, {1,4}, {1,4}, {1,4} },    // T
    { {0,0}, {0,0}, {2,0}, {0,1}, {2,1}, {0,2}, {0,2}, {2,2}, {0,3}, {2,3}, {1,4}, {1,4}, {1,4} },    // U
    { {0,0}, {0,0}, {2,0}, {0,1}, {2,1}, {0,2}, {0,2}, {2,2}, {1,3}, {1,3}, {1,4}, {1,4}, {1,4} },    // V
    { {0,0}, {0,0}, {2,0}, {0,1}, {2,1}, {0,2}, {0,2}, {2,2}, {1,3}, {1,3}, {0,4}, {2,4}, {2,4} },    // W
    { {0,0}, {0,0}, {2,0}, {0,1}, {2,1}, {1,2}, {1,2}, {1,2}, {0,3}, {2,3}, {0,4}, {2,4}, {2,4} },    // X // 40
    { {0,0}, {0,0}, {2,0}, {0,1}, {2,1}, {1,2}, {1,2}, {1,2}, {1,3}, {1,3}, {1,4}, {1,4}, {1,4} },    // Y
    { {0,0}, {1,0}, {2,0}, {2,1}, {2,1}, {1,2}, {1,2}, {1,2}, {0,3}, {0,3}, {0,4}, {1,4}, {2,4} },    // Z // 42 // ASCII 90

    { {0,0}, {1,0}, {2,0}, {0,1}, {0,1}, {0,2}, {0,2}, {0,2}, {0,3}, {0,3}, {0,4}, {0,4}, {0,4} },    //   // 43 // START_TOP_LEFT
    { {0,0}, {1,0}, {2,0}, {2,1}, {2,1}, {2,2}, {2,2}, {2,2}, {2,3}, {2,3}, {2,4}, {2,4}, {2,4} },    //   // 44 // START_TOP_RIGHT
    { {0,0}, {0,0}, {0,0}, {0,1}, {0,1}, {0,2}, {0,2}, {0,2}, {0,3}, {0,3}, {0,4}, {0,4}, {0,4} },    //   // 45 // START_MIDDLE_LEFT
    { {2,0}, {2,0}, {2,0}, {2,1}, {2,1}, {2,2}, {2,2}, {2,2}, {2,3}, {2,3}, {2,4}, {2,4}, {2,4} },    //   // 46 // START_MIDDLE_RIGHT
    { {0,0}, {0,0}, {0,0}, {0,1}, {0,1}, {0,2}, {0,2}, {0,2}, {0,3}, {0,3}, {0,4}, {1,4}, {2,4} },    //   // 47 // START_BOTTOM_LEFT
    { {2,0}, {2,0}, {2,0}, {2,1}, {2,1}, {2,2}, {2,2}, {2,2}, {2,3}, {2,3}, {0,4}, {1,4}, {2,4} }     //   // 48 // START_BOTTOM_RIGHT
};