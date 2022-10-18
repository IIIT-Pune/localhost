#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e3 + 7;
const int X = 1e5 + 1;
int dp[N][X];

int main()
{

    int n, m;
    cin >> n >> m;
    dp[0][0] = 0;

    vector<int> a(n + 1), b(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }

    for (int i = 1; i <= n; i++)
    {

        for (int j = 1; j <= m; j++)
        {

            int t1 = 0;
            if (i > 1)
                t1 = dp[i - 1][j];
            int t2 = 0;
            if (j - a[i] >= 0)
                t2 = dp[i - 1][j - a[i]] + b[i];

            dp[i][j] = max(t1, t2);
        }
    }

    cout << dp[n][m];

    return 0;
}
