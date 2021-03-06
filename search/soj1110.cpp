/**********************jibancanyang**************************
 *Author*        :jibancanyang
 *Created Time*  : 二  6/21 20:44:55 2016
**Problem**:
**Analyse**:
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
#define vep(c) for(vector<int>::iterator it = (c).begin(); it != (c).end(); it++) 
const int mod = int(1e9) + 7, INF = 0x3f3f3f3f;
const int maxn = 1e5 + 13;
int G[4][4];
int dirx[] = {-1, 0, 1, 0};
int diry[] = {0, 1, 0, -1};
int aims[4][4] = { {1, 2, 3, 4} , {5, 6, 7, 8} , {9, 10, 11, 12} , {13, 14, 15, 0}};
int aim;
bool ans;
pii mp[16];

inline int abss(int y) {
    return y > 0 ? y : -y;
}

int star() {
    int sum = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (G[i][j]) sum += abss(mp[G[i][j]].xx - i) + abss(mp[G[i][j]].yy - j);
        }
    }
    return sum;
}

inline void swaps(int &a, int &b) {
    a ^= b;
    b ^= a;
    a ^= b;
}


void dfs(int res, int emptyx, int emptyy, pii pre, int stars) {
    if (ans) return;
    int k = stars;
    if (res == 0) {
        if (!k) ans = true;
        return;
    }
    if (res < k) return;
    for (int i = 0; i < 4; i++) {
        int nxtx = emptyx + dirx[i], nxty = emptyy + diry[i];
        if (nxtx >= 0 && nxtx < 4 && nxty >= 0 && nxty < 4 && !(nxtx == pre.xx && nxty == pre.yy)) {
            int temp = stars;
            temp -= abss(mp[G[nxtx][nxty]].xx - nxtx) + abss(mp[G[nxtx][nxty]].yy - nxty);
            temp += abss(mp[G[nxtx][nxty]].xx - emptyx) + abss(mp[G[nxtx][nxty]].yy - emptyy);
            swaps(G[emptyx][emptyy], G[nxtx][nxty]);
            if (temp <= stars) dfs(res - 1, nxtx, nxty, pii(emptyx, emptyy), temp);
            swaps(G[emptyx][emptyy], G[nxtx][nxty]);
        }
    }
}

int main(void)
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int n;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            mp[aims[i][j]] = pii(i, j);
        }
    }

    sa(n);
    while (n--) {
        int x, y;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                sa(G[i][j]);
                if (!G[i][j]) x = i, y = j;
            }
        }
        ans = false;
        int tt = star();
        for (int i = tt; ; i++) {
            dfs(i, x, y, pii(-1, -1), tt);
            if (ans) {
                pri(i);
                break;
            }
        }

    }
    return 0;
}
