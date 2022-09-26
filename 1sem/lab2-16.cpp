#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    setlocale(0,"");
    cout << "Программа определяет можно ли получить число A вычёркиванием цифр из B\n";
    cout << "Введите натуральные числа A и B (при вводе чисел < 0 знак откидывается): ";
    unsigned long long A, B; //опять всё определяет размер переменных
    cin >> A >> B;
    while (A < 1 || B < 1) {
        cout << "\n\t[ОШИБКА]\tЧисла должны быть натуральными и больше 0\n";
        cout << "Введите натуральные числа A и B: ";
        cin >> A >> B;
    }
    if (A > B) {
        cout << "\t!!!НЕЛЬЗЯ!!!\n";
        return 0;
    }
    else if (A == B) {
        cout << "\t!!!МОЖНО!!!\n\tA = B = "<< A <<"\n";
        return 0;
    }

    int lenB = (int)log10(B)+1;
    int lenA = (int)log10(A)+1;

    int a = 0, b = 0;

    //для красоты
    int* ids = new int[lenA]; //номера цифр которые не надо зачёркивать

    int ainA;
    int binB;
    while (a < lenA && b < lenB) {
        ainA = A % (int)pow(10, lenA - a) / pow(10, lenA - a - 1); //-> a-тая цифра А
        binB = B % (int)pow(10, lenB - b) / pow(10, lenB - b - 1); //-> b-тая цифра В
        if (ainA == binB) {
            ids[a] = b;
            a++;
        }
        b++;
    }
    if (a == lenA) {
        cout << "\t!!!МОЖНО!!!\n\t" << A << " получится если в\n\t" << B << " зачеркнуть:\n\t";
        for (int i = 0, id = 0; i < lenB; i++)
            if (id < lenA)
                if (ids[id] == i) {
                    cout << floor(A % (int)pow(10, lenA - id) / pow(10, lenA - id - 1));
                    id++;
                }
                else
                    cout << "X";
            else 
                cout << "X";

        cout << "\n";
    } else
        cout << "\t!!!НЕЛЬЗЯ!!!\n";
}
