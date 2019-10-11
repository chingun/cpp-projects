#ifndef IO_H
#define IO_H

#include <string>

//     EFFECTS: Prints the prompt, and reads a double from cin.
//              If the value is between min and max, inclusive, returns
//              it.  Otherwise, repeats.
double GetParam(std::string prompt, double min, double max);

//     EFFECTS: prints out a nice header for the payment info table.
//     MODIFIES: cout
void PrintHeader (void);

//     EFFECTS: prints out a row in the payment info table.
//     MODIFIES: standard output stream
void PrintMonthlyData (int month, double principal,
                       double interest, double loaned);

#endif

