#include<iostream>
#include<vector>

using namespace std;


// 283. Move Zeroes
// https://leetcode.com/problems/move-zeroes/description/
// 时间复杂度: O(n)
// 空间复杂度: O(n)

//class Solution {
//public:
//	void moveZeroes(vector<int>& nums) {
//
//        vector<int> nonZeroElements;
//
//        // 将vec中所有非0元素放入nonZeroElements中
//        for (int i = 0; i < nums.size(); i++)
//            if (nums[i])
//                nonZeroElements.push_back(nums[i]);
//
//        // 将nonZeroElements中的所有元素依次放入到nums开始的位置
//        for (int i = 0; i < nonZeroElements.size(); i++)
//            nums[i] = nonZeroElements[i];
//
//        // 将nums剩余的位置放置为0
//        for (int i = nonZeroElements.size(); i < nums.size(); i++)
//            nums[i] = 0;
//	}
//};

////优化1
//class Solution {
//public:
//    void moveZeroes(vector<int>& nums) {
//
//        int k = 0; //代表[0,k)这个区间为非零元素
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

////优化2 把0与非零元素交换，这样后续就不用单独赋值0了
//class Solution {
//public:
//    void moveZeroes(vector<int>& nums) {
//
//        int k = 0; //代表[0,k)这个区间为非零元素
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


//优化3 如果这个数组全为非零元素，那么就直接调过，避免交换
class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int k = 0; //代表[0,k)这个区间为非零元素

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