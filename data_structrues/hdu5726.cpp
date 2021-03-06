#include <iostream>
#include <map>
#include <algorithm>
#include <cstdio>
using namespace std;

#define sa(x) scanf("%d", &(x))
#define root 1, n, 1
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1

struct jibancanyang
{
    int n, gcds[112345 << 2], A[112345], cnt;
    map<int, long long> ans, pre, aft;

    void push_up(int rt) {
        gcds[rt] = __gcd(gcds[rt << 1], gcds[rt << 1 | 1]);
    }

    void build(int l, int r, int rt) {
        if (l == r) {
            gcds[rt] = A[l - 1]; 
            return;
        }
        int m = (l + r) / 2;
        build(lson), build(rson);
        push_up(rt);
    }

    int query(int L, int R, int l, int r, int rt) {
        if (L <= l && r <= R) return gcds[rt];
        int m = (l + r) >> 1;
        int a = -1, b = -1;
        if (L <= m) a = query(L, R, lson);
        if (R > m) b = query(L, R, rson);
        if (a == -1) return b;
        if (b == -1) return a;
        return __gcd(a, b);
    }

    void space() {
        pre.clear();
        for (int i = 0; i < n; i++) {
            aft.clear();
            aft[A[i]]++;
            for (map<int, long long>::iterator it = pre.begin(); it != pre.end(); ++it) {
                aft[__gcd(it -> first, A[i])] += it -> second;
            }
            pre = aft;
            for (map<int, long long>::iterator it = pre.begin(); it != pre.end(); ++it) {
                ans[it -> first] += it -> second;
            }
        }
    }

    void run() {
        cnt = 0;
        build(1, n, 1);
        space();
        int m;
        sa(m);
        while (m--) {
            int l, r;
            sa(l), sa(r);
            int g = query(l, r, 1, n, 1);
            printf("%d %lld\n", g, ans[g]);
        }
    }

}ac;

int main()
{
    freopen("in.txt", "r", stdin);
    int T;
    sa(T);
    for (int cas = 1; cas <= T; cas++){
        printf("Case #%d:\n", cas);
        //cout << "Case #" << cas << ":" << endl;
        sa(ac.n);
        ac.ans.clear();
        for (int i = 0; i < ac.n; i++) {
            sa(ac.A[i]);
        }
        ac.run();
    }
    return 0;
}

