/**********************jibancanyang**************************
 *Author*        :jibancanyang
 *Created Time*  : 三  7/13 15:22:59 2016
**Problem**:
最大化平均值，限制是选k个物品。
**Analyse**:
平均值的式子具有特殊性很容易去贪心地判断平均值是否大于一个数。
复杂度$nlog^nlog{10^12}}$
**Get**:
这题很容易去想dp，但是显然复杂度太高。看数据范围应该是$nlogn$这样的算法。
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
int n, k;
struct pi {
    int xx, yy, num;
}V[maxn];
double temp;

bool cmp(const pi &a, const pi &b) {
    return a.xx - a.yy * temp > b.xx - b.yy * temp;
}

bool judge(double t) {
    temp = t;
    sort(V, V + n, cmp);
    temp = 0;
    for (int i = 0; i < k; i++) {
        temp += V[i].xx - V[i].yy * t;
    }
    return temp >= 0;
}

int main(void)
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    while (~scanf("%d%d", &n, &k)) {
        for (int i = 0; i < n; i++) {
            sa(V[i].xx),  sa(V[i].yy), V[i].num = i + 1;
        }
        double l = 0, r = 1e12;
        for (int i = 0; i < 75; i++) {
            double mid = (l + r) / 2;
            if (judge(mid)) {
                l = mid;
            } else r = mid - 1e-9;
        }
        for (int i = 0; i < k; i++) {
            printf("%d ", V[i].num);
        }
        puts("");
    }
    return 0;
}
