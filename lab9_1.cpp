#include<iostream>
#include<iomanip> // For using setw(), setprecision(), ...
using namespace std;

int main() {
    double initialLoan, interestRate, paymentPerYear;

    cout << "Enter initial loan: ";
    cin >> initialLoan;
    cout << "Enter interest rate per year (%): ";
    cin >> interestRate;
    cout << "Enter amount you can pay per year: ";
    cin >> paymentPerYear;

    cout << setw(13) << left << "EndOfYear#";
    cout << setw(13) << left << "PrevBalance";
    cout << setw(13) << left << "Interest";
    cout << setw(13) << left << "Total";
    cout << setw(13) << left << "Payment";
    cout << setw(13) << left << "NewBalance";
    cout << "\n";

    cout << fixed << setprecision(2);

    double prevBalance = initialLoan;
    int endOfYear = 1;

    while (prevBalance > 0) {
        double interest = (interestRate / 100) * prevBalance;
        double total = prevBalance + interest;
        double payment = min(paymentPerYear, total);
        double newBalance = total - payment;

        cout << setw(13) << left << endOfYear;
        cout << setw(13) << left << prevBalance;
        cout << setw(13) << left << interest;
        cout << setw(13) << left << total;
        cout << setw(13) << left << payment;
        cout << setw(13) << left << newBalance;
        cout << "\n";

        prevBalance = newBalance;
        endOfYear++;
    }

    return 0;
}
