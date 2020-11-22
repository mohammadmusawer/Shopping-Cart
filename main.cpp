/*** Mohammad Musawer -- Shopping Cart ***/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

#include "ItemToPurchase.h"
#include "ShoppingCart.h"

void printCustomerNameAndDate(ShoppingCart &cart)
{
  cout << "Customer name: " << cart.GetCustomerName() << endl;
  cout << "Today's date: " << cart.GetDate() << endl;
}

void printMenu()
{
  cout << endl << "MENU" << endl <<
         "a - Add item to cart" << endl <<
         "d - Remove item from cart" << endl <<
         "c - Change item quantity" << endl <<
         "i - Output items' descriptions" << endl <<
         "o - Output shopping cart" << endl <<
         "q - Quit" << endl << endl;
}

void getUserInput(char &userInput)
{
  vector<char> possibleInputs = {'a', 'd', 'c', 'i', 'o', 'q'};
  
  do
  {
    cout << "Choose an option: ";
    cin >> userInput;
    cin.ignore();
  } while(find(possibleInputs.begin(), possibleInputs.end(), userInput) == possibleInputs.end());
}

void addItemToCart(ShoppingCart &cart)
{
  string name, description;
  int price, quantity;
  
  cout << "ADD ITEM TO CART" << endl;
  cout << "Enter the item name:" << endl;
  getline(cin, name);
  cout << "Enter the item description: " << endl;
  getline(cin, description);
  cout << "Enter the item price:" << endl;
  cin >> price;
  cin.ignore();
  cout << "Enter the item quantity:" << endl;
  cin >> quantity;
  cin.ignore();
  ItemToPurchase newItem(name, description, price, quantity);
  cart.AddItem(newItem);
}

void removeItemFromCart(ShoppingCart &cart)
{
  string name;
  
  cout << "REMOVE ITEM FROM CART" << endl;
  cout << "Enter name of item to remove:" << endl;
  getline(cin, name);
  cart.RemoveItem(name);
}

void changeItemQuantity(ShoppingCart &cart)
{
  string name;
  int quantity;
  
  cout << "CHANGE ITEM QUANTITY" << endl;
  cout << "Enter the item name:" << endl;
  getline(cin, name);
  cout << "Enter the new quantity:" << endl;
  cin >> quantity;
  cart.ChangeQuantity(name, quantity);
}

void outputItemDescriptions(ShoppingCart &cart)
{
  cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
  cout << cart.GetCustomerName() << "\'s Shopping Cart - " << cart.GetDate();
  cout << endl << endl << "Item Descriptions" << endl;
  cart.PrintDescriptions();
}

void outputShoppingCart(ShoppingCart &cart)
{
  cout << "OUTPUT SHOPPING CART" << endl;
  cout << cart.GetCustomerName() << "\'s Shopping Cart - " << cart.GetDate() << endl;
  cout << "Number of items: " << cart.GetNumItemsInCart() << endl << endl;
  cart.PrintTotal();
}

int main()
{
  string name, date;
  char userInput;
  
  cout << "Enter customer's name: " << endl;
  getline(cin, name);
  cout << "Enter today's date:" << endl;
  getline(cin, date);
  
  ShoppingCart cart(name, date);
  
  printCustomerNameAndDate(cart);
  do
  {
  printMenu();
  getUserInput(userInput);
  
  if(userInput == 'a')
    addItemToCart(cart);
    
  else if(userInput == 'd')
    removeItemFromCart(cart);
    
  else if(userInput == 'c')
    changeItemQuantity(cart);
    
  else if(userInput == 'i')
    outputItemDescriptions(cart);
    
  else if(userInput == 'o')
    outputShoppingCart(cart);
    
  } while(userInput != 'q');

  return 0;
}
