#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "sandp.h"

void sandp::opener(int& total, vector<string>& item, vector<int>& icost) {
    int i;
    string reply;
    string helpreply;
    while (reply != "exit") {
        cout << "Shirts and Pants Available: " << endl << endl << endl;
        cout << "1. Black Shirt       Price: 15" << endl << endl << endl;
        cout << "2. White Shirt       Price: 14" << endl << endl << endl;
        cout << "3. Gray Shirt        Price: 13" << endl << endl << endl;
        cout << "4. Black Pants       Price: 25" << endl << endl << endl;
        cout << "5. White Pants       Price: 24" << endl << endl << endl;
        cout << "6. Gray Pants        Price: 23" << endl << endl << endl;

        cout << "Please choose the name of shirt or pants wanted or enter 'exit' to return to main page" << endl;
        getline (cin, reply);
        for (i = 0; i < reply.size(); ++i) {
            reply.at(i) = tolower(reply.at(i));
        }
        while ((reply != "black shirt") && (reply != "white shirt") && (reply != "gray shirt") && (reply != "black pants") && 
            (reply != "white pants") && (reply != "gray pants") && (reply != "exit")) {
                cout << "Please choose the name of shirt or pants wanted or enter 'exit'" << endl;
                getline (cin, reply);
                for (i = 0; i < reply.size(); ++i) {
                    reply.at(i) = tolower(reply.at(i));
                }
        }
        if ((reply == "black shirt") || (reply == "white shirt") || (reply == "gray shirt") || (reply == "black pants") || 
            (reply == "white pants") || (reply == "gray pants")) {
            cout << "Would u like to add to bag? (Reply with a 'Yes' or 'No')" << endl;
            getline (cin, helpreply);
            for (i = 0; i < helpreply.size(); ++i) {
                helpreply.at(i) = tolower(helpreply.at(i));
            }
            int helper = 0;
            bool help = false;
            if (helpreply == "no") {
                cout << "Returning to Available Shirts and Pants..." << endl;
                help = true;
            }
            while ((helper != 1) && (helpreply != "no")) {
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
                cout << "Returning to Available Shirts and Pants..." << endl;
            }
        }
        else if ((reply == "exit")) {
            cout << "Redirecting to main page..." << endl;
        }
    }
}

void sandp::addtobag(string reply, int& total, vector<string>& item, vector<int>& icost) {
    int cost;
    string i;
    if (reply == "black shirt") {
        cost = 15;
        item.push_back("black shirt");
        icost.push_back(15);
        i = "Black Shirt";
    }
    else if (reply == "white shirt") {
        cost = 14;
        item.push_back("white shirt");
        icost.push_back(14);
        i = "White Shirt";
    }
    else if (reply == "gray shirt") {
        cost = 13;
        item.push_back("gray shirt");
        icost.push_back(13);
        i = "Gray Shirt";
    }
    else if (reply == "black pants") {
        cost = 25;
        item.push_back("black pants");
        icost.push_back(25);
        i = "Black Pants";
    }
    else if (reply == "white pants") {
        cost = 24;
        item.push_back("white pants");
        icost.push_back(24);
        i = "White Pants";
    }
    else if (reply == "gray pants") {
        cost = 23;
        item.push_back("gray pants");
        icost.push_back(23);
        i = "Gray Pants";
    }
    else {
        cost = 0;
    }

    total = total + cost;

    cout << i << " was added to bag" << endl;
    cout << endl;
    cout << "Returning to Available Shirts and Pants..." << endl;
    cout << endl;
}
