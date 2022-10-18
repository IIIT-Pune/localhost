#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod = 1e9 + 7;

int main()
{

    ll n;
    cin >> n;

    vector<ll> dp(n + 1, 0);
    // Intializing dp with value 0

    dp[0] = 1;
    /* We always have a way to not choosing any coins,thus
    to get a sum of '0' is not choosing, giving us 0th state of dp as '1' */

    for (ll i = 1; i <= n; i++)
    {
        // Traversing through each possible sum till 'n'

        for (ll j = 1; j <= 6; j++)
        // Checking all possible combinations of dice
        {
            // If it is possible to get a sum :- 'i' from j

            // Checking if i >= j for handling negative cases when j > i
            if (i - j >= 0)
                dp[i] = ((dp[i - j]) + dp[i]) % mod;
            // Taking mod for large values
        }
    }
    // Answer is the 'n' state of dp

    cout << dp[n] << '\n';

    return 0;
}