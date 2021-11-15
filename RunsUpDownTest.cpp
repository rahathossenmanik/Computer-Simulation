#include<bits/stdc++.h>
using namespace std;

int main(){
    double N;
    cout<<"Number of Sample: ";
    cin>>N;
    ofstream myfile;
    myfile.open("RunsUpDownTest.txt");

    int Random1, Random2, Run, Range, upflag;
    upflag = 0;
    Range = 100;
    Run = 0;
    Random1 = rand()%Range;
    myfile<<Random1<<" ";

    for(int i=1;i<N;i++){
        Random2 = rand()%Range;
        myfile<<Random2<<" ";

        if(Random2>Random1 && upflag == 0){
            Run++;
            upflag = 1;
        }
        if(Random2<Random1 && upflag == 1){
            Run++;
            upflag = 0;
        }
        Random1 = Random2;
    }

    double Mean, SD, Randomness, Z;
    Mean = (2*N-1)/3;
    SD = sqrt((16*N-29)/90);
    Randomness = (Run-Mean)/SD;
    cout<<"Acceptance Region Z: ";
    cin>>Z;

    if(Randomness>-Z && Randomness<Z)cout<<"Randomness is Accepted!"<<endl;
    else cout<<"Randomness is Rejected!"<<endl;
    myfile.close();
    return 0;
}
