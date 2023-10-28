#include <stdio.h>
#include "Array.h"

void del(int* arr, int index, int& len) { //„…„t„p„|„y„|„y „„|„u„}„u„~„„
    len--;
    for (int i = index; i < len; i++) {
        arr[i] = arr[i + 1];
    }
}

void pushArr(int* arr, int* arr2, int index, int value, int& len) {
    arr2[index] = value;
    for (int i = 0; i < index; i++) {
        arr2[i] = arr[i];
    }
    for (int i = index + 1; i <= len; i++) {
        arr2[i] = arr[i - 1];
    }
}