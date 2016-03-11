#include <stdio.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

int main(void) {
	srand(1);
	printf("%d\n", rand() % 100);
	srand(2);
	printf("%d\n", rand() % 100);
	srand(3);
	printf("%d\n", rand() % 100);
	srand(4);
	printf("%d\n", rand() % 100);
}