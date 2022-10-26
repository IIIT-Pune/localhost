// https://leetcode.com/problems/3sum-closest/
// Time: O(N^2), where N <= 10^3 is number of elements in array nums.
// Space: from O(sorting)


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), ans = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < n-2; ++i) {
            int l = i + 1, r = n - 1;
            while (l < r) {
                int sum3 = nums[i] + nums[l] + nums[r];
                if (abs(ans - target) > abs(sum3 - target)) // Update better ans
                    ans = sum3;
                if (sum3 == target) break;
                if (sum3 > target)
                    --r; // Sum3 is greater than the target, to minimize the difference, we have to decrease our sum3
                else
                    ++l; // Sum3 is lesser than the target, to minimize the difference, we have to increase our sum3
            }
        }
        return ans;
    }
};

// if nums[first] + nums[second] + nums[third] is smaller than the target, we know we have to increase the sum. so only choice is moving the second index forward.

// if the sum is bigger than the target, we know that we need to reduce the sum. so only choice is moving 'third' to backward. of course if the sum equals to target, we can immediately return the sum.

// when second and third cross, the round is done so start next round by moving 'first' and resetting second and third.

// when second and third cross, the round is done so start next round by moving 'first' and resetting second and third.

// if no exactly matching sum has been found so far, the value in closest will be the answer.
