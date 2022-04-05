#include <iostream>

using namespace std;

int sorted[8];

void merge(int *data, int start, int middle, int end) {
  int left = start;
  int right = middle + 1;
  int key = start;

  while (left <= middle && right <= end) {
    if (data[left] <= data[right]) {
      sorted[key] = data[left];
      left++;
    } else {
      sorted[key] = data[right];
      right++;
    }
    key++;
  }

  if (left > middle) {
    for (int i = right; i <= end; i++) {
      sorted[key] = data[i];
      key++;
    }
  } else {
    for (int i = left; i <= middle; i++) {
      sorted[key] = data[i];
      key++;
    }
  }

  for (int i = 0; i <= end; i++) {
    data[i] = sorted[i];
  }
}

void mergeSort(int *data, int start, int end) {
  if (start < end) {
    int middle = (start + end) / 2;
    mergeSort(data, start, middle);
    mergeSort(data, middle + 1, end);
    merge(data, start, middle, end);
  }
}

int main(void) {
  int arr[8] = {7, 1, 8, 9, 5, 3, 2, 4};
  mergeSort(arr, 0, 8 - 1);
  for (int i = 0; i < 8; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}