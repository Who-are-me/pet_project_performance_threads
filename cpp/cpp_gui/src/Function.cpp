#include <cmath>


#include "Function.hpp"


void Function::calculate(f64 begin, f64 end, f64 step, f64& data, const std::function<f64 (f64, f64)> integral_function) {
    while (begin <= end) {
        data += integral_function(begin, step);
        begin += step;
    }
}
