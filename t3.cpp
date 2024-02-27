#include "iostream"
#include "fstream"
#include "string"
#include "cstdio"

using namespace std;

class Student
{
private:
    int id;
    float marks;

    friend istream &operator>>(istream &in, Student &ob)
    {
        in >> ob.id >> ob.marks;
        return in;
    }

    friend ostream &operator<<(ostream &out, const Student &ob)
    {
        out << ob.id << "\t" << ob.marks;
        return out;
    }

public:
    Student(int id = 0, float marks = 0.0f)
    {
        this->id = id;
        this->marks = marks;
    }

    void addStudent(fstream *outf)
    {
        outf->write(reinterpret_cast<char *>(this), sizeof(Student));
        cout << "Added successfully\n";
    }

    void displayStudentAll(fstream *outf)
    {
        Student temp;
        outf->seekg(0, ios::beg);
        outf->read(reinterpret_cast<char *>(&temp), sizeof(Student));
        while (!outf->eof())
        {
            cout << temp << "\n";
            outf->read(reinterpret_cast<char *>(&temp), sizeof(Student));
        }
    }

    bool findStudent(fstream *outf)
    {
        Student temp;
        outf->seekg(0, ios::beg);
        outf->read(reinterpret_cast<char *>(&temp), sizeof(Student));
        while (!outf->eof())
        {
            if (this->id == temp.id && this->marks == temp.marks)
            {
                cout << "student Find!!\t";
                return 1;
            }
            outf->read(reinterpret_cast<char *>(&temp), sizeof(Student));
        }
        cout << "Student not Found!!\t";
        return 0;
    }

    void deleteStudent(fstream *old)
    {
        Student tempObj;
        fstream newfile("temp.dat", ios::binary | ios::out);

        old->read(reinterpret_cast<char *>(&tempObj), sizeof(Student));
        while (!old->eof())
        {
            if (this->id == tempObj.id && this->marks == tempObj.marks)
            {
                old->read(reinterpret_cast<char *>(&tempObj), sizeof(Student));
            }
            else
            {
                newfile.write(reinterpret_cast<char *>(&tempObj), sizeof(Student));
                old->read(reinterpret_cast<char *>(&tempObj), sizeof(Student));
            }
        }

        newfile.close();

        old->close();

        remove("task2.dat");
        rename("temp.dat", "task2.dat");
    }
};

int main()
{
    Student ob1(1, 1.1);
    Student ob2(2, 2.2);
    Student ob3(3, 3.3);

    fstream outf("task2.dat", ios::binary | ios::app | ios::in);
    if (!outf)
    {
        cout << "File Error!";
        exit(0);
    }
    cout << "\n\t\tAdd Student!!\n";
    ob1.addStudent(&outf);
    ob2.addStudent(&outf);
    cout << "\n\t\tOld file data!!\n";
    ob1.displayStudentAll(&outf);
    outf.close();
    cout << "\n\t\tFinding Student!!\n";
    fstream outd("task2.dat", ios::binary | ios::app | ios::in);
    if (!outd)
    {
        cout << "File Error!";
        exit(0);
    }

    cout << ob1.findStudent(&outd) << "\n";
    cout << ob3.findStudent(&outd) << "\n";

    outd.close();

    fstream old("task2.dat", ios::binary | ios::app | ios::in);
    if (!old)
    {
        cout << "File Error!";
        exit(0);
    }
    ob2.deleteStudent(&old);

    cout << "\n\t\tNew file data!!\n";
    fstream newFile("task2.dat", ios::binary | ios::app | ios::in);
    if (!newFile)
    {
        cout << "File Error!";
        exit(0);
    }
    ob2.displayStudentAll(&newFile);

    newFile.close();
    return 0;
}