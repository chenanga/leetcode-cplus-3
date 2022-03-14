
//https://leetcode-cn.com/problems/reverse-vowels-of-a-string/

#include<iostream>

using namespace std;


class Solution {
public:
	string reverseVowels(string s) {
		string letter = "aeiouAEIOU";
		int left = 0, right = s.size() - 1;

		while (left < right) {

			if (letter.find(s[left]) != string::npos && letter.find(s[right]) != string::npos) //找到字符对就交换
				swap(s[left++], s[right--]);
			else if (letter.find(s[left]) != string::npos) //找到了一个，移动另一个指针
				right--;
			else if (letter.find(s[right]) != string::npos) //找到了一个，移动另一个指针
				left++;
			else { //两边都没移动到元音字母
				left++;
				right--;
			}

		}
		return s;
	}
};

int main() {

	system("pause");
	return 0;
}