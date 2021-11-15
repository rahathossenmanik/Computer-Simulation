#include<bits/stdc++.h>
using namespace std;

int main(){
    int a = 37, c = 19, X[100], m=100;
    X[0]=10;
    for(int i=1; i<10; i++){
        cout<<"A random Number between 1-100: "<<(a*X[i-1]+c)%m<<endl;
    }
    return 0;
}
