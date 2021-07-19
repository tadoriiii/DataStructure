#include <iostream>
#include <cstdio>

using namespace std;
int lef, rig;
int Search(int a[], int n, int x)
{
    int l, r, m;
    l=0; r=n-1;
    while( l<=r){
        m=(l+r)/2;
        if(a[m]==x) {return m;}
        else if (a[m]<x){l=m+1;}
        else {r=m-1;}
    }
    lef = r ; rig= l; return -1;
}

int Insert(int a[], int n, int x)
{
    int i;
    if(Search(a,n,x) == -1){
        for(i=n-1;i>=rig;i--)
            a[i+1] = a[i];
        a[rig] = x;
        return 0;
    }
    return -1;
}
int Delete(int a[], int n , int x)
{
    int i, j;
    i = Search(a,n,x);
    if(i== -1) return -1;
    else{
        for(j=1; j<n-1;j++)
            a[j] = a[j+1];
        return 0;
    }
    return 0;
}

int main()
{
    int arr[100]; int n=0; int S=100;
    
    int i, in, x;
    char com;
    for(i=0; i< S;i++) arr[i] = -1;
    //arr[0] = 1; arr[1]=5;arr[2]=8; n=3;
    while(1){
        //print array
        for(i=0;i<=n;i++)printf("|%4d",i);
        printf("|\n");
        for(i=0;i<=n;i++) printf("|%4d",arr[i]);
        printf("|\n");
        scanf(" %c", &com);
        if(com=='q'){break;}
        else if(com=='s'){
            scanf("%d", &x);
            in = Search(arr,n,x);
            if (in == -1) printf("Not Found. left = %d, right =%d\n\n", lef, rig);
            else printf("Found at index %d\n\n",in);
        }
        else if(com=='i'){
            scanf("%d", &x);
            if(Insert(arr,n,x)==0)
                n++;
        }
        else if(com=='d'){
            scanf("%d", &x);
            if(Delete(arr, n, x)==0)
                n--;
        }
        else{
            printf("???\n");
        }
    }
    return 0;
}