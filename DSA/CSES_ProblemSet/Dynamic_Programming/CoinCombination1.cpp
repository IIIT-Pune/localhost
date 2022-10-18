#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e6 + 7;
int mod = 1e9 + 7;
int dp[N];

int32_t main()
{

    int n, m;
    cin >> n >> m;

    dp[0] = 1;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= m; i++)
    {

        for (int j = 1; j <= n; j++)
        {

            if (i - a[j] >= 0)
            {
                dp[i] = (dp[i] + dp[i - a[j]]) % mod;
            }
        }
    }

    cout << dp[m] % mod;

    return 0;
}