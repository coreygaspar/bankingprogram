// Author: Corey Gaspar
// Date: 2/2/2025
#pragma once
#include <string>
using namespace std;
#include <cmath> // Required for pow()

class BankingApp
{
public:
	// Constructors
	BankingApp(double initialInvestment, double annualInterestRate); // Default monthlyDeposit = 0
	BankingApp(double initialInvestment, double annualInterestRate, double monthlyDeposit);

	// Calculates the final balance after numYears with monthly deposits
	double getFinalBalance(int numYears) const;

	// Calculates the total interest earned over the number of years
	double getInterestEarned(int numYears) const;

	// Returns final balance and formats to 2 decimal places
	string getFormattedFinalBalance(int numYears) const;

	// Returns total interest earned and formats to 2 decimal places
	string getFormattedInterestEarned(int numYears) const;

	// Getters
	double getInitialInvestment() const;
	double getAnnualInterestRate() const;
	double getMonthlyDeposit() const;

	// Utility functions
	double round(double value, int places) const;
	string format(double value) const;

private:
	// Can only be used within the BankingApp class
	double initialInvestment;
	double annualInterestRate;
	double monthlyDeposit;
};
