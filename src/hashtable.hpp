#ifndef HASHTABLE_H_
#define HASHTABLE_H_
#include "graphics.hpp"
#include <bits/stdc++.h>
using namespace std;
class HashNode {
public:
  int value;
  std::string key;

  HashNode(std::string key, int value);
};

class HashMap {
  HashNode **arr;
  Cell *cells[10][3];
  int capacity;
  int size;

public:
  HashMap();
  unsigned int hashCode(std::string key);
  void insertNode(Cell *cells[10][3], std::string key, int value);
  int deleteNode(Cell *cells[10][3], std::string key);
  int get(Cell *cells[10][3], std::string key);
  int sizeofMap();
  bool isEmpty();
  void display();
  void init(Cell *cells[10][3]);
  string getKey(int index);
  int getValue(int index);
};
#endif // HASHTABLE_H_
