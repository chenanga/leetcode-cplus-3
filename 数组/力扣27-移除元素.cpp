#include<iostream>
#include<vector>
using namespace std;



//class Solution {
//public:
//	int removeElement(vector<int>& nums, int val) {
//		int k = 0; //����[0,k)������ û��valԪ��
//		for (int i = 0; i < nums.size(); i++) {
//			if (nums[i] != val)
//				swap(nums[i], nums[k++]);
//
//		}
//		return k;
//	}
//};

//�Ż�1 ���������в�����valʱ���������õĽ���
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int k = 0; //����[0,k)������ û��valԪ��
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