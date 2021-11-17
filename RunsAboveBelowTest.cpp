#include<bits/stdc++.h>
using namespace std;

int main(){
    double N;
    cout<<"Number of Sample: ";
    cin>>N;
    ofstream myfile;
    myfile.open("RunsAboveBelowTest.txt");

    double Average, Run, n1, n2;
    int aboveflag, Random, Range;
    Range = 100;
    aboveflag = 0;
    Average = (Range - 1)/2;
    Run = 0;
    n1 = 0;
    n2 = 0;

    for(int i=0;i<N;i++){
        Random = rand()%Range;
        myfile<<Random<<" ";
        if(Random>Average){
            n1++;
            if(aboveflag == 0){
                Run++;
                aboveflag = 1;
            }
        }
        if(Random<Average){
            n2++;
            if(aboveflag == 1 || (aboveflag == 0 && i ==0)){
                Run++;
                aboveflag = 0;
            }
        }
    }

    double Mean, SD, Randomness, Z;
    Mean = (2*n1*n2/N) + 1/2;
    SD = sqrt(2*n1*n2*(2*n1*n2-N)/(N*N*(N-1)));
    Randomness = (Run-Mean)/SD;
    cout<<"Acceptance Region Z: ";
    cin>>Z;

    if(Randomness>-Z && Randomness<Z)cout<<"Randomness is Accepted!"<<endl;
    else cout<<"Randomness is Rejected!"<<endl;
    myfile.close();
    return 0;
}
