/* My name: William Landrum
 * Course Name: CS3304 Data Structures
 * This program calculates and displays the area of six geometric
 * shapes in a table.
 */

#include <iostream>    // Provides cout
#include <iomanip>     // Provides setw function for setting output width
#include <cassert>     // Provides assert function
#include <cmath>       // Provides math library
#include <cstdlib>     // Provides EXIT_SUCCESS
using namespace std;   // Allows all standard library items to be used

double eq_Tri (double side)
// Precondition: t is greater than 0 and is less than or equal to 6
// Postcondition: returns the area of a triangle
{
    assert (side > 0 && side <= 6);
    return (sqrt(3) / 4) * (side * side);
}

double square (double side)
// Precondition: s is greater than 0 and is less than or equal to 6
// Postcondition: returns the area of a square
{
    assert (side > 0 && side <= 6);
    return side * side;
}

double pent (double side)
// Precondition: p is greater than 0 and is less than or equal to 6
// Postcondition: returns the area of a pentagon
{
    assert (side > 0 && side <= 6);
    return (.25 * sqrt(5 * (5 + 2 * sqrt(5))) * (side * side));
}

double hex (double side)
// Precondition: h is greater than 0 and is less than or equal to 6
// Postcondition: returns the area of a hexagon
{
    assert (side > 0 && side <= 6);
    return ((3 * sqrt(3)) * .5) * (side * side);
}

double hep (double side)
// Precondition: side is greater than 0 and is less than or equal to 6
// Postcondition: returns the area of a heptagon
{
    assert (side > 0 && side <= 6);
    return (1.75 * (side * side) * 1/tan(M_PI / 7));
}

double oct (double side)
// Precondition: side is greater than 0 and is less than or equal to 6
// Postcondition: returns the area of a octagon
{
    assert (side > 0 && side <= 6);
    return (2 * (1 + sqrt(2)) * (side * side));
}

void setup_cout_fractions(int fraction_digits)
// Precondition: fraction_digits is not negative.
// Postcondition: All double or float numbers printed to cout will now be
// rounded to the specified digits on the right of the decimal.
{
    assert(fraction_digits > 0);
    cout.precision(fraction_digits);
    cout.setf(ios::fixed, ios::floatfield);
    if (fraction_digits == 0)
        cout.unsetf(ios::showpoint);
    else
        cout.setf(ios::showpoint);
}

int main()
{
    // Constants declared
    const double MAX_SIDE_VALUE  =              6;
    const char   HEADING1[]  = "Shape       "; // Heading for table's 1st column
    const char   HEADING2[]  = "Area        "; // Heading for table's 2nd column
    const string LABEL1      = "Triangle    "; // Label for first shape
    const string LABEL2      = "Square      "; // Label for second shape
    const string LABEL3      = "Pentagon    "; // Label for third shape
    const string LABEL4      = "Hexagon     "; // Label for fourth shape
    const string LABEL5      = "Heptagon    "; // Label for fifth shape
    const string LABEL6      = "Octagon     "; // Label for sixth shape
    const int    WIDTH       =              9; // Number chars in output numbers
    const int    DIGITS      =              1; // Number digits right of decimal pt

    setup_cout_fractions(DIGITS);
    cout << HEADING1 << HEADING2 << endl;

    // For loop to print table
    for (int x = 1; x <= MAX_SIDE_VALUE; x++)
    {
      cout << setw(WIDTH) << LABEL1 << eq_Tri(x) << endl;
    }

    cout << endl;

    for (int x = 1; x <= MAX_SIDE_VALUE; x++)
    {
        cout << setw(WIDTH) << LABEL2 << square(x) << endl;
    }

    cout << endl;

    for (int x = 1; x <= MAX_SIDE_VALUE; x++)
    {
        cout << setw(WIDTH) << LABEL3 << pent(x) << endl;
    }

    cout << endl;

    for (int x = 1; x <= MAX_SIDE_VALUE; x++)
    {
        cout << setw(WIDTH) << LABEL4 << hex(x) << endl;
    }

    cout << endl;

    for (int x = 1; x <= MAX_SIDE_VALUE; x++)
    {
        cout << setw(WIDTH) << LABEL5 << hep(x) << endl;
    }

    cout << endl;

    for (int x = 1; x <= MAX_SIDE_VALUE; x++)
    {
        cout << setw(WIDTH) << LABEL6 << oct(x) << endl;
    }


    return EXIT_SUCCESS;
}
