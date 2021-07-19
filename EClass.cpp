#include <iostream>
#include <cstdio>

using namespace std;

class Node{
    public:
    int a;
    Node *n;
};

class List{
    public:
    List();
    int Insert(int x);
    void Zero();
    int Next();
    int Z;
    Node *head;
    Node *curr;
};

List::List() {head = NULL; curr = head;}


int List::Insert(int x){
    Node *NN;
    NN = new Node;
    NN->a=x;
    NN->n=head;
    head=NN;
    return 1;         
}

void List::Zero(){
    Z=1;
}

int List::Next(){
    if (Z==1){Z=0; curr = head; }
    else{curr = curr->n; }
    if(curr == NULL) return 0;
    else return curr -> a;
}

int V[1000];
List Lk[1000];
int SK[1000];
int SP;

void Push(int x){SK[SP] = x; SP++;}
int Pop(){SP--; return SK[SP];}
bool IsEmpty(){return SP == 0;}
int main(){ 
    int n, m, i, cur, x, y, nn;
    Node *T;
    scanf("%d %d",&n, &m);
    for (i=0; i<m; i++){
        scanf("%d %d", &x, &y);
        Lk[x].Insert(y);
        Lk[y].Insert(x);
    }
    for(i=1; i<=n;i++) Lk[i].Zero();
    for(i=1;i<=n;i++){
        if(V[i] == 0){
            cur = i; V[cur] = 1; printf("%d ", cur);
            while(1){
                if((nn = Lk[cur].Next()) != 0 ){
                    if(V[nn] == 0){
                        Push(cur); cur =nn; V[cur] =1;
                        printf("%d  ", cur);
                    }
                }
                else{
                    if(IsEmpty()) {break;}
                    else{
                        cur = Pop();
                    }
                }
                
            }
            printf("\n");
        }
    }
    /*for (i=1; i<n; i++){
        T = Lk[i].First ();
        while(T != NULL){
            printf("%d  ", T->a);
        }
        printf("\n");
    }*/
    return 0;
}