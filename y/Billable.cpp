#pragma once
/* Citation and Sources...
-----------------------------------------------------------
Final Project Milestone 3:3
Module: 3
Filename: Food.h
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
V1.0    2026/03/26  Ready for submission
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my work for function main,ect.
-----------------------------------------------------------
*/

#define _CRT_SECURE_NO_WARNINGS
#include "Billable.h"
#include <cstring>
using namespace std;

namespace seneca {

    Billable::Billable() {
        m_name = nullptr;
        m_price = 0.0;
    }

    void Billable::price(double value) {
        m_price = value;
    }

    void Billable::name(const char* nameVal) {
        delete[] m_name;
        if (nameVal) {
            m_name = new char[strlen(nameVal) + 1];
            strcpy(m_name, nameVal);
        }
        else {
            m_name = nullptr;
        }
    }

    Billable::Billable(const Billable& other) {
        m_name = nullptr;
        m_price = 0.0;
        *this = other;
    }

    Billable& Billable::operator=(const Billable& other) {
        if (this != &other) {
            name(other.m_name);
            m_price = other.m_price;
        }
        return *this;
    }

    Billable::~Billable() {
        delete[] m_name;
    }

    double Billable::price() const {
        return m_price;
    }

    Billable::operator const char* () const {
        return m_name;
    }

    double operator+(double money, const Billable& B) {
        return money + B.price();
    }

    double& operator+=(double& money, const Billable& B) {
        money += B.price();
        return money;
    }

}
