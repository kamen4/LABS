#include <iostream>
#include <string>
#include <ctime>
using namespace std;

int how_many_zeros(int num) {
    int zeros = 0;
    while (num > 1)
        if (num % 2 == 1)
            num = (num - 1) / 2;
        else {
            num /= 2;
            zeros++;
        }
    return zeros;
}

int main()
{
    setlocale(0, "");
    const int maxsize = 100;
    int arr[maxsize];
    int n;
    cout << "Введите длинну массива (0<n<" << maxsize << "): ";
    cin >> n;
    while (n<1 || n>maxsize || cin.fail())
    {
        cin.clear();
        cin.ignore(INT16_MAX, '\n');
        cout << "\t[ОШИБКА]\n";
        cout << "Неверно введена n\n";
        cout << "Введите длинну массива (0<n<" << maxsize << "): ";
        cin >> n;
    }
    cout << "Заполнить массив динамически (иначе вручную)?\nY/N: ";
    string way = "";
    cin >> way;
    while ((way != "Y" && way != "y" && way != "N" && way != "n") || cin.fail())
    {
        cin.clear();
        cin.ignore(INT16_MAX, '\n');
        cout << "\t[ОШИБКА]\n";
        cout << "Неверные данные\n";
        cout << "Введите 'Y' или 'N': ";
        cin >> way;
    }
    if (way == "y" || way == "Y") {
        int min, max;
        cout << "Введите минимальный и максимальный элементы интервала элементов: ";
        cin >> min >> max;
        while (min >= max || min < 0 || max >= INT16_MAX || cin.fail()) {
            cin.clear();
            cin.ignore(INT16_MAX, '\n');
            cout << "\t[ОШИБКА]\n";
            if (min >= max)
                cout << "Mаксимум должен быть больше минимума\n";
            if (min <= INT16_MIN)
                cout << "Минимум должен быть больше " << INT16_MIN << "\n";
            if (max >= INT16_MAX)
                cout << "Максимум должен быть меньше " << INT16_MAX << "\n";
            cout << "Заново введите минимальный и максимальный элементы интервала элементов: ";
            cin >> min >> max;
        }
        srand(time(NULL));
        for (int i = 0; i < n; i++)
            arr[i] = rand() % (max - min + 1) + min;
    }
    else {
        cout << "Введите " << n << " элементов массива:\n";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            while (arr[i] < 0 || arr[i] >= INT16_MAX || cin.fail()) {
                cin.clear();
                cin.ignore(INT16_MAX, '\n');
                cout << "\t[ОШИБКА]\n";
                if (arr[i] <= INT16_MIN)
                    cout << "Число слишком маленькое\n";
                if (arr[i] >= INT16_MAX)
                    cout << "Число слишком большое\n";
                cout << "Введите число ещё раз: ";
                cin >> arr[i];
            }
        }
    }
    cout << "\nВаш массив:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n\n";

    int minzero = 0;
    for (int i = 0; i < n; i++)
        if (how_many_zeros(arr[i]) < how_many_zeros(arr[minzero]))
            minzero = i;
    cout << "Число с минимальным количеством нулей: " << arr[minzero] << "\n";
    return 1;
}
