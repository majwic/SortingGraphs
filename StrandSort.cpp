#include "StrandSort.h"

#include <vector>
#include <ncurses.h>
#include <unistd.h>

void StrandSort::sort() {
  std::vector<int> nVect;
  vect.swap(nVect);
  strandSort(nVect);
}

void StrandSort::printSort() {
  std::vector<int> nVect;
  vect.swap(nVect);
  printStrandSort(nVect);
}

void StrandSort::strandSort(std::vector<int> &nVect) {
  if (nVect.empty()) {
    return;
  }

  std::vector<int> subVect;
  subVect.push_back(nVect.front());
  nVect.erase(nVect.begin());


  for (int i = 0; i < nVect.size(); ++i) {
    if (nVect[i] > subVect.back()) {
      subVect.push_back(nVect[i]);
      nVect.erase(nVect.begin() + i);
      i--;
    } 
  }
    
    merge(subVect);
    strandSort(nVect);
}

void StrandSort::merge(std::vector<int> &subVect) {
  std::vector<int> temp;

  int i = 0, j = 0;
  while (vect.size() > i && subVect.size() > j) {
    if (vect[i] > subVect[j]) {
      temp.push_back(subVect[j]);
      j++;
    } else {
      temp.push_back(vect[i]);
      i++;
    }
  }

  while (vect.size() > i) {
    temp.push_back(vect[i]);
    i++;
  }

  while (subVect.size() > j) {
    temp.push_back(subVect[j]);
    j++;
  }

  vect = temp;
}

void StrandSort::printStrandSort(std::vector<int> &nVect) {
  if (nVect.empty()) {
    return;
  }

  std::vector<int> subVect;
  subVect.push_back(nVect.front());
  nVect.erase(nVect.begin());
  clearPrintBar(subVect.size() - 1, subVect.back());

  for (int i = 0; i < nVect.size(); ++i) {
    if (nVect[i] > subVect.back()) {
      subVect.push_back(nVect[i]);
      refresh();
      usleep(10000);
      clearPrintBar(subVect.size() - 1, subVect.back());
      nVect.erase(nVect.begin() + i);
      i--;
    } 
  }

  for (int i = 0; i < nVect.size(); ++i) {
    refresh();
    usleep(10000);
    clearPrintBar(subVect.size() + i, nVect[i]);
  }
    
  printMerge(subVect);
  printStrandSort(nVect);
}

void StrandSort::printMerge(std::vector<int> &subVect) {
  std::vector<int> temp;

  int i = 0, j = 0;
  while (vect.size() > i && subVect.size() > j) {
    if (vect[i] > subVect[j]) {
      temp.push_back(subVect[j]);
      j++;
    } else {
      temp.push_back(vect[i]);
      i++;
    }
  }

  while (vect.size() > i) {
    temp.push_back(vect[i]);
    i++;
  }

  while (subVect.size() > j) {
    temp.push_back(subVect[j]);
    j++;
  }

  vect = temp;

  for (i = 0; i < vect.size(); ++i) {
    refresh();
    usleep(10000);
    clearPrintBar(i + (LINES - vect.size()), vect[i]);
  }
}
