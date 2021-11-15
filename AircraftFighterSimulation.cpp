#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

int main(){
	int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    double XZero, YZero, XMin, YMin, XMax, YMax;
    XZero=150, YZero=200;
    XMin=0, YMin=0;
    XMax=800, YMax=600;

    line(XMin,YZero,XMax,YZero);        //X Axis
    line(XZero,YMin,XZero,YMax);        //Y Axis

    int VF, T;
    cout<<"Speed of Fighter: ";
    cin>>VF;
    delay(3000);

    int Time[100], XB[100], YB[100];
    int XF[100], YF[100];
    ifstream myfile;
    myfile.open("AircraftSimulationInput.txt");
    int num, i;
    string s;

    i=0;
    getline(myfile, s);
    stringstream SSTime(s);
    while(SSTime >> num){
        Time[i]=num;
        i++;
    }

    i=0;
    getline(myfile, s);
    stringstream SSXB(s);
    while(SSXB >> num){
        XB[Time[i]]=num;
        i++;
    }

    i=0;
    getline(myfile, s);
    stringstream SSYB(s);
    while(SSYB >> num){
        YB[Time[i]]=num;
        i++;
    }

    int Distance, XDistance, YDistance;
    T = i-1;
    XF[0]=0, YF[0]=0;
    for(i=0;i<T;i++){
        putpixel( XB[Time[i]]+XZero , YZero-YB[Time[i]], RED );
        setfillstyle(SOLID_FILL, RED);
        circle(XB[Time[i]]+XZero , YZero-YB[Time[i]], 3);
        floodfill(XB[Time[i]]+XZero , YZero-YB[Time[i]], WHITE);

        putpixel( XF[Time[i]]+XZero , YZero-YF[Time[i]], BLUE );
        setfillstyle(SOLID_FILL, BLUE);
        circle(XF[Time[i]]+XZero , YZero-YF[Time[i]], 3);
        floodfill(XF[Time[i]]+XZero , YZero-YF[Time[i]], WHITE);
        delay(500);

        XDistance = XB[Time[i]]-XF[Time[i]];
        YDistance = YB[Time[i]]-YF[Time[i]];
        Distance = sqrt(abs(XDistance*XDistance+YDistance*YDistance));
        XF[Time[i+1]] = XF[Time[i]] + VF*XDistance/Distance;
        YF[Time[i+1]] = YF[Time[i]] + VF*YDistance/Distance;
        if(Distance<=VF){
            cout<<"Hurrah! The Bomber is Caught!"<<endl;
            setfillstyle(SOLID_FILL, BLUE);
            circle(XB[Time[i]]+XZero , YZero-YB[Time[i]], 5);
            floodfill(XB[Time[i]]+XZero , YZero-YB[Time[i]], WHITE);
            goto End;
        }
    }
    cout<<"Oops! Fighter is Failed to Catch Bomber!"<<endl;

End:
    getch();
	closegraph();
    return 0;
}
