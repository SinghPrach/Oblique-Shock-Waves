#include <iostream>
#include<fstream>
#include <cmath>
#include<math.h>
#include<iomanip>
#include<stdlib.h>
#define pi 3.141592654

using namespace std;

//We will take the value of gamma as 1.4
//We will keep value of upstream Pressure value = 1 bar


double j(double x)
{
    double a;
    a=x*180/pi;
    return a;
}

int main()
{
    cout << "We will take the value of gamma as 1.4"<< endl;
    cout<<"We will keep value of upstream Pressure value = 1 bar"<<endl;
    double Mn,M1,B,T,B1,T1,p,pu,pl,f,d,e;
    cout<<"Enter the value of M1"<<endl;
    cin>>M1;
    cout<<"Enter the lower value of downstream Pressure from which you want to start the iteration"<<endl;
    cin>>pl;
    cout<<"Enter the upper value of downstream Pressure till which you want to continue the iteration"<<endl;
    cin>>pu;
    ofstream myfile;
    myfile.open("Oblique Shock Theta Vary.csv");
    myfile <<"M1"<<","<<"Mn"<<","<<"p2"<<","<<"Theta"<<","<<"Beta"<<endl;
    for (p=pl;p<=pu;)
    {
        Mn = sqrt((p+0.167)/1.167);
        B = asin(Mn/M1);
        B1 = j(B);
        d=1.4+(cos(2*B));
        e=2+(M1*M1*d);
        f=(Mn*Mn-1)/e;
        T=atan(2*cos(B)*f/sin(B));
        T1 = j(T);
        myfile <<M1<<","<<Mn<<","<<p<<","<<T1<<","<<B1<<","<<endl;
        p = p+0.01;
    }
    cout<<"Please Check the .csv file for all the values"<<endl;
    return 0;
}
