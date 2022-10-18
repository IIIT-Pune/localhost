#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod = 1e9 + 7;

int main()
{

    int n, m;
    cin >> n >> m;

    vector<int> dp(m + 2);
    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    dp[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int sum = 0; sum <= m; sum++)
        {
            if (sum >= a[i - 1])
            {
                dp[sum] = (dp[sum] + dp[sum - a[i - 1]]) % mod;
            }
        }
    }

    cout << dp[m] << '\n';

    return 0;
}