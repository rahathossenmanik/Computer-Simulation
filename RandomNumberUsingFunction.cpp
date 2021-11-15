#include<bits/stdc++.h>
using namespace std;

int main(){
    cout<<"10 Random Numbers between 1-10: ";
    for(int i=0; i<10; i++)
        cout<<rand()%10+1<<endl;
    return 0;
}
