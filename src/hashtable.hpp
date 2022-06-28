#ifndef HASHTABLE_H_
#define HASHTABLE_H_
#include "graphics.hpp"
#include <bits/stdc++.h>
using namespace std;
class HashNode {
public:
  int value;
  std::string key;

  // Constructor of hashnode
  HashNode(std::string key, int value);
};

class HashMap {
  // hash element array
  HashNode **arr;
  int capacity;
  // current size
  int size;
  // dummy node
  HashNode *dummy;

public:
  HashMap();
  unsigned int hashCode(std::string key);
  // Function to add key value pair
  void insertNode(std::string key, int value);
  // Function to delete a key value pair
  int deleteNode(std::string key);
  // Function to search the value for a given key
  int get(std::string key);
  // Return current size
  int sizeofMap();
  // Return true if size is 0
  bool isEmpty();
  // Function to display the stored key value pairs
  void display();
  string getKey(int index);
  int getValue(int index);
};
#endif // HASHTABLE_H_
