#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() <= 2) return nums.size();

		int k = 2; // 代表[0,k）中没重复元素
		int i = 2;

		while (i < nums.size()) {
			if (nums[i] != nums[k - 2])
				nums[k++] = nums[i];
			i++;

		}


		return k;
	}
};


int main() {


	int arr[] = { 1,1,1 };
	vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));

	int k = Solution().removeDuplicates(vec);

	for (int i = 0; i < vec.size(); i++)
		if (i < k)
			cout << vec[i] << " ";
		else
			cout << vec[i] << "* ";
	cout << endl;
	system("pause");
	return 0;
}