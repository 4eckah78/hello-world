#pragma once

#include "arr.h"
#include "AVLtree.h"
#include <iostream>

struct HuffNode {
  unsigned val;
  HuffNode *left, *right;
};

template<typename T1, typename T2> struct para {
  T1 v1;
  T2 v2;
};


bool elemIsIn(int elem, int* arr, size_t n) {
  for (int i = 0; i < n; ++i)
    if (elem == arr[i])
      return true;
  return false;
}/*
Array <para<unsigned char, size_t> > calcStats(std::istream& ist) {
  for (int i = 0; i < k; ++i)
    if (!elemIsIn(M[i], C, count))
      C[count++] = M[i];
  Array <para<unsigned char, size_t> > res;

}

HuffNode* buildHuffTree(const Array< para<unsigned char, size_t> > &symbols_w_freq) {

}

AVLtree<unsigned char, Array<bool> >  tree2table(HuffNode*);*/