class Solution {
public:
	bool isPalindrome(string s) {
		string temp = s; reverse(temp.begin(), temp.end());
		if (temp == s)
			return true;
		return false;
	}


	string breakPalindrome(string palindrome) {
		string s = palindrome;
		int n = s.size();
		if (s[0] != 'a')
		{
			s[0] = 'a';

		}
		else
		{
			for (int i = 0; i < n; ++i)
			{
				if (s[i] != 'a')
				{
					s[i] = 'a';
					break;
				}
			}
		}
		bool ans = false;
		for (int i = 0; i < n; ++i)
		{
			if (palindrome[i] != 'a')
			{
				ans = true;
				break;
			}
		}
		if (n == 1)
		{
			s = "";
		}
		else if (ans == false)
		{
			s[n - 1] = 'b';
		}
		if (isPalindrome(s) and n != 1)
		{
			palindrome[n - 1]++;
			return palindrome;
		}
		return s;
	}
};