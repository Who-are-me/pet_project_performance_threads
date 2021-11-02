#include <iostream>
#include <ctime>


#define pi 3.14159265358979323846


#include <cmath>
#include "CalculatorIntegrals.hpp"
#include "mdef"


i32 main(i32 argc, ch **argv) {
    CalculatorIntegrals ci;

    const std::function integral_function = [](f64 begin, f64 step) {
        return step * sin(2 * (begin + step / 2)) * cos(3 * (begin + step / 2));
    };

    clock_t start = clock();

    if (argc == 2) {
        ci.setCountThreads(atoll(argv[1]));
        ci.calculator(0, pi/2, 1'000'000, integral_function);
    }
    else if (argc == 3) {
        ci.setCountThreads(atoll(argv[1]));
        ci.calculator(0, pi/2, atoll(argv[2]), integral_function);
    }
    else {
        ci.setCountThreads(1);
        ci.calculator(0, pi/2, 1'000'000, integral_function);
    }

    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;

    std::cout << "Result of integral is a:\t" << ci.getResult() << std::endl;
    std::cout << "Count threads is a:\t" << ( (argc > 1) ? atoll(argv[1]) : 1 ) << std::endl;
    std::cout << "Time this program is a:\t" << seconds << std::endl;
    std::cout << "Count steps on thread is a:\t" << ((argc > 2) ? atoll(argv[2]) : 1'000'000 ) << std::endl;

    return 0;
}








