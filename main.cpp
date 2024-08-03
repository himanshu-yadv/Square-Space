#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct Item {
    string name;
    double price;
};

void displayCart(const map<string, pair<double, int>>& cart) {
    cout << "\nYour Shopping Cart:\n";
    for (const auto& pair : cart) {
        cout << pair.first << " (Quantity: " << pair.second.second << ") - $" << pair.second.first << endl;
    }
}

int main() {
    cout<<"_________________________WELCOME TO SQUARE-SPACE TERMINAL INTERFACE_______________________";
    string customerName;
    map<string, vector<Item>> categories;
    map<string, pair<double, int>> shoppingCart; // Pair of total price and quantity

    // Existing categories and items
    categories["Electronics"] = {
        {"Laptop", 800.0},
        {"Smartphone", 500.0},
        {"Headphones", 50.0},
        {"Tablet", 300.0}
    };

    categories["Apparel"] = {
        {"T-Shirt", 20.0},
        {"Jeans", 40.0},
        {"Dress", 60.0},
        {"Jacket", 70.0}
    };

    categories["Footwear"] = {
        {"Sneakers", 50.0},
        {"Boots", 80.0},
        {"Sandals", 30.0},
        {"Slippers", 15.0}
    };

    categories["Consumables"] = {
        {"Toothpaste", 5.0},
        {"Shampoo", 8.0},
        {"Soap", 2.0},
        {"Snacks", 3.0}
    };

    categories["Home Decor"] = {
        {"Vase", 25.0},
        {"Curtains", 35.0},
        {"Rug", 45.0},
        {"Clock", 15.0}
    };

    categories["Toy"] = {
        {"Action Figure", 10.0},
        {"Board Game", 20.0},
        {"Doll", 15.0},
        {"Remote Control Car", 30.0}
    };

    categories["Jewellery"] = {
        {"Necklace", 50.0},
        {"Earrings", 40.0},
        {"Bracelet", 35.0},
        {"Ring", 45.0}
    };

    categories["Books"] = {
        {"Fiction", 12.0},
        {"Non-Fiction", 14.0},
        {"Science", 18.0},
        {"History", 16.0}
    };

    categories["Health"] = {
        {"Vitamins", 10.0},
        {"Supplements", 15.0},
        {"First Aid Kit", 20.0},
        {"Thermometer", 8.0}
    };

    categories["Personal Care & Beauty"] = {
        {"Shampoo", 8.0},
        {"Toothpaste", 5.0},
        {"Lotion", 12.0},
        {"Makeup Kit", 25.0}
    };
    cout << "\n\nEnter your name: ";
    getline(cin, customerName);

    while (true) {
        cout << "\nOptions:\n";
        cout << "1. Display Cart\n2. Add to Cart\n3. Delete From Cart\n0. Confirm Order\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        cin.ignore();

        if (choice == 0) {
            break;
        }

        switch (choice) {
            case 1:
                displayCart(shoppingCart);
                break;
            case 2: {
                // Add to Cart
                cout << "\nCategories:\n";
                cout << "1. Electronics\n2. Apparel\n3. Footwear\n4. Consumables\n5. Home Decor\n";
                cout << "6. Toy\n7. Jewellery\n8. Books\n9. Health\n10. Personal Care & Beauty\n";
                cout << "\nEnter your choice (0 to go back to options): ";
                int categoryChoice;
                cin >> categoryChoice;
                cin.ignore();

                if (categoryChoice < 1 || categoryChoice > 10) {
                    break;
                }

                string category;
                switch (categoryChoice) {
                    case 1: category = "Electronics"; break;
                    case 2: category = "Apparel"; break;
                    case 3: category = "Footwear"; break;
                    case 4: category = "Consumables"; break;
                    case 5: category = "Home Decor"; break;
                    case 6: category = "Toy"; break;
                    case 7: category = "Jewellery"; break;
                    case 8: category = "Books"; break;
                    case 9: category = "Health"; break;
                    case 10: category = "Personal Care & Beauty"; break;
                }

                while (true) {
                    cout << "\nAvailable items in " << category << ":\n";
                    vector<Item> items = categories[category];
                    for (int i = 0; i < items.size(); ++i) {
                        cout << i + 1 << ". " << items[i].name << " - $" << items[i].price << endl;
                    }

                    cout << "\nEnter item number to add to cart (0 to go back to categories): ";
                    int itemNumber;
                    cin >> itemNumber;
                    cin.ignore();

                    if (itemNumber < 1 || itemNumber > items.size()) {
                        break;
                    }

                    Item chosenItem = items[itemNumber - 1];

                    cout << "\nEnter quantity for this item: ";
                    int quantity;
                    cin >> quantity;
                    cin.ignore();

                    shoppingCart[chosenItem.name].first += chosenItem.price * quantity; // Update total price
                    shoppingCart[chosenItem.name].second += quantity; // Update quantity in the cart

                    cout << chosenItem.name << " (Quantity: " << quantity << ") added to your cart.\n";

                    cout << "\nWant to add any other item for this category? (y/n): ";
                    char addMore;
                    cin >> addMore;
                    cin.ignore();
                    if (addMore != 'y' && addMore != 'Y') {
                        break;
                    }
                }
                break;
            }
            case 3: {
                // Delete From Cart
                cout << "\nEnter item name to delete from cart: ";
                string itemName;
                getline(cin, itemName);

                if (shoppingCart.find(itemName) != shoppingCart.end()) {
                    int currentQuantity = shoppingCart[itemName].second;
                    cout << "Item: " << itemName << " is in your cart with a quantity of " << currentQuantity << ".\n";
                    cout << "Enter quantity to delete (0 to cancel): ";
                    int deleteQuantity;
                    cin >> deleteQuantity;
                    cin.ignore();
                    if (deleteQuantity == 0 || deleteQuantity >= currentQuantity) {
                        cout <<"\n"<< itemName << " removed from your cart.\n";
                        shoppingCart.erase(itemName);
                    } else {
                        shoppingCart[itemName].first -= (deleteQuantity * (shoppingCart[itemName].first / currentQuantity));
                        shoppingCart[itemName].second -= deleteQuantity;
                        cout << deleteQuantity << " of " << itemName << " removed from your cart.\n";
                    }
                } else {
                    cout << itemName << " not found in your cart.\n";
                }
                break;
            }

            default:
                cout << "\nInvalid choice. Please try again.\n";
        }
    }

    double totalAmount = 0.0;
    for (const auto& pair : shoppingCart) {
        totalAmount += pair.second.first;
    }

    cout << "\nTotal Amount: $" << totalAmount << endl;
    cout << "\nThank you for shopping, " << customerName << "!\n";
    cout<<"--------------------------==========================-----------------------------------";
    return 0;
}
