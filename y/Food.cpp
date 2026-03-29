/* Citation and Sources...
-----------------------------------------------------------
Final Project Milestone 3:3
Module: 3
Filename: Food.cpp
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
#include "Food.h"
#include <iostream>
#include <cstring>
using namespace std;

namespace seneca {

    Food::Food() {
        m_ordered = false;
        m_child = false;
        m_customize = nullptr;
    }

    Food::Food(const Food& other) {
        m_customize = nullptr;
        *this = other;
    }

    Food& Food::operator=(const Food& other) {
        if (this != &other) {
            Billable::operator=(other);

            m_ordered = other.m_ordered;
            m_child = other.m_child;

            delete[] m_customize;
            if (other.m_customize) {
                m_customize = new char[strlen(other.m_customize) + 1];
                strcpy(m_customize, other.m_customize);
            }
            else {
                m_customize = nullptr;
            }
        }
        return *this;
    }

    Food::~Food() {
        delete[] m_customize;
    }

    bool Food::ordered() const {
        return m_ordered;
    }

    bool Food::order() {
        cout << "         Food Size Selection\n";
        cout << "          1- Adult\n";
        cout << "          2- Child\n";
        cout << "          0- Back\n";
        cout << "         > ";
        int choice = 0;

        cin >> choice;

        while (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "         > ";
            cin >> choice;
        }

        cin.ignore(1000, '\n');

        if (choice == 1) {
            m_child = false;
            m_ordered = true;
        }
        else if (choice == 2) {
            m_child = true;
            m_ordered = true;
        }
        else {
            m_ordered = false;
            delete[] m_customize;
            m_customize = nullptr;
            return false;
        }

        cout << "Special instructions\n> ";

        char temp[100];

        cin.getline(temp, 100);

        delete[] m_customize;

        if (strlen(temp) > 0) {
            m_customize = new char[strlen(temp) + 1];
            strcpy(m_customize, temp);
        }
        else {
            m_customize = nullptr;
        }

        return true;
    }

    double Food::price() const {
        double base = Billable::price();

        if (m_ordered && m_child)
            return base * 0.5;

        return base;
    }

    ifstream& Food::read(ifstream& file) {
        char name[100];
        double priceVal;

        if (file.getline(name, 100, ',') && file >> priceVal) {
            file.ignore(1000, '\n');
            Billable::name(name);
            Billable::price(priceVal);

            m_child = false;
            m_ordered = false;

            delete[] m_customize;
            m_customize = nullptr;
        }

        return file;
    }

    ostream& Food::print(ostream& ostr) const {
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
        else if (m_child) ostr << "Child";
        else ostr << "Adult";

        ostr.setf(ios::right);
        ostr.width(7);
        ostr.setf(ios::fixed);
        ostr.precision(2);
        ostr << price();

        // if (&ostr == &cout && m_customize) {
        //     ostr << " >> " << m_customize;
       //  }
        if (&ostr == &cout && m_customize && m_customize[0] != '\0') {
            ostr << " >> " << m_customize;
        }
        return ostr;
    }

}
