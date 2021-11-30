#include <iostream>
using namespace std;

class Node {
  public:
  string key; dappf::meta::handler* value;
  Node *prev, *next;
  int frequency;
  Node(string k, dappf::meta::handler* v){
    key = k;
    value = v;
    frequency = 0;
    prev = NULL;
    next = NULL;
  }
};

class DoublyLinkedList {
  public:
  Node *head, *tail;

  DoublyLinkedList(){
    head = NULL;
    tail = NULL;
  }

  bool isEmpty() {
    return tail == NULL;
  }

  Node* insert(string key, dappf::meta::handler* value) {
      Node *element = new Node(key, value);
      if(!head && !tail) {
          head = tail = element;
      }
      else {
          element->next = head;
          head->prev = element;
          head = element;
      }
      return element;
  }

  void move_to_head(Node *element) {
      if(element == head) {
          return;
      }
      else if(element == tail) {
          tail = tail->prev;
          tail->next = NULL;
      }
      else {
          element->prev->next = element->next;
          element->next->prev = element->prev;
      }

      element->next = head;
      element->prev = NULL;
      head->prev = element;
      head = element;
  }

  void remove_tail() {
      if(isEmpty()) {
          return;
      }
      else if(head == tail) {
          delete tail;
          head = tail = NULL;
      }
      else {
          Node *temp = tail;
          tail = tail->prev;
          tail->next = NULL;
          delete temp;
      }
  }

  Node* get_tail() {
      return tail;
  }

  Node* get_head() {
      return head;
  }

};