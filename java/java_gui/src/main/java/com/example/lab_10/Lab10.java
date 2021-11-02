package com.example.lab_10;

import static java.lang.StrictMath.*;

public class Lab10 extends Thread implements Runnable {
    static private double data;
    static private int count_threads;
    static private Function2<Double, Double> integral_function;
    static private double start;
    static private double end;
    static private int count_steps_on_thread;
    static private int ix;
    static private Function fn;

    public Lab10() {
        fn = new Function();
        this.data = 0;
        this.count_threads = 1;
        integral_function = (begin, step) -> (step * (sin(2 * (begin + step / 2.0)) * cos(3 * (begin + step / 2.0))));
    }

    public void setIntegralFunction(Function2<Double, Double> integral_function) {
        this.integral_function = integral_function;
    }

    public void setCountThreads(int count_treads) {
        this.count_threads = count_treads;
    }

    public void _run_(double start, double end, int count_steps_on_thread) throws InterruptedException {
        System.out.println("------\trun lab 10\t------");

        Lab10[] temp_data = new Lab10[count_threads];
        this.start = start;
        this.end = end;
        this.count_steps_on_thread = count_steps_on_thread;
        int size = count_threads;

        System.out.println("count threads = " + count_threads);
        System.out.println("count steps = " + count_steps_on_thread);

        for (int x = 0; x < size; ++x) {
            temp_data[x] = new Lab10();
        }

        for (int x = 0; x < size; ++x) {
            ix = x;
            temp_data[x].start();
        }

        for (int x = 0; x < size; ++x) {
            temp_data[x].join();
        }

        System.out.println("Data is a " + this.data);
        System.out.println("------\tend lab 10\t------");
    }

    @Override
    public void run() {
        double size_part = (end - start) / count_threads;
        data += fn.calculate(size_part * ix, size_part * (ix + 1), (end - start) / count_steps_on_thread, integral_function);
    }

    @FunctionalInterface
    public interface Function2<One, Two> {
        public Two apply(One one, Two two);
    }

    public double getData() {
        return this.data;
    }
}
