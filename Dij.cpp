#include <iostream>
#include <cstdio>

using namespace std;

class PQ {
public:
    PQ();
    void Insert(pair <int, int> x);
    pair <int, int> Delete();
    int isEmpty();
    void print(int C, int depth, int LR);
    int s;
    pair <int, int> Arr[1000];
};

PQ::PQ()
{
    s = 0;
}

int PQ::isEmpty()
{
    return s == 0;
}

void PQ::Insert(pair <int, int> x)
{
    int i, j;
    pair <int, int> temp;
    s++;
    Arr[s] = x;
    i = s;
    while (i > 1) {
        j = i / 2;
        if (Arr[j] > Arr[i]) {
            temp = Arr[j]; Arr[j] = Arr[i]; Arr[i] = temp;
        }
        else {
            break;
        }
    }
}

pair <int, int> PQ::Delete()
{
    int i, j, k, p;
    pair<int, int> rt, temp;
    rt = Arr[1];
    Arr[1] = Arr[s];
    s--;
    i = 1;
    while (1) {
        j = i * 2; k = i * 2 + 1;
        if (j > s) break;
        if (k > s) {
            if (Arr[i] > Arr[j]) {
                temp = Arr[i]; Arr[i] = Arr[j]; Arr[j] = temp;
                i = j;
            }
            else {
                break;
            }
        }
        else {
            if (Arr[i] > Arr[j] || Arr[i] > Arr[k]) {
                if (Arr[j] < Arr[k]) p = j;
                else p = k;
                temp = Arr[i]; Arr[i] = Arr[p]; Arr[p] = temp; \
                    i = p;
            }
            else {
                break;
            }
        }
    }
    return rt;
}

void PQ::print(int C, int depth, int LR)
{
    if (s == 0) {
        printf("---\n");
        return;
    }
    if (depth == 0) {
        C = 1;
    }
    if (LR == 1) {
        int i;
        for (i = 0; i < depth; i++) printf("           ");
    }
    printf("---%03d, %03d", Arr[C].first, Arr[C].second);
    if (C * 2 <= s) {
        print(C * 2, depth + 1, 0);
    }
    else printf("\n");
    if (C * 2 + 1 <= s) {
        print(C * 2 + 1, depth + 1, 1);
    }
    else;
    return;
}

pair <int, int> LK[100][100];
int s[100];
int D[100];
int R[100];

int n, m;
int main()
{
    char c;
    int i;
    int p, q, r;
    pair <int, int> t, pkt;
    PQ Q;
    scanf("%d %d", &n, &m);
    for (i = 1; i < n; i++)
        s[i] = 0;
    for (i = 1; i <= m; i++) {
        scanf("%d %d %d", &p, &q, &r);
        s[p]++;
        LK[p][s[p]].first = q;
        LK[p][s[p]].second = r;
    }
    for (i = 1; i <= n; i++) {
        D[i] = 10000; R[i] = 0;
    }

    pkt.first = 0; pkt.second = 1;
    Q.Insert(pkt);
    while (Q.isEmpty() == 0) {
        for (i = 1; i <= n; i++) {
            printf("%5d ", D[i]);
        }
        printf("\n");
        Q.print(1, 0, 0);
        scanf("%c", &c);
        t = Q.Delete();
        r = t.first; q = t.second;
        if (R[q] == 1) continue;
        else {
            R[q] = 1;
            D[q] = r;
            for (i = 1; i <= s[q]; i++) {
                pkt.first = D[q] + LK[q][i].second;
                pkt.second = LK[q][i].first;
                Q.Insert(pkt);
            }
        }
    }
    return 0;
}
