#include "hashtable.hpp"
#include <fmt/color.h>
HashNode::HashNode(string key, int value) {
  this->value = value;
  this->key = key;
}
HashMap::HashMap() {
  capacity = 10;
  size = 0;
  arr = new HashNode *[capacity];
  for (int i = 0; i < capacity; i++)
    arr[i] = NULL;
}
unsigned int HashMap::hashCode(string key) { return key.length() % capacity; }

void HashMap::insertNode(Cell *cells[10][3], string key, int value) {
  HashNode *temp = new HashNode(key, value);
  int hashIndex = hashCode(key);
  for (int i = 0; i < capacity; i++) {
    this->init(cells);
    int next = (i + hashIndex) % capacity;
    cells[next][0]->hightlighted(true);
    cells[next][1]->hightlighted(true);
    cells[next][2]->hightlighted(true);
    sleep(1);
    if (arr[next] == NULL || arr[next]->key == key) {
      arr[next] = temp;
      fmt::print(fg(fmt::color::pale_green) | fmt::emphasis::bold,
                 "[INFO] {} is inserted at index {} for key {}\n", value, next,
                 key);
      this->init(cells);
      cells[next][0]->hightlighted(false);
      cells[next][1]->hightlighted(false);
      cells[next][2]->hightlighted(false);
      return;
    }
    cells[next][0]->hightlighted(false);
    cells[next][1]->hightlighted(false);
    cells[next][2]->hightlighted(false);
  }
}

int HashMap::deleteNode(Cell *cells[10][3], string key) {
  int hashIndex = hashCode(key);
  int count = 0;
  for (int i = 0; i < capacity; i++) {
    int next = (i + hashIndex) % capacity;
    cells[next][0]->hightlighted(true);
    cells[next][1]->hightlighted(true);
    cells[next][2]->hightlighted(true);
    sleep(1);
    if (arr[next] != NULL && arr[next]->key == key) {
      int temp = arr[next]->value;
      arr[next] = NULL;
      fmt::print(fg(fmt::color::pale_green) | fmt::emphasis::bold,
                 "[INFO] {} is deleted from index {} for key {}\n", temp, next,
                 key);
      this->init(cells);
      cells[next][0]->hightlighted(false);
      cells[next][1]->hightlighted(false);
      cells[next][2]->hightlighted(false);
      return temp;
    }
    cells[next][0]->hightlighted(false);
    cells[next][1]->hightlighted(false);
    cells[next][2]->hightlighted(false);
  }
  fmt::print(fg(fmt::color::red) | fmt::emphasis::bold,
             "[INFO] {} does not exist in HashTable \n", key);
  return (int)NULL;
}

int HashMap::get(Cell *cells[10][3], string key) {
  int hashIndex = hashCode(key);
  for (int i = 0; i < capacity; i++) {
    int next = (i + hashIndex) % capacity;
    if (arr[next] != NULL && arr[next]->key == key) {
      return arr[next]->value;
    }
  }
  return (int)NULL;
}

int HashMap::sizeofMap() { return size; }

bool HashMap::isEmpty() { return size == 0; }

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
void HashMap::init(Cell *cells[10][3]) {
  for (int i = 0; i < 10; i++) {
    cells[i][0]->clearText();
    cells[i][1]->clearText();
    cells[i][2]->clearText();
    if (this->arr[i] == NULL) {
      continue;
    }
    cells[i][0]->setText(to_string(i));
    cells[i][1]->setText(this->arr[i]->key);
    cells[i][2]->setText(to_string(this->arr[i]->value));
  }
}
