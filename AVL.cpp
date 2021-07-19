#include <iostream>
#include <cstdio>

using namespace std;

class Node{
    public:
    int a;
    int LL, RL;
    Node *L, *R;
};

class AVL{
    public:
    AVL();
    int Search(int x);
    int RInsert(int x, Node*D, Node **RP);
    int Insert(int x);
    int Print(Node *C, int depth, int LR);
    Node *root;
};

AVL::AVL()
{
    root = NULL;
} 

int AVL::Search(int x)
{
    Node *D;
    D = root; 
    while(D != NULL){
        if(D->a==x){return 1;}
        else if(D->a<x) {D = D->R;}
        else {D = D->L;}
    }
    return 0;
}

int AVL::RInsert(int x, Node *D, Node **RP){
    Node *NN, *FC;
    int rv;
    if(D->a<x){
        if(D->R==NULL){
            NN = new Node;
            NN->a = x; NN->LL =0; NN->RL=0;NN->L=NULL;NN->R=NULL;
            D->R = NN; D->RL = 1;
        }
        else{
            rv = RInsert(x,D->R, &FC);
            D->R = FC;
            D->RL = rv+1;
        }
    }
    else{
        if(D->L==NULL){
            NN = new Node;
            NN->a = x; NN->LL =0; NN->RL=0;NN->L=NULL;NN->R=NULL;
            D->L = NN; D->LL = 1;
        }
        else{
            rv = RInsert(x,D->L, &FC);
            D->L = FC;
            D->LL = rv+1;
        }
    }
    if(abs(D->LL - D->RL) > 1){
        Node *LC, *RC, *T1, *T2, *T3, *T4;
        LC = D->L;RC = D->R;
        if(x < D->a && x < LC->a){//case LL 
            T1 = LC -> L;
            T2 = LC -> R;
            LC -> R = D;
            D->L = T2;
            *RP = LC;
            if(T2 == NULL) D->LL = 0;
            else D->LL = max(T2->LL, T2->RL) + 1;
            LC->RL = max(D->LL, D->RL)+1;
            return max(LC->LL, LC->RL);
        }
        else if(x<D->a && x>LC->a){//case LR
            T1 = LC -> R;
            T2 = T1 -> L; T3 = T1->R;
            T1 -> L = LC; T1 -> R = D;
            LC -> R = T2; D->L = T3;
            *RP = T1;
            if(T2 == NULL) LC->RL = 0;
            else LC->RL = max(T2->LL, T2->RL) + 1;
            if(T3==NULL) D-> LL =0;
            else D->LL = max(T3->LL, T3->RL)+1;
            T1->LL = max(LC->LL,LC->RL)+1;
            T1->RL = max(D->LL, D->RL) +1;
            return max(T1->LL, T1->RL);
        }
        else if(x>D->a && x<RC->a){//case RL
            T1 = RC -> L;
            T2 = T1 -> L; T3 = T1->R;
            T1 -> L = D; T1 -> R = RC;
            D -> R = T2; RC->L = T3;
            *RP = T1;
            if(T2 == NULL) D->RL = 0;
            else D->RL = max(T2->LL, T2->RL) + 1;
            if(T3==NULL) RC-> LL =0;
            else RC->LL = max(T3->LL, T3->RL)+1;
            T1->LL = max(D->LL,D->RL)+1;
            T1->RL = max(RC->LL, RC->RL) +1;
            return max(T1->LL, T1->RL);
        }
        else if(x>D->a && x > RC->a){//case RRA
            T1 = RC -> R;
            T2 = RC -> L;
            RC -> L = D;
            D->R = T2;
            *RP = RC;
            if(T2 == NULL) D->RL = 0;
            else D->RL = max(T2->LL, T2->RL) + 1;
            RC->LL = max(D->LL, D->RL)+1;
            return max(RC->LL, RC->RL);
        }
    }
    else{
        *RP = D;
    }
    return max(D->LL,D->RL);
}

int AVL::Insert(int x){
    Node *D, *RR;
    D = root; 
    if(D==NULL){
        D = new Node;
        D->a = x; D->LL = 0; D->RL = 0; D->L=NULL; D->R = NULL;
        root = D;
        return 1;
    }
    if(Search(x)==1) return 0;
    RInsert(x, D, &RR);
    root = RR;
    return 1;
}

int AVL::Print(Node *C, int depth, int LR)
{
    if(depth == 0){
        C = root;
        if (C==NULL){printf("---\n\n"); return 0;}
    }
    if(LR == 1){
        int i;
        for(i=0;i<depth;i++) printf("          ");
    }
    printf("---%d %03d %d",C->LL, C->a, C->RL);
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
    AVL TT;
    while(1){
        TT.Print(NULL,0,0);
        scanf(" %c", &com);
        if(com == 'q') {break;}
        else if (com=='s'){
            scanf("%d",&x);
            in = TT.Search(x);
            if(in==0) printf("Not Found. \n\n");
            else printf("Found at address \n\n");
        }
        else if(com == 'i'){
            scanf("%d",&x);
            if(TT.Insert(x)==1) printf("Insert Successful.\n");
            else printf("Insert Failed.\n");
        }
        else{
            printf("???\n");
        }
    }
    return 0;
}