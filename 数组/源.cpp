#include<iostream>
using namespace std;


//���ֲ��ҷ���˼����1946����֣���һ��û��bug�Ķ��ֲ�����1962�����


template<typename T>
int binarySearch(T arr[], int n, T target) {

	int l = 0, r = n - 1; // ��[l,..., r]�ķ�Χ��Ѱ��target
	while( l <= r){
		int mid = (l + r) / 2;
		if (arr[mid] == target)
			return mid;
		if (target > arr[mid])
			l = mid + 1; //target ��[mid +l, r]��
		else
			r = mid - 1;

	} 
	return -1;

}

int main() {

	system("pause");
	return 0;
}