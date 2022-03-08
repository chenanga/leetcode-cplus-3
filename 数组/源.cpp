#include<iostream>
using namespace std;


//二分查找法的思想在1946年出现，第一个没有bug的二分查找是1962年出现


template<typename T>
int binarySearch(T arr[], int n, T target) {

	int l = 0, r = n - 1; // 在[l,..., r]的范围内寻找target
	while( l <= r){
		int mid = (l + r) / 2;
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

	system("pause");
	return 0;
}