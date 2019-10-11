//
//  main.cpp
//  Project #1
//
//  Created by Chingun Khasar on 6/1/15.
//  Copyright (c) 2015 Chingun Khasar. All rights reserved.
//
#include <iostream>
using namespace std;
#include "io.h"
//End yagaad io.h-g ni oruulj baigaa bilee?? io.h-s io.cpp ruu orood tegeed io.h ruu orj baigaamuu yaj baigaan?
//io.cpp dotor #include "io.h" l gechihsen baih yum tegeegui baihad bolno gejuu
double roundTo4sigfigs(double a);

int main(){
    double MonthlyPayment = 0;
    double InterestRate = 0;
    double DurationOfLoan = 0;
    double balance = 0;
    
    double principal = 0;
    double interest = 0;
    
    //taking in datas months interest durofLoan and such
    MonthlyPayment = GetParam("Please enter the monthly payment: ", 1, 100000);
    InterestRate = GetParam("Please enter the interest rate: ", 0, 1);
    DurationOfLoan = GetParam("Please enter the duration of the loan, in years: ", 1, 100);
    
    
    balance = MonthlyPayment/(1 + InterestRate/12);
    principal = balance;
    
    double irrelevant = 0;
    
    PrintHeader();
    for (int month = DurationOfLoan * 12; month > 0; month -= 1){
        //main equation for stuff here
        irrelevant = balance;
        interest = 100 - principal;
        cout << roundTo4sigfigs(month) << "\t\t\t"
        << roundTo4sigfigs(principal) << "\t\t"
        << roundTo4sigfigs(interest) << "\t\t"
        << roundTo4sigfigs(balance) << endl;
        
        balance = (balance + MonthlyPayment)/(1 + InterestRate/12);
        principal = balance - irrelevant;
    }
}


double roundTo4sigfigs(double a){
    a = a * 100;
    int b = 0;
    b = a;
    if (b < a) {
        a = b;
        a = (a + 1)/100;
        return a;
    }
    else {
        a = b;
        a = a/100;
        return a;
    }
}


