#include<iostream>
#include<vector>
using namespace std;


//https://leetcode-cn.com/problems/merge-sorted-array/
class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int i = 0, j = 0; //i为nums1的指针，j为nums2的指针
		vector<int>ans;
		for (int k = 0; k < n + m; k++) {
			if (i == m)
				ans.push_back(nums2[j++]);
			else if (j == n)
				ans.push_back(nums1[i++]);
			else if (nums1[i] <= nums2[j]) {
				ans.push_back(nums1[i]);
				i++;
			}
			else { // nums1[i] > nums2[j]
				ans.push_back(nums2[j]);
				j++;
			}
		}
		nums1 = ans;

	}
};

int main() {

	system("pause");
	return 0;
}