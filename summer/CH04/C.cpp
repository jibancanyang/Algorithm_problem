/**********************jibancanyang**************************
 *Author*        :jibancanyang
 *Created Time*  : 一  7/11 09:31:26 2016
**Problem**:
**Analyse**:
模拟，翻转就是遍历顺序不同而已.
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
int n;
int A[33][33], B[33][33];



int main(void)
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    while (sa(n), n) {
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) sa(A[i][j]);
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) sa(B[i][j]);
        int ans = 0;
        int temp = 0;
        for (int i = 0, a = 0; i < n; i++, a++) {
            for (int j = 0, b = 0; j < n; j++, b++) {
                if (A[i][j] == B[a][b]) temp++;
            }
        }
        ans = max(ans, temp);
        temp = 0;
        for (int i = 0, a = 0; i < n; i++, a++) {
            for (int j = 0, b = n - 1; j < n; j++, b--) {
                if (A[i][j] == B[b][a]) temp++;
            }
        }
        ans = max(ans, temp);
        temp = 0;
        for (int i = 0, a = n - 1; i < n; i++, a--) {
            for (int j = 0, b = n - 1; j < n; j++, b--) {
                if (A[i][j] == B[a][b]) temp++;
            }
        }
        ans = max(ans, temp);
        temp = 0;
        for (int i = 0, a = n - 1; i < n; i++, a--) {
            for (int j = 0, b = 0; j < n; j++, b++) {
                if (A[i][j] == B[b][a]) temp++;
            }
        }
        ans = max(ans, temp);
        pri(ans);
    }
    
    return 0;
}
