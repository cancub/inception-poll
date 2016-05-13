#include <stdint.h>
#include <inttypes.h>

uint64_t xorshift64star(uint64_t x) {
	x ^= x >> 12; // a
	x ^= x << 25; // b
	x ^= x >> 27; // c
	return x * UINT64_C(2685821657736338717);
}