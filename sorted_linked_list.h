#ifndef SORTED_LINKED_LIST__H__
#define SORTED_LINKED_LIST__H__


class SortedLinkedList {
private:
  struct Node {
    int data;
    Node* next;
    
    Node(int x)
      : data(x)
      , next(nullptr) {}
  };

  Node* root;

public:
  void insert(int value);
  bool remove(int value);
  void print();

  SortedLinkedList();
  ~SortedLinkedList();

};


#endif // SORTED_LINKED_LIST__H__