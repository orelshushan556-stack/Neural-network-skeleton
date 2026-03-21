#include <iostream>
#include <stdexcept>
#include <cassert>
#include <cmath>
#include "Matrix.h"

int main() {
    try {
        std::cout << "--- Starting Matrix Engine Comprehensive Test ---" << std::endl;

        // 1. בדיקת בנאי ו-fillZero
        Matrix m1(3, 3);
        m1.fillZero();
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) assert(m1(i,j) == 0.0);
        }
        std::cout << "[PASS] Constructor & fillZero" << std::endl;

        // 2. בדיקת אופרטור השוויון (Epsilon)
        Matrix eq1(2, 2);
        Matrix eq2(2, 2);
        eq1.fillZero();
        eq2.fillZero();
        eq1(0,0) = 0.5;
        eq2(0,0) = 0.50000000001; // הפרש קטן מאפסילון
        assert(eq1 == eq2);

        eq2(0,0) = 0.6; // הפרש גדול מאפסילון
        assert(!(eq1 == eq2));
        std::cout << "[PASS] Equality Operator (Epsilon)" << std::endl;

        // 3. בדיקת כפל מטריצות (A * B)
        Matrix A(2, 3);
        Matrix B(3, 2);
        A(0,0)=1; A(0,1)=2; A(0,2)=3; A(1,0)=4; A(1,1)=5; A(1,2)=6;
        B(0,0)=7; B(0,1)=8; B(1,0)=9; B(1,1)=10; B(2,0)=11; B(2,1)=12;

        Matrix C = A * B;
        assert(std::abs(C(0,0) - 58.0) < 1e-9);
        assert(std::abs(C(1,1) - 154.0) < 1e-9);
        std::cout << "[PASS] Matrix Multiplication" << std::endl;

        // 4. בדיקת Hadamard (כפל איבר באיבר)
        Matrix H1(2,2); Matrix H2(2,2);
        H1.randomize(1,1); // הכל 1
        H2.randomize(5,5); // הכל 5
        Matrix H3 = H1.hadamard(H2);
        assert(H3(0,0) == 5.0);
        std::cout << "[PASS] Hadamard Product" << std::endl;

        // 5. בדיקת ReLU ונגזרת
        Matrix D(2, 2);
        D(0,0) = 5.0;  D(0,1) = -2.0;
        D(1,0) = 0.0;  D(1,1) = 3.0;

        Matrix deriv = D.reluDerivative();
        assert(deriv(0,0) == 1.0); // חיובי -> 1
        assert(deriv(0,1) == 0.0); // שלילי -> 0
        assert(deriv(1,0) == 0.0); // אפס -> 0

        D.applyReLU();
        assert(D(0,1) == 0.0);
        assert(D(0,0) == 5.0);
        std::cout << "[PASS] ReLU & reluDerivative" << std::endl;

        // 6. בדיקת randomize (טווח ערכים)
        Matrix R(10, 10);
        R.randomize(-1.0, 1.0);
        for(int i=0; i<100; i++) {
            // גישה ישירה ל-data רק לצורך הטסט (אם הוא פומבי) או שימוש ב-get
            double val = R(i/10, i%10);
            assert(val >= -1.0 && val <= 1.0);
        }
        std::cout << "[PASS] Randomize (Bounds check)" << std::endl;

        // 7. בדיקת חריגות (שגיאות צפויות)
        std::cout << "Testing Error Handling... ";
        try {
            Matrix E(5, 5);
            Matrix F = A * E; // אמור להיכשל
            assert(false); // אם הגענו לכאן - הטסט נכשל!
        } catch (const std::invalid_argument& e) {
            std::cout << "Caught: " << e.what() << " [PASS]" << std::endl;
        }

    } catch (const std::exception& e) {
        std::cerr << "CRITICAL ERROR: Unexpected exception: " << e.what() << std::endl;
        return 1;
    }

    std::cout << "\n--- ALL TESTS PASSED SUCCESSFULLY! ---" << std::endl;
    return 0;
}