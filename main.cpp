#include <iostream>
#include <random>
#include <ctime>
#include <string>

using namespace std;

string alphabet_small = "abcdefghijklmnopqrstuvwxyz";   // 26
string ALPHABET_CAPITAL = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // 26
string digit = "0123456789";                            // 10
string symbol = "!@#$%^&(){}[]/*-+|";                   // 18

int getRandom(int MIN, int MAX)
{
    // This Fanction return Random Number in [ MIN , MAX ]
    return MIN + rand() % ((MAX + 1) - MIN);
}
int getType(int MIN, int MAX)
{
    // Return Type of Char would be added
    // if 1 is small alphabet
    // if 2 is capital alphabet
    // if 3 is digit
    // if 4 is symbol
    return getRandom(MIN, MAX);
}

char getChar(int type)
{
    // return char to string
    char result = '0';
    if (type == 1)
    {
        result = alphabet_small[getRandom(0, 25)];
    }
    else if (type == 2)
    {
        result = ALPHABET_CAPITAL[getRandom(0, 25)];
    }
    else if (type == 3)
    {
        result = digit[getRandom(0, 9)];
    }
    else if (type == 4)
    {
        result = symbol[getRandom(0, 17)];
    }
    return result;
}

string PasswordGenerator(int passwordLength)
{
    string password = "";
    while (passwordLength--)
    {
        int type = getType(1, 4);
        char passwd_char = getChar(type);
        password += passwd_char;
    }
    return password;
}
void showPassword(int length)
{
    cout << "\n=========================================\n";
    cout << "-----> Password      :                        ";
    cout << "\n=========================================\n\n";
    cout << PasswordGenerator(length) << endl;
    cout << "\n\nvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv\n";
}
void welcome()
{
    int order = 1, length;
    do
    {
        cout << "------------------------------------------\n";
        cout << "             Password Generator           \n";
        cout << "------------------------------------------\n\n";
        while (true)
        {
            cout << "      1. Generate Password                 \n";
            cout << "      2. Quit                             \n\n";
            cout << "Press [1] to Generate Password or [2] to Quit.. : ";
            cin >> order;
            if (order == 1 || order == 2)
            {

                break;
            }
            else
            {
                cout << "\n\n  xxxxx InValid Input xxxx  \n\n";
                cout << "    --> Try Again,... <--  \n\n\n";
            }
        }
        if (order == 1)
        {
            cout << "\nEnter Password Length : ";
            cin >> length;
            showPassword(length);
        }
    } while (order == 1);
    cout << "\n                 Godby Sir...!!\n"
         << endl;
}
int main()
{

    srand(time(nullptr));
    welcome();
}
