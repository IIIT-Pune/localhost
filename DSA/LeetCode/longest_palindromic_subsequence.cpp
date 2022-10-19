#include <bits/stdc++.h>
using namespace std;

int LCS(string X, string Y, int n, int m) {
	int dp[n + 1][m + 1]; // DP - matrix

	// base case of recursion --> for initialization of dp - matrix
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			if (i == 0 || j == 0)
				dp[i][j] = 0;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (X[i - 1] == Y[j - 1]) // when last character is same
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else // when last character is not same -> pick max
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);

	return dp[n][m];
}

int LPS(string X, int n) {
	string rev_X = X;
	reverse(rev_X.begin(), rev_X.end());
	return LCS(X, rev_X, n, n);
}

signed main() {
	string X, Y; cin >> X;
	int n = X.length();

	cout << LPS(X, n) << endl;
	return 0;
}

// Time Complexity: O(n^2)
// Auxiliary Space: O(n^2),  Creating a table

// Steps Below : for reference 


// // Every single character is a palindrome of length 1
// L(i, i) = 1 for all indexes i in given sequence

// // IF first and last characters are not same
// If (X[i] != X[j])  L(i, j) =  max{L(i + 1, j),L(i, j - 1)} 

// // If there are only 2 characters and both are same
// Else if (j == i + 1) L(i, j) = 2  

// // If there are more than two characters, and first and last 
// // characters are same
// Else L(i, j) =  L(i + 1, j - 1) + 2 