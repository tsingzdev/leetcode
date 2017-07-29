/*URL: https://leetcode.com/problems/median-of-two-sorted-arrays/#/description
 *
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 *
 * Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 *
 * Example 1:
 * nums1 = [1, 3]
 * nums2 = [2]
 *
 * The median is 2.0
 * Example 2:
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 *
 * The median is (2 + 3)/2 = 2.5
 * */


double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {

	int *arr;
    int num = nums1Size + nums2Size;
    int i, j, k;
    double ret;

    arr = (int *) malloc (sizeof(int) * num);
    i = 0;
    j = 0;
    k = 0;
    while ( i < nums1Size && j < nums2Size)
        arr[k++] = nums1[i] < nums2[j] ? nums1[i++] : nums2[j++];

    while (i < nums1Size)
        arr [k++] = nums1[i++];
    while (j < nums2Size)
        arr [k++] = nums2[j++];

    if(num % 2)
        ret = arr[num/2];
    else
        ret = (arr[(num-1)/2] + arr[num/2])/2.0;

    free(arr);
    return ret;        
}



