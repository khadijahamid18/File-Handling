#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    // Open the file in input and output mode
    fstream file("filename.txt", ios::in | ios::out);

    if (file.is_open())
    {
        // Read data from the file
        string content;
        getline(file, content);

        // Modify the content (for example, append something to it)
        content += " Updated ";

        // Clear the existing content in the file
        file.seekp(0);
        file.clear(); // Clear any error flags

        // Write the updated content back to the file
        file << content;

        // Close the file
        file.close();

        cout << "File updated successfully." << endl;
    }
    else
    {
        cout << "Error: Unable to open the file." << endl;
    }

    return 0;
}
