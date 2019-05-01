#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

int N=40;
int K=12;

void wypisz(int tab[]){
    for(int i=0;i<N;i++)
    {
        cout<<tab[i]<<" ";
    }
    cout<<endl;
    cout<<"----------------------------------";
    cout<<endl;
    return;
}

void countingSort(int t[])
{
    int b[K]={};
    int result[N];

    for(int i=0;i<N;i++)b[t[i]]++;
    for(int i=1;i<K;i++)b[i]+=b[i-1];
    for(int i=0;i<N;i++)
    {
        b[t[i]]--;
        result[b[t[i]]]=t[i];
    }
    for(int i=0;i<N;i++)t[i]=result[i];
    return;
}

int main()
{
    srand(time(NULL));
    int t[N];

    for(int i=0 ; i<N ;i++)
        t[i]=(rand()%K);

    wypisz(t);
    countingSort(t);
    wypisz(t);
    return 0;
}
