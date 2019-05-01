#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

int N=61;

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
int digit(int i,int x)
{
    for(int p=x;p>0;p--)
        i/=10;
    return i%10;
}
void countingSort(int t[],int x)
{
    int b[10];
    int r[N];

    for(int i=0;i<10;i++)b[i]=0;
    for(int i=0;i<N;i++)b[digit(t[i],x)]++;
    for(int i=1;i<10;i++)b[i]+=b[i-1];
    for(int i=N-1;i>=0;i--)
    {
        b[digit(t[i],x)]--;
        r[b[digit(t[i],x)]]=t[i];
    }
    for(int i=0;i<N;i++)
        t[i]=r[i];

    return;
}

void radixsort(int t[])
{
    for(int i=0;i<3;i++)
        countingSort(t,i);
    return;
}

int main()
{
    srand(time(NULL));
    int t[N];

    for(int i=0 ; i<N ;i++)
        t[i]=(rand()%900 + 100);

    wypisz(t);
    radixsort(t);
    wypisz(t);
    return 0;
}
