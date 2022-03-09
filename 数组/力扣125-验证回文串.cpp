#include<iostream>
using namespace std;

//和剑指18一样
//https://leetcode-cn.com/problems/valid-palindrome/
//https://leetcode-cn.com/problems/XltzEq/
class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty()) return true;

        //把无用字符串去掉
        string s1;
        for (int i = 0; i < s.size(); i++) {
            if (('A' <= s[i] && s[i] <= 'Z') || ('0' <= s[i] && s[i] <= '9'))
                s1.insert(s1.end(), s[i] + 32);
            else if ('a' <= s[i] && s[i] <= 'z')
                s1.insert(s1.end(), s[i]);

        }
        if (s1.size() <= 1) return true;

        for (int i = 0; i < s1.size() / 2; i++) {
            if (s1[i] != s1[s1.size() - 1 - i])
                return false;
        }


        return true;
    }
};


int main() {

	system("pause");
	return 0;
}