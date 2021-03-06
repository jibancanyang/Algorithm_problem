/**********************jibancanyang**************************
 *Author*        :jibancanyang
 *Created Time*  : 一  7/11 09:59:19 2016
**Problem**:
**Analyse**:
用bfs处理相互之间的最短路，然后dfs枚举这个路径的所有情况。
复杂度：$O(n*m*k!)$
**Get**:
数据小的，尽管暴力就是了。
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
char G[109][109];
int n, m, k;
int sx, sy;
int dirx[] = {-1, 0, 1, 0};
int diry[] = {0, 1, 0, -1};

struct node {
    int x, y, step;
    node(){}
    node(int a, int b, int c): x(a), y(b), step(c){}
};
bool vis[109][109];

int bfs(int sx, int sy, int ex, int ey)
{
    memset(vis, false, sizeof(vis));
    queue<node> que;
    int ret = INF;
    node t = node(sx, sy, 0);
    que.push(t);
    while (!que.empty()) {
        node cur = que.front(); que.pop();
        if (cur.x == ex && cur.y == ey) {
            ret = cur.step;
            break;
        }
        vis[cur.x][cur.y] = true;

        for (int i = 0; i < 4; i++) {
            node nxt(cur.x + dirx[i], cur.y + diry[i], cur.step + 1);
            if (nxt.x > 0 && nxt.x <= n && nxt.y > 0 && nxt.y <= m && (G[nxt.x][nxt.y] == '.')) {
                if (!vis[nxt.x][nxt.y]) que.push(nxt);
                vis[nxt.x][nxt.y] = true;
            }
        }
    }
    return ret;
}

pii aim[5];
int d[5][5];
bool vv[10];
int ans = INF;

void dfs(int s, int l, int par) {
    if (l >= ans) return;
    if (s == k) {
        ans = min(ans, l);
        return;
    }
    for (int i = 0; i < k; i++) {
        if (!vv[i]) {
            vv[i] = true;
            dfs(s + 1, l + d[par][i], i);
            vv[i] = false;
        }
    }
}

int main(void)
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    while (scanf("%d%d", &n, &m)) {
        ans = INF;
        if (n == 0 && m == 0) break;
        for (int i = 1; i <= n; i++) {
            getchar();
            for (int j = 1; j <= m; j++) {
                scanf("%c", &G[i][j]);
                if (G[i][j] == '@') G[i][j] = '.', sx = i, sy = j;
            }
        }
        sa(k);
        for (int i = 0; i < k; i++) {
            scanf("%d%d", &aim[i].xx, &aim[i].yy); 
        }
        aim[k].xx = sx, aim[k].yy = sy;
        for (int i = 0; i <= k; i++) {
            for (int j = 0; j <= k; j++) {
                d[i][j] = bfs(aim[i].xx, aim[i].yy, aim[j].xx, aim[j].yy);
            }
        }
        memset(vv, false, sizeof(vv));
        dfs(0, 0, k);
        pri(ans == INF ? -1 : ans);
    }
    return 0;
}
