#include <iostream>
#include <locale>

// Функция для возведения числа в степень.
int power(int base, int exponent) {
    // Статическая переменная для подсчета количества вызовов рекурсивной функции.
    static int callCount = 0;
    // Увеличиваем счетчик вызовов.
    callCount++;
        // Базовый случай: если степень равна 0, то результат равен 1.
    if (exponent == 0) {
        return 1;
    }
    // Рекурсивный случай: умножаем число на результат возведения в степень (n-1).
    else {
        return base * power(base, exponent - 1);
    }
}
int main() {
    setlocale(LC_ALL, "Russian");

    int base = 5, exponent = 4;
    std::cout << "Введите основание и степень: " << base << " " << exponent << std::endl;
    if (exponent < 0) { // Проверка на отрицательную степень.
        std::cout << "Степень должна быть целым положительным числом." << std::endl; // Ошибка!
    }

    else {
        int result = power(base, exponent); // Вызов функции для вычисления степени.
        std::cout << base << " в степени " << exponent << " равно " << result << std::endl;
    }
    return 0;
}
