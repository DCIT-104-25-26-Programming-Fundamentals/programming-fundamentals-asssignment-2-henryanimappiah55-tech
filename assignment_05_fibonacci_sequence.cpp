#include <iostream>
using namespace std;

void printFibonacci(int n) {
    int first = 0, second = 1;

    cout << "Fibonacci sequence: ";
    for (int i = 0; i < n; i++) {
        cout << first << " ";
        int next = first + second;
        first = second;
        second = next;
    }
    cout << endl;
}

bool isFibonacci(int num) {
    if (num < 0) {
        return false;
    }

    int first = 0, second = 1;

    while (first <= num) {
        if (first == num) {
            return true;
        }
        int next = first + second;
        first = second;
        second = next;
    }

    return false;
}

int main() {
    int n;

    cout << "How many terms? ";
    cin >> n;

    if (n <= 0) {
        cout << "Error: N must be a positive integer." << endl;
    } else {
        printFibonacci(n);
    }

    int num;
    cout << "\nEnter a number to check: ";
    cin >> num;

    if (isFibonacci(num)) {
        cout << num << " is a Fibonacci number." << endl;
    } else {
        cout << num << " is NOT a Fibonacci number." << endl;
    }

    return 0;
}