#include<iostream>
#include<vector>

using namespace std;
//https://leetcode-cn.com/problems/minimum-size-subarray-sum/submissions/
class Solution {
public:
	int minSubArrayLen(int target, vector<int>& nums) {
		int left = 0, right = -1; //nums[left,right] 为滑动窗口，初值不包含元素
		int sum = 0;
		int res = nums.size() + 1;

		while (left < nums.size()) {
			if ( right + 1 < nums.size() && sum < target) {
				right++;
				sum += nums[right];
			}
			else {
				sum -= nums[left];
				left++;
			}
			if (sum >= target)
				res = min(res, right - left + 1);
				
		}
		if (res == nums.size() + 1)
			return 0;
		return res;

	}
};


int main() {

	system("pause");
	return 0;
}