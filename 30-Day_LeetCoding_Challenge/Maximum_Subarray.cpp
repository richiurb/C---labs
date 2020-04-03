#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        
        return maxSubArray(nums, l, r);
    }
    
    int maxSubArray(vector<int>& nums, int l, int r) {
        if (l == r) {
            return nums[l];
        } else {
            int m = (l + r) / 2;
            int first_ = 0; 
            int firstSum = INT_MIN; 
            for (int i = m; i >= l; i--) 
            { 
                first_ += nums[i]; 
                if (first_ > firstSum) 
                  firstSum = first_; 
            } 
 
            int second_ = 0; 
            int secondSum = INT_MIN; 
            for (int i = m + 1; i <= r; i++) 
            { 
                second_ += nums[i]; 
                if (second_ > secondSum) 
                  secondSum = second_; 
            } 
            
            return max(maxSubArray(nums, l, m), maxSubArray(nums, m + 1, r), firstSum + secondSum);
        }
    }
    
    int max(int a, int b, int c) {
        return ((c > a) && (c > b)) ? (c) : (std::max(a, b));
    }
};