#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

int main(){
	int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    double XZero, YZero, XMin, YMin, XMax, YMax;
    XZero=100, YZero=400;
    XMin=0, YMin=0;
    XMax=800, YMax=600;

    line(XMin,YZero,XMax,YZero);        //X Axis
    line(XZero,YMin,XZero,YMax);        //Y Axis

    double AQuantity, BQuantity, CQuantity;
    cout<<"Quantity of A: ";
    cin>>AQuantity;
    cout<<"Quantity of B: ";
    cin>>BQuantity;
    CQuantity=0;

    double K1, K2, dt, T;
    cout<<"Reaction Constants (K1, K2): ";
    cin>>K1>>K2;
    dt = 0.01;
    T = 5;
    delay(15000);

    for(double t=0; t<T; t=t+dt){

        putpixel(t/dt+XZero , YZero-AQuantity , BLUE );    //A Quantity
        putpixel(t/dt+XZero , YZero-BQuantity , BLUE );    //B Quantity
        putpixel(t/dt+XZero , YZero-CQuantity , BLUE );    //A & B Initial Quantity
        delay(20);

        AQuantity = AQuantity + (K2*CQuantity - K1*AQuantity*BQuantity)*dt;
        BQuantity = BQuantity + (K2*CQuantity - K1*AQuantity*BQuantity)*dt;
        CQuantity = CQuantity + (2*K1*AQuantity*BQuantity - 2*K2*CQuantity)*dt;
    }
    getch();
	closegraph();
    return 0;
}
