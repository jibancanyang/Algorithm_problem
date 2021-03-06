/**********************jibancanyang**************************
 *Author*        :jibancanyang
 *Created Time*  : 四  6/16 21:00:50 2016
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
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++) 
const int mod = int(1e9) + 7, INF = 0x3f3f3f3f;
const int maxn = 1e5 + 13;

int bits[7];
int dp[7][10];

int dfs(int len, int high, bool limit) 
{
    if (len == 1) {
        return 1;
    }
    if (!limit && dp[len][high] != -1) return dp[len][high];
    int m = limit ? bits[len - 1] : 9;
    int ret = 0;
    for (int i = 0; i <= m; i++) {
        if (i != 4 && !(high == 6 && i == 2) ) {
            ret += dfs(len - 1, i, limit && i == m);
        }
    }
    if (!limit) dp[len][high] = ret;
    return ret;
}

int solve(int n) {
    int t = 1;
    while (n) {
        bits[t++] = n % 10;
        n /= 10;
    }
    bits[t] = 9;
    return dfs(t, 9, true);
}

int main(void)
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int l, r;
    memset(dp, -1, sizeof(dp));
    while (sa(l), sa(r), l && r) {
        pri(solve(r) - solve(l - 1));
    }
    return 0;
}
