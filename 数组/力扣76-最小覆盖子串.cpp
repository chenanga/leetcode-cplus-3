#include<iostream>
#include<vector>

using namespace std;

 //class Solution {
 //public:
 //	string minWindow(string s, string t) {

 //		int len_s = s.size(), len_t = t.size();
 //		if (len_s < len_t) return "";
 //		vector<int> freqS('z' - 'A' + 1, 0), freqT('z' - 'A' + 1, 0);
 //		int res = len_s + 1;
 //		string resStr = "";
 //		for (int i = 0; i < len_t; i++) {
 //			freqT[t[i] - 'A']++;
 //			freqS[s[i] - 'A']++;

 //		}
 //		if (freqS == freqT) return s.substr(0, len_t );
 //		int left = 0, right = len_t - 1;
 //		while (left < len_s - len_t + 1) {
 //			if (isSame(freqS, freqT)) { //��߽�++
 //                if(res > right - left + 1){
 //                    res = right - left + 1;
 //				    resStr = s.substr(left, right - left + 1);// ��һ��������ʼλ�ã��ڶ�����������
 //                }		
 //				freqS[s[left] - 'A']--;
 //				left++;
 //			}
 //			else {
 //				if (right < len_s - 1) {
 //					right++;
 //					freqS[s[right] - 'A']++;
 //				}
 //				else {//�ұ߽絽ͷ�ˣ����������ȣ������˳�
 //					break;
 //				}			
 //			}		
 //		}	
 //		return resStr;
 //	}
 //private:
 //	bool isSame(vector<int>& freqS, vector<int>& freqT) {

 //		for (int i = 0; i < freqT.size(); i++) {
 //			if (freqT[i] != 0 && freqS[i] < freqT[i])
 //				return false;
 //		}
 //		return true;

 //	}
 //};


//�Ż�1,ÿ���ж����������Ƿ���ͬ�ķ�ʱ�䣬������һ��������¼��ǰ�ִ��л����Ԫ������
class Solution {
public:
	string minWindow(string s, string t) {

		int len_s = s.size(), len_t = t.size();
		if (len_s < len_t) return "";
		vector<int> need(128, 0);
		int res = len_s + 1, needCount = len_t; // needCount:��Ҫ��Ԫ��������res:���ַ�������
		int start = 0; //��ʼλ��
		for (char c : t)
			need[c]++;

		int left = 0, right = -1;
		while (left < len_s - len_t + 1) {
			if (!needCount) { //��߽�++
				if (res > right - left + 1) {
					res = right - left + 1;
					start = left;
				}
				need[s[left]]++;
				if (need[s[left]] > 0) needCount++;
				left++;
			}
			else {
				if (right < len_s - 1) {
					right++;
					if (need[s[right]] > 0)
						needCount--;
					need[s[right]]--;
				}
				else {//�ұ߽絽ͷ�ˣ����������ȣ������˳�
					break;
				}
			}
		}
		if (res == len_s + 1)
			return "";
		return s.substr(start, res);
	}

};



int main() {
	/*vector<int>res;
	res.push_back(0);
	res.push_back(0);
	res.push_back(1);*/

	Solution s;
	cout<< s.minWindow("ADOBECODEBANC", "ABC");
	//string s1 = "abcdefgh";
	//cout << s1.substr(0, 1);


	system("pause");
	return 0;
}