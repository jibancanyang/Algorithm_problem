/**********************jibancanyang**************************
 *Author*        :jibancanyang
 *Created Time*  : 二  7/12 15:23:29 2016
**Problem**:
**Analyse**:
树上任意路径的异或值看来是比较容易求得。
trie树求与当前数异或的第$k$大，只需要记录size即可。
**Get**:
**Code**:
***********************1599664856@qq.com**********************/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <stack>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
#define pr(x) cout << #x << ": " << x << "  " 
#define pl(x) cout << #x << ": " << x << endl;
#define pri(a) printf("%d\n",(a))
#define xx first
#define yy second
#define sa(n) scanf("%d", &(n))
#define sal(n) scanf("%lld", &(n))
#define sai(n) scanf("%I64d", &(n))
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++) 
const int mod = int(1e9) + 7, INF = 0x3f3f3f3f;
const int maxn = 1e5 + 13;
int n, m;

struct tree {
    int to; 
    ll cost;
    tree(){}
    tree(int a, ll b):to(a), cost(b){}
};

struct node {
    int size;
    node *son[2];
    node(): size(0) { son[0] = NULL, son[1] = NULL; } 
}* root;

struct dot {
    ll v;
    int x, k;
    dot(){}
    dot(ll V, int X, int K): v(V), x(X), k(K){}
};

vector<tree> G[maxn];
ll xors[maxn];
ll ans[maxn * 2];
int query[maxn];

void dfs(int cur, ll x) {
    xors[cur] = x;
    for (int i = 0; i < (int)G[cur].size(); i++) {
        tree nxt = G[cur][i];
        if (xors[nxt.to] == -1) dfs(nxt.to, x ^ nxt.cost);
    }
}

void add(ll x) {
    node *cur = root;
    for (int i = 63; i >= 0; i--) {
        if (x >> i & 1) {
            if (cur -> son[1] == NULL) cur -> son[1] = new node;
            cur = cur -> son[1];
        } else {
            if (cur -> son[0] == NULL) cur -> son[0] = new node;
            cur = cur -> son[0];
        }
        (cur -> size)++;
    }
}

void destroy(node *cur) {
    if (cur -> son[0]) destroy(cur -> son[0]);
    if (cur -> son[1]) destroy(cur -> son[1]);
    delete cur;
}

class cmp
{
public:
    bool operator()(dot &a, dot &b) {
        return a.v < b.v;
    }
};

ll search(ll x, int k) {
    //int t = k;
    node *cur = root;
    if (k > n - 1) return -1;
    ll ans = 0;
    for (int i = 63; i >= 0; i--) {
        if (x >> i & 1) {
            if (cur -> son[0]) {
                int t = cur -> son[0] -> size;
                if (t >= k) cur = cur -> son[0];
                else  {
                    k -= t;
                    cur = cur -> son[1];
                    ans |= (1ll << i);
                }
            } else {
                cur = cur -> son[1];
                ans |= (1ll << i);
            }
        } else {
            if (cur -> son[1]) {
                int t = cur -> son[1] -> size;
                if (t >= k) cur = cur -> son[1], ans |= (1ll << i);
                else {
                    k -= t;
                    cur = cur -> son[0];
                } 
            } else {
                cur = cur -> son[0];
            }
        }
    }
    ll ret = x ^ ans;
    return ret;
}


int main(void)
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    while (sa(n), n) {
        for (int i = 1; i <= n; i++) G[i].clear();
        for (int i = 0; i < n - 1; i++) {
            int x, y; ll z;
            sa(x), sa(y),sai(z);
            G[x].push_back(tree(y, z));
            G[y].push_back(tree(x, z));
        }
        memset(xors, -1, sizeof(xors));
        memset(ans, -1, sizeof(ans));
        dfs(1, 0);
        root = new node;
        for (int i = 1; i <= n; i++) add(xors[i]);
        priority_queue<dot, vector<dot>, cmp> que;
        sa(m);
        int maxq = 0;
        for (int i = 0; i < m; i++) sa(query[i]), maxq = max(maxq, query[i]);
        ll k = (ll)n * (n - 1);
        for (int i = 1; i <= n; i++) que.push(dot(search(xors[i], 1), i, 1));
        int cnt = 1;
        for (; maxq > 0 && k > 0 && !que.empty(); k--, maxq--) {
            ans[cnt++] = que.top().v;
            dot cur = que.top(); que.pop();
            ll temp = search(xors[cur.x], cur.k + 1);
            if (temp != -1) {
                que.push(dot(temp, cur.x, cur.k + 1));
            }
        }
     //   for (int i = 1; i <= n *(n - 1); i++) pr(i), pl(ans[i]);

        for (int i = 0; i < m; i++) {
            //cout << ans[query[i]] << endl;
            printf("%I64d\n", ans[query[i]]);
        }
        destroy(root);
    }
    
    return 0;
}
