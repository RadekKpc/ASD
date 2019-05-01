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

void insertionsort(node *& p)
{

    node * q =new node;
    q->next=p;
    p=q;
    q=q->next;

    node * r=new node;
    r->w=-1;
    r->next=NULL;

    while(q!=NULL)
    {
        node * l = r;
        while(l->next==NULL ? false : l->next->w < q->w)
            l=l->next;

        p->next=p->next->next;

        q->next=l->next;
        l->next=q;

        q=p->next;

    }

    node * tmp=r->next;
    delete(r);
    p=tmp;

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
    insertionsort(p);
    wypisz(p);
    return 0;
}
