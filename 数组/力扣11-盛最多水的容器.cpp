//https://leetcode-cn.com/problems/container-with-most-water/

#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int res = 0;
        while (left < right) {
            //�ؼ��㣬ֵС��ָ���ƶ�
            int area = min(height[right], height[left]) * (right - left);
            if (res < area)
                res = area;

            if (height[left] <= height[right])
                left++;
            else // height[left] > height[right]
                right--;

        }
        return res;
    }
};

int main() {

	system("pause");
	return 0;
}