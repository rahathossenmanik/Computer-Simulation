#include<bits/stdc++.h>
using namespace std;

int main(){
    cout<<"10 Random Numbers between 0-9."<<endl;
    cout<<"Using Function:"<<endl;
    for(int i=0; i<10; i++){
        cout<<"X["<<i+1<<"]: "<<rand()%10<<endl;
    }

    cout<<"Using Linear Congruential Method:"<<endl;
    int a = 7, c = 4, X[100], m=10;
    X[0]=3;
    for(int i=0; i<10; i++){
        cout<<"X["<<i+1<<"]: "<<(a*X[i]+c)%m<<endl;
    }

    return 0;
}
