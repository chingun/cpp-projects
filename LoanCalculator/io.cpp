#include "io.h"

#include <iostream>
#include <iomanip>

using namespace std;


//     EFFECTS: Prints the prompt, and reads a double from cin.
//              If the value is between min and max, inclusive, returns
//              it.  Otherwise, repeats.
double GetParam(string prompt, double min, double max)
{
    double result = min-1.0;
    bool done = false;

    do {
        cout << prompt;
        cin >> result;
        if ((result >= min) && (result <= max)) {
            done = true;
        }
    } while (!done);

    return result;
}

//     EFFECTS: prints out a nice header for the payment info table.
//     MODIFIES: cout
void PrintHeader (void)
{
    cout << endl;
    cout << "Month\tPrincipal\t Interest\t  Balance" << endl;
    cout << "-----\t---------\t---------\t---------" << endl;
}

//     EFFECTS: prints out a row in the payment info table.
//     MODIFIES: standard output stream
void PrintMonthlyData (int month, double principal,
                       double interest, double loaned)
{
    cout << month << "\t" << fixed << setprecision(2)
         << setw(9) << principal << "\t"
         << setw(9) << interest << "\t"
         << setw(9) << loaned << endl;
}



