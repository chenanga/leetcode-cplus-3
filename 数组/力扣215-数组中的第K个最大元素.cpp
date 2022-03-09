#include<iostream>
#include<vector>
using namespace std;

//https://leetcode-cn.com/problems/kth-largest-element-in-an-array/

class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		srand(time(NULL));
		return _quickSort(nums, 0, nums.size() - 1, nums.size() - k);

	}

private:

	// 对arr[l...r]部分进行partition操作
	// 返回p, 使得arr[l+1...j] < arr[l] ; arr[j+1...r] > arr[l]
	int _partition(vector<int>& nums, int l, int r) {

		swap(nums[l], nums[rand() % (r - l + 1) + l]);

		int j = l; //[l+1,j] 小于等于nums[l]，[j+1,i]大于
		for (int i = l + 1; i <= r; i++) {
			if (nums[i] <= nums[l])
				swap(nums[++j], nums[i]);
		}

		swap(nums[l], nums[j]);
		return j;


	}
	int _quickSort(vector<int>& nums, int l, int r, int k) {

		int p = _partition(nums, l, r);
		if (p == k)
			return nums[p];

		if (k > p) {
			//在右半边
			return _quickSort(nums, p + 1, r, k);
		}
		else {
			return _quickSort(nums, l, p - 1, k);
		}
	}
};

int main() {

	int arr[] = { 3,2,1,5,6,4 };
	vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));

	int k = Solution().findKthLargest(vec, 2);
	cout << k << endl;

	/*for (int i = 0; i < vec.size(); i++)
		if (i < k)
			cout << vec[i] << " ";
		else
			cout << vec[i] << "* ";
	cout << endl;*/

	system("pause");
	return 0;
}