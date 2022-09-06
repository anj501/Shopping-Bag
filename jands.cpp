#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include "jands.h"

void jands::opener(int& total, vector<string>& item, vector<int>& icost) {
    string reply;
    string helpreply;
    int i;
        
    while (reply != "exit") {
        cout << "Jackets and Sweaters Available: " << endl << endl << endl;
        cout << "1. Black Jacket      Price: 25" << endl << endl << endl;
        cout << "2. White Jacket      Price: 25" << endl << endl << endl;
        cout << "3. Vintage Sweater   Price: 35" << endl << endl << endl;
        cout << "4. Black Hoodie      Price: 30" << endl << endl << endl;
        cout << "5. White Hoodie      Price: 30" << endl << endl << endl;
        cout << "6. Vintage Hoodie    Price: 35" << endl << endl << endl;

        cout << "Please choose a Jacket or Sweater wanted or enter 'exit' to return to main page" << endl;
        getline (cin, reply);
        for (i = 0; i < reply.size(); ++i) {
            reply.at(i) = tolower(reply.at(i));
        }

        while ((reply != "black jacket") && (reply != "white jacket") && (reply != "vintage sweater") && (reply != "black hoodie") 
            && (reply != "white hoodie") && (reply != "vintage hoodie") && (reply != "exit")) {
            cout << "Please choose the name of the Jacket or Sweater wanted or enter 'exit'" << endl;
            getline (cin, reply);
            for (i = 0; i < reply.size(); ++i) {
                reply.at(i) = tolower(reply.at(i));
            }
        }
        if ((reply == "black jacket") || (reply == "white jacket") || (reply == "vintage sweater") || (reply == "black hoodie") || 
            (reply == "white hoodie") || (reply == "vintage hoodie")) {
            cout << "Would u like to add to bag? (Reply with a 'Yes' or 'No')" << endl;
            getline (cin, helpreply);
            for (i = 0; i < helpreply.size(); ++i) {
                helpreply.at(i) = tolower(helpreply.at(i));
            }
            int helper = 0;
            bool help = false;
            if (helpreply == "no") {
                cout << "Returning to Available Jackets and Sweaters..." << endl;
                help = true;
            }
            while (helper != 1  && (helpreply != "no")) {
                if ((helpreply == "yes") || (helpreply == "no")) {
                    if (helpreply == "yes") {
                        addtobag(reply, total, item, icost);
                        helper = 1;
                    }
                }
                else {
                    cout << "Please reply with a 'Yes' or 'No'" << endl;
                    getline (cin, helpreply);
                    for (i = 0; i < helpreply.size(); ++i) {
                        helpreply.at(i) = tolower(helpreply.at(i));
                    }
                }
            }
            if ((!help) && (helper != 1)) {
                cout << "Returning to Available Jackets and Sweaters..." << endl;
            }
        }
        else if (reply == "exit") {
            cout << "Redirecting to main page..." << endl;
        }
    }
}

void jands::addtobag(string reply, int& total, vector<string>& item, vector<int>& icost) {
    int cost;
    string i;
    if (reply == "black jacket") {
        cost = 25;
        item.push_back("black jacket");
        icost.push_back(25);
        i = "Black Jacket";
    }
    else if (reply == "white jacket") {
        cost = 25;
        item.push_back("white jacket");
        icost.push_back(25);
        i = "White Jacket";
    }
    else if (reply == "vintage sweater") {
        cost = 35;
        item.push_back("vintage sweater");
        icost.push_back(35);
        i = "Vintage Sweater";
    }
    else if (reply == "black hoodie") {
        cost = 30;
        item.push_back("black hoodie");
        icost.push_back(30);
        i = "Black Hoodie";
    }
    else if (reply == "white hoodie") {
        cost = 30;
        item.push_back("white hoodie");
        icost.push_back(30);
        i = "White Hoodie";
    }
    else if (reply == "vintage hoodie") {
        cost = 35;
        item.push_back("vintage hoodie");
        icost.push_back(35);
        i = "Vintage Hoodie";
    }
    else {
        cost = 0;
    }

    total = cost + total;

    cout << i << " was added to bag" << endl;
    cout << endl;
    cout << "Returning to Available Jackets and Sweaters..." << endl;
    cout << endl;
}