#pragma once


#include "mdef"
#include <functional>


struct Function {
    void calculate(f64 begin, f64 end, f64 step, f64& data, const std::function<f64 (f64, f64)> integral_function);
};
