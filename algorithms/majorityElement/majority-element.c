/* URL: https://leetcode.com/problems/majority-element/#/description
 * Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
 *
 * You may assume that the array is non-empty and the majority element always exist in the array.
 * */
#include <stdlib.h>
#include <stdio.h>


//reference: http://www.cs.utexas.edu/~moore/best-ideas/mjrty/index.html
int majorityElement(int* nums, int numsSize) {
    int ret ;
    int cnt = 0 ;

    for (int i = 0; i< numsSize; i++) {
        if (cnt ==0) {
            ret = nums[i];
            cnt ++;
        } else {
            ret == nums[i] ? cnt++ : cnt --; 
            //if (cnt >= numsSize/2) 
            //    return ret;
        }
    } 
    return ret;
}

// solution 2
int majorityElement2(int* nums, int numsSize) {
    int major;
    int i;

    major = nums[0];
    int count = 1;

    for ( i = 1; i < numsSize; i++) {
        if (nums[i] == major)
            count++;
        else count --;

        if (count == 0) {
            major = nums[i];
            count = 1;
        }
    
    }

    return major;

}

int main(int argc, char** argv)
{
    int array[] = {3,3,3,3,3,3,1,2,1,2,1};
    int array2[] = {8,8,7,7,7};

    printf("%d\n", majorityElement(array, 11));
    printf("%d\n", majorityElement2(array, 11));
    printf("%d\n", majorityElement(array2, 5));
    printf("%d\n", majorityElement2(array2, 5));

    return 0;
}
