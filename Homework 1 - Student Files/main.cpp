#include <iostream>

#include "GroceryItem.hpp"

int main() {
  GroceryItem newItem;
  std::cin >> newItem;

  std::cout << newItem;
  // while( !std::cin.eof() )
  // {
  //   std::cin >> newNum;
  //   index++;
  // }
  return 0;
}
