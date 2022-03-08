#include<iostream>
#include<vector>

using namespace std;


// 283. Move Zeroes
// https://leetcode.com/problems/move-zeroes/description/
// ʱ�临�Ӷ�: O(n)
// �ռ临�Ӷ�: O(n)

//class Solution {
//public:
//	void moveZeroes(vector<int>& nums) {
//
//        vector<int> nonZeroElements;
//
//        // ��vec�����з�0Ԫ�ط���nonZeroElements��
//        for (int i = 0; i < nums.size(); i++)
//            if (nums[i])
//                nonZeroElements.push_back(nums[i]);
//
//        // ��nonZeroElements�е�����Ԫ�����η��뵽nums��ʼ��λ��
//        for (int i = 0; i < nonZeroElements.size(); i++)
//            nums[i] = nonZeroElements[i];
//
//        // ��numsʣ���λ�÷���Ϊ0
//        for (int i = nonZeroElements.size(); i < nums.size(); i++)
//            nums[i] = 0;
//	}
//};

////�Ż�1
//class Solution {
//public:
//    void moveZeroes(vector<int>& nums) {
//
//        int k = 0; //����[0,k)�������Ϊ����Ԫ��
//
//        for (int i = 0; i < nums.size(); i++) {
//            if (nums[i] ) 
//                nums[k++] = nums[i];    
//        }
//        for (int i = k; i < nums.size(); i++)
//            nums[i] = 0;
//       
//    }
//};

////�Ż�2 ��0�����Ԫ�ؽ��������������Ͳ��õ�����ֵ0��
//class Solution {
//public:
//    void moveZeroes(vector<int>& nums) {
//
//        int k = 0; //����[0,k)�������Ϊ����Ԫ��
//
//        for (int i = 0; i < nums.size(); i++) {
//            if (nums[i])
//                    swap(nums[k++], nums[i]);
//                
//        }
//
//
//    }
//};


//�Ż�3 ����������ȫΪ����Ԫ�أ���ô��ֱ�ӵ��������⽻��
class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int k = 0; //����[0,k)�������Ϊ����Ԫ��

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i])
                if (i != k)
                    swap(nums[k++], nums[i]);
                else // i == k
                    k++;
        }


    }
};
int main() {

    int arr[] = { 0, 1, 0, 3, 12 };
    vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));

    Solution().moveZeroes(vec);

    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;

	system("pause");
	return 0;
}