#include<iostream>
#include<math.h>
using namespace std;

double Ofunction(double x){
    return cos(x)+5*x-6;
}
void bisection(double a , double b , double error ){
    double fa = Ofunction(a);
    double fb = Ofunction(b);

    if(fa*fb>=0){
        cout<<"Cannot find root\n";
        return;
    }
    int iteration =0;
    double c,fc;
    do{
        c = (a+b)/2;
        fc = Ofunction(c);

        if(fa*fc<0){
            b = c;
            fb = fc;
        }
        else{
            a =c;
            fa = fc;
        }
        iteration++;
        

    }while(fabs(fc)>error);

    cout<<"Estimated end root is: "<<c<<"\n Functional value is: "<<fc;
    cout<<"\nNumber of iteration is: "<<iteration;


}
int main(){
    double a,b,error;
    cout<<"Enter the  interval a and b";
    cin>>a>>b;
    cout<<"Enter the desired error: ";
    cin>>error;
    
    bisection(a,b,error);


    return 0;
}
