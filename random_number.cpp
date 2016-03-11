#include <iostream>
#include <cstdlib>     /* srand, rand */
#include <time.h>       /* time */
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	int total_STAs = atoi(argv[1]);
	int maximum_backoff_slots = atoi(argv[2]);
	int total_attempts = atoi(argv[3]);
	int test_rand;
	int no_repetition;
	std::vector<int> backoff_slots;
	backoff_slots.reserve(total_STAs);

	for (int i = 0; i < total_attempts; i++) {
		no_repetition = 1;
		for (int j = 1; j <= total_STAs; j++) {
			srand(i+j);
			if (j == 1) {
				backoff_slots.push_back(rand() % maximum_backoff_slots);
			}			
			else {
				test_rand = rand() % maximum_backoff_slots;
				for (std::vector<int>::iterator it = backoff_slots.begin(); it != backoff_slots.end(); ++it) {
					if (test_rand == *it){
						no_repetition = 0;
						break;
					}
				}

				if (!no_repetition) {
					backoff_slots.clear();
					break;
				}
				else {
					backoff_slots.push_back(test_rand);
				}
			}
		}

		if (no_repetition) {
			cout << i << ":\t";
			for (std::vector<int>::iterator it = backoff_slots.begin(); it != backoff_slots.end(); ++it) {
				cout << *it << "\t";
			}
			cout << endl;
		}
	}
	


	return 0;
}