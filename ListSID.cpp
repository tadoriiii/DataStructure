#include <iostream>
#include <cstdio>

using namespace std;

class Node{
    public:
    int a;
    Node *n;
};

Node DS,DE;

class List{
    public:
    List();
    int Search(int x, Node **P, Node **L);
    int Insert(int x);
    int Delete(int x, Node **D);
    int Print();
    Node *head;
};

List::List() {head = &DS; DS.n = &DE; DS.a=-100; DE.a=1000000; DE.n=NULL;}

int List::Search(int x, Node **P, Node **L)
{
    *L = head; 
    while(*L != NULL){
        if((*L)->a<x){
            *P = *L;
            *L = (*L) -> n;
        }
        else if((*L)->a==x){
            return 1;
        }
        else{
            return 0;
        }
    }
    return 0;
}

int List::Insert(int x){
    Node *P,*L,*NN;
    if(Search(x, &P, &L)==0){
        NN = new Node;
        NN->a=x;
        NN->n=L;
        P->n=NN;
        return 1;         
    }
    else{
        return 0;
    }
}

int List::Delete(int x, Node **D){
    Node *P,*L;
    if(Search(x, &P, &L)==1){
        *D = L;
        P->n = L->n;
        return 1;
    }
    else return 0;
}

int List::Print()
{
    Node *C;
    C = head;
    while(C!=NULL){
        printf("%d -> ", C->a);
        C = C->n;
    }
    printf("\n");
    return 0;
}

int main(){ 
    char com;
    int x, in ;
    Node *Temp, *P, *L;
    List LL;
    while(1){
        LL.Print();
        scanf(" %c", &com);
        if(com == 'q') {break;}
        else if (com=='s'){
            scanf("%d",&x);
            in = LL.Search(x, &P, &L);
            if(in==0) printf("Not Found. \n\n");
            else printf("Found at address %x\n\n", L);
        }
        else if(com == 'i'){
            scanf("%d",&x);
            if(LL.Insert(x)==1) printf("Insert Successful.\n");
            else printf("Insert Failed.\n");
        }
        else if(com == 'd'){
            scanf("%d", &x);
            if(LL.Delete(x,&Temp)==1) printf("Delete Successful.\n");
            else printf("Delete Failed.\n");
        }
        else{
            printf("???\n");
        }
    }
    return 0;
}