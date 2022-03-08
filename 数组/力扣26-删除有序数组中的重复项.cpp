#include<iostream>
#include<vector>
using namespace std;


//https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() <= 1) return nums.size();

		int k = 0; // 代表[0,k）中没重复元素
		int i = 0;
		for (; i < nums.size() - 1; i++) {
			while (i < nums.size() - 1 && nums[i] == nums[i + 1])
				i++;

			swap(nums[k++], nums[i]);

		}
		if (i == nums.size() - 1 && k - 1 != i)
			swap(nums[k++], nums[i]);

		return k;
	}
};


////解法2
//class Solution {
//public:
//	int removeDuplicates(vector<int>& nums) {
//		int len = nums.size();
//		if (len <= 1) return len;
//
//		int k = 1; // 代表[0,k）中没重复元素
//		int i = 1;
//
//		while (i < len) {
//			if (nums[i] != nums[i - 1])
//				nums[k++] = nums[i];
//
//			i++;
//		}
//
//
//		return k;
//	}
//};

int main() {

	int arr[] = { 1, 1 };
	vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));

	Solution().removeDuplicates(vec);

	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";
	cout << endl;
	system("pause");
	return 0;
}