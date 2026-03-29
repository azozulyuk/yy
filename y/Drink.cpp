/* Citation and Sources...
-----------------------------------------------------------
Final Project Milestone 3:3
Module: 3
Filename: Drink.cpp
-----------------------------------------------------------
Author: Anastasiya Zozulyuk
Student number: 139,230,247
Email: azozulyuk@myseneca.ca
Subject: BTP200NAA
-----------------------------------------------------------
Revision History
------- --------- ------------------------------------------
Version Date      Reason
V0.7    2025/03/22  Completing code
V0.8    2025/03/23  Debugged
V0.9    -         Asked prof for help for XYZ
V1.0    2026/03/29  Ready for submission
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my work for function main,ect.
-----------------------------------------------------------
*/
#define _CRT_SECURE_NO_WARNINGS
#include "Drink.h"
#include <iostream>
#include <cstring> 
using namespace std;

namespace seneca {

    Drink::Drink() {
        m_size = 0;
    }

    bool Drink::ordered() const {
        return m_size != 0;
    }

    bool Drink::order() {
        cout << "         Drink Size Selection\n";
        cout << "          1- Small\n";
        cout << "          2- Medium\n";
        cout << "          3- Larg\n";
        cout << "          4- Extra Large\n";
        cout << "          0- Back\n";
        cout << "         > ";

        int choice = 0;
        cin >> choice;
        cin.ignore(1000, '\n');


        if (choice == 1) m_size = 'S';
        else if (choice == 2) m_size = 'M';
        else if (choice == 3) m_size = 'L';
        else if (choice == 4) m_size = 'X';
        else m_size = 0;

        return m_size != 0;
    }

    double Drink::price() const {
        double base = Billable::price();

        if (!ordered() || m_size == 'L') return base;
        if (m_size == 'S') return base * 0.5;
        if (m_size == 'M') return base * 0.75;
        if (m_size == 'X') return base * 1.5;

        return base;
    }

    ifstream& Drink::read(ifstream& file) {
        char name[100];
        double priceVal;

        if (file.getline(name, 100, ',') && file >> priceVal) {
            file.ignore(1000, '\n');
            Billable::name(name);
            Billable::price(priceVal);
            m_size = 0;
        }

        return file;
    }

    ostream& Drink::print(ostream& ostr) const {
        char name[29]{};

        if ((const char*)(*this)) {
            strncpy(name, (const char*)(*this), 28);
            name[28] = '\0';
        }
        else {
            strcpy(name, "No Name");
        }

        ostr.setf(ios::left, ios::adjustfield);
        ostr.fill('.');
        ostr.width(28);
        ostr << name;
        ostr.fill(' ');


        if (!ordered()) ostr << ".....";
        else if (m_size == 'S') ostr << "SML..";
        else if (m_size == 'M') ostr << "MID..";
        else if (m_size == 'L') ostr << "LRG..";
        else if (m_size == 'X') ostr << "XLR..";

        ostr.setf(ios::right);
        ostr.width(7);
        ostr.setf(ios::fixed);
        ostr.precision(2);
        ostr << price();

        return ostr;
    }
}
