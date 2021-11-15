#include<bits/stdc++.h>
using namespace std;

int main(){
    double N;
    cout<<"Number of Sample: ";
    cin>>N;
    ofstream myfile;
    myfile.open("RunsAboveBelowTest.txt");

    double Average, Run, n1, n2;
    int aboveflag, Random1, Random2, Range;
    Range = 100;
    aboveflag = 0;
    Average = (Range - 1)/2;
    Run = 0;
    n1 = 0;
    n2 = 0;

    Random1 = rand()%Range;
    myfile<<Random1<<" ";
    if(Random1>Average)n1++;
    else n2++;

    for(int i=1;i<N;i++){
        Random2 = rand()%Range;
        myfile<<Random2<<" ";
        if(Random2>Average)n1++;
        else n2++;

        if(Random2>Random1 && aboveflag == 0){
            Run++;
            aboveflag = 1;
        }
        if(Random2<Random1 && aboveflag == 1){
            Run++;
            aboveflag = 0;
        }
        Random1 = Random2;
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
