#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

int N=40000;

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
void bubblesort(int tab[])
{
    for(int i=N;i>0;i--)
    {
        for(int j=0;j<i-1;j++)
            if(tab[j]>tab[j+1])
                swap(tab[j],tab[j+1]);

    }
    return;
}
int main()
{
    srand(time(NULL));
    int t[N];

    for(int i=0 ; i<N ;i++)
        t[i]=(rand()%40 + 1);

   // wypisz(t);
    bubblesort(t);
   // wypisz(t);
    return 0;
}
