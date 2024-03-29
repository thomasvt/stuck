#include <Levels.h>

namespace levels {

	// copy these to the levels.h file:
	
	// -- end

	const uint16_t level0_name_data[] PROGMEM = { // entrance
	0, 0, 0, 0, 0, 0, 0,
	0
	};
	const uint16_t level1_name_data[] PROGMEM = { // prison
	0, 0, 0, 0, 0, 0, 0,
	0
	};
	const uint16_t level2_name_data[] PROGMEM = { // sevenportals
	0, 0, 0, 0, 0, 0, 0,
	0
	};
	const uint16_t level3_name_data[] PROGMEM = { // tower
	0, 0, 0, 0, 0, 0, 0,
	0
	};
	const uint16_t level4_name_data[] PROGMEM = { // vault
	0, 0, 0, 0, 0, 0, 0,
	0
	};
	const uint16_t level5_name_data[] PROGMEM = { // vaultl
	0, 0, 0, 0, 0, 0, 0,
	0
	};
	const uint16_t level6_name_data[] PROGMEM = { // vaultr
	0, 0, 0, 0, 0, 0, 0,
	0
	};

	const uint8_t level0_data[] PROGMEM = { // entrance
		77, 23, // width, height
2, // spawnpoints
39, 17,
63, 1,
2, // portals
63, 17, 2, 0,
1, 2, 0, 1,
7, // trigger areas
0, 53, 15, 53, 17,
1, 61, 15, 61, 17,
1, 65, 15, 65, 17,
2, 56, 20, 56, 21,
2, 70, 20, 70, 21,
3, 25, 16, 25, 17,
2, 73, 15, 73, 17,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
30, 0, 0, 30, 18, 18, 0, 0, 3, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
30, 30, 30, 30, 30, 30, 30, 30, 3, 3, 3, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 18, 0, 18, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 30, 30, 0, 0, 0, 0, 0, 0, 3, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 30, 65, 18, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 30, 30, 30, 30, 30, 30, 4, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 31, 31, 31, 31, 31, 30, 0, 0, 0, 30, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31,
0, 0, 30, 0, 0, 0, 0, 0, 4, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 32, 0, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30,
0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 32, 0, 0, 0, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 18, 0, 18, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30,
0, 0, 30, 0, 0, 0, 0, 18, 4, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 32, 0, 0, 0, 0, 0, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30,
0, 0, 30, 4, 30, 30, 30, 30, 30, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 33, 33, 33, 33, 33, 33, 33, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30,
0, 0, 30, 4, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34, 0, 0, 0, 0, 0, 34, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30,
0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34, 0, 0, 0, 0, 0, 34, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30,
0, 0, 30, 4, 18, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34, 0, 0, 0, 19, 67, 34, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 18, 18, 3, 0, 0, 0, 0, 0, 0, 0, 64, 0, 18, 30, 0, 0, 0, 0, 0, 0, 18, 0, 0, 0, 0, 0, 0, 0, 10, 0, 18, 0, 0, 30,
0, 0, 30, 30, 30, 30, 30, 30, 4, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34, 4, 33, 33, 33, 33, 34, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 30, 30, 30, 4, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 0, 0, 0, 0, 30, 30, 30, 30, 30, 0, 0, 0, 0, 0, 30, 30, 30, 0, 4, 30,
0, 0, 30, 0, 0, 0, 0, 0, 4, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34, 4, 0, 0, 0, 0, 34, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 29, 0, 0, 0, 0, 0, 0, 0, 29, 0, 30, 0, 29, 0, 0, 0, 0, 0, 0, 0, 30, 0, 4, 30,
0, 0, 30, 0, 0, 0, 0, 0, 4, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 29, 4, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 29, 0, 0, 0, 0, 0, 0, 0, 29, 0, 0, 0, 29, 0, 0, 0, 0, 0, 0, 0, 29, 0, 4, 30,
13, 0, 30, 19, 0, 19, 0, 18, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19, 0, 19, 0, 0, 29, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 29, 0, 19, 0, 0, 0, 0, 0, 29, 0, 0, 0, 29, 0, 0, 0, 0, 0, 0, 0, 29, 0, 4, 30,
31, 4, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 0, 0, 0, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 4, 0, 0, 30, 30, 30, 30, 30, 30, 30, 0, 0, 4, 30, 30, 30, 30, 30, 30, 30,
30, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 30, 4, 0, 0, 27, 0, 0, 0, 0, 0, 27, 0, 0, 4, 30, 0, 0, 0, 30, 0, 0,
30, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 29, 4, 0, 0, 27, 0, 0, 0, 0, 0, 27, 0, 0, 4, 29, 0, 0, 0, 30, 0, 0,
30, 4, 0, 0, 19, 0, 0, 0, 0, 0, 19, 0, 0, 0, 30, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 17, 0, 19, 29, 4, 0, 0, 27, 0, 0, 66, 0, 0, 27, 0, 0, 4, 29, 19, 0, 18, 30, 0, 0,
30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 0, 0,
	};
	const uint8_t level1_data[] PROGMEM = { // prison
		20, 31, // width, height
1, // spawnpoints
1, 29,
1, // portals
17, 4, 2, 0,
5, // trigger areas
4, 10, 28, 10, 29,
4, 13, 18, 13, 19,
5, 13, 13, 13, 14,
6, 3, 8, 4, 8,
6, 13, 28, 13, 29,
30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30,
30, 0, 0, 0, 0, 0, 0, 0, 0, 18, 30, 0, 0, 30, 0, 0, 0, 0, 0, 30,
30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 30, 0, 0, 0, 29, 29, 30,
30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 8, 0, 0, 0, 0, 29, 30,
30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 22, 0, 0, 29, 30,
30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 4, 30, 30, 30, 30, 30, 30, 30, 30,
30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 4, 0, 30, 0, 0, 0, 0, 0, 30,
30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 4, 0, 30, 0, 0, 0, 0, 0, 30,
30, 0, 0, 29, 29, 0, 0, 0, 0, 0, 7, 4, 0, 29, 0, 0, 0, 0, 0, 30,
30, 70, 5, 5, 5, 5, 5, 5, 23, 0, 0, 4, 0, 29, 0, 0, 0, 19, 0, 30,
30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 4, 30, 30, 30, 30, 30, 30, 30, 30,
30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 4, 0, 30, 0, 0, 0, 0, 0, 30,
30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 4, 0, 30, 0, 0, 0, 0, 0, 30,
30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 4, 0, 29, 0, 0, 0, 0, 0, 30,
30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 4, 0, 29, 0, 5, 5, 0, 11, 30,
30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 4, 30, 30, 30, 30, 30, 30, 30, 30,
30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 4, 0, 30, 0, 0, 0, 0, 0, 30,
30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 4, 0, 30, 0, 0, 0, 0, 0, 30,
30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 4, 0, 29, 0, 0, 0, 0, 0, 30,
30, 12, 241, 240, 243, 242, 241, 240, 0, 0, 0, 4, 0, 29, 0, 0, 19, 0, 69, 30,
30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 4, 30, 30, 30, 30, 30, 30, 30, 30,
30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 4, 0, 3, 0, 0, 0, 0, 0, 30,
30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 4, 0, 3, 0, 0, 0, 0, 0, 30,
30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 4, 0, 29, 0, 0, 0, 0, 0, 30,
30, 68, 0, 20, 0, 0, 0, 0, 0, 0, 30, 4, 0, 29, 0, 0, 17, 0, 18, 30,
30, 30, 30, 30, 30, 30, 30, 4, 30, 30, 30, 4, 30, 30, 30, 30, 30, 30, 30, 30,
30, 0, 0, 0, 0, 0, 0, 4, 0, 0, 30, 4, 0, 30, 0, 0, 0, 0, 0, 30,
30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 4, 0, 30, 0, 0, 0, 0, 0, 30,
30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 29, 4, 0, 29, 0, 0, 0, 0, 0, 30,
30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 29, 4, 0, 29, 0, 20, 19, 20, 13, 30,
30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30,
	};
	const uint8_t level2_data[] PROGMEM = { // sevenportals
		40, 35, // width, height
4, // spawnpoints
18, 33,
3, 30,
36, 33,
3, 9,
3, // portals
38, 33, 4, 1,
1, 30, 4, 0,
1, 9, 3, 0,
5, // trigger areas
7, 2, 29, 2, 30,
8, 37, 32, 37, 33,
9, 37, 13, 37, 14,
10, 2, 13, 2, 14,
10, 0, 18, 2, 18,
0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 30, 30, 0, 0, 30, 30, 0, 0, 30, 30, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 30, 30, 30, 30, 30, 30, 30, 30, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 30, 17, 18, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
29, 29, 29, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 30, 30, 30, 30, 30, 30, 4, 30, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
29, 0, 29, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 4, 30, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
29, 0, 29, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 4, 30, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 0, 0, 0, 0, 0, 30, 0, 0, 0, 18, 0, 4, 30, 0, 0, 0, 0, 0, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30,
0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 30, 4, 30, 30, 30, 30, 30, 30, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
29, 29, 29, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 29, 29, 29,
29, 0, 29, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 29, 0, 29,
29, 0, 29, 0, 0, 0, 0, 0, 0, 27, 0, 0, 19, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 29, 0, 29,
30, 30, 30, 30, 30, 30, 0, 30, 30, 30, 31, 31, 31, 31, 31, 31, 31, 31, 0, 0, 0, 31, 31, 31, 31, 31, 31, 31, 30, 30, 30, 4, 30, 30, 30, 30, 30, 30, 30, 30,
0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 4, 30, 0, 0, 0, 0, 0, 0, 0,
74, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 4, 30, 0, 0, 0, 0, 0, 0, 73,
29, 29, 29, 0, 0, 30, 30, 30, 0, 30, 0, 0, 0, 0, 30, 30, 0, 17, 30, 30, 30, 0, 30, 30, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 33,
0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 30, 4, 30, 30, 30, 30, 30, 30, 0, 0, 0, 0, 0, 30, 0, 0, 33, 32, 33, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 20, 0, 30, 0, 0, 0, 0, 0, 30, 4, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
33, 0, 0, 0, 0, 0, 0, 33, 33, 30, 0, 0, 0, 0, 0, 30, 4, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 30, 4, 0, 0, 18, 0, 0, 30, 0, 0, 0, 0, 0, 30, 33, 0, 0, 0, 0, 0, 0, 32, 0, 0, 0,
0, 0, 0, 0, 34, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 30, 30, 30, 30, 30, 30, 4, 30, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
5, 5, 5, 5, 34, 5, 5, 34, 18, 30, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 4, 30, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 18,
30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 4, 30, 0, 0, 0, 0, 0, 30, 5, 5, 5, 5, 34, 5, 5, 5, 5, 5, 34,
0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 18, 0, 4, 30, 0, 0, 0, 0, 0, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30,
0, 18, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 30, 4, 30, 30, 30, 30, 30, 30, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
29, 29, 29, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 27, 4, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 72, 0,
29, 0, 29, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 27, 4, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 33, 33,
29, 0, 29, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 27, 4, 0, 19, 0, 0, 0, 27, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 32, 0, 0, 0, 0,
30, 30, 30, 30, 30, 4, 30, 30, 0, 0, 0, 0, 0, 0, 0, 31, 31, 31, 31, 31, 31, 31, 31, 0, 0, 0, 0, 0, 27, 0, 0, 0, 32, 0, 0, 0, 0, 29, 29, 29,
30, 0, 0, 0, 0, 4, 0, 30, 29, 29, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 29, 29, 30, 30, 0, 0, 0, 0, 0, 0, 0, 29, 0, 29,
30, 71, 0, 0, 0, 0, 0, 30, 0, 29, 29, 0, 0, 0, 0, 27, 0, 0, 0, 0, 17, 0, 27, 0, 0, 29, 29, 0, 30, 30, 30, 0, 0, 0, 0, 0, 0, 29, 0, 29,
30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30,
	};
	const uint8_t level3_data[] PROGMEM = { // tower
		14, 142, // width, height
5, // spawnpoints
10, 141,
11, 88,
7, 69,
13, 62,
1, 30,
6, // portals
13, 103, 3, 1,
13, 70, 3, 2,
0, 64, 3, 3,
9, 42, 3, 4,
12, 3, 2, 3,
12, 141, 2, 3,
9, // trigger areas
11, 2, 33, 2, 35,
12, 8, 29, 8, 34,
13, 3, 4, 10, 4,
14, 6, 5, 7, 5,
15, 11, 2, 11, 3,
16, 5, 25, 7, 27,
17, 6, 48, 8, 48,
18, 9, 49, 9, 54,
13, 10, 14, 10, 17,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 29, 29, 29,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 29, 0, 29,
79, 18, 0, 0, 0, 0, 0, 0, 0, 0, 0, 29, 0, 29,
31, 31, 31, 29, 29, 29, 29, 29, 29, 29, 29, 31, 31, 31,
0, 0, 30, 0, 0, 0, 28, 28, 0, 0, 0, 30, 0, 0,
0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 9, 0, 0,
77, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 78,
30, 30, 30, 0, 0, 0, 0, 0, 0, 0, 0, 30, 30, 30,
0, 0, 0, 18, 0, 0, 0, 0, 0, 0, 18, 0, 0, 0,
18, 0, 18, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 18,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
5, 5, 5, 5, 5, 0, 0, 0, 0, 5, 5, 5, 5, 5,
30, 30, 30, 30, 30, 0, 0, 23, 0, 30, 30, 30, 30, 30,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 29, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 29, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 29, 0, 0, 0,
0, 0, 0, 0, 0, 5, 0, 0, 5, 0, 29, 0, 0, 0,
0, 0, 0, 0, 0, 30, 0, 0, 30, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 30, 0, 0, 30, 0, 0, 0, 0, 0,
0, 0, 0, 0, 10, 30, 0, 0, 30, 13, 0, 0, 0, 0,
0, 0, 0, 0, 0, 30, 23, 23, 30, 0, 0, 0, 0, 0,
0, 23, 0, 5, 5, 30, 0, 0, 30, 5, 5, 0, 23, 0,
5, 5, 5, 30, 30, 30, 0, 0, 30, 30, 30, 5, 5, 5,
30, 30, 30, 30, 0, 0, 0, 0, 0, 0, 30, 30, 30, 30,
0, 0, 0, 0, 0, 0, 0, 28, 0, 0, 0, 0, 0, 0,
18, 0, 0, 0, 0, 0, 28, 0, 0, 0, 0, 0, 0, 0,
80, 0, 0, 0, 0, 28, 0, 0, 0, 0, 0, 0, 0, 0,
30, 30, 30, 30, 30, 30, 30, 30, 30, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 29, 0, 0, 0, 0, 0,
18, 0, 0, 0, 0, 0, 0, 0, 29, 0, 0, 0, 0, 0,
30, 30, 30, 0, 0, 0, 0, 0, 29, 0, 0, 0, 0, 0,
0, 0, 30, 0, 0, 0, 0, 0, 29, 0, 17, 0, 0, 0,
0, 0, 29, 0, 0, 0, 0, 0, 29, 0, 0, 0, 0, 0,
0, 0, 29, 0, 0, 0, 0, 0, 29, 0, 0, 23, 0, 0,
82, 0, 29, 0, 0, 0, 0, 0, 5, 5, 5, 5, 0, 0,
30, 30, 30, 0, 0, 0, 0, 0, 30, 3, 30, 30, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 30, 240, 0, 0, 18, 18,
0, 0, 0, 0, 0, 0, 0, 0, 30, 30, 30, 30, 30, 30,
0, 0, 0, 0, 0, 23, 0, 0, 30, 0, 0, 0, 0, 0,
0, 5, 5, 5, 5, 5, 5, 5, 30, 0, 0, 0, 0, 0,
0, 30, 30, 30, 30, 30, 30, 30, 30, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 19, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 81, 30, 30, 30, 0, 0, 0,
30, 30, 30, 30, 0, 30, 30, 30, 30, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 23, 0,
4, 30, 30, 30, 30, 30, 29, 29, 29, 30, 30, 30, 30, 30,
4, 30, 18, 0, 0, 0, 0, 18, 0, 29, 0, 0, 18, 0,
4, 30, 0, 0, 0, 0, 0, 0, 0, 29, 0, 0, 0, 0,
4, 30, 0, 0, 0, 0, 0, 0, 0, 29, 0, 0, 0, 0,
4, 30, 0, 0, 0, 0, 0, 0, 0, 29, 0, 0, 0, 0,
4, 30, 0, 0, 0, 0, 0, 0, 0, 29, 0, 0, 0, 0,
4, 30, 0, 75, 0, 0, 0, 23, 0, 29, 0, 0, 76, 0,
4, 30, 5, 30, 5, 240, 5, 5, 5, 5, 5, 5, 30, 5,
4, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30,
4, 0, 0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0,
4, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0,
4, 0, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
31, 31, 31, 31, 31, 31, 31, 31, 31, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 30, 30, 30, 30, 30, 30,
0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0,
29, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 18, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 18,
0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 29,
0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 23, 0, 0, 30, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 29,
0, 0, 0, 0, 0, 0, 5, 5, 30, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 30, 30, 30, 0, 0, 0, 0, 0,
0, 0, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 17,
0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0,
0, 0, 23, 0, 0, 0, 0, 0, 0, 30, 0, 0, 23, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 5, 240, 5, 5,
0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 30, 30, 30, 30,
0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0,
5, 5, 5, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0,
31, 31, 31, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
11, 0, 30, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0,
30, 0, 30, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0,
0, 0, 30, 30, 30, 30, 30, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 23, 0, 0,
0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 0, 0,
0, 23, 0, 0, 0, 0, 30, 5, 5, 5, 5, 5, 5, 5,
0, 0, 0, 0, 0, 0, 30, 30, 30, 30, 30, 30, 30, 30,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 30,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 4, 30, 30, 30, 30, 30,
0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0,
0, 0, 0, 23, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 5, 5, 0, 0,
5, 5, 240, 5, 0, 0, 0, 30, 30, 30, 30, 30, 30, 4,
30, 30, 30, 30, 0, 0, 0, 30, 0, 0, 0, 0, 0, 4,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4,
0, 0, 0, 0, 0, 0, 0, 0, 30, 5, 5, 5, 30, 30,
0, 0, 0, 0, 0, 0, 0, 0, 30, 30, 30, 30, 30, 0,
4, 30, 5, 0, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0,
4, 30, 30, 0, 30, 30, 0, 0, 0, 0, 0, 0, 0, 0,
4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
31, 31, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 31, 31, 31, 31, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 240, 0, 0, 0, 0, 0, 0, 0, 0, 0, 23,
0, 0, 0, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 29, 29,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 29,
0, 23, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 29,
	};
	const uint8_t level4_data[] PROGMEM = { // vault
		60, 28, // width, height
4, // spawnpoints
3, 26,
56, 4,
6, 4,
53, 26,
5, // portals
5, 4, 5, 0,
54, 26, 6, 0,
1, 26, 2, 1,
58, 4, 2, 2,
33, 26, 2, 0,
5, // trigger areas
19, 16, 5, 17, 5,
20, 38, 5, 39, 5,
21, 21, 15, 21, 18,
22, 38, 12, 38, 14,
23, 32, 25, 32, 26,
0, 0, 0, 0, 0, 0, 0, 0, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30,
30, 30, 30, 30, 30, 30, 30, 30, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 29, 29, 29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 29, 29,
0, 0, 0, 0, 29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 29,
0, 0, 0, 0, 29, 0, 0, 0, 0, 19, 0, 0, 0, 0, 0, 18, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 83, 30, 84, 18, 0, 0, 0, 0, 0, 0, 0, 19, 0, 0, 0, 0, 0, 0, 0, 29,
30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 28, 28, 0, 0, 0, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 29, 29, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 4, 30, 30, 30, 30,
0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 30, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 30, 4, 0, 0, 0, 30,
0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 30, 30, 30, 0, 0, 0, 0, 30, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 18, 0, 30, 0, 4, 0, 0, 0, 30,
0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 30, 30, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 5, 0, 0, 5, 0, 0, 0, 0, 4, 0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 30, 30, 0, 4, 0, 0, 0, 30,
0, 0, 0, 0, 0, 30, 30, 30, 30, 30, 30, 30, 30, 0, 0, 0, 0, 30, 30, 0, 0, 4, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 33, 33, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 4, 0, 0, 30, 30,
0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 30, 30, 0, 0, 4, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 30, 30, 30, 0, 0, 0, 4, 0, 30, 30, 34,
0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 30, 0, 3, 0, 0, 4, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 4, 30, 30, 0, 34,
0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 19, 0, 0, 30, 30, 0, 18, 3, 0, 0, 4, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 29, 0, 0, 30, 0, 0, 0, 0, 0, 30, 30, 30, 0, 0, 0, 0, 0, 30, 30, 0, 0, 34,
0, 0, 0, 0, 0, 30, 4, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 0, 0, 4, 30, 0, 0, 0, 32, 18, 0, 18, 0, 18, 32, 0, 0, 0, 30, 0, 29, 0, 0, 30, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 30, 30, 0, 0, 0, 34,
0, 0, 0, 0, 0, 30, 4, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 30, 4, 30, 30, 30, 20, 0, 0, 18, 0, 18, 0, 18, 0, 18, 0, 0, 20, 30, 86, 29, 0, 0, 30, 0, 0, 0, 3, 3, 3, 0, 0, 0, 0, 0, 30, 30, 0, 0, 0, 0, 34,
0, 0, 0, 0, 0, 30, 4, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 30, 4, 30, 29, 30, 30, 0, 18, 0, 18, 0, 18, 0, 18, 0, 18, 0, 30, 30, 30, 30, 4, 0, 30, 0, 18, 0, 3, 0, 0, 0, 0, 0, 0, 30, 30, 0, 0, 0, 0, 0, 34,
0, 0, 0, 0, 0, 30, 4, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 30, 4, 0, 29, 0, 0, 0, 0, 0, 19, 14, 0, 17, 17, 19, 0, 0, 0, 0, 0, 30, 4, 0, 30, 0, 30, 30, 30, 0, 0, 0, 0, 0, 30, 30, 0, 0, 0, 0, 0, 0, 34,
0, 0, 0, 0, 0, 30, 4, 0, 0, 0, 18, 0, 0, 0, 0, 0, 18, 85, 30, 4, 0, 29, 0, 0, 0, 4, 30, 30, 30, 30, 30, 30, 30, 30, 4, 0, 0, 0, 30, 4, 0, 30, 18, 30, 0, 0, 0, 0, 0, 0, 30, 30, 0, 0, 0, 0, 0, 0, 0, 34,
30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 4, 30, 30, 30, 30, 30, 30, 30, 29, 30, 0, 0, 4, 0, 27, 0, 0, 0, 0, 27, 0, 4, 0, 0, 0, 30, 4, 0, 30, 30, 30, 0, 0, 0, 0, 0, 4, 30, 0, 0, 18, 18, 0, 0, 0, 0, 34,
30, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 4, 0, 30, 0, 0, 0, 0, 0, 0, 30, 4, 30, 30, 30, 30, 30, 30, 30, 0, 0, 34,
30, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 30, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27, 0, 0, 4, 0, 30, 0, 0, 0, 0, 0, 30, 30, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34,
30, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 30, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27, 0, 0, 4, 30, 30, 0, 0, 0, 0, 30, 30, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34,
30, 0, 18, 0, 0, 27, 0, 19, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 30, 18, 0, 0, 0, 27, 0, 19, 0, 0, 0, 30, 0, 0, 0, 19, 0, 0, 27, 0, 30, 30, 30, 0, 0, 0, 0, 30, 30, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 17, 18, 34,
30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 4, 30, 30, 0, 4, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 0, 0, 0, 0, 4, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30,
29, 29, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 30, 0, 0, 4, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 29, 29, 29, 0, 27, 0, 30, 0, 0, 0, 0, 4, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 29, 29, 29, 0, 0, 0,
29, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 30, 0, 0, 4, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 29, 0, 29, 0, 27, 0, 30, 0, 0, 0, 0, 4, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 29, 0, 0, 0, 0,
29, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 30, 0, 0, 4, 0, 27, 0, 0, 0, 0, 0, 20, 87, 0, 29, 0, 29, 0, 27, 0, 30, 0, 0, 0, 0, 4, 0, 0, 27, 0, 0, 0, 19, 0, 0, 0, 0, 29, 0, 0, 0, 0,
30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30,
	};
	const uint8_t level5_data[] PROGMEM = { // vaultl
		38, 35, // width, height
2, // spawnpoints
32, 17,
32, 13,
3, // portals
34, 28, 5, 1,
33, 17, 4, 2,
37, 22, 5, 0,
3, // trigger areas
24, 29, 12, 30, 13,
25, 33, 27, 33, 28,
26, 7, 24, 9, 24,
0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 31, 31, 31, 31, 31, 31, 31, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 3, 0, 0, 18, 0, 0, 18, 0, 0, 18, 0, 0, 0, 0, 0, 0,
0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 11, 0, 0, 18, 30, 0, 0, 31, 0, 0, 31, 0, 0, 31, 0, 0, 0, 0, 0, 0,
0, 30, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 30, 30, 4, 30, 30, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27, 0, 0, 4, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 17, 18, 0,
0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27, 0, 0, 4, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 31, 31, 31, 31, 31,
0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27, 0, 0, 4, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0,
0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27, 0, 0, 4, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0,
0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 88, 0, 0, 18,
0, 30, 0, 0, 0, 0, 0, 0, 0, 19, 0, 0, 0, 19, 0, 0, 27, 0, 31, 5, 31, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 30, 30, 4, 30,
0, 30, 30, 30, 4, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 31, 31, 31, 0, 0, 0, 0, 27, 0, 0, 4, 0,
0, 30, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 28, 0, 0, 0, 27, 0, 0, 4, 0,
30, 30, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 28, 0, 0, 27, 0, 0, 4, 0,
30, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30,
30, 0, 0, 17, 4, 0, 0, 0, 0, 19, 0, 18, 0, 0, 0, 0, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 29, 29, 29, 0, 0,
30, 0, 0, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 31, 31, 31, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 29, 0, 0, 0,
30, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 31, 0, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 29, 0, 0, 0,
30, 0, 0, 27, 0, 0, 0, 0, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27, 0, 0, 31, 0, 0, 0, 0, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30,
30, 30, 30, 30, 30, 30, 4, 30, 30, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27, 5, 5, 27, 0, 0, 30, 30, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 30, 4, 0, 0, 30, 30, 30, 0, 0, 31, 0, 0, 31, 0, 0, 30, 30, 30, 3, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 30, 4, 0, 0, 0, 0, 30, 0, 0, 27, 0, 0, 27, 0, 0, 30, 0, 0, 3, 0, 0, 3, 0, 0, 0, 0, 18, 0, 18, 0, 0, 0, 0,
0, 0, 0, 0, 0, 30, 4, 0, 0, 0, 0, 30, 0, 0, 27, 0, 0, 27, 0, 0, 30, 18, 0, 3, 0, 0, 3, 0, 18, 0, 30, 30, 5, 30, 30, 30, 0, 0,
0, 0, 0, 0, 0, 30, 4, 0, 12, 0, 90, 30, 5, 5, 27, 5, 5, 27, 5, 5, 30, 18, 0, 30, 5, 5, 30, 30, 30, 30, 30, 30, 30, 30, 0, 30, 30, 30,
0, 0, 0, 0, 0, 30, 30, 29, 29, 29, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 30, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 30, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 29, 29, 29, 4, 0,
0, 0, 0, 0, 0, 30, 0, 0, 0, 4, 0, 0, 0, 31, 31, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 29, 0, 29, 4, 0,
0, 0, 0, 0, 0, 30, 18, 0, 0, 30, 30, 30, 5, 27, 27, 5, 30, 30, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 19, 89, 19, 29, 0, 29, 4, 0,
0, 0, 0, 0, 0, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 0, 0, 0, 31, 0, 31, 0, 0, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 4,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 27, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 27, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 27, 0, 27, 0, 0, 0, 0, 0, 18, 31, 0, 0, 18, 0, 19, 0, 4,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 5, 5, 5, 27, 5, 27, 5, 5, 5, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	};
	const uint8_t level6_data[] PROGMEM = { // vaultr
		50, 40, // width, height
3, // spawnpoints
7, 10,
8, 30,
48, 8,
3, // portals
6, 10, 4, 3,
8, 26, 6, 1,
48, 26, 6, 2,
10, // trigger areas
27, 18, 23, 21, 23,
28, 43, 34, 43, 36,
29, 19, 18, 22, 18,
30, 27, 22, 29, 22,
30, 4, 21, 4, 22,
31, 26, 18, 29, 18,
31, 17, 25, 17, 26,
31, 14, 23, 14, 23,
31, 24, 11, 24, 11,
31, 46, 10, 46, 10,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 18, 0, 18, 0, 18, 0, 0, 0, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 0, 0, 0, 31, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 34, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34, 0, 0, 0, 0, 0, 0,
30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 29, 29, 29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 18, 0, 0,
0, 0, 0, 0, 0, 29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 30, 4,
0, 0, 0, 0, 0, 29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19, 0, 0, 0, 0, 0, 0, 0, 19, 0, 0, 0, 0, 0, 28, 30, 0, 4,
30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 28, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 0, 4,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 18, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 4,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 0, 30, 0, 0, 4,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 18, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 33, 33, 0, 30, 0, 0, 4,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 4,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 18, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 4,
94, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19, 0, 0, 0, 27, 0, 0, 0, 0, 18, 0, 0, 0, 0, 0, 18, 0, 0, 0, 27, 0, 0, 0, 19, 0, 0, 0, 0, 0, 0, 23, 0, 0, 18, 30, 0, 0, 4,
30, 30, 30, 4, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 28, 28, 28, 28, 0, 18, 0, 28, 28, 28, 28, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 0, 0, 4,
0, 0, 0, 4, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 4,
0, 0, 0, 4, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 18, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 4,
0, 0, 0, 4, 29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27, 0, 0, 19, 0, 0, 0, 0, 0, 0, 18, 0, 95, 17, 30, 0, 0, 0, 4,
18, 0, 0, 4, 29, 0, 93, 0, 0, 0, 0, 19, 0, 0, 0, 0, 27, 0, 0, 0, 18, 0, 0, 0, 18, 0, 0, 28, 28, 28, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 0, 0, 0, 4,
30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 29, 30, 30, 30, 28, 28, 28, 28, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4,
30, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 30, 0, 4, 0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 29, 29,
30, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 6, 0, 4, 0, 0, 29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 29,
30, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 0, 4, 19, 0, 29, 0, 0, 0, 91, 0, 0, 0, 22, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 19, 0, 0, 18, 0, 0, 0, 0, 0, 0, 29,
30, 0, 0, 0, 0, 0, 0, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 5, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 5, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 4, 30, 30, 30,
30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 30, 30, 0, 0, 0, 0, 13, 0, 0, 0, 30, 30, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 4, 0, 0, 0,
30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 4, 0, 0, 0,
30, 0, 0, 31, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 18, 30, 0, 0, 0, 0, 30, 30, 30, 30, 4, 0, 0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 4, 0, 0, 0,
30, 0, 0, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 0, 0, 0, 0, 27, 0, 0, 27, 4, 0, 0, 0, 30, 0, 18, 0, 0, 0, 0, 0, 0, 0, 0, 92, 0, 30, 0, 0, 4, 0, 0, 0,
30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27, 0, 0, 27, 4, 0, 0, 0, 30, 30, 30, 30, 30, 30, 4, 30, 30, 30, 30, 30, 30, 30, 0, 0, 4, 0, 0, 0,
30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 18, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27, 0, 0, 27, 4, 0, 19, 18, 30, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 30, 0, 0, 4, 0, 0, 0,
30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 29, 0, 0, 4, 0, 0, 0,
30, 0, 0, 0, 0, 32, 0, 0, 32, 0, 0, 0, 32, 0, 0, 32, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 29, 0, 0, 4, 0, 0, 0,
30, 0, 0, 0, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 19, 4, 0, 0, 0, 0, 0, 0, 29, 0, 0, 4, 0, 0, 18,
30, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 19, 0, 0, 0, 0, 0, 27, 0, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30,
30, 30, 30, 0, 0, 0, 0, 18, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 30, 30, 5, 5, 30, 30, 30, 30, 5, 5, 30, 30, 30, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 0, 30, 30, 30, 30, 0, 0, 30, 30, 30, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	};

	const Level levels[] PROGMEM = {
		Level(level0_name_data, level0_data),
		Level(level1_name_data, level1_data),
		Level(level2_name_data, level2_data),
		Level(level3_name_data, level3_data),
		Level(level4_name_data, level4_data),
		Level(level5_name_data, level5_data),
		Level(level6_name_data, level6_data),
	};

}

