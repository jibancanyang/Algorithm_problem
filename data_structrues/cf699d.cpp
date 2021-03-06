#include <iostream>
#include <vector>
const int maxn = int(2e5) + 12;

int par[maxn], G[maxn];

int find(int x) {
    return par[x] == x ? x : par[x] = find(par[x]); 
}

void unite(int a, int b) {
    par[find(a)] = find(b);
}

int main()
{
    freopen("in.txt", "r", stdin);
    int n, x;
    std::vector<int> my, circle;
    std::cin >> n;
    for (int i = 1; i <= n; i++) par[i] = i; 
    for (int i = 1; i <= n; i++) {
        std::cin >> x;
        G[i] = x;
        if (i == x) my.push_back(i);
        else if (find(x) == find(i)) circle.push_back(i);
        unite(x, i);
    }
    int root;
    int ans = 0;
    if (my.empty()) {
        ans++;
        root = circle[circle.size() - 1];
        G[root] = root;
        circle.pop_back();
    }
    else {
        root = my[my.size() - 1];
        my.pop_back();
    }
    for (auto c : my) {
        ans++;
        G[c] = root;
    }
    for (auto c : circle) {
        ans++;
        G[c] = root;
    }
    std::cout << ans << std::endl;
    for (int i = 1; i <= n; i++) {
        std::cout << G[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
