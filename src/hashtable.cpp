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

void HashMap::insertNode(Cell *cells[10][4], string key, int value) {
  HashNode *temp = new HashNode(key, value);
  int hashIndex = hashCode(key);
  int lastIndex;
  for (int i = 0; i < capacity; i++) {
    this->init(cells);
    int next = (i + hashIndex) % capacity;
    lastIndex = next;
    cells[next][0]->hightlighted(true);
    cells[next][1]->hightlighted(true);
    cells[next][2]->hightlighted(true);
    cells[next][3]->setText("<[LOG] isNull || KeyMatch");
    sleep(SIM_INTERVAL);
    cells[next][3]->setText("<[LOG] isNull = ?");
    sleep(SIM_INTERVAL);
    if (arr[next] == NULL) {
      cells[next][3]->setText("<[LOG] isNull = true");
      sleep(SIM_INTERVAL);
      arr[next] = temp;
      fmt::print(fg(fmt::color::pale_green) | fmt::emphasis::bold,
                 "[INFO] {} is inserted at index {} for key {}\n", value, next,
                 key);
      this->init(cells);
      cells[next][3]->setText("<[INFO] Inserted");
      sleep(SIM_INTERVAL);

      cells[next][0]->hightlighted(false);
      cells[next][1]->hightlighted(false);
      cells[next][2]->hightlighted(false);
      return;
    }
    cells[next][3]->setText("<[LOG] isNull = false");
    sleep(SIM_INTERVAL);
    cells[next][3]->setText("<[LOG] isKeyMatched = ?");
    sleep(SIM_INTERVAL);
    if (arr[next]->key == key) {
      cells[next][3]->setText("<[LOG] isKeyMatched = true");
      sleep(SIM_INTERVAL);
      arr[next] = temp;
      cells[next][3]->setText("<[INFO] Inserted");
      sleep(SIM_INTERVAL);
      fmt::print(fg(fmt::color::pale_green) | fmt::emphasis::bold,
                 "[INFO] {} is inserted at index {} for key {}\n", value, next,
                 key);
      this->init(cells);
      cells[next][0]->hightlighted(false);
      cells[next][1]->hightlighted(false);
      cells[next][2]->hightlighted(false);
      return;
    }
    cells[next][3]->setText("<[LOG] isKeyMatched = false");
    sleep(SIM_INTERVAL);
    cells[next][0]->hightlighted(false);
    cells[next][1]->hightlighted(false);
    cells[next][2]->hightlighted(false);
  }
  cells[lastIndex][3]->setText("<[INFO] Table Full");
  fmt::print(fg(fmt::color::red) | fmt::emphasis::bold,
             "[INFO] Table Is Full, value cannot be inserted.");
}

int HashMap::deleteNode(Cell *cells[10][4], string key) {
  int hashIndex = hashCode(key);
  int lastIndex;
  for (int i = 0; i < capacity; i++) {
    this->init(cells);
    int next = (i + hashIndex) % capacity;
    lastIndex = next;
    cells[next][0]->hightlighted(true);
    cells[next][1]->hightlighted(true);
    cells[next][2]->hightlighted(true);
    cells[next][3]->setText("<[LOG] isNotNull && KeyMatch");
    sleep(SIM_INTERVAL);
    cells[next][3]->setText("<[LOG] isNotNull = ?");
    sleep(SIM_INTERVAL);
    if (arr[next] != NULL) {
      cells[next][3]->setText("<[LOG] isNotNull = true");
      sleep(SIM_INTERVAL);

      cells[next][3]->setText("<[LOG] isKeyMatched = ?");
      sleep(SIM_INTERVAL);
      this->init(cells);
      if (arr[next]->key == key) {
        cells[next][3]->setText("<[LOG] isKeyMatched = true");
        sleep(SIM_INTERVAL);
        int temp = arr[next]->value;
        arr[next] = NULL;
        fmt::print(fg(fmt::color::pale_green) | fmt::emphasis::bold,
                   "[INFO] {} is deleted from index {} for key {}\n", temp,
                   next, key);
        this->init(cells);
        cells[next][3]->setText("<[INFO] Deleted");
        sleep(SIM_INTERVAL);
        cells[next][0]->hightlighted(false);
        cells[next][1]->hightlighted(false);
        cells[next][2]->hightlighted(false);
        return temp;
      }
      cells[next][3]->setText("<[LOG] isKeyMatched = false");
      sleep(SIM_INTERVAL);
    } else {
      cells[next][3]->setText("<[LOG] isNotNull = false");
      sleep(SIM_INTERVAL);
    }
    cells[next][0]->hightlighted(false);
    cells[next][1]->hightlighted(false);
    cells[next][2]->hightlighted(false);
  }
  cells[lastIndex][3]->setText("<[INFO] Key not found");
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
void HashMap::init(Cell *cells[10][4]) {
  for (int i = 0; i < 10; i++) {
    cells[i][0]->clearText();
    cells[i][1]->clearText();
    cells[i][2]->clearText();
    cells[i][3]->setText(" ");
    if (this->arr[i] == NULL) {
      continue;
    }
    cells[i][0]->setText(to_string(i));
    cells[i][1]->setText(this->arr[i]->key);
    cells[i][2]->setText(to_string(this->arr[i]->value));
  }
}
