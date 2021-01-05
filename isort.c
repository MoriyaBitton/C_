#include <stdio.h>

// The function will get a pointer to the array 
// (not necessarily to the beginning of the array) and a number. 
// The function will move the i members following 
// in one cell array to the right.
void shift_element(int* arr, int i) {
  	for (int index = i; index > 0; index--) {
       	*(arr + index) = *(arr + (index - 1));
   	}
}

// The function must have an array the size of 
// a len and sort it using the income sorting algorithm.
void insertion_sort(int* arr, int len) {
	for (int i = 1; i < len; i++) { 
		int current_element = *(arr + i);
     		int j;
      		for (j = 0; j < i && (current_element > *(arr + j)); j++);
      		shift_element(arr + j, i - j);
       	*(arr + j) = current_element;
   	}
}

