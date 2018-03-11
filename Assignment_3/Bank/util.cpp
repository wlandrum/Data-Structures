#include <cmath> // Provides fabs

bool double_equal (double value, double expected_value,
                   double epsilon)
{
    bool result = true;
    if (value != expected_value)
    {
        double relative_error = fabs((value - expected_value) / expected_value);
        if (relative_error > epsilon)
            result = false;
    }
    return result;
}
