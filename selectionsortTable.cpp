#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

int N=40;

void selectionsort(int t[])
{
    int i=0;
    int tmp=0;
    for(int i=0; i<N; i++)
    {
        for(int j=i+1; j<N; j++)
        {
            if(t[tmp]>t[j])
                tmp=j;
        }
        swap(t[i],t[tmp]);
        tmp=i+1;
    }
    return;
}

void wypisz(int tab[])
{
    for(int i=0; i<N; i++)
    {
        cout<<tab[i]<<" ";
    }
    cout<<endl;
    cout<<"----------------------------------";
    cout<<endl;
    return;
}

int main()
{
    srand(time(NULL));
    int t[N];

    for(int i=0 ; i<N ; i++)
        t[i]=(rand()%40 + 1);

    wypisz(t);
    selectionsort(t);
    wypisz(t);
    return 0;
}
