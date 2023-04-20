#include <iostream>
#include <string>
#include <thread>
#include <chrono>

using namespace std;

//! GLOBALS
bool firstTimeBank, firstTimeChoice;
string acnt1, acnt2, acnt3;
double bal = 0;

namespace bank // Bank namespace
{
    struct account // Bank account class
    {
        string name;
        double balance;
    };
}

bank::account account1;
bank::account account2;
bank::account account3;

void bankInfo(bank::account acnt)
{
    cout << "----- ACCOUNT INFO -----\n";
    cout << "Overall balance: " << bal << "\n";
    cout << "Name: " << acnt.name << "\n";
    cout << "Balance in account: " << acnt.balance << "\n";
    cout << "------------------------\n\n";
}

void choice();

void bankLocation() // Bank scene
{
    int emCheck = 2;

    if (firstTimeBank == true)
    {
        cout << "Welcome to the bank! Here you can make accounts, and manage your money!\n";
        cout << "Because it is your first time here, you will need to make a bank account.\n\n";
        while (emCheck == 2)
        {
            cout << "Enter the name for your first account: ";
            cin.ignore();
            getline(cin, acnt1);
            system("cls");

            if (acnt1.empty())
            {
                cout << "You have to enter a name!\n";
            }

            else
            {
                emCheck = 1;
            }
        }

        cout << "Great name! Creating bank accout " << acnt1 << ":\n";
        account1.name = acnt1;
        bal = 100;
        account1.balance = 25;

        std::this_thread::sleep_for(std::chrono::seconds(2));
        cout << "Account created!\n";
        bankInfo(account1);
        std::this_thread::sleep_for(std::chrono::seconds(5));
        firstTimeBank = false;
        firstTimeChoice = true;
        system("cls");
        choice();
    }

    else if (firstTimeBank == false)
    {
        system("cls");

        string input;

        cout << "Welcome back! You know how things roll arround here so i'll not interupt.\n\n";
        cout << "---OPTIONS---\n";
        cout << "1: check overall balance\n";
        cout << "2: check account balance\n";
        cout << "2: add account\n";
        cout << "3: delete account\n";
        cout << "4: deposit\n";
        cout << "5: withdrawal\n";
        cout << "-------------\n\n";
        cin.ignore();
        cout << ">>> ";
        getline(cin, input);

        if (input == "check overall balance")
        {
            system("cls");
            cout << "Overall Balance is: " << bal << "\n";
            std::this_thread::sleep_for(std::chrono::seconds(3));
            choice();
        }
        
        if (input == "check account balance")
        {
            string accountInput;

            while(true)
            {
                system("cls");
                cout << "---ACCOUNTS---\n";
                cout << "1: " << account1.name << "\n";
                cout << "2: " << account2.name << "\n";
                cout << "3: " << account3.name << "\n";
                cout << "--------------\n\n";
                cin.ignore();
                cout << "Choose a bank account: ";
                getline(cin, accountInput);

                if (accountInput == "1")
                {
                    if (account1.name.empty())
                    {
                        cout << "Account is empty!";
                        std::this_thread::sleep_for(std::chrono::seconds(2));
                    }

                    else
                    {   
                        cout << "\n\n" << account1.balance << "\n\n";
                        break;
                        choice();   
                    }
                }

                if (accountInput == "2")
                {
                    if (account2.name.empty())
                    {
                        cout << "Account is empty!";
                        std::this_thread::sleep_for(std::chrono::seconds(2));
                    }

                    else
                    {
                        cout << "\n\n" << account2.balance << "\n\n";
                        break;
                        choice();
                    }
                }

                if (accountInput == "3")
                {
                    if (account3.name.empty())
                    {
                        cout << "Account is empty!";
                        std::this_thread::sleep_for(std::chrono::seconds(2));
                    }

                    else
                    {
                        cout << "\n\n" << account3.balance << "\n\n";
                        break;
                        choice();
                    }
                }

                else
                {
                    cout << "\nChoose an account!\n";
                }
            }
             
            }  
            
            if (input == "add account")
            {
                
            }

            
            if (input == "delete account")
            {
                
            }
            
            if (input == "deposit")
            {
                
            }
            
            if (input == "withdrawal")
            {
                
            }
        }
}

void shop(bank::account acnt) // Shop scene
{

}

void choice() // choice
{
    string input;

    while(firstTimeChoice == true)
    {
        cout << "This is the choice menu. You can chose where to go and what to do!\n";
        cout << "At any time if you want to leave the application, you can just type 'exit' in here\n";
        firstTimeChoice = false;
        break;
    }

    cout << "-----OPTIONS-----\n";
    cout << "1: exit\n";
    cout << "2: bank\n";
    cout << "3: shop\n";
    cout << "-----------------\n\n";

    cout << ">>> ";
    cin >> input;

    if (input == "exit")
    {

    }

    else if (input == "bank")
    {
        system("cls");
        bankLocation();
    }

    else if (input == "shop")
    {
        string accountInput;

        while(true)
        {
            system("cls");
            cout << "---ACCOUNTS---\n";
            cout << "1: " << account1.name << "\n";
            cout << "2: " << account2.name << "\n";
            cout << "3: " << account3.name << "\n";
            cout << "--------------\n\n";
            cin.ignore();
            cout << "Choose a bank account: ";
            getline(cin, accountInput);

            if (accountInput == "1")
            {
                if (account1.name.empty())
                {
                    cout << "Account is empty!";
                    std::this_thread::sleep_for(std::chrono::seconds(2));
                }

                else
                {   
                    shop(account1);
                    break;   
                }
            }

            if (accountInput == "2")
            {
                if (account2.name.empty())
                {
                    cout << "Account is empty!";
                    std::this_thread::sleep_for(std::chrono::seconds(2));
                }

                else
                {
                    shop(account2);
                    break;
                }
            }

            if (accountInput == "3")
            {
                if (account3.name.empty())
                {
                    cout << "Account is empty!";
                    std::this_thread::sleep_for(std::chrono::seconds(2));
                }

                else
                {
                    shop(account3);
                    break;
                }
            }

            else
            {
                cout << "\nChoose an account!\n";
            }
        }
        
    }
}

int main()
{
    // variables
    string begin;

    // start code
    cout << "Welcome to the bank simulator!\n";
    cout << "You can make money and spend it on things! Truly the American dream.\n\n";
    cout << "Do you wish to start?\n";
    cout << "y/n: ";
    cin >> begin;

    // condition checks
    if (begin == "y" || "yes")
    {
        system("cls");
        cout << "Great! Starting game...";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        system("cls");
        firstTimeBank = true;
        bankLocation();
    }

    else if (begin == "n" || "no")
    {
        system("cls");
        cout << "It's okay, you don't have to play.";
        std::this_thread::sleep_for(std::chrono::seconds(3));
    }

    else
    {

    }
}