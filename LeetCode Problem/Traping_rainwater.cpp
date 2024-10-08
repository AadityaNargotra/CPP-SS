/*
Link: https://leetcode.com/problems/trapping-rain-water/
42. Trapping Rain Water
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.


Example 1:
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

Example 2:
Input: height = [4,2,0,3,2,5]
Output: 9
 
Constraints:
n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int trap(vector<int>& height) {         //Solution 1
    int water_trap=0, s=height.size(), left=0, right[s];
    right[s-1]=height[s-1];
    for(int i=s-2;i>=0;i--){
        if(height[i]>right[i+1]) right[i]=height[i];
        else right[i]=right[i+1];
    }
    for(int i=0;i<s;i++){
        if(left<height[i]) left=height[i];
        water_trap+=min(left,right[i])-height[i];
    }
    return water_trap;
}

int trap(vector<int>& height) {         //Solution 2
    int water_trap=0, s=height.size();
    int left[s];int right[s];
    left[0]=height[0];
    for(int i=1;i<s;i++){
        if(height[i]>left[i-1]) left[i]=height[i];
        else left[i]=left[i-1];
    }
    right[s-1]=height[s-1];
    for(int i=s-2;i>=0;i--){
        if(height[i]>right[i+1]) right[i]=height[i];
        else right[i]=right[i+1];
    }
    for(int i=0;i<s;i++){
        water_trap+=min(left[i],right[i])-height[i];
    }
    return water_trap;
}

int main(){
    return 0;
}