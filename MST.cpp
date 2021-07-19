#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int n, m;
int A[1000];
class Edge{
public:
    int a, b, w;
    bool operator < (const Edge&k) const
    {
        return w < k.w;
    }
};
Edge E[1000];
int Use[1000];
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
vector<pair<int,int> >Ad[1000];
int Print(int nd, int depth, int wei, int pr, int LR){
    int j, cnt;
    if (LR>0){
        int i;
        for(i=0;i<depth-1;i++) printf("           ");
        printf("       ");
    }
    if(depth==0){
        printf("--[%02d]" ,nd);
    }
    else{
        printf("--(%02d)--[%02d]", wei, nd);
    }
    cnt = 0;
    for(j=0;j<Ad[nd].size();j++){
        if(Ad[nd][j].first!=pr){
            Print(Ad[nd][j].first, depth+1, Ad[nd][j].second, nd, cnt);
            cnt++;
        }
    }
    if(cnt == 0) printf("\n");
    return 0;
}

int main(){
    int i, cnt, pr, qr;
    scanf("%d %d", &n, &m);
    for(i=1;i<=m;i++)
        scanf("%d %d %d", &E[i].a, &E[i].b, &E[i].w);
    sort(E+1, E+m+1);
    // for(i=1;i<=m;i++) printf("%d %d %d", &E[i].a, &E[i].b, &E[i].w);
    cnt = 0; i=1;
    while(cnt<n-1){
        if(i>m){
            printf("Not Connected! \n"); exit(1);
        }
        pr = Find(E[i].a);
        qr = Find(E[i].b);
        if(pr == qr){}
        else{
            cnt++;
            Use[i] = 1;
            Union(E[i].a,E[i].b);
        }
        i++;
    }
    printf("\nResult->\n");
    for(i=1;i<=m;i++)
        if(Use[i]== 1)
            printf("%d %d %d\n", E[i].a, E[i].b, E[i].w);
    printf("\nTree->\n");
    for(i=1;i<=m;i++){
        if(Use[i]){
            Ad[E[i].a].push_back(make_pair(E[i].b, E[i].w));
            Ad[E[i].b].push_back(make_pair(E[i].a, E[i].w));
        }
    }
    Print(1,0,0,0,0);
    return 0;
}