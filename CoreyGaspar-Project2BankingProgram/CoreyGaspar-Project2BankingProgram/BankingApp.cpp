// Author: Corey Gaspar
// Date: 2/2/2025

#include "BankingApp.h"
#include <iostream>
#include <iomanip> // For formatting
#include <sstream> // For string formatting

// Constructor without monthly deposit (defaults to 0)
BankingApp::BankingApp(double initialInvestment, double annualInterestRate)
	: initialInvestment(initialInvestment), annualInterestRate(annualInterestRate), monthlyDeposit(0) {}

// Constructor with monthly deposit
BankingApp::BankingApp(double initialInvestment, double annualInterestRate, double monthlyDeposit)
	: initialInvestment(initialInvestment), annualInterestRate(annualInterestRate), monthlyDeposit(monthlyDeposit) {}

// Computes the final balance after numYears (compounded monthly)
double BankingApp::getFinalBalance(int numYears) const
{
	double closingBalance = initialInvestment;
	int totalMonths = numYears * 12;
	double monthlyInterestRate = (annualInterestRate / 100) / 12;

	for (int i = 0; i < totalMonths; i++)
	{
		double interestEarned = (closingBalance + monthlyDeposit) * monthlyInterestRate;
		closingBalance += monthlyDeposit + interestEarned;
	}

	return round(closingBalance, 2);
}

// Computes total interest earned over numYears
double BankingApp::getInterestEarned(int numYears) const
{
	// Get the final balance after numYears
	double finalBalance = getFinalBalance(numYears);

	// Calculate total deposits made (initial investment + monthly deposits over years)
	double totalDeposits = initialInvestment + (monthlyDeposit * numYears * 12);

	// If interest is compounded monthly, we might also need to factor in the interest accrued
	// on monthly deposits, not just the initial investment. So we calculate the interest as:
	double interestEarned = finalBalance - totalDeposits;

	// Ensure the result is rounded to 2 decimal places
	return std::round(interestEarned * 100.0) / 100.0;  // Round to two decimal places
}

// Returns final balance as a formatted string
string BankingApp::getFormattedFinalBalance(int numYears) const
{
	return format(getFinalBalance(numYears));
}

// Returns interest earned as a formatted string
string BankingApp::getFormattedInterestEarned(int numYears) const
{
	return format(getInterestEarned(numYears));
}

// Getters
double BankingApp::getInitialInvestment() const { return initialInvestment; }
double BankingApp::getAnnualInterestRate() const { return annualInterestRate; }
double BankingApp::getMonthlyDeposit() const { return monthlyDeposit; }

// Rounds a value to the specified decimal places
double BankingApp::round(double value, int places) const
{
	double multiplier = pow(10, places);
	return static_cast<double>(static_cast<int>(value * multiplier + 0.5)) / multiplier;
}

// Formats a double to 2 decimal places
string BankingApp::format(double value) const
{
	stringstream stream;
	stream << fixed << setprecision(2) << value;
	return stream.str();
}