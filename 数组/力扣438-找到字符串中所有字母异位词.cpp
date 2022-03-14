#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	vector<int> findAnagrams(string s, string p) {
		int len_s = s.size(), len_p = p.size();
		vector<int> ans(26, 0);
		vector<int> freq(26, 0);
		vector<int>res;
		if (len_s < len_p) return res;
		for (int i = 0; i < len_p; i++) {
			ans[p[i] - 'a']++;
			freq[s[i] - 'a']++;
		}
		int left = 0, right = left + len_p - 1; //[left,right]

		while (left < len_s - len_p + 1) {
			if (ans == freq)
				res.push_back(left);

			freq[s[left] - 'a']--;
			left++;
			if (right < len_s - 1) {
				right++;
				freq[s[right] - 'a']++;
			}

		}

		return res;
	}
};

int main() {

	Solution s1;
	s1.findAnagrams("cbaebabacd", "abc");

	system("pause");
	return 0;
}