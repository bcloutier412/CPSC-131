#include <iostream>
#include <vector>
#include <memory>
#include <utility>

#include "GroceryItem.hpp"

int main() {
  std::cout << "Welcome to Kroger.  Place grocery items into your shopping cart by entering each item's information.\n"
            << "   enclose string entries in quotes, separate fields with comas\n"
            << "   for example:  \" 00016000306707 \", \" Betty Crocker \", \" Betty Crocker Double Chocolate Chunk Cookie Mix \", 17.19\n"
            << "   Enter CTL-Z (Windows) or CTL-D (Linux) to quit\n";
  std::cout << '\n';

  // Vector of grocery items
  std::vector<std::unique_ptr<GroceryItem>> groceryItems{};

  // Populate groceryItems vector
  bool continueLoop = true;
  while( continueLoop )
  {
    std::unique_ptr<GroceryItem> newItem = std::make_unique<GroceryItem>();

    std::cout << "Enter UPC, Product Brand, Product Name, and Price\n";
    std::cout << "Item added to shopping cart: ";

    if ( !(std::cin >> *newItem)) {
      continueLoop = false;
    }
    std::cout << '\n';

    if( std::cin.good() ) {
      groceryItems.push_back( std::move( newItem ) );
    }
  }


  std::cout << '\n';
  // Print out the groceryItems vector in reverse
  std::cout << "Here is an itemized list of the items in your shopping cart:\n";

  for( auto it = groceryItems.rbegin(); it != groceryItems.rend(); ++it)
  {
    std::cout << *(*it) << '\n';
  }

  return 0;
}
