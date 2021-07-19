 #include <iostream>
#include <cstdio>

using namespace std;

int Search(int a[], int n, int x)
{
    int i;
    for (i=0; i<n;i++)
        {if(a[i]==x)
             break;}
    if(i<n) return i;
    else return -1; 
}

int Delete(int a[], int n , int x)
{
    int i;
    i = Search(a,n,x);
    if(i== -1) return -1;
    else{
        a[i] = a[n-1];
        return i;
    }
    return 0;
}

int main()
{
    int arr[100]; int n=0; int S=100;
    int i, in, x;
    char com;
    for(i=0; i< S;i++) arr[i] = -1;
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
            if (in == -1) printf("Not Found. \n\n");
            else printf("Found at index %d\n\n",in);
        }
        else if(com=='i'){
            scanf("%d", &x);
            arr[n++] = x;
        }
        else if(com=='d'){
            scanf("%d", &x);
            Delete(arr, n, x);
            n--;
        }
        else{
            printf("???\n");
        }
    }
    return 0;
}