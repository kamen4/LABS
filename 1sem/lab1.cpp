#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

#define PI 3.14159265358

int main()
{
    setlocale(0,"");
    while (true)
    {
        int k = 0, n = 0;
        double e, x, xn = 1, sum = 1;
        while (k <= 1) {
            cout << "Введите порядок точности 10^-k (k>0)  k: ";
            cin >> k;
        }
        e = pow(10, -k);

        cout << "Введите x в градусах: ";
        cin >> x;
        x = fabs(x);
        while (x > 360)
            x -= 360;
        x = x / 180 * PI;

        while (e < fabs(xn)) {
            n++;
            xn = xn * (-1) * x * x / (2 * n * (2 * n - 1));
            sum += xn;
        }

        cout << "\tМой cos(): " << setprecision(k) << fixed << sum
            << " <-> cmath.cos(): " << cos(x) << "\n\n";
    }
}
