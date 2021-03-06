#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
#define pr(x) cout << #x << ": " << x << "  " 
#define pl(x) cout << #x << ": " << x << endl;


const int  maxn = 1e6  + 1e4 + 13;
char str[maxn], aim[maxn * 2];
int ti, P[maxn * 2]; //ti表示转换后的串的长度, P[i]表示以i为中心的回文子串的长度.
void pre()
{
    int len = strlen(str);
    ti = 0;
    if (len == 0) {aim[0] = '^', aim[1] = '$'; return;} //空串
    aim[ti++] = '^';
    for (int i = 0; i < len; i++) aim[ti++] = '#', aim[ti++] = str[i];
    aim[ti++] = '#', aim[ti++] = '$';
}

int  manacher()
{
    pre();
    int c = 0, r = 0;
    for (int i = 1; i < ti - 1; i++) {
        int im = c - (i - c);
        P[i] = r > i ? min(P[im], r - i) : 0;
        while (aim[i + P[i] + 1] == aim[i - P[i] - 1]) P[i]++;
        if (i + P[i] > r) c = i, r = i + P[i];
    }
    int ret = 0;
    for (int i = 1; i < ti - 1; i++) {
        if (P[i] > ret) ret = P[i];
    }
    return ret;
}

int main()
{
#ifdef xiaoai
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    while (n--) {
        cin >> str;
        cout << manacher() << endl;
    }
    
    return 0;
}
