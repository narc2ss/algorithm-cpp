#include <iostream>

using namespace std;

int main(void) {
  int arr[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};
  int min, index, temp;

  for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
    min = 99999;
    for (int j = i; j < sizeof(arr) / sizeof(int); j++) {
      if (min > arr[j]) {
        min = arr[j];
        index = j;
      }
    }
    temp = arr[i];
    arr[i] = arr[index];
    arr[index] = temp;
  }

  for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}