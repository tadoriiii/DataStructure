#include <iostream>
#include <cstdio>

using namespace std;

int n;
int A[1000];
int Find(int p){
    int r, t, r2;
    r = p;
    while(A[r]!=0){
        r = A[r];
    }
    r2 = r;
    r = p;
    while(A[r]!=0){
        t = r;
        r = A[r];
        A[t] = r2;
    }
    return r;
}

void Union(int p, int q){
    int pr, qr;
    pr = Find(p); qr = Find(q);
    A[qr] = pr;
    return;
}

int main(){
    int i, p, q;
    char com;
    printf("size? :");
    scanf("%d" , &n);
    while(1){
        for(i=1;i<=n;i++)
            printf("%4d", A[i]);
        printf("\n");
        scanf(" %c", &com);
        if (com == 'q') {break;}
        else if (com == 'u'){
            scanf("%d %d", &p, &q);
            Union(p,q);
        }
        else if (com == 'f'){
            scanf("%d", &p);
            q = Find(p);
            printf("result = %d\n", q);
        }
        else{
            printf("???\n");
        }
    }
    return 0;
}