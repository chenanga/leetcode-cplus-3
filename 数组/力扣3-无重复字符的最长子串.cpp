#include<iostream>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {

		int freq[256] = { 0 };
		int left = 0, right = -1; //��������Ϊs[left,right]
		int res = 0;
		while (left < s.size()) {

			if (right + 1 < s.size() && (freq[s[right + 1]] == 0)) { //ȷ�����鲻Խ��
				right++;
				freq[s[right]]++;
			}
			else {
				//��¼һ�´�ʱ�ĳ���
				//if (res < right - left + 1)
					//res = right - left + 1;
				res = max(res, right - left + 1);

				freq[s[left]]--;
				left++;
				
			}

		}

		return res;

	}
};


int main() {

	system("pause");
	return 0;
}