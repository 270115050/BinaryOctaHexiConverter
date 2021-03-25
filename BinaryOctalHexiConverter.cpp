// BinaryOctalHexiConverter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <string>
using namespace std;
int main()
{
again:
    int dec = 0,choice = 0, tempNum = 0;
    string str = " ", binary = " ", temp = " ";
    char ascii = ' ';

    cout << "Press 1 to run Decimal to Binary program" << endl
        << "Press 2 to run Decimal to Octal program" << endl
        << "Press 3 to run Decimal to Hexidicimal program" << endl
        << "Press 4 to run Binary to Decimal program" << endl
        << "Press 5 to run Octal to Decimal program" << endl
        << "Press 6 to run Hexidecimal to Decimal program" << endl
        << "Press any key to exit..." << endl
        << "----------------------------------------------" << endl << endl
        << "Choose a program to run: ";
    cin >> choice;

    switch (choice) {
    case 1: //convert decimal to binary 
        cout << "Decimal to Binary converter" << endl
            << "Enter decimal number: ";
        cin >> dec;
        while (dec > 0) {
            binary.append(to_string(dec % 2));
            dec /= 2;
        }
        reverse(binary.begin(), binary.end());
        cout << "Decimal to binary: " << binary;
        break;
    case 2://convert decimal to octa
        cout << "Decimal to Octal converter" << endl
            << "Enter decimal number: ";
        cin >> dec;
        while (dec > 0) {
            binary.append(to_string(dec % 8));
            dec /= 8;
        }
        reverse(binary.begin(), binary.end());
        cout << "Decimal to Octa: " << binary;
        break;
    case 3://convert decimal to hexi
        cout << "Decimal to Hexidecimal converter" << endl
            << "Enter decimal number: ";
        cin >> dec;
        while (dec > 0) {
            if ((dec % 16) > 9)
            {
                ascii = dec % 16 + 55;
                temp = ascii;
                binary.append(temp);
            }
            else
                binary.append(to_string(dec % 16));

            dec /= 16;
        }
        reverse(binary.begin(), binary.end());
        cout << "Decimal to Hexi: " << binary;
        break;
    case 4: //binary to decimal
        cout << "Binary to Decimal converter" << endl
            << "Enter decimal number: ";
        cin >> str;

        reverse(str.begin(), str.end());

        for (int i = 0; i < str.size(); i++) {           
            tempNum = str[i] - '0';        
            dec += (tempNum * (pow(2, i)));
        }
        cout << "Binary to decimal: " << dec;
        break;
    case 5: //octa to decimal
        cout << "Octa to Decimal converter" << endl
            << "Enter decimal number: ";
        cin >> str;
        reverse(str.begin(), str.end());

        for (int i = 0; i < str.size(); i++) {
            tempNum = str[i] - '0';
            dec += (tempNum * (pow(8, i)));
        }
        cout << "Octa to decimal: " << dec;
        break;
    case 6: //hexi to decimal

        cout << "Hexidecimal to Decimal converter" << endl
            << "Enter decimal number: ";
        cin >> str;
        reverse(str.begin(), str.end());

        for (int i = 0; i < str.size(); i++) {
            int check = (int)(tolower(str[i]));
            int num = 10, z = 97;
            if (check >= 97) {         
                while (z != check) {
                    num++;
                    z++;
                } 
                dec += (num * (pow(16, i)));
            }
            else {
                tempNum = str[i] - '0';
                dec += (tempNum * (pow(16, i)));
            }     
        }
        cout << "Hexidecimal to decimal: " << dec;
        break;
    default: 
        break;
    }
    cout << endl;
    system("pause");
    system("cls");
    goto again;
    
    return 0;
}
