#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;
int N=40;
struct node{
    int w;
    node * next=NULL;

};

void wypisz(node * p){
    while(p!=NULL)
    {
        cout<<p->w<<" ";
        p=p->next;
    }
    cout<<endl<<"---------------------------"<<endl;
    return;
}

void quicksort(node * w,node * k)
{

    node * p=w;
    node * q=w->next;

    if(q==k) return;

    while(p==k ? false : p->next!=NULL && p->next!=k)
    {
    if(p->next->w<q->w)
       {
           cout<<p->next->w<<endl;
           node * tmp =p->next;
           p->next=p->next->next;
           tmp->next=w->next;
            w->next=tmp;

       }
    else
        {
        p=p->next;
        }
    }


   quicksort(w,q);
   quicksort(q,k);

   return;
}

int main()
{
    srand(time(NULL));
    node * p = new node;
    node * q = p;

    for(int i=0 ; i<N ;i++){
        q->w=rand()%40 + 1;
        q->next=new node;
        q=q->next;
    }
    q->w=4;

    wypisz(p);
    quicksort(p,NULL);
    wypisz(p);

    return 0;
}
