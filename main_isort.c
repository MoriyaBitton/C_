#include <stdio.h>
#include "isort.h"

#define LEN 50

int main() { 
    int arr[LEN] = {};
    //printf("The %d-size array is sorted using- income sorting: ", LEN);
    for (int i = 0; i < LEN; i++) {
    	scanf("%d", arr+ i);
    }

    insertion_sort(arr, LEN);

    //Sorted Array
    printf("%d", arr[0]);
    for (int i = 1; i < LEN; i++) {
        printf(",%d", arr[i]);
    }
    printf("\n");

    return 0;
}
