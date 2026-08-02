#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>
using namespace std;

// Structure to store student information
struct Student
{
    string name;
    int id;
    vector<double> scores;
};

// Function to calculate average score
double calculateAverage(const Student &student)
{
    if (student.scores.empty())
        return 0.0;

    double sum = 0;
    for (double score : student.scores)
    {
        sum += score;
    }

    return sum / student.scores.size();
}

// Function to add a student
void addStudent(vector<Student> &students)
{
    Student student;
    int numScores;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Student name: ";
    getline(cin, student.name);

    cout << "Student ID: ";
    cin >> student.id;

    cout << "How many scores? ";
    cin >> numScores;

    for (int i = 0; i < numScores; i++)
    {
        double score;
        cout << "Enter score " << i + 1 << ": ";
        cin >> score;
        student.scores.push_back(score);
    }

    students.push_back(student);

    cout << "Student \"" << student.name << "\" added successfully.\n";
}

// Function to display all students
void displayStudents(const vector<Student> &students)
{
    if (students.empty())
    {
        cout << "No students have been added yet.\n";
        return;
    }

    cout << "\n===============================================================\n";
    cout << left << setw(20) << "Name"
         << setw(12) << "ID"
         << setw(25) << "Scores"
         << "Average\n";
    cout << "===============================================================\n";

    for (const Student &student : students)
    {
        cout << left << setw(20) << student.name
             << setw(12) << student.id;

        for (double score : student.scores)
        {
            cout << score << " ";
        }

        if (student.scores.size() < 4)
        {
            int spaces = (4 - student.scores.size()) * 5;
            cout << string(spaces, ' ');
        }

        cout << fixed << setprecision(2)
             << calculateAverage(student) << endl;
    }
}

// Function to calculate average for a specific student
void calculateStudentAverage(const vector<Student> &students)
{
    int id;
    cout << "Enter student ID: ";
    cin >> id;

    for (const Student &student : students)
    {
        if (student.id == id)
        {
            cout << fixed << setprecision(2);
            cout << student.name << "'s average score: "
                 << calculateAverage(student) << endl;
            return;
        }
    }

    cout << "Error: Student ID not found.\n";
}

// Main function
int main()
{
    vector<Student> students;
    int choice;

    do
    {
        cout << "\n================================\n";
        cout << "   STUDENT RECORD SYSTEM MENU\n";
        cout << "================================\n";
        cout << "1. Add student\n";
        cout << "2. Display all students\n";
        cout << "3. Calculate average score\n";
        cout << "4. Quit\n";
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addStudent(students);
            break;

        case 2:
            displayStudents(students);
            break;

        case 3:
            calculateStudentAverage(students);
            break;

        case 4:
            cout << "Exiting program. Goodbye!\n";
            break;

        default:
            cout << "Invalid choice. Please enter a number between 1 and 4.\n";
        }

    } while (choice != 4);

    return 0;
}