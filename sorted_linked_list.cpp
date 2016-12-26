#include <iostream>
#include "sorted_linked_list.h"
 

SortedLinkedList::SortedLinkedList()
  : root(nullptr) {}


SortedLinkedList::~SortedLinkedList() {
  SortedLinkedList::Node* current_node = root;
  SortedLinkedList::Node* node_to_delete = nullptr;
  while (current_node != nullptr) {
    node_to_delete = current_node;
    current_node = current_node->next;
    delete node_to_delete;
  }
}



void SortedLinkedList::insert(int value) {
  SortedLinkedList::Node* current_node = root;
  SortedLinkedList::Node* prev_node = nullptr;

    while (current_node != nullptr) {  // until the end of list

      if (current_node->data >= value) {  // if place to insert is found
        break;  // exit the loop 

      } else {  
        // move to the next element in the list
        prev_node = current_node;
        current_node = current_node->next;
      }
    } 

    // insert new element:
    SortedLinkedList::Node* inserted = new SortedLinkedList::Node(value);
    
    if (prev_node != nullptr) {
      prev_node->next = inserted;
    } else {
      root = inserted;  // inserted element is the root
    }

    if (current_node != nullptr) {
      inserted->next = current_node;
    }

}



bool SortedLinkedList::remove(int value) {
  SortedLinkedList::Node* current_node = root;
  SortedLinkedList::Node* prev_node = nullptr;
  
  while (current_node != nullptr) {  // until the end of list
    
    if (current_node->data == value) {   // if value to remove is found in the list 
      
      if (prev_node == nullptr) {  // if current node to be removed is the root

        if (current_node->next != nullptr) {  
          root = current_node->next;
          delete current_node;

        } else {  // if root is the only element
          delete root;
          root = nullptr;
        } 


      } else {

        // delete link to current element:
        if (current_node->next != nullptr) {  
          prev_node->next = current_node->next; 
        } else {
          prev_node->next = nullptr;  // if no further elements 
        }

        delete current_node;  // delete current element itself

      }
      
      return true;
    
    } else {  // move to the next element in the list
      prev_node = current_node;
      current_node = current_node->next;
    }

  }

  return false;
}



void SortedLinkedList::print() {
  SortedLinkedList::Node* current_node = root;
  while (current_node != nullptr) {
    std::cout << current_node->data << " ";
    current_node = current_node->next;
  }
  std::cout << "\n";
}