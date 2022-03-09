#include<iostream>
#include<vector>


using namespace std;

////��������
//class Solution {
//public:
//    void sortColors(vector<int>& nums) {
//
//		int count[3] = { 0 }; //���0��1��2����Ԫ�ص�Ƶ��
//		for (int i = 0; i < nums.size(); i++)
//			count[nums[i]] ++;
//		int index = 0;
//		for (int i = 0; i < count[0]; i++)
//			nums[index++] = 0;
//		for (int i = 0; i < count[1]; i++)
//			nums[index++] = 1;
//		for (int i = 0; i < count[2]; i++)
//			nums[index++] = 2;
//    }
//};
//��·����
// 75. Sort Colors
// https://leetcode.com/problems/sort-colors/description/
//
// ��·���������˼��
// ����������ֻ������һ��
// ʱ�临�Ӷ�: O(n)
// �ռ临�Ӷ�: O(1)
class Solution {
public:
	void sortColors(vector<int>& nums) {
		int len = nums.size();
		int zero = -1, two = len, i = 0;
		while (i <= two - 1) {
			if (nums[i] == 0)
				swap(nums[++zero], nums[i++]);

			else if (nums[i] == 1)
				i++;

			else { // (nums[i] == 2) 
				// assert(nums[i] == 2);
				swap(nums[i], nums[--two]);
			}

		}
	}
};


int main() {

	int arr[] = { 2,0,2,1,1,0 };
	vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));

	Solution().sortColors(vec);

	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";
	cout << endl;

	system("pause");
	return 0;
}