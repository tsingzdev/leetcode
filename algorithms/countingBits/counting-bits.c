/*URL:https://leetcode.com/problems/counting-bits/#/description
 *Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

* Example:
* For num = 5 you should return [0,1,1,2,1,2].

* Follow up:

* It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
* Space complexity should be O(n).
* Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.
* */

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 * */

// Using DP, equation: arr[i] == i&1? arr[i/2]+1 : arr[i/2];
int* countBits(int num, int* returnSize) {
    num++;
    *returnSize = num;
    int* arr = (int*)malloc(sizeof(int)*num);
    arr[0] =0;
    for(int i =1; i<num; i++){
        arr[i] = (i&1)?arr[i>>1]+1 : arr[i>>1];
        // arr[i] = arr[i>>1] + (i&1);   // also wordks, but less readable than above^
    }
    return arr;
}
