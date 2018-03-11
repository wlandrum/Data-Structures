bool double_equal (double value, double expected_value,
                   double epsilon = 0.000001);
// precondition: epsilon > 0
// returned true if relative difference between x & y is at most
//          epsilon - false ow