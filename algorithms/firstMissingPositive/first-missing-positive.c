/* https://leetcode.com/problems/first-missing-positive/description/
 * Given an unsorted integer array, find the first missing positive integer.

* For example,
* Given [1,2,0] return 3,
* and [3,4,-1,1] return 2.
*
* Your algorithm should run in O(n) time and uses constant space.

*/

#include<stdio.h>
#include<assert.h>

/* ref : https://leetcode.com/problems/first-missing-positive/discuss/17071/My-short-c++-solution-O(1)-space-and-O(n)-time
 *
 * Algorithm: 
 * Put each number in its right place.

 * For example:
 * 
 * When we find 5, then swap it with A[4].
 * 
 * At last, the first place where its number is not right, return the place + 1.
 **/

/*Solution 1 */
int firstMissingPositive(int* nums, int numsSize) {
    int i;  
    for (i = 0; i< numsSize; i++) {
        while(nums[i] > 0 && nums[i]< numsSize && nums[nums[i]-1] != nums[i]) {

            int t = nums[i];
            nums[i] = nums[t-1]; 
            nums[t-1] = t; 
        }
    }

    for(i = 0; i<numsSize; i++) {
        if(nums[i]!=i+1) {
            break;
        }
    }
    return i+1;
}

/*Solution 2 */
void swap(int *a, int *b) {
    *a = *b-*a;
    *b = *b-*a;
    *a = *b+*a;
}

int firstMissingPositive_2(int* nums, int numsSize) {
    int i;
    for (i = 0; i < numsSize;) {
        if (nums[i]<=0 || nums[i] == i+1 || nums[i] > numsSize || nums[i]==nums[nums[i]-1])
            i++;
        else
            swap(&nums[i], &nums[nums[i]-1]);
    }
    for (i = 0; i < numsSize; i++)  {
        if(nums[i]!=i+1)
            break;
    }

    return i+1;
}

int main() {
    int nums0[] = {1, 2, 0};
    int nums1[] = {3, 4, -1, 1};
    int nums2[] = {-1, 4, 2, 1, 9, 10};
    int nums3[] = {1, 1};
    int nums4[] = {1, 2, 3};

    int p1 = firstMissingPositive_2(nums0, 3);
    int p2 = firstMissingPositive_2(nums1, 4);
    int p3 = firstMissingPositive_2(nums2, 6);
    int p4 = firstMissingPositive_2(nums3, 2);
    int p5 = firstMissingPositive(nums4, 3);

    printf("%d\n", p1);
    printf("%d\n", p2);
    printf("%d\n", p3);
    printf("%d\n", p4);
    printf("%d\n", p5);

    return 0;
}
