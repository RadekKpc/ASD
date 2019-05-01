#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

int N=400000;

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

int part(int t[],int p,int k)
{
    int x=t[p];
    int i=p-1;
    int j=k+1;

    while(true)
    {
        do{
            i++;
        }
        while(t[i]<x);
        do{
            j--;
        }
        while(t[j]>x);

        if(i<j)
            swap(t[i],t[j]);
        else return j;

    }

}

void quicksort(int t[],int p,int k)
{
    if(p==k)return;
    int q = part(t,p,k);
    quicksort(t,p,q);
    quicksort(t,q+1,k);
    return;

}

int main()
{
    srand(time(NULL));
    int t[N];

    for(int i=0 ; i<N ;i++)
        t[i]=(rand()%40 + 1);

 //   wypisz(t);
    quicksort(t,0,N-1);
  //  wypisz(t);
    return 0;
}
