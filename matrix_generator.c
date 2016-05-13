#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include "prngs.h"

int main( int argc, char *argv[]) {
	uint64_t seed = 1;
	int number_of_STAs = atoi(argv[1]);
	int maximum_BO_count = atoi(argv[2]);
	int total_attempts = atoi(argv[3]);

	int i;

	// fill in the permutation order, have 2-d array for orders (e.g., 1,2,3,4; 1,3,2,4; 1,3,4,2; 1,4,2,3; 1,4,3,2)
	// have the order be stored in a multidimensional array based on order to find seed (e.g., seed = seed_array[1][2][4][3])
	for(i=1; i <= number_of_STAs; i++) {
		printf("%" PRIu64 "\n", xorshift64star((uint64_t)i) % maximum_BO_count);
	}
}