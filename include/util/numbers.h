#ifndef MY_NUMBERS_MODULE_H
#define MY_NUMBERS_MODULE_H

#define min(x, y) (((x) < (y)) ? (x) : (y))
#define max(x, y) (((x) > (y)) ? (x) : (y))

int r_int(int max);

int r_irange(int min, int max);

int r_chance();

int r_min(int x, int y);

int r_max(int x, int y);

#endif