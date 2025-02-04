#include <iostream>
#include <stdio.h>
using namespace std;

int binary_search(int array[], int min, int max, int value) {

  while (min <= max) {

    int mid = min + (max - min) / 2;
    if (array[mid] == value) {
      return mid;
    }
    else if (array[mid] < value) {
      min = mid + 1;
    }
    else {
      max = mid - 1;
    }
  }
  return -1;
}

int main () {
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << binary_search(array, 0, 11, 10) << endl;
}