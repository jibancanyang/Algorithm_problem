#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define pr(x) cout << #x << ": " << x << "  " 
#define pl(x) cout << #x << ": " << x << endl;

static const int maxn = int(2e4) + 13;
//后缀数组模板，时间复杂度nlogn,空间复杂度n
struct Suffix
{

    int r[maxn];
    //后缀数组，名词数组，高度数组（表示和它前一名后缀的最长前缀长度, 从2开始有意义)。
    int sa[maxn],rnk[maxn],height[maxn];
    int t[maxn],t2[maxn],c[maxn],n,m;

    char str[maxn];

    //把string转化为r[i]
    void init_string(string &s) {
        n = s.size();
        for(int i=0;i<n;i++) r[i]=(int)s[i];
        m = 128;
    }

    void init_char(char *s) {
        n = strlen(s);
        for(int i=0;i<n;i++) r[i]=(int)s[i];
        m = 128;
    }

    int cmp(int *r,int a,int b,int l) { return r[a]==r[b]&&r[a+l]==r[b+l]; }

    //处理得到后缀数组
    void build() {
        int i,k,p,*x=t,*y=t2;
        r[n++]=0;
        for (i=0; i<m; i++) c[i]=0;
        for (i=0; i<n; i++) c[x[i]=r[i]]++;
        for (i=1; i<m; i++) c[i]+=c[i-1];
        for (i=n-1; i>=0; i--) sa[--c[x[i]]]=i;
        for (k=1,p=1; k<n; k*=2,m=p) {
            for (p=0,i=n-k; i<n; i++) y[p++]=i;
            for (i=0; i<n; i++) if (sa[i]>=k) y[p++]=sa[i]-k;
            for (i=0; i<m; i++) c[i]=0;
            for (i=0; i<n; i++) c[x[y[i]]]++;
            for (i=1; i<m; i++) c[i]+=c[i-1];
            for (i=n-1; i>=0; i--) sa[--c[x[y[i]]]]=y[i];
            swap(x,y);
            p=1;
            x[sa[0]]=0;
            for (i=1; i<n; i++) x[sa[i]]=cmp(y,sa[i-1],sa[i],k)?p-1:p++;
        }
        n--;
    }

    //处理得到高度数组和名次数组
    void lcp() {
        int i, j, k = 0;
        for (i=1; i <= n; i++) rnk[sa[i]]=i;
        for (i=0; i < n; i++) {
            if (k) k--;
            j = sa[rnk[i] - 1];
            while (r[i + k]==r[j + k]) k++;
            height[rnk[i]] = k;
        }
    }
};

struct jibancanyang
{

    int que[maxn];

    void fun() {
        int n, k;
        scanf("%d%d", &n, &k);
        string str;
        for (int i = 0; i < n; ++i) {
            int x;
            scanf("%d", &x);
            str += char(x + '0');
        }
        Suffix now;
        now.init_string(str);
        now.build();
        now.lcp();
        int head = 0, tail = 0;
        int l = 2, r = 2, ans = 0;
        while (r <= n) {
            while (r - l < k - 1) {
                if (r > n) break;
                int x = now.height[r++];
                while (tail != head && x < que[tail - 1]) --tail;
                que[tail++] = x;
            }
            if (r > n) break;
            ans = max(ans, que[head]);
            if (que[head] == now.height[l++]) head++;
        }
        printf("%d\n", ans);
    }

}ac;

int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    ac.fun();
    return 0;
}
