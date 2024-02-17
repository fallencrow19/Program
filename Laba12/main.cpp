#include <iostream>  
#include <iomanip>   
#include <cstdint>   

// Функция для вывода числа в шестнадцатеричном виде.
void printHex(uint8_t& byte) {
    std::cout << std::hex << std::setw(2) << std::setfill('0') << (int)byte << " ";  // Установка вывода в шестнадцатеричной системе счисления, установка ширины и заполнение нулями, вывод значения и пробела.
}
// Функция для вывода числа в двоичном виде.
void printBinary(uint8_t& byte) {
    for (int i = 7; i >= 0; --i) {  // Цикл по битам числа.
        std::cout << ((byte >> i) & 1);  // Вывод i-го бита числа.
    }
    std::cout << " ";  // Вывод пробела
}
// Функция для вывода побайтового представления переменной.
void printBytes(int& length, uint8_t* ptr) {
    for (int i = length - 1; i >= 0; --i) {  // Цикл по байтам переменной.
        printHex(ptr[i]);  // Вывод i-го байта в шестнадцатеричном виде.
    }
    std::cout << std::endl;  // Переход на новую строку.
    for (int i = length - 1; i >= 0; --i) {  // Цикл по байтам переменной.
        printBinary(ptr[i]);  // Вывод i-го байта в двоичном виде.
    }
    std::cout << std::endl;  // Переход на новую строку.
}
int main() {
    setlocale(LC_ALL, "Russian");
    // Примеры вызова функции для различных типов данных.
    int intValue = 12345;
    float floatValue = 12345;
    double doubleValue = 12345;
    int intLength = sizeof(intValue);
    int floatLength = sizeof(floatValue);
    int doubleLength = sizeof(doubleValue);
    std::cout << "Побайтовое представление int:" << std::endl;  // Вывод заголовка для int.
    printBytes(intLength, reinterpret_cast<uint8_t*>(&intValue));  // Вызов функции для вывода побайтового представления int.
    std::cout << "Побайтовое представление float:" << std::endl;  // Вывод заголовка для float.
    printBytes(floatLength, reinterpret_cast<uint8_t*>(&floatValue));  // Вызов функции для вывода побайтового представления float.
    std::cout << "Побайтовое представление double:" << std::endl;  // Вывод заголовка для double.
    printBytes(doubleLength, reinterpret_cast<uint8_t*>(&doubleValue));  // Вызов функции для вывода побайтового представления double.
    return 0;
}
