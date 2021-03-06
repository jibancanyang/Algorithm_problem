/************************************************
 *Author        :jibancanyang
 *Created Time  : 二  4/ 5 22:00:39 2016
 *题目类型:很好的利用了过半的特性,记录当前最大频率数和他的频率.
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
const int mod = int(1e9) + 7, INF = 0x3fffffff, maxn = 1e5 + 12;



int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    cin.sync_with_stdio(false);
    int n;
    while (cin >> n) {

    int key = -123433, cnt = 0;
        rep(i, 0, n) {
            int x;
            cin >> x;
            if (x != key) {
                if (cnt == 0) key = x, cnt++;
                else cnt--;
            } else cnt++;
        }
        cout << key << endl;
    }
    return 0;
}
