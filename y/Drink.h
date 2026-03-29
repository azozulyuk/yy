#pragma once
/* Citation and Sources...
-----------------------------------------------------------
Final Project Milestone 3:3
Module: 3
Filename: Drink.h
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
#pragma once
#ifndef SENECA_DRINK_H
#define SENECA_DRINK_H
#include "Billable.h"
#include <iostream>
#include <fstream>

namespace seneca {

    class Drink : public Billable {
        char m_size{};

    public:
        Drink();

        std::ostream& print(std::ostream& ostr = std::cout) const override;
        bool order() override;
        bool ordered() const override;
        std::ifstream& read(std::ifstream& file) override;
        double price() const override;
    };

}

#endif
