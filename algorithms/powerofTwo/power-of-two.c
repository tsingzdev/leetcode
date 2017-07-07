/*url:https://leetcode.com/problems/power-of-two/#/description
 *Given an integer, write a function to determine if it is a power of two.
 *
 * */
//#include <stdio.h>
//#include <stdbool.h>

bool isPowerOfTwo(int n) {
    if (n <=0)
        return 0;
    else if (!( n & n-1 ))   // note that the !(n&n-1), the brackets needed. 
        return 1;
    else return 0;        
        
}

