#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6 + 7;
int dp[N];

int main()
{

    int n;
    cin >> n;
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        int z = i;
        int m = INT_MAX;

        while (z != 0)
        {
            int d = z % 10;
            z /= 10;
            if (d)
                m = min(m, 1 + dp[i - d]);
        }

        dp[i] = m;
    }

    cout << dp[n];

    return 0;
}