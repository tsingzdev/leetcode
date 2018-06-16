//https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/
/*Given an unsorted array of integers, find the number of longest increasing subsequence.
 * 
 *   Example 1:
 * Input: [1,3,5,4,7]
 * Output: 2
 * Explanation: The two longest increasing subsequence are [1, 3, 4, 7] and [1, 3, 5, 7].
 * Example 2:
 * Input: [2,2,2,2,2]
 * Output: 5
 * Explanation: The length of longest continuous increasing subsequence is 1, and there are 5 subsequences' length is 1, so output 5.
 * Note: Length of the given array will be not exceed 2000 and the answer is guaranteed to be fit in 32-bit signed int.
*/

class NumberofLongestIncreasingSubsequence {
    public static void main(String[] args) throws Exception {
        int[] A = {1,3,5,4,7};
        System.out.println(new NumberofLongestIncreasingSubsequence().findNumberOfLIS2(A));
    }

    // Solution 1:
    public int findNumberOfLIS(int[] nums) {
        if(nums.length == 0) return 0;
        int[] length = new int[nums.length];
        length[0] = 1;
        int maxVal = 1;
        for(int i = 1; i < nums.length; i ++){
            int max = 1;
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    max = Math.max(max, length[j] + 1);
                    maxVal = Math.max(maxVal, max);
                }
            }
            length[i] = max;
        }
        int[] count = new int[nums.length];
        count[0] = 1;
        for(int i = 1; i < length.length; i ++){
            for(int j = 0; j < i; j++){
                if((length[j] + 1 == length[i]) && (nums[j] < nums[i])){
                    count[i] += count[j];
                }
            }
            if(count[i] == 0){
                count[i] = 1; //default is just 1
            }
        }
        int ans = 0;
        for(int i = 0; i < length.length; i ++){
            if(length[i] == maxVal){
                ans += count[i];
            }
        }
        return ans;
    }

    //Solution 2: 
    /* The idea is to use two arrays len[n] and cnt[n] to record the maximum length of Increasing
     * Subsequence and the coresponding number of these sequence which ends 
     * with nums[i], respectively. That is:

    * len[i]: the length of the Longest Increasing Subsequence which ends with nums[i].
    * cnt[i]: the number of the Longest Increasing Subsequence which ends with nums[i].

    * Then, the result is the sum of each cnt[i] while its corresponding 
    * len[i] is the maximum length.
    * */
    public int findNumberOfLIS2(int[] nums) {
        int n = nums.length, res = 0, max_len = 0;
        int[] len = new int[n], cnt = new int[n];
        for(int i =0; i<n; i++) {
            len[i] = cnt[i] =1;
            for(int j =0; j<i; j++) {
                if(nums[i] > nums[j]) {
                    if(len[i] == len[j] + 1) 
                        cnt[i] += cnt[j];
                    if(len[i] < len[j]+1) {
                        len[i] = len[j] +1;
                        cnt[i] = cnt[j];
                    }
                }
            }
            if (max_len == len[i]) res+=cnt[i]; 
            if (max_len < len[i]) {
                max_len = len[i];
                res = cnt[i];
            }
        }
        return res;
    }
}

