#include <iostream>
#include <cstdio>

using namespace std;

class Node{
    public:
    int a;
    Node *L, *R;
};

class BST{
    public:
    BST();
    int Search(int x, Node **P, Node **D);
    int Insert(int x);
    int Delete(int x);
    int Print(Node *C, int depth, int LR);
    Node *root;
};

BST::BST()
{
    root = new Node;
    root->a=999;
    root->L=NULL;
    root->R=NULL;
}

int BST::Search(int x, Node **P, Node **D)
{
    *D = root; *P = NULL;
    while(*D != NULL){
        if((*D)->a==x){return 1;}
        else if((*D)->a<x) {*P=*D; *D = (*D)->R;}
        else {*P=*D; *D = (*D)->L;}
    }
    return 0;
}

int BST::Insert(int x){
    Node *P,*D,*NN;
    if(Search(x, &P, &D)==0){
        NN = new Node;
        NN->a=x; NN->L = NULL; NN->R = NULL;
        if(P->a<x) P->R = NN;
        else P->L = NN;
        return 1;         
    }
    else{
        return 0;
    }
}

int BST::Delete(int x){
    Node *P,*D;
    if(Search(x, &P, &D)==1){
        if(D->L == NULL&& D->R == NULL){
            if(D==P->L) P->L = NULL;
            else P->R = NULL;
            delete D;
        }
        else if(D->L == NULL&& D->R != NULL){
            if(D==P->L) P->L = D->R;
            else P->R = D->R;
            delete D;
        }
        else if(D->L != NULL&& D->R == NULL){
            if(D==P->L) P->L = D->L;
            else P->R = D->L;
            delete D;
        }
        else{
            Node *RLL, *RLLP;
            RLL = D->R; RLLP = 0;
            while(RLL -> L != NULL){
                RLLP = RLL; RLL = RLL -> L;
            }
            D->a = RLL->a;
            if(RLL->L == NULL&& RLL->R == NULL){
                if(RLL==RLLP->L) RLLP->L = NULL;
                else RLLP->R = NULL;
                delete RLL;
            }
            else if(RLL->L == NULL&& RLL->R != NULL){
                if(RLL==RLLP->L) RLLP->L = RLL->R;
                else RLLP->R = RLL->R;
                delete RLL;
            }
        }
        return 1;
    }
    else return 0;
}

int BST::Print(Node *C, int depth, int LR)
{
    if(depth == 0){
        C = root;
    }
    if(LR == 1){
        int i;
        for(i=0;i<depth;i++) printf("      ");
    }
    printf("---%03d",C->a);
    if(C->L != NULL){
        Print(C->L,depth+1,0);
    }
    else printf("\n");
    if(C->R != NULL){
        Print(C->R, depth+1,1);
    }
    else ;
    return 0;
}

int main(){ 
    char com;
    int x, in ;
    Node *P, *D;
    BST TT;
    while(1){
        TT.Print(NULL,0,0);
        scanf(" %c", &com);
        if(com == 'q') {break;}
        else if (com=='s'){
            scanf("%d",&x);
            in = TT.Search(x, &P, &D);
            if(in==0) printf("Not Found. \n\n");
            else printf("Found at address %x\n\n", D);
        }
        else if(com == 'i'){
            scanf("%d",&x);
            if(TT.Insert(x)==1) printf("Insert Successful.\n");
            else printf("Insert Failed.\n");
        }
        else if(com == 'd'){
            scanf("%d", &x);
            if(TT.Delete(x)==1) printf("Delete Successful.\n");
            else printf("Delete Failed.\n");
        }
        else{
            printf("???\n");
        }
    }
    return 0;
}