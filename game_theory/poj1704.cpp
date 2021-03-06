#include <iostream>

class solve
{
private:
    int T, n, A[1111];
public:
    void sort() {
        for (int i = 1; i <= n; i++) {
            int  key = i;
            for (int j = i + 1; j <= n; j++) {
                if (A[j] < A[key]) {
                    key = j;
                }
            }
            std::swap(A[i], A[key]);
        }
    }

    void run() {
        std::cin >> T;
        A[0] = 0;
        while (T--) {
            std::cin >> n;
            for (int i = 1; i <= n; i++) std::cin >> A[i];
            sort();
            int ans = 0;
            for (int i = (n % 2 ? 1 : 2); i <= n; i += 2) {
                ans ^= A[i] - A[i - 1] - 1;
            }
            std::cout << (ans ? "Georgia will win" : "Bob will win") << std::endl;
        }
    }
}ac;

int main()
{
    freopen("in.txt", "r", stdin);
    ac.run();
    return 0;
}
