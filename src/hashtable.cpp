#include "hashtable.hpp"

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
  cells[hashIndex][0]->hightlighted(true);
  cells[hashIndex][1]->hightlighted(true);
  cells[hashIndex][2]->hightlighted(true);
  for (int i = 0; i < capacity; i++) {
    cells[i][0]->hightlighted(true);
    cells[i][1]->hightlighted(true);
    cells[i][2]->hightlighted(true);
    sleep(3);
    int next = (i + hashIndex) % capacity;
    if (arr[next] == NULL) {
      arr[next] = temp;
      cout << value << " is inserted at " << next << endl;
      this->init(cells);
      return;
    }
    cells[i][0]->hightlighted(false);
    cells[i][1]->hightlighted(false);
    cells[i][2]->hightlighted(false);
  }
}

int HashMap::deleteNode(Cell *cells[10][3], string key) {
  int hashIndex = hashCode(key);
  for (int i = 0; i < capacity; i++) {
    int next = (i + hashIndex) % capacity;
    if (arr[next] != NULL && arr[next]->key == key) {
      int temp = arr[next]->value;
      arr[next] = NULL;
      this->init(cells);
      return temp;
    }
  }
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
