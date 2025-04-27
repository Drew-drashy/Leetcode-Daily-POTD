class Solution {
public:
    int countSubarrays(vector<int>& nums) {
         int count = 0;

    // Iterate through the array, considering all subarrays of length 3
    for (int i = 1; i < nums.size() - 1; ++i) {
        // Extract the three numbers of the current subarray
        int first = nums[i-1];
        int middle = nums[i ];
        int third = nums[i +1];

        // Check the condition: sum of first and third equals half of middle
        if (first + third == middle / 2.0) {
            ++count;
        }
    }

    return count;
}
    
};