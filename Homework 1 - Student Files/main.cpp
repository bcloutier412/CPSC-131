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
  std::cout << std::endl;

  // Vector of grocery items
  std::vector<std::unique_ptr<GroceryItem>> groceryItems{};

  // Populate groceryItems vector
  while( !std::cin.eof() )
  {
    std::unique_ptr<GroceryItem> newItem = std::make_unique<GroceryItem>();

    std::cout << "Enter UPC, Product Brand, Product Name, and Price\n";
    std::cout << "Item added to shopping cart: ";

    std::cin >> *newItem;
    std::cout << "\n";

    if( std::cin.good() ) {
      groceryItems.push_back( std::move( newItem ) );
    }
  }


  std::cout << "\n";
  // Print out the groceryItems vector in reverse
  std::cout << "Here is an itemized list of the items in your shopping cart:\n";

  for( std::vector<std::unique_ptr<GroceryItem>>::reverse_iterator it = groceryItems.rbegin(); it != groceryItems.rend(); ++it)
  {
    std::cout << *(*it) << std::endl;
  }

  return 0;
}
