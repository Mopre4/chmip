#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

double F(double x){
    return x*x*x-0.2*x*x+0.3*x-1.2;
}

double dF(double x){
    return 3*x*x-0.4*x +x*0.3;
}

double d2F(double x){
    return 6*x-0.4;
}

int rootFind(double a, double b, double step){
    int countRoot = 0;
    for(double x = a; x <= b- step; x +=step) {
        double y1 = F(x);
        double y2 = F(x + step);
        if (y1 * y2 <= 0) {
            ++countRoot;
            cout << "Корни находятся на интервале от " << x << " до "
            << x + step << endl;
        }
    }
    return countRoot;
}

int main() {
    double a_root, b_root, step;
    cout<<("Введите концы интервала для локализации корней: ") << endl;
    cout << "A: ";
    cin >> a_root;
    cout << "B: ";
    cin >> b_root;
    cout << ("Введите шаг Step: ");
    cin >> step;
    if(rootFind(a_root, b_root, step) > 0) {
        double a, b, e, m, x;
        cout << "===================================================" << endl;
        cout << "Введите концы интервала для нахождения корня " <<endl;
        cout << "A: ";
        cin >> a;
        cout << "B: ";
        cin >> b;
        cout << "Введите точность e: ";
        cin >> e;

        if(fabs(dF(a)) < fabs(dF(b))){
            m = fabs(dF(a));
        } else m = fabs(dF(b));

        if(F(a)*d2F(a) > 0) {
            x = a;
        } else x = b;

        cout << "===================================================" << endl;
        cout << "Значение параметра m = " << m << endl;
        cout << "===================================================" << endl;

        cout << "===================================================" << endl;
        cout << "Начальное приближение х0 = " << x << endl;
        cout << "===================================================" << endl;

        while (fabs(F(x)) / m > e){
            x = x - F(x)/dF(x);
        }

        cout << "===================================================" << endl;
        cout << "Значение корня с точностью " << setprecision(5)<< e << " = " << x << endl;
        cout << "===================================================" << endl;
    }
    else cout << "На заданном интервале нет корней\n";
    return 0;
}