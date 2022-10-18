#include <iostream>
#include <string>
#include <ctime>
using namespace std;


int main()
{
    setlocale(0, "");
    const int maxsize = 100;
    double arr[maxsize];
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
        while (min >= max || min <= INT16_MIN || max >= INT16_MAX || cin.fail()) {
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
        srand((unsigned int)time(NULL));
        for (int i = 0; i < n; i++)
            arr[i] = (double)(rand() % ((max - min) * 100) + min * 100) / 100;
    }
    else {
        cout << "Введите " << n << " элементов массива:\n";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            while (arr[i] <= INT16_MIN || arr[i] >= INT16_MAX || cin.fail()) {
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

    //если нельзя использовать доп массивы:
    int difr = 0; //количество различных элементов
    int firstM = -1, lastM = -1; //индекс первого и последнего отриц числа
    for (int i = 0; i < n; i++) {
        difr++;
        for (int j = 0; j < i; j++)
            if (arr[i] == arr[j]) {
                difr--;
                break;
            }

        if (arr[i] < 0) {
            if (firstM == -1)
                firstM = i;
            else
                lastM = i;
        }
    }
    double sum = 0; //сумма между отриц
    if (firstM != -1 && lastM != -1)
        for (int i = firstM + 1; i < lastM; i++)
            sum += arr[i];

    //удалить всё что меньше X
    cout << "Введите Х > 0 чтобы удалить все эллементы модуль которых меньше: ";
    double X;
    cin >> X;

    while (X <= 0 || cin.fail())
    {
        cin.clear();
        cin.ignore(INT16_MAX, '\n');
        cout << "\t[ОШИБКА]\n";
        cout << "Неверно введен X\n";
        cout << "Введите Х > 0 чтобы удалить все эллементы модуль которых меньше: ";
        cin >> X;
    }

    if (fabs(arr[n - 1]) < X) {
        arr[n - 1] = 0;
    }
    for (int i = 0; i < n-1; i++)
        if (fabs(arr[i]) <= X) {
            arr[i] = 0;
            int k = i + 1;
            while (fabs(arr[k]) <= X && k < n - 1)
                k++;
            swap(arr[i], arr[k]);
        }
            

    //вывод 
    cout << "\tКоличество разных элементов: " << difr << "\n";
    if (firstM != -1 && lastM != -1)
        cout << "\tСумма элементов между первым и последним отрицательными: " << sum << "\n";
    else
        cout << "\tВ массиве меньше двух отрицательных\n";
    cout << "\tМассив после удаления элемнтов меньших " << X <<": \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
    return 1;
}
