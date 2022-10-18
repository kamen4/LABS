#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    setlocale(0,"");
    int n, m;
    cout << "Введите размерность матрицы n на m (1 <= n и m <= 10): ";
    cin >> n >> m;
    while (n > 10 || m > 10 || n < 1 || m < 1 || cin.fail()) {
        cin.clear();
        cin.ignore(INT16_MAX, '\n');
        cout << "\t[ОШИБКА]\nВведите размерность матрицы n на m (1 <= n и m <= 10): ";
        cin >> n >> m;
    }
    int** arr = new int*[n];
    for (int i = 0; i < n; i++)
        arr[i] = new int[m];

    cout << "Введите " << n * m << " элементов матрицы:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];          

    int max = INT16_MIN;
    int maxRow;
    int min = INT16_MAX;
    int minRow;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (arr[i][j] > max) {
                max = arr[i][j];
                maxRow = i;
            }
            if (arr[i][j] <= min) {
                min = arr[i][j];
                minRow = i;
            }
        }
    cout << "\nВаш массив: \n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << setw(5) << arr[i][j] << " ";
        if (maxRow != minRow) {
            if (i == maxRow)
                cout << " <-- Тут ваш максимальный элемент равный " << max;
            else if (i == minRow)
                cout << " <-- “Тут ваш минимальный элемент равный " << min;
        }else 
            if (i == maxRow)
                cout << " <-- Тут ваши максимальный и минимальный элементы равные " << max << " и " << min;
        cout << "\n";
    }
    cout << "\n";
    if (minRow != maxRow) {
        for (int i = 0; i < m; i++)
            swap(arr[minRow][i], arr[maxRow][i]);

        cout << "Ваш массив после смены строк: \n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cout << setw(5) << arr[i][j] << " ";
            cout << "\n";
        }
    }
    else {
        cout << "Минимальный и максимальные элемент в одной строке, ничего мен¤ть не надо\n";
    }
}
