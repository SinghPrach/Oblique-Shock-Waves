#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
#define sq(a) a*a
#include<fstream>
#include<iomanip>
#define Y 1.4 // heat capacity ratio gamma
#define pi 3.141592654
#define ESP 0.001

using namespace std;

//We will take the value of gamma as 1.4
//We will keep value of upstream Pressure value = 1 bar

double h(double x) //Theta to Radians
{
    double a;
    a=x*pi/180;
    return a;
}

double j(double x) //Radians to Theta
{
    double a;
    a=x*180/pi;
    return a;
}

int main()
{
    cout << "We will take the value of gamma as 1.4"<< endl;
    cout<<"We will keep value of upstream Pressure value = 1 bar"<<endl;
    double pl,pu,T;
    cout<<"Enter the lower value of downstream Pressure from which you want to start the iteration"<<endl;
    cin>>pl;
    cout<<"Enter the upper value of downstream Pressure till which you want to continue the iteration"<<endl;
    cin>>pu;
    cout<<"Enter the value of theta in degree"<<endl;
    cin>>T;
    double Mn1,p,a,b,c,Tr,Br,B,z,M1;
    ofstream myfile;
    myfile.open("Oblique Shock Mach Vary.csv");
    myfile <<"M1"<<","<<"Mn1"<<","<<"p2"<<","<<"Theta"<<","<<"Beta"<<endl;
    for (p=pl;p<=pu;)
    {
        a=(p-1);
        b=(Y+1)/(2*Y);
        c=1+a*b;
        Mn1=pow(c,0.5);
        int i=0;
        int j=0;
        while (j==0)
        {
            B= 1+.1*i;
            Tr=h(T);
            Br=h(B);
            M1=Mn1/sin(Br);
            float X,x,d,e,f,z;
            d=Y+cos(2*Br);
            e=2+(M1*M1*d);
            f=(Mn1*Mn1-1)/e;
            X=2*cos(Br)*f/sin(Br);
            x=tan(Tr);
            z=X-x;
            if(ESP>fabs(z))
            {
                break;
            }
            else
                i=i+1;
        }
    myfile <<M1<<","<<Mn1<<","<<p<<","<<T<<","<<B<<","<<endl;
    p = p+0.1;
    }
    return 0;
}


