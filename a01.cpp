/******************************************************************************
# Author:            Ari P.
# Assignment:        Assignment 1
# Date:              9/25/2025
# Description:       This program will calculate the total cost of a restaurant
                     meal, including the tip and any applicable discount.
# Input:             option (integer), orderMore (char), name (string), cost
                     (double), tip (double)
# Output:            total (double), discount (double)
# Sources:           Assignment 1 specifications, zyBooks reference
#*****************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

// Declare and initialize global constant variables
const double DISCOUNT_35 = 0.05;
const double DISCOUNT_50 = 0.10;

// Declare functions, all of which are defined after main()
void welcome();
void displayMenu();
void readOption(int &option);
void readInt(string prompt, int &num);
void readDouble(string prompt, double &num);
void placeOrder(double &total);
double tipDiscount(double &tip, double &discount, double total);
void goodbye();

int main() {
   // Declare and intitialize variables for input and output
   int option = 0;
   string name = "";
   double cost = 0.00;
   double tip = 0.00;
   double discount = 0.00;
   double total = 0.00;

   // Set floating point precision to 2 decimal places
   cout << fixed << setprecision(2);

   // Print welcome message
   welcome();
   cout << endl;
   
   // Allow user to continue making orders until they quit
   do {
      // Display menu
      displayMenu();
      cout << endl;
      // Prompt user for menu selection
      readOption(option);
      cout << endl;
      if (option == 1) {
         // Get contents of user's order
         placeOrder(total);
         cout << endl;
         // Display total
         cout << "Your total is: $" << total << endl << endl;

         // Update total to include tip
         total = tipDiscount(tip, discount, total);
         
         // Display final totals
         cout << "Your new total is: $" << total << endl;
         // Update total after discount
         if (discount > 0.00) {
            cout << "You earned a discount of $" << discount << "!" << endl;
            total -= discount;
         }
         else {
            cout << "You didn't spend enough to earn a discount." << endl;
         }
         cout << "Your final total is: $" << total << endl << endl;

         // Clear total for future orders
         total = 0.00;
      }
   } while (option != 2);

   // Print goodbye message
   goodbye();
   return 0;
}

// Name:    welcome()
// Desc:    This function prints a welcome message
// input:   None
// output:  None
// return:  void
void welcome() {
   cout << "Welcome to the Meal Calculator!" << endl;
}

// Name:    displayMenu()
// Desc:    This function displays a menu with two options (order and quit)
// input:   None
// output:  None
// return:  void
void displayMenu() {
   cout << "Would you like to order?" << endl;
   cout << "Please select an option:" << endl;
   cout << "   1. Place an order" << endl;
   cout << "   2. Quit";
}

// Name:    readOption()
// Desc:    This function uses readInt() to get the user's menu selection, and
//          allows only inputs of '1' and '2'.
// input:   option (int)
// output:  prompt (string)
// return:  void
void readOption(int &option) {
   readInt("Your choice: ", option);
   // Ensure option is either 1 or 2
   while (option != 1 && option != 2) {
      cin.clear();
      cin.ignore(100, '\n');
      cout << "Invalid answer! Please enter only 1 or 2!" << endl;
      readInt("Your choice: ", option);
   }
}

// Name:    readInt()
// Desc:    This function gets an integer from the user (used for menu options)
//          and performs basic data validation.
// input:   num (int)
// output:  prompt (string)
// return:  void
void readInt(string prompt, int &num) {
   cout << prompt;
   cin >> num;
   // Ensure num is a positive number
   while (cin.fail() || num < 0) {
      cin.clear();
      cin.ignore(100, '\n');
      cout << "Invalid answer! Please enter a positive integer!" << endl;
      cout << prompt;
      cin >> num;
   }
}

// Name:    readDouble()
// Desc:    This function gets a double from the user (used for item costs and
//          tip) and performs basic data validation.
// input:   num (double)
// output:  prompt (string)
// return:  void
void readDouble(string prompt, double &num) {
   cout << prompt;
   cin >> num;
   // Ensure num is a positive number
   while (cin.fail() || num < 0.00) {
      cin.clear();
      cin.ignore(100, '\n');
      cout << "Invalid answer! Please enter a positive number!" << endl;
      cout << prompt;
      cin >> num;
   }
}

// Name:    placeOrder()
// Desc:    This function gets restaurant items and their costs from the user
//          until they're done ordering.
// input:   name (string), cost (double), orderMore (char)
// output:  prompt (string)
// return:  void
void placeOrder(double &total) {
   // Declare and initialize variables for logic and input
   char orderMore = ' ';
   string name = "";
   double cost = 0.00;

   // Allow user to add multiple items to their order
   while (orderMore != 'N' && orderMore != 'n') {
      // Get name of item
      cout << "Enter item name: ";
      cin >> name;
      while (cin.fail()) {
         cin.clear();
         cin.ignore(100, '\n');
         cout << "Invalid answer! Please enter a name!" << endl;
         cout << "Enter item name: ";
         cin >> name;
      }
      cin.clear();
      cin.ignore(100, '\n');

      // Get cost of item and add it to total
      readDouble("Enter item cost (USD): ", cost);
      total += cost;

      // Check for further items
      cout << "Order more? (Y/N): ";
      cin >> orderMore;
      // Ensure orderMore is 'Y'/'y' or 'N'/'n'
      while (cin.fail() || (orderMore != 'Y' && orderMore != 'y' && orderMore != 'N' && orderMore != 'n')) {
         cin.clear();
         cin.ignore(100, '\n');
         cout << "Invalid answer! Please enter only 'Y'/'y' or 'N'/'n'!" << endl;
         cout << "Order more? (Y/N): ";
         cin >> orderMore;
      }
   }
}

// Name:    tipDiscount()
// Desc:    This function gets the user's tip, then calculates the total cost
//          and whether they're eligible for a discount.
// input:   tip (double)
// output:  prompt (string)
// return:  newTotal (double)
double tipDiscount(double &tip, double &discount, double total) {
   double newTotal = 0.00;
   // Get tip and add it to total
   readDouble("Enter tip amount (USD): ", tip);
   newTotal = total + tip;

   // Check for and apply discount
   if (newTotal >= 50.00) {
      discount = newTotal * DISCOUNT_50;
   }
   else if (newTotal >= 35.00) {
      discount = newTotal * DISCOUNT_35;
   }
   return newTotal;
}

// Name:    goodbye()
// Desc:    This function prints a goodbye message
// input:   None
// output:  None
// return:  void
void goodbye() {
   cout << "Thanks for using the Meal Calculator!" << endl;
}