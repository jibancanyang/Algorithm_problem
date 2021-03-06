#include <iostream>
#include <cstdio>
using namespace std;

#define root l, r, rt
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1

struct jibancanyang
{
    int flower[212345 << 2], n;

    void push_up(int rt) {
        flower[rt] = max(flower[rt << 1] , flower[rt << 1 | 1]);
    }

    void build(int l, int r, int rt) {
        if (l == r) {
            scanf("%d", &flower[rt]);
            return;
        }
        int m = (l + r) >> 1;
        build(lson), build(rson);
        push_up(rt);
    }

    void update(int a, int b, int l, int r, int rt) {
        if (l == r) {
            flower[rt] = b;
            return;
        }
        int m = (l + r) / 2;
        if (a <= m) update(a, b, lson);
        if (a > m) update(a, b, rson);
        push_up(rt);
    }

    int query(int L, int R, int l, int r, int rt) {
        if (L <= l && r <= R) return flower[rt];
        int m = (l + r) / 2;
        int ret = -int(1e9);
        if (L <= m) ret = max(ret, query(L, R, lson));
        if (R > m) ret = max(ret, query(L, R, rson));
        return ret;
    }

    void run() {
        int m;
        while (~scanf("%d%d", &n, &m)) {
            build(1, n, 1);
            while (m--) {
                char c;
                int x, y;
                getchar();
                scanf("%c%d%d", &c, &x, &y);
                if (c == 'Q') printf("%d\n", query(x, y, 1, n, 1));
                else update(x, y, 1, n, 1);
            }
        }
    }

}ac;

int main() 
{
    freopen("in.txt", "r", stdin);
    ac.run();
    return 0;
}
