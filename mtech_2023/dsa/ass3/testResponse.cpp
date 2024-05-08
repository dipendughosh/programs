#include <iostream>
#include <string>
#include <limits>

using namespace std;

int main()
{
    char choice;
    do
    {
        cout << "Do you want to continue? (yes/y or no/n): ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
        // Convert choice to lowercase for case-insensitive comparison
        choice = tolower(choice);
        if (choice == 'y')
        {
            cout << "Continuing...\n";
            // Place your code for what to do when the user wants to continue here
        }
        else if (choice == 'n')
        {
            cout << "Exiting...\n";
            // Place your code for what to do when the user wants to exit here
        }
        else
        {
            cout << "Invalid input. Please enter yes/y or no/n.\n";
        }
    } while (choice != 'n');

    return 0;
}
