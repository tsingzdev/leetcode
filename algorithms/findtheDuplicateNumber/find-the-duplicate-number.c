/* https://leetcode.com/problems/find-the-duplicate-number/description/
 * Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.
 * 
 * Example 1:
 * 
 * Input: [1,3,4,2,2]
 * Output: 2
 * Example 2:
 * 
 * Input: [3,1,3,4,2]
 * Output: 3
 * Note:
 * 
 * You must not modify the array (assume the array is read only).
 * You must use only constant, O(1) extra space.
 * Your runtime complexity should be less than O(n2).
 * There is only one duplicate number in the array, but it could be repeated more than once.
 * */
//Solution 1:
int findDuplicate(int* nums, int size) {
    int *arr = (int*)malloc(sizeof(int)*size);
    memset(arr, 0, sizeof(int)*size);
    for(int i=0; i<size; i++) {
        arr[nums[i]]++;
        if(arr[nums[i]]>1)
            return nums[i];
    }
    return 0;
}


//Solution 2: using binary search
int findDuplicate(int* nums, int numsSize) {
    int l=1, h=numsSize-1;
    while(l<h) {
        int m = (l+h)/2;
        int count = 0;
        for(int i=0; i<numsSize; i++) 
            if(nums[i]>=l && nums[i]<=m ) count++;
        if(count <=m-l+1) l=m+1;
        else h = m;
    }
    return l;
}

//Solution 3:
int findDuplicate(int* nums, int size) {
    if(size>0) {
        int slow = nums[0];
        int fast = nums[nums[0]];
        while(slow != fast) { //check the existance of the loop
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        fast = 0;
        while(slow != fast) { // find the start of the loop which means 
                              //at least two integer are the same value
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
    return -1;
}

