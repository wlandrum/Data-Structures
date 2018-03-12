

#ifndef LAB2_COMPLEX_H
#define LAB2_COMPLEX_H

namespace william_lab_2
{
    class complex
    {
    public:
        // CONSTRUCTORS
        complex(double r = 0, double c = 0);

        double get_real() const;
        // Postcondition: Real is returned
        double get_complex() const;
        // Postcondition: Complex is returned
        void display();

        double reduce(double r, double c);


    private:
        double real;     // real number.
        double compnum;  // complex number.
    };

    complex operator + (const complex& r1, const complex& r2);
// postcondition: sum of r1 & r2 has been returned

    complex operator - (const complex& r1, const complex& r2);
// postcondition: difference of r1 & r2 has been returned

    complex operator * (const complex& r1, const complex& r2);
// postcondition: product of r1 & r2 has been returned

    complex operator / (const complex& r1, const complex& r2);
// precondition: r2 is not zero
// postcondition: quotient of r1 & r2 has been returned

    bool  operator < (const complex& r1, const complex& r2);
// postcondition: whether r1 < r2 has been returned

    bool  operator <= (const complex& r1, const complex& r2);
// postcondition: whether r1 <= r2 has been returned

    bool  operator > (const complex& r1, const complex& r2);
// postcondition: whether r1 > r2 has been returned

    bool  operator >= (const complex& r1, const complex& r2);
// postcondition: whether r1 >= r2 has been returned

    bool  operator == (const complex& r1, const complex& r2);
// postcondition: whether r1 == r2 has been returned

    bool  operator != (const complex& r1, const complex& r2);
// postcondition: whether r1 != r2 has been returned
}


#endif //LAB2_COMPLEX_H
