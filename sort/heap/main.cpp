#include <iostream>

using namespace std;

int main(void) {
    int heap[9] = {7, 6, 5, 8, 3, 5, 9, 1, 6};
    int number = 9, temp;

    for (int i = 1; i < number; i++) {
        int c = i;
        do {
            int root = (c - 1) / 2;
            if (heap[root] < heap[c]) {
                temp = heap[root];
                heap[root] = heap[c];
                heap[c] = temp;
            }
            c = root;
        } while (c != 0);
    }

    for (int i = number - 1; i >= 0; i--) {
        temp = heap[0];
        heap[0] = heap[i];
        heap[i] = temp;
        int root = 0;
        int c;
        do {
            c = root * 2 + 1;
            if (heap[c] < heap[c + 1] && c < i - 1) {
                c++;
            }

            if (heap[root] < heap[c] && c < i) {
                temp = heap[root];
                heap[root] = heap[c];
                heap[c] = temp;
            }
            root = c;
        } while (c < i);
    }

    for (int i = 0; i < number; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}