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
      temp = data[left];
      data[left] = data[right];
      data[right] = temp;
    }
  }

  quickSort(data, start, right - 1);
  quickSort(data, right + 1, end);
}

int main(void) {
  int arr[1000001];
  int size;

  cin >> size;

  for (int i = 0; i < size; i++) {
    cin >> arr[i];
  }

  quickSort(arr, 0, size - 1);

  for (int i = 0; i < size; i++) {
    cout << arr[i] << endl;
  }
}