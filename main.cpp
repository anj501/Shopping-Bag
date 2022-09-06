#include <iostream>
#include <vector>
#include <string>
using namespace std;
#include "sandp.h"
#include "aandg.h"
#include "jands.h"

void options();

int main() {
    int total;
    int i;
    int j;
    string option;
    sandp a;
    aandg b;
    jands c;
    

    vector<string> items;
    vector<int> icost;
    
    while (option != "exit") {
        char f;
        string r;
        cout << "Welcome to Best Shopping" << endl;
        options();
        getline(cin, option);
        for (i = 0; i < option.size(); ++i) {
            option.at(i) = tolower(option.at(i));
        }
        while ((option != "shirts and pants") && (option != "accessories and gear") && (option != "jackets and sweaters")
            && (option != "items in bag and cost") && (option != "remove item") && (option != "exit")) {
            cout << "Please enter a valid option (Please enter exact option)" << endl;
            getline(cin, option);
            for (i = 0; i < option.size(); ++i) {
                option.at(i) = tolower(option.at(i));
            }
        }
        if (option == "shirts and pants") {
            a.opener(total, items, icost);
        }
        else if (option == "accessories and gear") {
            b.opener(total, items, icost);
        }
        else if (option == "jackets and sweaters") {
            c.opener(total, items, icost);
        }
        else if (option == "items in bag and cost") {
            while (r != "exit") {
                if (total != 0) {
                    cout << endl;
                    cout << "Items in bag: " << endl;
                    for (i = 0; i < items.size(); ++i) {
                        (items.at(i)).at(0) = toupper((items.at(i)).at(0));
                        for (j = 1; j < (items.at(i)).size(); ++j) {
                            if ((items.at(i)).at(j - 1) == ' ') {
                                (items.at(i)).at(j) = toupper((items.at(i)).at(j));
                            }
                        }
                        cout << items.at(i) << "    " << "Price: " << icost.at(i) << endl;
                    }
                    cout << "Total cost: " << total << endl;
                    for (i = 0; i < items.size(); ++i) {
                        for (j = 0; j < (items.at(i)).size(); ++j) {
                            (items.at(i)).at(j) = tolower((items.at(i)).at(j));
                        }
                    }
                }
                else {
                    cout << "No items in bag" << endl;
                }

                cout << "To repeat bag type any letter or phrase (example: a) or type 'exit' to return to main page" << endl;
                getline(cin, r);
                for (i = 0; i < r.size(); ++i) {
                    r.at(i) = tolower(r.at(i));
                }

                if (r == "exit") {
                    cout << "Redirecting to main page..." << endl;
                }
            }
        }
        else if (option == "remove item") {
            string remove;
            string rhelper;
            string curr;
            cout << "Please type the item you want to remove or type 'exit' to return to main page" << endl;
            getline (cin, remove);
            for (i = 0; i < remove.size(); ++i) {
                remove.at(i) = tolower(remove.at(i));
            }
            if (remove == "exit") {
                    cout << "Redirecting to main page..." << endl;
            }
            while (remove != "exit") {
                bool helper = false;
                for (i = 0; i < items.size(); ++i) {
                    if (items.at(i) == remove) {
                        (items.at(i)).at(0) = toupper((items.at(i)).at(0));
                        for (j = 1; j < (items.at(i)).size(); ++j) {
                            if ((items.at(i)).at(j - 1) == ' ') {
                                (items.at(i)).at(j) = toupper((items.at(i)).at(j));
                            }
                        }
                        curr = items.at(i);
                        items.erase(items.begin() + i);
                        total = total - icost.at(i);
                        helper = true;
                    }
                }
                if (helper) {
                    cout << curr << " was removed from bag" << endl;
                    cout << "To remove another item type any letter (example: a) or type 'exit' to return to main page" << endl;
                }
                else {
                    cout << "Item not in bag. Please type exact item name or type 'exit' to return to main mage" << endl;
                }
                getline (cin, remove);
                for (i = 0; i < remove.size(); ++i) {
                    remove.at(i) = tolower(remove.at(i));
                }

                if (remove == "exit") {
                    cout << "Redirecting to main page..." << endl;
                }
            }
        }
    }
    return 0;
}

void options() {
    cout << "Options: " << endl;
    cout << "Shirts and Pants" << endl;
    cout << "Accessories and Gear" << endl;
    cout << "Jackets and Sweaters" << endl;
    cout << "Items in Bag and Cost" << endl;
    cout << "Remove Item" << endl;
    cout << "Exit" << endl;

    cout << "Please enter an option: " << endl;
}

