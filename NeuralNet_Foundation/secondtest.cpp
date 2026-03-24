#include <iostream>
#include <iomanip> // בשביל עיצוב ההדפסה
#include "Matrix.h"
#include "Layer.h"

int main() {
    std::cout << "--- Integration Test 2: Layer Forward Pass ---" << std::endl;

    try {
        // 1. הקמת השכבה
        Layer myLayer(4, 10);

        // 2. יצירת קלט אקראי
        Matrix input(4, 1);
        input.randomize(0, 4);

        // 3. הרצת הצינור (Forward Pass)
        Matrix output = myLayer.forward(input);

        // 4. בדיקת ממדים
        std::cout << "[+] Output dimensions: " << output.getRows() << "x" << output.getCols() << std::endl;

        // 5. האישור הסופי - בדיקת ערכי ה-ReLU
        std::cout << "\n[*] Verifying ReLU output values (Should be >= 0):" << std::endl;
        std::cout << "-----------------------------------------------" << std::endl;

        output.print(); // כאן קורית ההדפסה שמוכיחה שהסינון עבד

        std::cout << "-----------------------------------------------" << std::endl;
        std::cout << "[!] If you see 0.00, it means a negative value was successfully filtered!" << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "\n[-] EXCEPTION CAUGHT: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}