#include <iostream>

using namespace std;

void quickSort(int *data, int start, int end) {
  if (start >= end) {
    return;
  }

  int pivot = start;
  int left = start + 1;
  int right = end;
  int temp;

  while (left <= right) {
    while (data[left] <= data[pivot]) {
      left++;
    }
    while (data[right] >= data[pivot] && right > start) {
      right--;
    }
    if (left > right) {
      temp = data[right];
      data[right] = data[pivot];
      data[pivot] = temp;
    } else {
      temp = data[right];
      data[right] = data[left];
      data[left] = temp;
    }
  }

  quickSort(data, start, right - 1);
  quickSort(data, right + 1, end);
}

int main(void) {
  int arr[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};

  quickSort(arr, 0, sizeof(arr) / sizeof(int) - 1);

  for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}