
//https://leetcode-cn.com/problems/reverse-vowels-of-a-string/

#include<iostream>

using namespace std;


class Solution {
public:
	string reverseVowels(string s) {
		string letter = "aeiouAEIOU";
		int left = 0, right = s.size() - 1;

		while (left < right) {

			if (letter.find(s[left]) != string::npos && letter.find(s[right]) != string::npos) //�ҵ��ַ��Ծͽ���
				swap(s[left++], s[right--]);
			else if (letter.find(s[left]) != string::npos) //�ҵ���һ�����ƶ���һ��ָ��
				right--;
			else if (letter.find(s[right]) != string::npos) //�ҵ���һ�����ƶ���һ��ָ��
				left++;
			else { //���߶�û�ƶ���Ԫ����ĸ
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