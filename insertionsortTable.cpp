#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

int N=40;

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

void insertionsort(int t[]){

    for(int i=1;i<N;i++){
            int j=0;
            while(t[i]>t[j] && j<= i)j++;
            int tmp=t[i];
            for(int k=i;k>j;k--)
                t[k]=t[k-1];
            t[j]=tmp;
    }
    return;
}

int main()
{
    srand(time(NULL));
    int t[N];

    for(int i=0 ; i<N ;i++)
        t[i]=(rand()%40 + 1);

    wypisz(t);
    insertionsort(t);
    wypisz(t);
    return 0;
}
