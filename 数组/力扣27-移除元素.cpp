#include<iostream>
#include<vector>
using namespace std;



//class Solution {
//public:
//	int removeElement(vector<int>& nums, int val) {
//		int k = 0; //代表[0,k)区间内 没有val元素
//		for (int i = 0; i < nums.size(); i++) {
//			if (nums[i] != val)
//				swap(nums[i], nums[k++]);
//
//		}
//		return k;
//	}
//};

//优化1 ，当数组中不含有val时，避免无用的交换
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int k = 0; //代表[0,k)区间内 没有val元素
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] != val)
				if (k != i)
					swap(nums[i], nums[k++]);
				else //k == i
					k++;

		}
		return k;
	}
};


int main() {

	system("pause");
	return 0;
}