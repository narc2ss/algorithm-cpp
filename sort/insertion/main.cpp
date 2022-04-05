#include <iostream>

using namespace std;

int main(void) {
  int arr[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};
  int temp, j;

  for (int i = 0; i < sizeof(arr) / sizeof(int) - 1; i++) {
    j = i;
    while (arr[j] > arr[j + 1]) {
      temp = arr[j];
      arr[j] = arr[j + 1];
      arr[j + 1] = temp;
      j--;
    }
  }

  for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}