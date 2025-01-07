#leetcode 324

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        vector<int> nums1(nums);
        
        // Sort the array
        sort(nums1.begin(), nums1.end());
        
        // Pointers to fill from the end and start of the sorted array
        int i = n - 1;
        int j = 0;
        int k = (n + 1) / 2;  // middle index, ceil(n / 2)
        
        // Fill nums[] with the wiggle order
        while (i >= 0) {
            // Fill the even indices (0, 2, 4, ...)
            if (i % 2 == 0) {
                nums[i] = nums1[j++];
            } 
            // Fill the odd indices (1, 3, 5, ...)
            else {
                nums[i] = nums1[k++];
            }
            i--;
        }
    }
};
