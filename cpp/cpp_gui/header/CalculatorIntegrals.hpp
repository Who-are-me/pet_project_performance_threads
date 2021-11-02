#pragma once


#include <thread>
#include <functional>
#include "mdef"


class CalculatorIntegrals {
    u16 count_threads{1};
    f64 result{0.0};

public:
    CalculatorIntegrals (f64 start, f64 end, u64 count_steps, const std::function<f64 (f64, f64)> integral_function);
    CalculatorIntegrals ();

    void calculator (f64 start, f64 end, u64 count_steps_on_thread, const std::function<f64 (f64, f64)> integral_function);
    void setCountThreads (u16 count);

    f64 getResult();
};
