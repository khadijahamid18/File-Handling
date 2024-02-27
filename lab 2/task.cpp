#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Student
{
    int id;       // store the id of a student
    float marks;  // store the marks of a student

    friend istream &operator>>(istream &, Student &);
    friend ostream &operator<<(ostream &, const Student &);

public:
    Student(int id = 0, float marks = 0.0f);

    void addStudent(ofstream &ofs);
    static void displayAllStudents(ifstream &ifs);
    bool findStudent(ifstream &ifs);
    void deleteStudent(ifstream &ifs);
};

Student::Student(int id, float marks) : id(id), marks(marks) {}

istream &operator>>(istream &is, Student &student)
{
    cout << "Enter student ID: ";
    is >> student.id;
    cout << "Enter student marks: ";
    is >> student.marks;
    return is;
}

ostream &operator<<(ostream &os, const Student &student)
{
    os << "Student ID: " << student.id << ", Marks: " << student.marks;
    return os;
}

void Student::addStudent(ofstream &ofs)
{
    ofs.write(reinterpret_cast<const char *>(this), sizeof(Student));
    cout << "Student added successfully." << endl;
}

void Student::displayAllStudents(ifstream &ifs)
{
    ifs.seekg(0, ios::end);
    if (ifs.tellg() == 0)
    {
        cout << "No records found in the file." << endl;
        return;
    }

    ifs.seekg(0, ios::beg);
    while (!ifs.eof())
    {
        Student student;
        ifs.read(reinterpret_cast<char *>(&student), sizeof(Student));
        if (!ifs.eof())
        {
            cout << student << endl;
        }
    }
}

bool Student::findStudent(ifstream &ifs)
{
    ifs.seekg(0, ios::end);
    if (ifs.tellg() == 0)
    {
        cout << "No records found in the file." << endl;
        return false;
    }

    ifs.seekg(0, ios::beg);
    while (!ifs.eof())
    {
        Student student;
        ifs.read(reinterpret_cast<char *>(&student), sizeof(Student));
        if (!ifs.eof() && student.id == this->id && student.marks == this->marks)
        {
            cout << "Student found: " << student << endl;
            return true;
        }
    }

    cout << "Student not found." << endl;
    return false;
}

void Student::deleteStudent(ifstream &ifs)
{
    string tempFileName = "temp.dat";
    ofstream tempFile(tempFileName, ios::out | ios::binary);
    bool found = false;

    ifs.seekg(0, ios::end);
    if (ifs.tellg() == 0)
    {
        cout << "No records found in the file." << endl;
        return;
    }

    ifs.seekg(0, ios::beg);
    while (!ifs.eof())
    {
        Student student;
        ifs.read(reinterpret_cast<char *>(&student), sizeof(Student));
        if (!ifs.eof())
        {
            if (student.id == this->id && student.marks == this->marks)
            {
                found = true;
                continue; // Skip writing this student to the temp file (effectively deleting it)
            }
            tempFile.write(reinterpret_cast<const char *>(&student), sizeof(Student));
        }
    }

    tempFile.close();
    ifs.close();
    remove("student.dat");
    rename(tempFileName.c_str(), "student.dat");

    if (found)
        cout << "Student deleted successfully." << endl;
    else
        cout << "Student not found." << endl;
}

int main()
{
    ofstream ofs("student.dat", ios::out | ios::binary);
    ifstream ifs("student.dat", ios::in | ios::binary);

    if (!ofs || !ifs)
    {
        cerr << "Error opening the file." << endl;
        return 1;
    }

    int choice;
    Student student;
    bool quit = false;

    while (!quit)
    {
        cout << "Menu:\n"
                  << "1. Add Student\n"
                  << "2. Find Student\n"
                  << "3. Delete Student\n"
                  << "4. Display All Students\n"
                  << "5. Quit\n"
                  << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cin >> student;
            student.addStudent(ofs);
            break;
        case 2:
            cout << "Enter student ID and marks to find: ";
            cin >> student;
            student.findStudent(ifs);
            break;
        case 3:
            cout << "Enter student ID and marks to delete: ";
            cin >> student;
            student.deleteStudent(ifs);
            break;
        case 4:
            Student::displayAllStudents(ifs);
            break;
        case 5:
            quit = true;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }

    ofs.close();
    ifs.close();
    return 0;
}
