#pragma once


#include <thread>
#include <functional>
#include "mdef"


class CalculatorIntegrals {
    ui16 count_threads{1};
    f64 result{0.0};

public:
    CalculatorIntegrals (f64 start, f64 end, ui64 count_steps, const std::function<f64 (f64, f64)> integral_function);
    CalculatorIntegrals ();

    void calculator (f64 start, f64 end, ui64 count_steps_on_thread, const std::function<f64 (f64, f64)> integral_function);
    void setCountThreads (ui16 count);

    f64 getResult();
};
