#pragma once
/* Citation and Sources...
------------------------------------ -----------------------
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
#ifndef SENECA_BILLABLE_H
#define SENECA_BILLABLE_H

#include <iostream>
#include <fstream>

namespace seneca {

    class Billable {
        char* m_name{};
        double m_price{};

    protected:
        void price(double value);
        void name(const char* name);

    public:
        Billable();
        Billable(const Billable& other);
        Billable& operator=(const Billable& other);
        virtual ~Billable();

        virtual double price() const;

        virtual std::ostream& print(std::ostream& ostr = std::cout) const = 0;
        virtual bool order() = 0;
        virtual bool ordered() const = 0;
        virtual std::ifstream& read(std::ifstream& file) = 0;

        operator const char*() const;
    };

    double operator+(double money, const Billable& B);
    double& operator+=(double& money, const Billable& B);

}

#endif  // SENECA_BILLABLE_H
