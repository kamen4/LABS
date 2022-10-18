#include <iostream>
#include <string>
#include <ctime>
using namespace std;

int main()
{
    setlocale(0, "");
    const int maxsize = 100;
    int arr[maxsize]{};
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
        srand(time(NULL));
        for (int i = 0; i < n; i++)
            arr[i] = rand() % (max - min + 1) + min;
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

    //поиск мин по модулю элемента и суммы после нулегого
    int buf = arr[0];
    int  sum = -1;
    for (int i = 0; i < n; i++) {
        if (abs(arr[i]) < abs(buf))
            buf = arr[i];
        if (arr[i] == 0)
            sum = 0;
        if (sum != -1)
            sum += arr[i];
    }
    cout << "\tМинимальный по модулю элемент: " << buf << "\n";
    if (sum != -1)
        cout << "\tСумма элементов после последнего нулевого: " << sum << "\n";
    else
        cout << "\tЭлемента равного нулю нет!\n";
    
    //разбить массив на четные-нечетные
    int k = 0; //индекс чётного
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            buf = arr[i];
            if(i != k)
                for (int j = i; j > k; j--)
                    arr[j] = arr[j - 1];
            arr[k] = buf;
            k++;
        }    
    }
    cout << "\tМассив разделен на четные (их " << k << "):\n";
    for (int i = 0; i < k; i++)
        cout << arr[i] << " ";
    cout << "\n";
    cout << "\tи нечетные (их " << n-k << "):\n";
    for (int i = k; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
    cout << "\tВесь массив:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
    return 1;
}
