#include <iostream>
#include "sorted_linked_list.h"

void printInstructions() {
  std::cout << "To add an element to the list, enter \"1\" followed by the element\n";
  std::cout << "To remove an element from the list, enter \"2\" followed by the element\n";
  std::cout << "To print the list, enter \"3\"\n";
  std::cout << "To exit, enter \"0\"\n";
}

int main(int argc, char** argv) {
  std::cout << "SORTED LINKED LIST OF INTEGERS\n";

  SortedLinkedList A;
  int input;
  
  printInstructions();

  while (true) {
    std::cout << ">> ";
    std::cin >> input;

    switch (input) {
      case 1: 
        std::cin >> input;
        A.insert(input);
        std::cout << "Inserted " << input << "\n";
        break;

      case 2: 
        std::cin >> input;
        if (A.remove(input)) {
          std::cout << "Removed " << input << "\n";
        } else {
          std::cout << input << " not found\n";
        }
        break;

      case 3: 
        A.print();
        break;

      case 0: 
        std::cout << "Exit\n";
        return 0;

      default: 
        std::cout << "Wrong input, try again:\n";
        printInstructions();
    }

  }

  return 0;
}