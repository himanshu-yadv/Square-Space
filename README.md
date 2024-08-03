# Square Space - terminal-based Shopping application

The "Square-Space Terminal Interface" is a terminal-based shopping cart application. This program allows users to browse through various product categories, add items to their cart, view the contents of their cart, and delete items from their cart. The application calculates the total amount due for the items in the cart and provides a seamless shopping experience within a terminal interface.

Key Features
Welcome Interface:

A welcoming message for the user.
User Interaction:

Prompt for user's name.
Menu options for displaying the cart, adding items to the cart, deleting items from the cart, and confirming the order.
Product Categories:

The application includes a variety of categories such as Electronics, Apparel, Footwear, Consumables, Home Decor, Toys, Jewellery, Books, Health, and Personal Care & Beauty.
Adding Items to Cart:

Users can browse items in a selected category and add their desired items to the shopping cart with specified quantities.
Displaying Cart:

Users can view the items in their cart along with the quantity and total price of each item.
Deleting Items from Cart:

Users can delete specified quantities of items or remove items entirely from their cart.
Order Confirmation:

Upon confirmation, the application calculates and displays the total amount due for the items in the cart and thanks the user for shopping.
Technologies and Concepts Used
C++ Programming:

Utilizes standard input/output for user interaction.
Employs the C++ Standard Library (<iostream>, <map>, <vector>) for data management and operations.
Data Structures:

Struct: Defines the Item structure to store item names and prices.
Map:
categories map for storing items categorized by product type.
shoppingCart map for storing the cart's contents with the total price and quantity for each item.
Vector: Used within the categories map to store lists of items.
Control Flow:

Implements loops and conditionals to handle user input and program logic, ensuring a user-friendly and interactive experience.