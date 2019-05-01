#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

int N=40;

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

void heapify(int t[],int i)
{

    int largest=i;
    if(2*i<N)
        if(t[2*i]>t[i])
            largest=2*i;
        else
            largest=i;
    if(2*i+1<N)
        if(t[largest]<t[2*i +1])
            largest=2*i+1;
    if(largest!=i)
    {
        swap(t[largest],t[i]);
        heapify(t,largest);
    }
    return;
}

void buildheap(int t[])
{
    for(int i=N/2; i>0; i--)
        heapify(t,i);
    return;
}

void heapsort(int t[])
{
    buildheap(t);
    for(int i=N-1; i>1; i--)
    {
        swap(t[1],t[i]);
        N--;
        heapify(t,1);
    }
}

int main()
{
    srand(time(NULL));
    int t[N];

    for(int i=0 ; i<N ; i++)
        t[i]=(rand()%40 + 1);
    t[0]=-1;
    wypisz(t);
    heapsort(t);
    N=40;
    wypisz(t);
    return 0;
}
