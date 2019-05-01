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

    return 0;
}
