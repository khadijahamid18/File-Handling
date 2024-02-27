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

    int rollNumber, maxNumber, secMax;
    int quizScore[10]; 

    inf >> rollNumber;
    for (int i = 0; i < 10; i++)
    {
        inf >> quizScore[i];
    }

    while (!inf.eof())
    {
        maxNumber = quizScore[0];
        secMax;

        for (int i = 0; i < 10; i++)
        {
            if (maxNumber < quizScore[i])
            {
                secMax = maxNumber;
                maxNumber = quizScore[i];
            }
        }

        cout << rollNumber << "\t";

        cout << maxNumber << "\t" << secMax << endl;


        inf >> rollNumber;
        for (int i = 0; i < 10; i++)
        {
            inf >> quizScore[i];
        }
    }

    inf.close();

    return 0;
}