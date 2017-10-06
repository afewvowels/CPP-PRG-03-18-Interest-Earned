//
//  main.cpp
//  PRG-3-18-Interest-Earned
//
//  Created by Keith Smith on 10/6/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
//  Assuming there are no deposits other than the original investment, the balance in a
//  savings account after one year may be calculated as
//  Amount = Principal * (1 + (Rate / T))^T
//  Principal is the balance in the savings account, Rate is the interest rate, and T is
//  the number of times the interest is compounded during a year(T is 4 if the interest is
//  compounded quarterly).
//  Write a program that asks for the principal, the interest rate, and the number of times
//  the interest is compounded. It should display a report similar to:
//  Interest Rate:              4.25%
//  Times Compounded:           12
//  Principal:                  $1000.00
//  Interest:                   $43.34
//  Amount in Savings:          $1043.34

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    
    int intTimesCompounded;
    
    float fltPrincipal,
          fltInterestRate,
          fltInterestTotal,
          fltInterestEarned,
          fltAmountInSavings;
    
    cout << "Please enter the principal: " << endl << "$";
    cin >> fltPrincipal;
    while(!cin || fltPrincipal < 0.0f || fltPrincipal > 10000000.0f)
    {
        cout << "Please enter a dollar amount between $0.00 and $10,000,000.00:\n";
        cin.clear();
        cin.ignore();
        cin >> fltPrincipal;
    }
    
    cout << "Please enter the interest rate: " << endl;
    cin >> fltInterestRate;
    while(!cin || fltInterestRate < 0.0f || fltInterestRate > 100.0f)
    {
        cout << "Please enter a interest rate between 0% and 100%:\n";
        cin.clear();
        cin.ignore();
        cin >> fltInterestRate;
    }
    
    cout << "Please enter the number of times the interest will be compounded: " << endl;
    cin >> intTimesCompounded;
    while(!cin || intTimesCompounded < 0 || intTimesCompounded > 999)
    {
        cout << "Please enter a number of times between 0 and 999:\n";
        cin.clear();
        cin.ignore();
        cin >> intTimesCompounded;
    }
    
    //Convert percent from whole numbers to decimal
    fltInterestRate = fltInterestRate / 100.0f;
    
    fltInterestTotal = fltPrincipal * pow((1 + (fltInterestRate/static_cast<float>(intTimesCompounded))), intTimesCompounded);
    
    fltAmountInSavings = fltInterestTotal;
    fltInterestEarned = fltInterestTotal - fltPrincipal;
    
    cout << setprecision(2) << fixed << showpoint;
    
    cout << setw(25) << left << "Interest Rate:" << " " << fltInterestRate * 100.0f << "%" << endl;
    cout << setw(25) << left << "Times Compounded:" << " " << intTimesCompounded << endl;
    cout << setw(25) << left << "Principal:" << " $" << fltPrincipal << endl;
    cout << setw(25) << left << "Interest Earned:" << " $" << fltInterestEarned << endl;
    cout << setw(25) << left << "Total amount in savings:" << " $" << fltAmountInSavings << endl;
    
    return 0;
}


