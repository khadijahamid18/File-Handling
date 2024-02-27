#include <iostream>
#include <cstdio> // Include the header for remove() function
using namespace std;

int main()
{
    const char *filename = "filename.txt"; // Specify the name of the file to be deleted

    // Check if the file exists before attempting to delete it
    if (remove(filename) == 0)
    {
        cout << "File '" << filename << "' has been deleted successfully." << endl;
    }
    else
    {
        cout << "Error: Unable to delete the file." << endl;
    }

    return 0;
}
