package com.example.lab_10;

public class Function extends Thread implements Runnable {
        public Function() {}

    public double calculate(double begin, double end, double step, Lab10.Function2<Double, Double> integral_function) {
        double result = 0.0;

        while (begin <= end) {
            result += integral_function.apply(begin, step);
            begin += step;
        }

        return result;
    }
}
