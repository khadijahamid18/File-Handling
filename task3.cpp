#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream inf("input.txt");
    if (!inf)
    {
        cerr << "Error: Unable to open input.txt" << endl;

    }

    int rollNumber, maxNumber;
    int quizScore[10]; 

    inf >> rollNumber;
    for (int i = 0; i < 10; i++)
    {
        inf >> quizScore[i];
    }

    while (!inf.eof())
    {
        maxNumber = quizScore[0];
        for (int i = 0; i < 10; i++)
        {
            if (maxNumber < quizScore[i])
            {
                maxNumber = quizScore[i];
            }
        }

        cout << rollNumber << "\t";

        for (int i = 0; i < 10; i++)
        {
            cout << quizScore[i] << " ";
        }
        cout << maxNumber << endl;

        inf >> rollNumber;
        for (int i = 0; i < 10; i++)
        {
            inf >> quizScore[i];
        }
    }

    inf.close();

    return 0;
}