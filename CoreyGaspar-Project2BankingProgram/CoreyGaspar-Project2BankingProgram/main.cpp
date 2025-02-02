// Author: Corey Gaspar
// Date: 2/2/2025

#include <iostream>  // used for input/output (cin, cout)
#include <iomanip>   // used for formatting output (in this case, setw and setprecision)
#include <limits>    // used to validate user input
#include <sstream>   // used to convert numbers to strings
#include "BankingApp.h"  // including the customer header file BankingApp.h

using namespace std; // makes coding more efficient instead of having to prefix with std::

void displayOutput(const BankingApp& banking, int numYears, bool withDeposits);

int main()
{
    char restart; // This variable will ask the user if they would like to try again with different values
    do {
        double initialInvestment, annualInterestRate, monthlyDeposit;
        int numYears;
        
        // Data Input header
        cout << "\n**********************************" << endl;
        cout << "********** Data Input ************" << endl;

        // Asks user to enter the initial investment amount and checks to see if input is valid
        cout << "Initial Investment Amount: $";
        while (!(cin >> initialInvestment) || initialInvestment < 0) {
            cout << "Invalid input. Please enter a valid investment amount:  $";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        // Asks user to enter the monthly deposit amount and checks to see if input is valid
        cout << "Monthly Deposit:  $";
        while (!(cin >> monthlyDeposit) || monthlyDeposit < 0) {
            cout << "Invalid input. Please enter a valid monthly deposit:  $";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        // Asks user to enter the annual interest rate and checks to see if input is valid
        cout << "Annual Interest:  %";
        while (!(cin >> annualInterestRate) || annualInterestRate < 0) {
            cout << "Invalid input. Please enter a valid annual interest rate:  %";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        // Asks user to enter the number of years and checks to see if input is valid
        cout << "Number of Years: ";
        while (!(cin >> numYears) || numYears <= 0) {
            cout << "Invalid input. Please enter a positive number of years: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        // Program pauses until user enters a key
        cout << "Press any key to continue...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get(); // Listens for user key press

        // Creating two BankingApp instances, one with monthly deposits and one without
        BankingApp depositAccount(initialInvestment, annualInterestRate, monthlyDeposit);
        BankingApp noDepositAccount(initialInvestment, annualInterestRate, 0);  // No monthly deposit for this case

        // Display both tables (with and without monthly deposits) sequentially
        displayOutput(depositAccount, numYears, true);  // Table with monthly deposits
        displayOutput(noDepositAccount, numYears, false);  // Table without monthly deposits

        // Asking user if they would like to try again
        cout << "\nWould you like to try again with different values? (Y/N): ";
        while (true) {
            cin >> restart;
            restart = tolower(restart); // Automatically converts user input to lowercase
            if (restart == 'y' || restart == 'n') break; // Checking for valid input
            cout << "Invalid input. Please enter Y (Yes) or N (No): ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

    } while (restart == 'y'); // Loop continues if user input is 'y' or 'Y'

    cout << "\nThank you for using the Airgead Banking App!" << endl;
    return 0;
}

// Function that displays the formatted tables for balance and interest with and without additional monthly deposits
void displayOutput(const BankingApp& banking, int numYears, bool withDeposits)
{
    double totalAmount = banking.getInitialInvestment(); // Start with the initial investment
    double interestAmount = 0.0;
    double yearlyTotalInterest = 0.0;
    double annualInterest = banking.getAnnualInterestRate();

    if (withDeposits) {
        // Display year-end data with monthly deposits
        cout << endl << "     Balance and Interest With Additional Monthly Deposits" << endl;
        cout << "================================================================" << endl;
        cout << "   Year        Year End Balance      Year End Earned Interest   " << endl;
        cout << "----------------------------------------------------------------" << endl;

        // Calculate yearly interest and year-end total with monthly deposits
        for (int i = 0; i < numYears; i++) {
            yearlyTotalInterest = 0;  // Reset the yearly total interest

            for (int j = 0; j < 12; j++) {
                // Calculate monthly interest amount
                interestAmount = ((totalAmount + banking.getMonthlyDeposit()) * (annualInterest / 100)) / 12;

                // Accumulate the yearly interest
                yearlyTotalInterest += interestAmount;

                // Update the total amount for the month with the deposit and interest
                totalAmount += banking.getMonthlyDeposit() + interestAmount;
            }
            cout << right << setw(7) << (i + 1);

            ostringstream formatBalance, formatInterest;
            formatBalance << fixed << setprecision(2) << totalAmount;
            formatInterest << fixed << setprecision(2) << yearlyTotalInterest;

            cout << right << setw(24) << ("$" + formatBalance.str())
                << right << setw(30) << ("$" + formatInterest.str())
                << endl;

        }
    }
    else {
        // Display year-end data if no monthly deposits
        cout << endl << "    Balance and Interest Without Additional Monthly Deposits" << endl;
        cout << "================================================================" << endl;
        cout << "   Year        Year End Balance      Year End Earned Interest   " << endl;
        cout << "----------------------------------------------------------------" << endl;

        // Calculate yearly interest and year-end total without monthly deposits
        for (int i = 0; i < numYears; i++) {
            // Calculate yearly interest amount
            interestAmount = totalAmount * (annualInterest / 100);

            // Update total amount by adding the interest
            totalAmount += interestAmount;

            // Show year-end balance and interest for the current year
            cout << left << setw(6) << " " << setw(8) << (i + 1)  // Added extra space for year value
                << right << setw(13) << "$" << fixed << setprecision(2) << totalAmount
                << right << setw(26) << "$" << fixed << setprecision(2) << interestAmount
                << endl;
        }
    }
}
