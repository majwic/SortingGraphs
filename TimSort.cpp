#include "TimSort.h"

#include <ncurses.h>
#include <unistd.h>
#include <bits/stdc++.h>

void TimSort::sort() {
  int mid, right;
  for (int i = 0; i < vect.size(); i += RUN) {
    insertionSort(i, std::min((i + RUN - 1), ((int) vect.size() - 1)));
  }

  for (int size = RUN; size < vect.size(); size = 2 * size) {
    for (int left = 0; left < vect.size(); left += 2 * size) {
      mid = left + size - 1;
      right = std::min((left + 2 * size - 1), ((int) vect.size() - 1));

      if (mid < right) {
	merge(left, mid, right);
      }
    }
  }
}

void TimSort::printSort() {
  printGraph();
  int mid, right;
  for (int i = 0; i < vect.size(); i += RUN) {
    printInsertionSort(i, std::min((i + RUN - 1), ((int) vect.size() - 1)));
  }

  for (int size = RUN; size < vect.size(); size = 2 * size) {
    for (int left = 0; left < vect.size(); left += 2 * size) {
      mid = left + size - 1;
      right = std::min((left + 2 * size - 1), ((int) vect.size() - 1));

      if (mid < right) {
	printMerge(left, mid, right);
      }
    }
  }
}

void TimSort::insertionSort(const int left, const int right) {
  int temp, j;
  for (int i = left + 1; i <= right; ++i) {
    temp = vect[i];
    j = i - 1;
    
    while (j >= left && vect[j] > temp) {
      vect[j + 1] = vect[j];
      j--;
    }
    vect[j + 1] = temp;
  }
}

void TimSort::printInsertionSort(const int left, const int right) {
  int temp, j;
  for (int i = left + 1; i <= right; ++i) {
    temp = vect[i];
    j = i - 1;
    
    while (j >= left && vect[j] > temp) {
      vect[j + 1] = vect[j];
      clearPrintBar(j + 1, vect[j + 1]);
      refresh();
      usleep(10000);
      j--;
    }
    vect[j + 1] = temp;
    clearPrintBar(j + 1, vect[j + 1]);
    refresh();
    usleep(10000);
  }
}

void TimSort::merge(const int l, const int m, const int r) {
  int len1 = m - l + 1, len2 = r - m;
  int left[len1], right[len2];

  for (int i = 0; i < len1; ++i) {
    left[i] = vect[l + i];
  }

  for (int i = 0; i < len2; ++i) {
    right[i] = vect[m + 1 + i];
  }

  int i = 0, j = 0, k = l;

  while (i < len1 && j < len2) {
    if (left[i] <= right[j]) {
      vect[k] = left[i];
      i++;
    } else {
      vect[k] = right[j];
      j++;
    }
    k++;
  }

  while (i < len1) {
    vect[k] = left[i];
    k++;
    i++;
  }

  while (j < len2) {
    vect[k] = right[j];
    k++;
    j++;
  }
}

void TimSort::printMerge(const int l, const int m, const int r) {
  int len1 = m - l + 1, len2 = r - m;
  int left[len1], right[len2];

  for (int i = 0; i < len1; ++i) {
    left[i] = vect[l + i];
  }

  for (int i = 0; i < len2; ++i) {
    right[i] = vect[m + 1 + i];
  }

  int i = 0, j = 0, k = l;

  while (i < len1 && j < len2) {
    if (left[i] <= right[j]) {
      vect[k] = left[i];
      clearPrintBar(k, vect[k]);
      refresh();
      usleep(10000);
      i++;
    } else {
      vect[k] = right[j];
      clearPrintBar(k, vect[k]);
      refresh();
      usleep(10000);
      j++;
    }
    k++;
  }

  while (i < len1) {
    vect[k] = left[i];
    clearPrintBar(k, vect[k]);
    refresh();
    usleep(10000);
    k++;
    i++;
  }

  while (j < len2) {
    vect[k] = right[j];
    clearPrintBar(k, vect[k]);
    refresh();
    usleep(10000);
    k++;
    j++;
  }
}
