//Shubhayu Shrestha 1001724804
//Coding Assignment 3: Part 1 of Building a Coke Machine
/*Create a class called CokeMachine and a Code3_xxxxxxxxxx.cpp 
    program to instantiate your own CokeMachine and exercise its functionality */
#include <iostream>
#include <vector>
#include <string.h>
#include "CokeMachine.h"

using namespace std;

//function that prints out menu and takes in user choice
void printMenu(int &menuChoice)
{
    //asking user for input
    cout << "\nPlease choose from the following options\n" << endl;

    //Printing out options to user
    cout << "0. Walk Away" << endl;
    cout << "1. Buy a Coke" << endl;
    cout << "2. Restock Machine" << endl;
    cout << "3. Add change" << endl;
    cout << "4. Display Machine Info\n" << endl;

    cout << "Choice: ";

    //utilizing if statement utilizing ors and fail flags for error handling user input
    cin >> menuChoice;

    //checking if input is a letter, and if it is, ask user to reenter
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "\ninput must be numeric, please reenter ";
        cin >> menuChoice;
    }
}

int main(void)
{
    //declaring variables
    int menuChoice{};
    bool runSwitch = true;
    int inventory;
    int payment;
    string change;
    int action;
    int inputStock;
    bool inputStockBool;
    int inputChange;
    bool inputChangeBool;
    bool ableToBuy;

    CokeMachine MyCokeMachine{"CSE 1325 Coke Machine", 50, 500, 100};

    do
    {
        //printing out name of machine
        cout << "\n" << MyCokeMachine.getMachineName() << endl;

        //printing menu
        printMenu(menuChoice);

        //creating switch statement to follow allong with menu choice
        //switch statement with user menu choice
        switch (menuChoice)
        {
        case 0: // walk away
        {
            cout << "Thank you. Have a good day!" << endl;
            runSwitch = false;
            break;
        }
        case 1: //purchase coke
        {
            cout << "Insert payment for 1 coke (in cents): ";
            cin >> payment;

            while (cin.fail())
            {
                cin.clear();
                cin.ignore(100, '\n');
                cout << "\ninput must be numeric, please reenter ";
                cin >> payment;
            }

            ableToBuy = MyCokeMachine.buyACoke(payment, change, action);

            if (ableToBuy)
            {
                if (action == ACTION::EXACTCHANGE)
                {
                    cout << "\nThank you for providing the exact change!\n" << endl;
                    cout << "Here is your coke!\n\n\n" << endl;
                }
                else if (action == ACTION::OK)
                {
                    cout << "\nHere is your Coke and your change of " << change << endl;
                }
                else
                {
                    cout << "\nunknown error occured";
                }
            }
            else
            {
                if(action == ACTION::NOCHANGE)
                {
                    cout << "\nUnable to give change at this time... returning your payment\n" << endl; 
                }
                else if(action == ACTION::NOINVENTORY)
                {
                    cout << "\nThis machine is now out of product...\n" << endl; 
                }
                else if(action == ACTION::INSUFFICIENTFUNDS)
                {
                    cout << "\nInsufficiant payment... returning your payment\n" << endl; 
                }
                else if(action ==ACTION::BOXFULL)
                {
                    cout << "\nChange box is full - call 1800IMFULL to get change removed... \n" << endl; 
                }
                else
                {
                    cout << "\nunknown error occured\n" << endl; 
                }
            }
            
            break;
        }
        case 2: //restock inventory
        {
            cout << "Enter how much product you are adding to the machine: "; 
            cin >> inputStock;

            while (cin.fail())
            {
                cin.clear();
                cin.ignore(100, '\n');
                cout << "\ninput must be numeric, please reenter ";
                cin >> inputStock;
            }

            inputStockBool = MyCokeMachine.incrementInventory(inputStock); 

            if(inputStockBool == true)
            {
                cout << "\n\nYour machine has been restocked.\n" << endl; 

                cout << "\nYour inventory level is now " << MyCokeMachine.getInventoryLevel() << endl; 
            }
            else
            {
                cout << "\n\nYou have exceeded your machine's max capacity\n" << endl; 

                cout << "\nYour inventory level is now " << MyCokeMachine.getInventoryLevel() << endl; 
            }
            
            break;
        }
        case 3: //add change
        {
            cout << "Enter how much change you are adding to the machine: ";
            cin >> inputChange;

            while (cin.fail())
            {
                cin.clear();
                cin.ignore(100, '\n');
                cout << "\ninput must be numeric, please reenter ";
                cin >> inputChange;
            }

            inputChangeBool = MyCokeMachine.incrementChangeLevel(inputChange);

            if (inputChangeBool == true)
            {
                cout << "\n\nYour change has been refilled.\n" << endl;

                cout << "\nYour change level is now " << MyCokeMachine.getChangeLevel() << endl;
            }
            else
            {
                cout << "\n\nYou have exceeded your machine's max change capacity\n" << endl;

                cout << "\nYour change level is now " << MyCokeMachine.getChangeLevel() << endl;
            }

            break;
        }
        case 4: //display machine info
        {
            //Checking current Inventory Level
            cout << "\n\nCurrent Inventory Level: ";
            cout << MyCokeMachine.getInventoryLevel() << endl;

            //Checking Max Inventory Capacity
            cout << "\nMax Inventory Capacity: ";
            cout << MyCokeMachine.getMaxInventoryCapacity() << endl;

            //Checking Current Change Level
            cout << "\n\nCurrent Change Level: ";
            cout << MyCokeMachine.getChangeLevel() << endl;

            //Checking Max Change Capacity
            cout << "\nMax Change Capacity: ";
            cout << MyCokeMachine.getMaxChangeCapacity() << endl;

            //Checking Current Coke Price
            cout << "\n\nCurrent Coke Price: ";
            cout << MyCokeMachine.getCokePrice() << endl;
            break;
        }
        default:
            cout << "\nInvalid menu choice. Please choose again." << endl;
        }
    } 
    while (runSwitch == true);

    return 0;
}
