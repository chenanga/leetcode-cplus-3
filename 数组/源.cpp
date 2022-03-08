#include<iostream>
#include"MyUtil.h"

using namespace std;


//二分查找法的思想在1946年出现，第一个没有bug的二分查找是1962年出现


template<typename T>
int binarySearch(T arr[], int n, T target) {

	int l = 0, r = n - 1; // 在[l,..., r]的范围内寻找target
	while( l <= r){
		int mid = l + (r - l) / 2;  // 避免整型溢出
		if (arr[mid] == target)
			return mid;
		if (target > arr[mid])
			l = mid + 1; //target 在[mid +l, r]中
		else
			r = mid - 1;

	} 
	return -1;

}

int main() {

	int n = pow(10, 7);
	int* data = MyUtil::generateOrderedArray(n);

	clock_t startTime = clock();
	for (int i = 0; i < n; i++)
		assert(i == binarySearch(data, n, i));
	clock_t endTime = clock();

	cout << "Binary Search test complete." << endl;
	cout << "Time cost: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;

	system("pause");
	return 0;
}