/************************************************
 *Author        :jibancanyang
 *Created Time  : 二  4/ 5 21:35:55 2016
 *题目类型:
*************************************************/

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
vector<int> vi;
#define xx first
#define yy second
#define sa(n) scanf("%d", &(n))
#define rep(i, a, n) for (int i = a; i < n; i++)
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++) 
const int mod = int(1e9) + 7, INF = 0x3fffffff, maxn = 1e3 + 12;
int dp[maxn][maxn];


int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    cin.sync_with_stdio(false);
    string a, b;
    while (cin >> a >> b) {
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= (int)a.size(); i++) {
            for (int j = 1; j <= (int)b.size(); j++) {
                dp[i][j] = max(dp[i - 1][j - 1] + (a[i - 1] == b[j - 1]), max(dp[i - 1][j], dp[i][j - 1])); 
            }
        }
        cout << dp[a.size()][b.size()] << endl;
    }
    return 0;
}
