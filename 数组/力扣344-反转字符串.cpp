//https://leetcode-cn.com/problems/reverse-string/

#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
	void reverseString(vector<char>& s) {
		int left = 0, right = s.size() - 1;
		while (left < right) 
			swap(s[left++], s[right--]);
		return;
		
	}
};

int main() {

	system("pause");
	return 0;
}