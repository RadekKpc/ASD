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

void boublesort(node * &l)
{

    node * p = new node;
    p->next=l;
    l = p;
    node * r;
    node * k;
    node * pivot=NULL;



    while(pivot!= l->next)
    {
        k=l;
        r=l->next;

        while(r->next!=pivot)
        {

            if(r->w > r->next->w)
            {
                node * tmp =r->next;
                r->next=tmp->next;
                tmp->next=r;
                k->next=tmp;
                r=tmp;
            }

            k=r;
            r=r->next;
        }

        pivot=r;

    }
    node * tmp = l->next;
    delete(l);
    l=tmp;
    return ;
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
    q->next=NULL;

    wypisz(p);
    boublesort(p);
    cout<<"====================="<<endl;
    wypisz(p);
    return 0;
}
