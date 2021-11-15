#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cout<<"Number of Sample: ";
    cin>>N;

    ofstream myfile;
    myfile.open("UniformityTestChiSquare.txt");

    int RandomNumber, RangeNumber, Range, RangeDiff;
    RangeNumber = 5;
    Range = 100;
    RangeDiff = Range/RangeNumber;

    int Observed[RangeNumber];
    for(int i=0;i<RangeNumber;i++)Observed[i]=0;
    for(int i=0;i<N;i++){
        RandomNumber = rand()%Range;
        Observed[RandomNumber/RangeDiff]++;
        myfile<<RandomNumber<<" ";
    }

    int Expected[RangeNumber];
    double ChiSQ = 0;
    for(int i=0;i<RangeNumber;i++){
        Expected[i]=N/RangeNumber;
        ChiSQ = ChiSQ + pow((Expected[i]-Observed[i]),2)/Expected[i];
    }
    if(ChiSQ>0.207 && ChiSQ<14.860)cout<<"Randomness is Accepted!"<<endl;
    else cout<<"Randomness is Rejected!"<<endl;
    myfile.close();
    return 0;
}
