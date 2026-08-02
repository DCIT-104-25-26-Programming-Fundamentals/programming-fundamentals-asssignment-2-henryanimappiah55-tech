#include <iostream>
#include <iomanip>
using namespace std;

void printTable(int num) {
    cout << "Multiplication Table for " << num << ":" << endl;
    for (int i = 1; i <= 12; i++) {
        cout << num << "  x  " << setw(2) << i << "  =  " << (num * i) << endl;
    }
}

void printTablesUpTo(int n) {
    for (int num = 1; num <= n; num++) {
        printTable(num);
        if (num != n) {
            cout << "---------------------------" << endl;
        }
    }
}

int main() {
    int number;

    cout << "Enter a number: ";
    cin >> number;

    cout << endl;
    printTable(number);

    int n;
    cout << "\nEnter N (to print tables from 1 to N): ";
    cin >> n;

    if (n <= 0) {
        cout << "Error: N must be a positive integer." << endl;
        return 0;
    }

    cout << endl;
    printTablesUpTo(n);

    return 0;
}