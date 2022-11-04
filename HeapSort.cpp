#include "HeapSort.h"

#include <ncurses.h>
#include <unistd.h>

void HeapSort::sort() {
  for (int i = vect.size() / 2 - 1; i >= 0; --i) {
    heapify(vect.size(), i);
  }

  for (int i = vect.size() - 1; i >= 0; --i) {
    swap(0, i);
    heapify(i, 0);
  }
}

void HeapSort::printSort() {
  for (int i = vect.size() / 2 - 1; i >= 0; --i) {
    printHeapify(vect.size(), i);
  }

  for (int i = vect.size() - 1; i >= 0; --i) {
    printSwap(0, i);
    printHeapify(i, 0);
  }
}

void HeapSort::heapify(const int n, const int i) {
  int largest = i;
  int left = i * 2 + 1;
  int right = i * 2 + 2;

  if (left < n && vect[left] > vect[largest]) {
    largest = left;
  }

  if (right < n && vect[right] > vect[largest]) {
    largest = right;
  }

  if (largest != i) {
    swap(i, largest);
    heapify(n, largest);
  }
}

void HeapSort::printHeapify(const int n, const int i) {
  int largest = i;
  int left = i * 2 + 1;
  int right = i * 2 + 2;

  if (left < n && vect[left] > vect[largest]) {
    largest = left;
  }

  if (right < n && vect[right] > vect[largest]) {
    largest = right;
  }

  if (largest != i) {
    printSwap(i, largest);
    printHeapify(n, largest);
  }
}

void HeapSort::swap(const int index1, const int index2) {
  int temp = vect[index1];
  vect[index1] = vect[index2];
  vect[index2] = temp;
}

void HeapSort::printSwap(const int index1, const int index2) {
  refresh();
  usleep(10000);
  int temp = vect[index1];
  vect[index1] = vect[index2];
  vect[index2] = temp;
  clearPrintBar(index1, vect[index1]);
  clearPrintBar(index2, vect[index2]);
}
