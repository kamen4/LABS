#include <iostream>

using namespace std;

//наибольший общий делитель
int NOD(int a, int b) { 
    if (a < b)
        swap(a, b);

    while (a % b != 0) {
        a = a % b;
        swap(a, b);
    }
    return b;
}

int main()
{
    setlocale(0, "");
    cout << "Введите N (число до которого будет натуральный знаменатель - >2): ";
    int N, c = 1;
    cin >> N;
    while (N <= 2) {
        cout << "\n\tНеверно введено N\n";
        cout << "Введите N (число до которого будет натуральный знаменатель - >2): ";
        cin >> N;
    }

    //  n/d
    //вычисление количества таких дробей
    for (int d = 2; d < N; d++)
        for (int n = 1; n < d; n++)
            if (NOD(d, n) == 1) {
                cout << c << ":\t" << n << "/" << d << "\n";
                c++;
            }
    cout << "\n\t[СОРТИРОВКА]\n\n";

    //запись числителей и знаменателей в массивы 
    int* arrN = new int[c];
    int* arrD = new int[c];
    c = 0;
    for (int d = 2; d < N; d++)
        for (int n = 1; n < d; n++)
            if (NOD(d, n) == 1) {
                arrN[c] = n;
                arrD[c] = d;
                c++;
            }


    //сортировка пузырьком
    double frJ, frJ1;
    for (int i = 0; i < c - 1; i++)
        for (int j = 0; j < c - i - 1; j++) {
            frJ = (double)arrN[j] / arrD[j];          //j-тая дробь
            frJ1 = (double)arrN[j + 1] / arrD[j + 1]; //j+1-ая

            if (frJ > frJ1) {
                swap(arrN[j], arrN[j + 1]);
                swap(arrD[j], arrD[j + 1]);
            }
        }
    
    //вывод
    for (int i = 0; i < c; i++) {
        cout << i+1 << ":\t" << arrN[i] << "/" << arrD[i] << "\n";
    }
}
