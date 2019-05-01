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
void selectionsort(node *& l)
{
    node * w = new node;
    w->next=l;
    l=w;

    node * result =NULL;

    while(w->next!=NULL)
    {
        node * p=w;
        node * q=w->next;
        node * r=p;
        int maks=-1;
        while(q!=NULL)
        {

            if(q->w>maks)
            {
                maks=q->w;
                r=p;
            }
            p=q;
            q=q->next;
        }
        node * tmp = r->next;
        r->next=r->next->next;
        tmp->next=result;
        result=tmp;


    }

    node * tmp=l->next;
    delete(l);
    l=result;
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
    selectionsort(p);
    wypisz(p);
    return 0;
}
