#include<iostream>
#include<vector>

using namespace std;


////二分搜索
//class Solution {
//public:
//	vector<int> twoSum(vector<int>& numbers, int target) {
//		for (int i = 0; i < numbers.size() - 1; i++) {
//			int res = binarySearch(numbers, i + 1, target - numbers[i]);
//			if (res != -2000)
//				return { i + 1, res + 1 };
//		}
//		return numbers;
//	}
//private:
//	int binarySearch(vector<int>& numbers, int left, int target) {
//		int right = numbers.size() - 1;
//		while (left <= right) {
//			int mid = left + (right - left) / 2;
//			if (numbers[mid] == target)
//				return mid;
//			else if (numbers[mid] < target)
//				left = mid + 1;
//			else //numbers[mid] > target
//				right = mid - 1;
//		}
//		return -2000;
//	}
//};

//双指针
//因为返回的两个索引不是同一个数，一定是一个左，一个右
class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		int left = 0, right = numbers.size() - 1;
		while (left < right){
			int sum = numbers[left] + numbers[right];
			if (sum == target)
				return { left + 1, right + 1 };
			else if (sum > target)
				right--;
			else //sum < target
				left++;
		}
		throw invalid_argument("The input has no solution.");
	}

};

int main() {

	system("pause");
	return 0;
}