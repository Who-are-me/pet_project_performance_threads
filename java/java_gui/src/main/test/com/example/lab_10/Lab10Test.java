package com.example.lab_10;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import static java.lang.StrictMath.cos;
import static java.lang.StrictMath.sin;
import static org.junit.jupiter.api.Assertions.*;

class Lab10Test {
    @BeforeEach
    void setUp() {}

    @Test
    void check() throws  InterruptedException {
        Lab10 l10 = new Lab10();
        l10.setCountThreads(16);
        l10.setIntegralFunction((begin, step) -> (step * (sin(2 * (begin + step / 2.0)) * cos(3 * (begin + step / 2.0)))));
        l10._run_(0.0, 3.14159265358979323846/2, 1000000);

        assertEquals(-0.4, l10.getData(), 0.0005, "error out data");
    }
}