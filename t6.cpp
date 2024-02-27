#include "iostream"
#include "string"
#include "fstream"
#include "cstdio"

using namespace std;

class Student
{
	int id;
	float gpa;
public:

	Student(int id = 0, float gpa = 0)
	{
		this->id = id;
		this->gpa = gpa;
	}

	int get_id()const
	{
		return this->id;
	}

	float get_gpa()const
	{
		return this->gpa;
	}

	void set_id(const int id)
	{
		this->id = id;
	}

	void set_gpa(const float gpa)
	{
		this->gpa = gpa;
	}

	void print()const
	{
		cout << id << '\t' << gpa << endl;
	}

};

int main()
{

	// creation of record
	
	ofstream outf("test.dat", ios::binary);
	
	if (!outf)
	{
		cerr << "File creation failed !";
		exit(0);
	}
	cout << "File created Successfully." << endl;

	Student s1(1, 3.5), s2(2, 3.7), s3(3, 3.8), s4(4, 3.4), s5(5, 3.9);
	Student arr[5] = { s1,s2,s3,s4,s5 };

	outf.write(reinterpret_cast<char*>(arr), sizeof(arr));

	outf.close();

	// opening file

	ifstream inf("test.dat");
	if (!inf)
	{
		cerr << "File creation failed !";
		exit(0);
	}
	cout << "File created Successfully." << endl;

	Student temp;

	inf.read(reinterpret_cast<char*>(&temp), sizeof(Student));
	while (!inf.eof())
	{
		temp.print();
		inf.read(reinterpret_cast<char*>(&temp), sizeof(Student));
	}
	inf.close();

	// updating and deleting


	ifstream orignalFile("test.dat", ios::binary);
	ofstream tempFile("temp.dat", ios::binary);
	
	orignalFile.read(reinterpret_cast<char*>(&temp), sizeof(Student));
	while (!orignalFile.eof())
	{

		if (temp.get_id() == 3) // updating record with id 3
		{
			temp.set_gpa(4.0);
			tempFile.write(reinterpret_cast<char*>(&temp), sizeof(Student));
		}
		else if (temp.get_id() != 4) // delete record with id 4
		{
		tempFile.write(reinterpret_cast<char*>(&temp), sizeof(Student));
		}
		orignalFile.read(reinterpret_cast<char*>(&temp), sizeof(Student));

	}

	orignalFile.close();
	tempFile.close();

	remove("test.dat");
	rename("temp.dat", "test.dat");

	// opening file again to check deletion and updation

	ifstream inf1("test.dat");
	if (!inf1)
	{
		cerr << "File creation failed !";
		exit(0);
	}
	cout << "File created Successfully." << endl;


	inf1.read(reinterpret_cast<char*>(&temp), sizeof(Student));
	while (!inf1.eof())
	{
		temp.print();
		inf1.read(reinterpret_cast<char*>(&temp), sizeof(Student));
	}
	inf1.close();

	return 0;
}