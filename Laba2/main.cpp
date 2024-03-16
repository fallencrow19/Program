#include <iostream>
#include <vector>
#include <locale>

// Функция для вычисления факториала числа n
std::vector<int> factorial(int n) {
    std::vector<int> result = {1};
    for (int i = 2; i <= n; ++i) {
        int carry = 0;
        for (size_t j = 0; j < result.size() || carry; ++j) {
            if (j == result.size())
                result.push_back(0);
            long long current = carry + result[j] * 1LL * i;
            result[j] = current % 10;
            carry = current / 10;
        }
    }
    return result;
}

// Функция для вычисления степени числа 2
std::vector<int> powerOfTwo(int n) {
    std::vector<int> result = {1};
    for (int i = 0; i < n; ++i) {
        int carry = 0;
        for (size_t j = 0; j < result.size() || carry; ++j) {
            if (j == result.size())
                result.push_back(0);
            long long current = carry + result[j] * 1LL * 2;
            result[j] = current % 10;
            carry = current / 10;
        }
    }
    return result;
}

// Функция для сложения двух чисел в виде векторов
std::vector<int> addVectors(std::vector<int> a, std::vector<int> b, int sz) {
    std::vector<int> result;
    int carry = 0;
    for (size_t i = 0; i < std::max(sz, sz) || carry; ++i) {
        if (i == sz)
            a.push_back(0);
        int sum = a[i] + carry + (i < sz ? b[i] : 0);
        result.push_back(sum % 10);
        carry = sum / 10;
    }
    return result;
}

// Функция для вычитания двух чисел в виде векторов
std::vector<int> subtractVectors(std::vector<int> a, std::vector<int> b, int sz) {
    std::vector<int> result;
    int borrow = 0;
    for (size_t i = 0; i < sz; ++i) {
        int diff = a[i] - borrow - (i < sz ? b[i] : 0);
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result.push_back(diff);
    }
    while (result.size() > 1 && result.back() == 0)
        result.pop_back();
    return result;
}


int main() {
    setlocale(LC_ALL, "Russian");

    int input_1, input_2;

    // Задание 1
    std::cout << "Введите число больше 100 для вычисления факториала: ";
    std::cin >> input_1;
    std::vector<int> factResult = factorial(input_1);
    std::cout << "Факториал числа " << input_1 << " равен: ";
    for (auto it = factResult.rbegin(); it != factResult.rend(); ++it)
        std::cout << *it;
    std::cout << std::endl;

    // Задание 2
    std::cout << "Введите число больше 64 для вычисления степени числа 2: ";
    std::cin >> input_1;
    std::vector<int> powerResult = powerOfTwo(input_1);
    std::cout << "2 в степени " << input_1 << " равно: ";
    for (auto it = powerResult.rbegin(); it != powerResult.rend(); ++it)
        std::cout << *it;
    std::cout << std::endl;

    // Задание 3
    std::cout << "Введите два числа больше 64 для сложения степеней числа 2: ";
    std::cin >> input_1 >> input_2;
    std::vector <int> vecpow1 = powerOfTwo(input_1);
    std::vector <int> vecpow2 = powerOfTwo(input_2);
    std::vector<int> powerSumResult = addVectors(vecpow1, vecpow2, std::max((int)vecpow1.size(), (int)vecpow2.size()));
    std::cout << "Сумма 2^" << input_1 << " + 2^" << input_2 << " равна: ";
    for (auto it = powerSumResult.rbegin(); it != powerSumResult.rend(); ++it)
        std::cout << *it;
    std::cout << std::endl;

    // Задание 4
    std::cout << "Введите два числа больше 64, где первое больше второго, для вычитания степеней числа 2: ";
    std::cin >> input_1 >> input_2;
    vecpow1 = powerOfTwo(input_1);
    vecpow2 = powerOfTwo(input_2);
    std::vector<int> powerDiffResult = subtractVectors(vecpow1, vecpow2, (int)vecpow1.size());
    std::cout << "Разность 2^" << input_1 << " - 2^" << input_2 << " равна: ";
    for (auto it = powerDiffResult.rbegin(); it != powerDiffResult.rend(); ++it)
        std::cout << *it;
    std::cout << std::endl;
 
    return 0;
}