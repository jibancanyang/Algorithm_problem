/**********************jibancanyang**************************
 *Author*        :jibancanyang
 *Created Time*  : 三  7/ 6 09:14:58 2016
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
bool dp[510][510][510];



int main(void)
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int n, k;
    sa(n), sa(k);
    dp[0][0][0] = true;
    for (int i = 1; i <= n; i++) {
        int c; sa(c);
        for (int j = 0; j <= k; j++) {
            for (int t = 0; t <= k; t++) {
                dp[i][j][t] |= dp[i - 1][j][t];
                if (t - c >= 0) dp[i][j][t] |= dp[i - 1][j][t - c];
                if (j - c >= 0) dp[i][j][t] |= dp[i - 1][j - c][t];
            }
        }
    }
    vector<int> V;
    for (int i = 0; i <= k; i++) {
        if (dp[n][i][k - i]) V.push_back(i);
    }
    pri((int)V.size());
    for (int i = 0; i < (int)V.size(); i++) {
        printf("%d ", V[i]);
    }
    puts("");
    return 0;
}
