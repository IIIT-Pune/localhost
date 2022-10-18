#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dp[1001][1001];
ll mod = 1e9 + 7;

int main()
{

    int n;
    cin >> n;

    vector<vector<char>> a(n, vector<char>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    dp[0][0] = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == '*')
            {
                dp[i][j] = 0;
            }
            else if (i == 0 && j == 0)
            {
                dp[i][j] == 1;
            }
            else
            {
                int o1 = 0, o2 = 0;
                if (i > 0)
                {
                    o1 = dp[i - 1][j];
                }
                if (j > 0)
                {
                    o2 = dp[i][j - 1];
                }
                dp[i][j] = (o1 + o2) % mod;
            }
        }

        cout << dp[n - 1][n - 1];
    }
    return 0;
}