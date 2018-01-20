// URL: https://leetcode.com/problems/powx-n/description/
/*Implement pow(x, n).


Example 1:

Input: 2.00000, 10
Output: 1024.00000
Example 2:

Input: 2.10000, 3
Output: 9.26100
*/

#include <stdio.h>

// Solution 0:
// Time Limit Exceeded !!
double 0_myPow(double x, int n) {
    double ret = 1.00;    
    while (n ) {
        ret = ret*x;
        n--;
    }
    return ret;
}

//Solution 1:
double myPow(double x, int n) {
        
}



int main () {
    double x = 2.0000; 
    int n = 10;
    double r = myPow(x, n);
    printf("result is %f\n", r);
    printf("result is %f\n", myPow(2.10000, 3));

}
