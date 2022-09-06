#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include "aandg.h"

void aandg::opener(int& total, vector<string>& item, vector<int>& icost) {
        string reply;
        string helpreply;
        int i;
        
    while (reply != "exit") {
        cout << "Accessories and Gear Available: " << endl << endl << endl;
        cout << "1. 12 Pcs Headband   Price: 12" << endl << endl << endl;
        cout << "2. Hats              Price: 25" << endl << endl << endl;
        cout << "3. 12 Pair Socks     Price: 13" << endl << endl << endl;
        cout << "4. Necklace          Price: 30" << endl << endl << endl;
        cout << "5. Ring              Price: 25" << endl << endl << endl;
        cout << "6. Sunglasses        Price: 20" << endl << endl << endl;

        cout << "Please choose an Accessory or Gear wanted or enter 'exit' to return to main page" << endl;
        getline (cin, reply);
        for (i = 0; i < reply.size(); ++i) {
            reply.at(i) = tolower(reply.at(i));
        }
        while ((reply != "12 pcs headband") && (reply != "hats") && (reply != "12 pair socks") && (reply != "necklace") && 
            (reply != "ring") && (reply != "sunglasses") && (reply != "exit")) {
                cout << "Please choose the name of the Accessory or Gear wanted or enter 'exit'" << endl;
                getline (cin, reply);
                for (i = 0; i < reply.size(); ++i) {
                    reply.at(i) = tolower(reply.at(i));
                }
        }
        if ((reply == "12 pcs headband") || (reply == "hats") || (reply == "12 pair socks") || (reply == "necklace") || 
            (reply == "ring") || (reply == "sunglasses")) {
            cout << "Would u like to add to bag? (Reply with a 'Yes' or 'No')" << endl;
            getline (cin, helpreply);
            for (i = 0; i < helpreply.size(); ++i) {
                helpreply.at(i) = tolower(helpreply.at(i));
            }
            int helper = 0;
            bool help = false;
            if (helpreply == "no") {
                cout << "Returning to Available Accessories and Gear..." << endl;
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
                cout << "Returning to Available Accessories and Gear..." << endl;
            }
        }
        else if (reply == "exit") {
            cout << "Redirecting to main page..." << endl;
        }
    }
}

void aandg::addtobag(string reply, int& total, vector<string>& item, vector<int>& icost) {
    int cost;
    string i;
    if (reply == "12 pcs headband") {
        cost = 12;
        item.push_back("12 pcs headband");
        icost.push_back(12);
        i = "12 Pcs Headband";
    }
    else if (reply == "hats") {
        cost = 25;
        item.push_back("hats");
        icost.push_back(25);
        i = "Hats";
    }
    else if (reply == "12 pair socks") {
        cost = 13;
        item.push_back("12 pair socks");
        icost.push_back(13);
        i = "12 Pair Socks";
    }
    else if (reply == "necklace") {
        cost = 30;
        item.push_back("necklace");
        icost.push_back(30);
        i = "Necklace";
    }
    else if (reply == "ring") {
        cost = 25;
        item.push_back("ring");
        icost.push_back(25);
        i = "Ring";
    }
    else if (reply == "sunglasses") {
        cost = 20;
        item.push_back("sunglasses");
        icost.push_back(20);
        i = "Sunglasses";
    }
    else {
        cost = 0;
    }

    total = cost + total;

    cout << i << " was added to bag" << endl;
    cout << endl;
    cout << "Returning to Available Accessories and Gear..." << endl;
    cout << endl;
}