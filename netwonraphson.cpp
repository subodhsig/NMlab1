#include<iostream>
#include<math.h>
using namespace std;

double Fun(double x){
    return cos(x)+ 5*x - 6;
}
double derivative(double x){
    return 5 - sin(x);
}
void Newton(double a, double error){
    double x = a;
   
    
    int iteration = 0;
    while (fabs(Fun(x)) > error) {
        double fa = Fun(x);
        double fb = derivative(x);
        x = x - Fun(x) / derivative(x);
        iteration++;
    } 

    cout << "Estimated root: " << x << endl;
    cout << "Functional value at root: " << Fun(x) << endl;
    cout << "Number of iterations: " << iteration << endl;





}

int main(){
    double x,error;

    cout << "Enter the initial guess: ";
    cin >> x;

    cout << "Enter the desired precision (error): ";
    cin >> error;

    Newton(x, error);

    return 0;
}
