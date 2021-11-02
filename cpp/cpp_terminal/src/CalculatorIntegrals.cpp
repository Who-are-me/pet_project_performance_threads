#include "CalculatorIntegrals.hpp"
#include "Function.hpp"


CalculatorIntegrals::CalculatorIntegrals (f64 start, f64 end, ui64 count_steps, const std::function<f64 (f64, f64)> integral_function) {
    calculator(start, end, count_steps, integral_function);
}


CalculatorIntegrals::CalculatorIntegrals () {}


void CalculatorIntegrals::calculator (f64 start, f64 end, ui64 count_steps_on_thread, const std::function<f64 (f64, f64)> integral_function) {
    f64* results = new f64[this->count_threads];
    std::thread threads[this->count_threads];
    Function fn;
    f64 size_part = (end - start) / this->count_threads;

    auto lambda_into_thread =
        [&](i32 x) {
            fn.calculate(size_part * x, size_part * (x + 1), (end - start) / count_steps_on_thread, results[x], integral_function);
        };

    for (i32 x = 0; x < this->count_threads; ++x) {
        threads[x] = std::thread(lambda_into_thread, x);
    }

    for (i32 x = 0; x < this->count_threads; ++x) {
        threads[x].join();
        this->result += results[x];
    }

    delete[] results;
}


void CalculatorIntegrals::setCountThreads (ui16 count) {
    this->count_threads = count;
}


f64 CalculatorIntegrals::getResult () {
    return this->result;
}



