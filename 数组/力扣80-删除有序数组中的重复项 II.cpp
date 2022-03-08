#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() <= 1) return nums.size();

		int k = 0; // ����[0,k����û�ظ�Ԫ��
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


int main() {

	system("pause");
	return 0;
}