#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
using namespace std;

int max_sequence_len(int* arr, int arrlen) {
    int max_s_len = 1, cur_s_len = 1;
    for (int i = 1; i < arrlen; i++) {
        if (arr[i - 1] < arr[i])
            cur_s_len++;
        else {
            if (cur_s_len > max_s_len)
                max_s_len = cur_s_len;
            cur_s_len = 1;
        }
    }
    return max_s_len;
}   

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
        srand((unsigned int)time(NULL));
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
    cout << "\nВаша матрица:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << setw(5) << arr[i][j] << " ";
        cout << "\n";
    }
    cout << "\n\n";

    int whithoutzero = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            if (arr[j][i] == 0)
                break;
            if (j == n - 1)
                whithoutzero++;
        }
    int max_len = 0;
    int max_len_num = 0;
    for (int i = 0; i < n; i++){
        int msl = max_sequence_len(arr[i], m);
        if (msl > max_len) {
            max_len = msl;
            max_len_num = i;
        }
    }
            

    cout << "Здесь "<< whithoutzero <<" столбцов без нулей\n";
    cout << "Строка содержащая самму длинную (длинна: "<<max_len<<") строговозрастающую последовательность под номером: " << max_len_num+1 << "\n";
}
