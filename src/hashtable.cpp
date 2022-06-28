#include "hashtable.hpp"

HashNode::HashNode(string key, int value) {
  this->value = value;
  this->key = key;
}
HashMap::HashMap() {
  // Initial capacity of hash array
  capacity = 10;
  size = 0;
  arr = new HashNode *[capacity];
  // Initialise all elements of array as NULL
  for (int i = 0; i < capacity; i++)
    arr[i] = NULL;
  // dummy node with value and key -1
  dummy = new HashNode("-1", -1);
}
// This implements hash function to find index
// for a key
//
unsigned int HashMap::hashCode(string key) { return key.length() % capacity; }

// Function to add key value pair
void HashMap::insertNode(string key, int value) {
  HashNode *temp = new HashNode(key, value);
  // Apply hash function to find index for given key
  int hashIndex = hashCode(key);
  // find next free space
  for (int i = 0; i < capacity; i++) {
    int next = (i + hashIndex) % capacity;
    // cout << next << " = " << i << "+" << hashIndex << "%" << capacity <<
    // endl;
    if (arr[next] == NULL) {
      arr[next] = temp;
      // cout << value << " is inserted at " << next << endl;
      return;
    }
  }
}

// Function to delete a key value pair
int HashMap::deleteNode(string key) {
  // Apply hash function
  // to find index for given key
  int hashIndex = hashCode(key);
  for (int i = 0; i < capacity; i++) {
    int next = (i + hashIndex) % capacity;
    if (arr[next] != NULL && arr[next]->key == key) {
      int temp = arr[next]->value;
      arr[next] = NULL;
      return temp;
    }
  }
  // If not found return null
  return (int)NULL;
}

// Function to search the value for a given key
int HashMap::get(string key) {
  // Apply hash function
  // to find index for given key
  int hashIndex = hashCode(key);
  for (int i = 0; i < capacity; i++) {
    int next = (i + hashIndex) % capacity;
    if (arr[next] != NULL && arr[next]->key == key) {
      return arr[next]->value;
    }
  }
  // If not found return null
  return (int)NULL;
}

// Return current size
int HashMap::sizeofMap() { return size; }

// Return true if size is 0
bool HashMap::isEmpty() { return size == 0; }

// Function to display the stored key value pairs
void HashMap::display() {
  for (int i = 0; i < capacity; i++) {
    if (arr[i] != NULL && arr[i]->key != "-1")
      cout << "key = " << arr[i]->key << " value = " << arr[i]->value << endl;
  }
};
string HashMap::getKey(int index) {
  if (arr[index] == NULL) {
    return "";
  }
  return arr[index]->key;
}
int HashMap::getValue(int index) {
  if (arr[index] == NULL) {
    return -1;
  }
  return arr[index]->value;
}
