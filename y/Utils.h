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
#pragma once
#ifndef SENECA_UTILS_H
#define SENECA_UTILS_H

namespace seneca {

    class Utils {
    public:
        int getInt(int min, int max);
    };

    extern Utils ut;

}

#endif