/*https://leetcode.com/problems/hamming-distance/#/description
 *  The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
 * 
 *  Given two integers x and y, calculate the Hamming distance.
 * 
 * Note:
 * 0 ≤ x, y < 231.
 * 
 * Example:
 * 
 * Input: x = 1, y = 4
 * 
 * Output: 2
 * 
 * Explanation:
 * 1   (0 0 0 1)
 * 4   (0 1 0 0)
 *        ↑   ↑
 * 
 * The above arrows point to positions where the corresponding bits are different.
 */
#include <stdio.h>

int hammingDistance(int x, int y) {
    int hdis = 0;
    int tmp = 0;
    tmp = x^y;
    while(tmp) {
        tmp = tmp&(tmp-1);
        hdis++;
    }
    return hdis; 
}

int main( ) {
	int x = 1;
	int y = 4;
	printf("hamming distance of x and y is %d\n", hammingDistance(1,4));
}
