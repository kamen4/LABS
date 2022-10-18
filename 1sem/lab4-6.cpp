#include <iostream>
#include <string>
#include <ctime>
using namespace std;

int main()
{
    setlocale(0, "");
    int n, m;
    cout << "Введите длинну и высоту матрицы (n>0, m>0): ";
    cin >> n >> m;
    while (n < 1 || m < 1 || cin.fail())
    {
        cin.clear();
        cin.ignore(INT16_MAX, '\n');
        cout << "\t[ОШИБКА]\n";
        cout << "Неверно введены n и m\n";
        cout << "Введите длинну и высоту матрицы (n>0, m>0): ";
        cin >> n;
    }
    int** arr = new int* [n];
    for (int i = 0; i < n; i++)
        arr[i] = new int[m];

    cout << "Заполнить матрицу динамически (иначе вручную)?\nY/N: ";
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
        srand(time(NULL));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                arr[i][j] = rand() % (max - min + 1) + min;
    }
    else {
        cout << "Введите " << n * m << " элементов матрицы (слева на право, сверху вниз):\n";
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
                while (arr[i][j] <= INT16_MIN || arr[i][j] >= INT16_MAX || cin.fail()) {
                    cin.clear();
                    cin.ignore(INT16_MAX, '\n');
                    cout << "\t[ОШИБКА]\n";
                    if (arr[i][j] <= INT16_MIN)
                        cout << "Число слишком маленькое\n";
                    if (arr[i][j] >= INT16_MAX)
                        cout << "Число слишком большое\n";
                    cout << "Введите число ещё раз: ";
                    cin >> arr[i][j];
                }
            }
    }
    cout << "\nВаша маттрица:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] < 0)
                cout << arr[i][j] << " ";
            else
                cout << " " << arr[i][j] << " ";
            if(arr[i][j] != 0)
                for (int s = 0; s < 3 - floor(log10(abs(arr[i][j]))); s++)
                    cout << " ";
            else
                cout << "   ";
        }

        cout << "\n";
    }
    cout << "\n\n";

    //сумма элементов в строках без нулей
    for (int i = 0; i < n; i++) {
        int sum = 0;
        int iszero = false;
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 0) {
                iszero = true;
                break;
            }
            sum += arr[i][j];
        }
        cout << "Строка " << i+1 << ": ";
        if (!iszero)
            cout << "сумма элементов равна " << sum << "\n";
        else
            cout << "в этой есть ноль\n";
    }

    //меняем столбец i c m-i
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m/2; j++) {
            int buf = arr[i][j];
            arr[i][j] = arr[i][m-1-j];
            arr[i][m-1-j] = buf;
        }
    
    cout << "\nВаша маттрица после замены столбцов:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] < 0)
                cout << arr[i][j] << " ";
            else
                cout << " " << arr[i][j] << " ";
            if (arr[i][j] != 0)
                for (int s = 0; s < 3 - floor(log10(abs(arr[i][j]))); s++)
                    cout << " ";
            else
                cout << "   ";
        } cout << "\n";
    } cout << "\n\n";

}
