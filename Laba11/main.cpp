#include <iostream>
#include <cmath>
#include <locale>

// Функция для вычисления индекса массы тела
double calculateBMI(double weight, double height) {
    return (weight / (pow(height, 2) + 4)) * 10000;
}

int main(int, char**){
    setlocale(LC_ALL, "Russian");

    double mas = 79, ros = 174, ind;

    std::cout << "Введите массу " << mas << std::endl;
    std::cout << "Введите рост " << ros << std::endl;

    ind = calculateBMI(mas, ros); // Вызов функции для расчета ИМТ.
    std::cout << round(ind * 100) / 100 << std::endl; //Вывод рассчитанного ИМТ с округлением до двух знаков после запятой.
    
    return 0;
}
