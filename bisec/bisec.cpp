#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;


double F(double x){
    return x*x*cos(2*x) + 1;
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
        double a, b, c, e;
        cout << "===================================================" << endl;
        cout << "Введите концы интервала для нахождения корня " <<endl;
        cout << "A: ";
        cin >> a;
        cout << "B: ";
        cin >> b;
        cout << "Введите точность: ";
        cin >> e;
        while (b - a > 2 * e) {
            c = (a + b) / 2;
            if (F(a) * F(c) > 0) {
                cout << c << "....." << b << endl;
                a = c;
            } else {
                cout << a << "....." << c << endl;
                b = c;
            }
        }
        cout << "===================================================" << endl;
        cout << "Значение корня с точностью " << e << " равно " << (a + b) / 2 << endl;
        cout << "===================================================" << endl;
    }
    else cout << "На заданном интервале нет корней\n";
    return 0;
}