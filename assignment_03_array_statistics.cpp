#include <iostream>
using namespace std;

int computeSum(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

double computeAverage(int arr[], int n) {
    return static_cast<double>(computeSum(arr, n)) / n;
}

int computeMax(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

int computeMin(int arr[], int n) {
    int minVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }
    return minVal;
}

int main() {
    int n;

    cout << "How many numbers? ";
    cin >> n;

    if (n <= 0) {
        cout << "Error: N must be a positive integer." << endl;
        return 0;
    }

    int* numbers = new int[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter number " << (i + 1) << ": ";
        cin >> numbers[i];
    }

    cout << "\nResults:" << endl;
    cout << "Sum:     " << computeSum(numbers, n) << endl;
    cout << "Average: " << computeAverage(numbers, n) << endl;
    cout << "Maximum: " << computeMax(numbers, n) << endl;
    cout << "Minimum: " << computeMin(numbers, n) << endl;

    delete[] numbers;

    return 0;
}