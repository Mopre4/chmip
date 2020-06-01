#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

double F(double x){
    return (x / (sqrt(x*x + 1))) - 0.5;
}
double dF(double x){
    return -((x*x)/(pow(x*x+1, 1.5))) + 1/(sqrt(x*x+1));
}

double d2F(double x){
    return (3*x*(((x*x)/(x*x+1)) -1))/ (pow(x*x+1, 1.5));
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
            x = b;
        } else x = a;
        if(x == b){
            b=a;
            a=x;
        }
        cout << "===================================================" << endl;
        cout << "Значение параметра m = " << m << endl;
        cout << "===================================================" << endl;

        cout << "===================================================" << endl;
        cout << "Начальное приближение х0 = " << x << endl;
        cout << "===================================================" << endl;

        cout <<  "Xi" <<right << setw(23)<<"f(xi)" <<setw(23) << "|f(xi)/m|" <<endl;
        while ( fabs(F(x))/m > e){
            cout << fixed << setprecision(8)<< x <<  setw(20) << fixed <<
            setprecision(7)<< F(x)<< setw(18)<< fabs(F(x)/m) << endl;
            x = x-F(x)/(F(x)-F(b))*(x-b);
        }
        cout << "===================================================" << endl;
        cout << "Значение корня с точностью " << setprecision(7)<< e << " = " << x << endl;
        cout << "===================================================" << endl;
    }
    else cout << "На заданном интервале нет корней\n";
    return 0;
}