#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod = 1e9 + 7;
int N = 1000001;

int main()
{

    ll n, m;
    cin >> n >> m;

    vector<ll> numbers(n), dp(N, INT_MAX);
    // Intializing dp with maximum value

    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }

    dp[0] = 0;
    // Coins to get a sum :- '0' is obivously 0 coins

    for (ll sum = 0; sum <= m; sum++)
    {
        // Traversing through each possible value sum possible till 'm'

        for (int i = 0; i < n; i++)
        {
            // Checking all possible combinations of coins available

            // Checking if it is possible to take numbers[i]
            if (sum >= numbers[i])
            {
                /* Possiblity is either to take that number and
                find the min. no. of coins required  for (sum - numbers[i])
                or leave that number */
                dp[sum] = (min(dp[sum], 1 + dp[sum - numbers[i]]));
            }
        }
    }
    // If it is not possible to get a desired sum
    if (dp[m] == INT_MAX)
        cout << -1 << '\n';
    else
        cout << dp[m];
    // Else answer is mth state of dp

    return 0;
}