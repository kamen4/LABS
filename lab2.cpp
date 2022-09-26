lab#include <iostream>

using namespace std;

/*
* @param n - количество чисел которые надо вывести
* @param counter - количество выведенных чисел 
* @param prev - предыдущее число
* @param pprev - предпредыдущее число
*/
void fibonachi(int n, int counter = 0, unsigned long long prev = 1, unsigned long long pprev = 1) {
    //в зависимости от размера переменных prev и pprev может выводиться разнное максимальное число
    //при "unsigned long long" - 12.200.160.415.121.876.738 под номером 93 т к далее переполняется ячейка переменной
    //ведь максимальное значение unsigned long long (u_int64) - 2^64 = 18.446.744.073.709.551
    //число под номером 93 уже не влазит в unsigned long long, но может посчитаться и вывестись компилятором
    if (n == 1) {
        cout << "1:\t1\n";
        return;
    }
    else if (counter == 0) {
        cout << "1:\t1\n2:\t1\n";
        counter = 2;
    }

    if (n<=counter) {
        cout << "\n";
        return;
    }else {
        counter++;
        cout << counter << ":\t" << prev + pprev << "\n";
        fibonachi(n, counter, pprev, pprev + prev);
        return;
    }
}

int main()
{
    setlocale(0,"");
    int N;
    cout << "Введите количество чисел Фибоначчи которые вы хотите видеть [1;93]: ";
    cin >> N;
    while (N<1 || N>93)
    {
        cout << "Количство должно быть больше 0 и меньше 94!!!\nВведите новое число: ";
        cin >> N;
    }
    fibonachi(N);
}
