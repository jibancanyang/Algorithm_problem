/**********************jibancanyang**************************
 *Author*        :jibancanyang
 *Created Time*  : 五  7/ 8 14:12:54 2016
**Problem**:
**Analyse**:
二分距离加DLX可重复覆盖。
注意这里的距离爆int.
**Get**:
在头文件<limits.h>下可以找到各种数据的范围.
其中int大概是2e9.
**Code**:
***********************1599664856@qq.com**********************/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <limits.h>
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

int n;
int k; //最多选多少行
const int maxnode = 10000;
const int maxm = 65;
const int maxn = 65;

struct DLX{
    int n,m,len;
    int U[maxnode],D[maxnode],R[maxnode],L[maxnode],Row[maxnode],Col[maxnode];
    int H[maxn];//行头结点
    int S[maxm];//每列有多少个结点
    int ansd,ans[maxn];//如果有答案，则选了ansd行，具体是哪几行放在ans[]数组里面,ans[0~ansd-1]

    void init(int _n,int _m){
        n = _n;m = _m;
        for(int i = 0; i <= m; i++){
            S[i] = 0;
            U[i] = D[i] = i;//初始状态时，上下都指向自己
            L[i] = i-1;
            R[i] = i+1;
        }
        R[m] = 0,L[0] = m;
        len = m;//编号，每列都有一个头结点，编号1~m
        for(int i = 1; i <= n; i++)
            H[i] = -1;//每一行的头结点
    }

    void link(int r,int c){//第r行，第c列
        ++S[Col[++len]=c];//第len个节点所在的列为c,当前列的结点数++
        Row[len] = r;//第len个结点行位置为r
        D[len] = D[c];
        U[D[c]] = len;
        U[len] = c;
        D[c] = len;
        if(H[r] < 0)
            H[r] = L[len] = R[len] = len;
        else{
            R[len] = R[H[r]];
            L[R[H[r]]] = len;
            L[len] = H[r];
            R[H[r]] = len;
        }
    }

    void del(int c){
        for(int i = D[c]; i != c; i = D[i]){
            L[R[i]] = L[i];
            R[L[i]] = R[i];
        }
    }

    void resume(int c){
        for(int i = U[c]; i != c; i = U[i])
            L[R[i]] = R[L[i]] = i;
    }
    bool v[maxnode];
    int f(){
        int ret = 0;
        for(int c = R[0]; c != 0; c = R[c])
            v[c] = true;
        for(int c = R[0]; c != 0; c = R[c]){
            if(v[c]){
                ret++;
                v[c] = false;
                for(int i = D[c]; i != c; i = D[i]){
                    for(int j = R[i]; j != i; j = R[j]){
                        v[Col[j]] = false;
                    }
                }
            }
        }
        return ret;
    }
    bool dance(int d){//递归深度
        if(d + f() > k)
            return false;
        if(R[0] == 0)
            return d <= k;

        int c = R[0];
        for(int i = R[0]; i != 0; i = R[i]){
            if(S[i] < S[c])
                c = i;
        }
        for(int i = D[c]; i != c; i = D[i]){
            del(i);
            ans[d] = Row[i];//列头节点下面的一个节点
            for(int j = R[i]; j != i; j = R[j])
                del(j);
            if(dance(d+1))
                return true;
            for(int j = L[i]; j != i; j = L[j])
                resume(j);
            resume(i);
        }
        return false;
    }
}head;

/*
int main(void) {
    int n, m;  //n行m列的01矩阵中选取一些行，让每一列都至少含有一个1，最多选k行。
    head.init(n, m);
    if (matrix[i][j]矩阵单元值为1) head.link(i, j)
    head.dance(0)；//返回是否可以覆盖的布尔值。
}
*/

pii city[maxn];

ll dist(pii &a, pii &b) {
    return abs((ll)a.xx - b.xx) + abs((ll)a.yy - b.yy);
}

int main(void)
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    //cout << INT_MAX << endl;
    int T; sa(T);
    for (int cas = 1; cas <= T; cas++) {
        sa(n), sa(k);
        for (int i = 0; i < n; i++) sa(city[i].xx), sa(city[i].yy);
        ll l = 0, r = (ll)4e9 + 100;
    
        while (l < r) {
            ll mid = (r + l) / 2; 
            //        pr(l), pr(r), pl(mid);
            head.init(n, n);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist(city[i], city[j]) <= mid) 
                        head.link(i + 1, j + 1);
                }
            }
            if (head.dance(0)) r = mid;
            else l = mid + 1;
        }
     //   printf("Case #%d: %lld\n", cas, l);
        printf("Case #%d: %I64d\n", cas, l);
    }
    return 0;
}
