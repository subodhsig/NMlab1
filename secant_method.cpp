#include <iostream>
#include <cmath>
using namespace std;

double Fun(double x) {
    return cos(x) + 5*x - 6;
}


void Secant(double a, double b, double error) {
    double c, fa, fb, err;
    fa = Fun(a);
    fb = Fun(b);
    int iteration = 0;
    do {
        c = a - ((a - b) / (fa - fb)) * fa;
        if (c == 0) {
            break;
        }
        a = b;
        fa = fb;
        b = c;
        fb = Fun(b);

        err = abs((c - b) / b);

        iteration++;

    } while (err > error);

    cout << "Estimated root: " << c << endl;
    cout << "Functional value at root: " << Fun(c) << endl;
    cout << "Number of iterations: " << iteration << endl;
}

int main() {
    double a, b, error;

    cout << "Enter the initial guess 'a': ";
    cin >> a;
    cout << "Enter the initial guess 'b': ";
    cin >> b;
    cout << "Enter the desired precision (error): ";
    cin >> error;

    Secant(a, b, error);

    return 0;
}
