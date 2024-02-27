#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    system("cls"); 

    // Open the file in output mode (ios::out)
    ofstream outfile("filename.txt", ios::out);

    if (outfile.is_open())
    {
        // Insert data into the file
        outfile << "This is a line of text." << endl;
        outfile << 513 << endl;

        // Close the file after inserting data
        outfile.close();

        cout << "Data inserted successfully." << endl;
    }
    else
    {
        cout << "Error: Unable to open the file." << endl;
    }

    return 0;
}
