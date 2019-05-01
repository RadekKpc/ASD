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


void scal(int t[],int p,int s,int k)
{
    int r[k-p];
    int i=0;
    int wp=p;
    int wk=s+1;

    while(wp<=s&& wk<=k)
    {
        if(t[wp]<t[wk])
        {   r[i]=t[wp];
            wp++;
        }
        else{
            r[i]=t[wk];
            wk++;
        }
        i++;
    }
    while(wp<=s)
    {
        r[i]=t[wp];
        i++;
        wp++;
    }
    while(wk<=k)
    {
        r[i]=t[wk];
        i++;
        wk++;
    }

    for(i=0;p<=k;p++,i++)
        t[p]=r[i];
}

void mergesort(int t[],int p,int k)
{
    if(k-p==0)return;
    int s=(p+k)/2;
    mergesort(t,p,s);
    mergesort(t,s+1,k);
    scal(t,p,s,k);
    return;
}

int main()
{
    srand(time(NULL));
    int t[N];

    for(int i=0 ; i<N ;i++)
        t[i]=(rand()%40 + 1);

    wypisz(t);
    mergesort(t,0,N-1);
    wypisz(t);
    return 0;
}
