#include <iostream>
#include "string"
#include "fstream"

using namespace std;

int main()
{
    system("cls");
    ofstream outf("student.txt");
    if (!outf)
    {
        cerr << "File creation failed" << endl;
    }
    int rollNumber = 0;
    string firstName = "";
    string lastName = "";
    int marks = 0;

    cout << "Please enter roll number, First name, last name and marks:  " << endl;

    while (cin >> rollNumber >> firstName >> lastName >> marks && rollNumber != -999)
    {
        outf << rollNumber << " " << firstName << " " << lastName << " " << marks << endl;
        cout << "Enter roll number, first name, last name and marks : " << endl;
    }

    outf.close();

    return 0;
}
