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
 //			if (isSame(freqS, freqT)) { //左边界++
 //                if(res > right - left + 1){
 //                    res = right - left + 1;
 //				    resStr = s.substr(left, right - left + 1);// 第一个参数起始位置，第二个参数长度
 //                }		
 //				freqS[s[left] - 'A']--;
 //				left++;
 //			}
 //			else {
 //				if (right < len_s - 1) {
 //					right++;
 //					freqS[s[right] - 'A']++;
 //				}
 //				else {//右边界到头了，如果还不相等，可以退出
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


//优化1,每次判断两个数组是否相同耗费时间，所有用一个变量记录当前字串中还差几个元素满足
class Solution {
public:
	string minWindow(string s, string t) {

		int len_s = s.size(), len_t = t.size();
		if (len_s < len_t) return "";
		vector<int> need(128, 0);
		int res = len_s + 1, needCount = len_t; // needCount:需要的元素数量，res:子字符串长度
		int start = 0; //起始位置
		for (char c : t)
			need[c]++;

		int left = 0, right = -1;
		while (left < len_s - len_t + 1) {
			if (!needCount) { //左边界++
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
				else {//右边界到头了，如果还不相等，可以退出
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