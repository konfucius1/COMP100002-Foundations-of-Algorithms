#include <stdio.h>

void findFrequency(int A[], int n) {
	/*	create a count array of size `n` to store the count of all 
		array elements */
	int freq[n];

	for (int i = 0; i <= n; i++) {
		freq[i] = 0;
	}

	/* 	update frequency of each element */
	for (int i = 0; i < n; i++) {
		freq[A[i]]++;
	}

	/* 	iterate through the array to print frequencies */
	for (int i = 0; i <= n; i++) {
		if (freq[i] > 1 && i > 0) {
			printf("): %d instances of %d\n", freq[i], i);
		}
	}
}

int main() {
    int A[9] = {9, 3, 8, 9, 0, 2, 2, 0, 9};
    int n = sizeof(A) / sizeof(A[0]);

    findFrequency(A, n);
}

