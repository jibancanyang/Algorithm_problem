/**********************jibancanyang**************************
 *Author*        :jibancanyang
 *Created Time*  : 三  7/ 6 10:20:37 2016
**Problem**:
**Analyse**:
把连续相等的数缩为一个节点，节点内有区间起点终点和值.
然后每次给了区间查寻之后去二分查找这个区间左端点，然后判断一下就可。
以上是自己YY的方法。
这个题的标准做法是，用并查集。
把连续相等的数合并为一组。
然后对于每个区间查寻去看左右端点是否在同一组，如果不是，那么久一定能找到。
如果是，看这个组的值的比较。
**Get**:
并查集在各大分组问题中有其效果.
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
const int maxn = 2e5 + 13;
int n, m;
int A[maxn];
pii B[maxn];



int main(void)
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    while (~scanf("%d%d", &n, &m)) {
        int cnt = -1;
        for (int i = 1; i <= n; i++) {
            int x; sa(x);
            if (cnt == -1 || x != B[cnt].yy) {
                if (cnt != -1) B[cnt].xx = i - 1;
                A[++cnt] = i;
                B[cnt].yy = x;
            }
        }
        B[cnt].xx = n;

        while (m--) {
            int l, r, x; sa(l), sa(r), sa(x);
            int t = lower_bound(A, A + cnt + 1, l) - A;
            //pr(A[t]), pr(B[t].xx), pl(B[t].yy);
            if (l > A[cnt]) {
                pri(x == B[cnt].yy ? -1 : l);
            } else if (A[t] > r) {
                pri(B[t - 1].yy == x ? -1 : r);
            } else {
                if (A[t] == l) {
                    if (t + 1 > cnt) pri(B[t].yy == x ? -1 : l);
                    else {
                        if (r >= A[t + 1]) {
                            pri(x == B[t].yy ? A[t + 1] : l);
                        } else pri(B[t].yy == x ? -1 : l);
                    }
                } else {
                    pri(B[t].yy == x ? B[t - 1].xx : A[t]);
                }
            }
        }
    }
    return 0;
}

