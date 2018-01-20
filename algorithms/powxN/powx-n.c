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
// 1. Time Limit Exceeded caused by the while loop; 2. Also neglect the case when n < 0.
double myPow_0(double x, int n) {
    double ret = 1.00;    
    while (n ) {
        ret = ret*x;
        n--;
    }
    return ret;
}

//Solution 1: accepted.
double myPow(double x, int n) {
    if (n ==0) return 1;     
    if (n < 0) return 1/x * myPow(1/x, -(n+1));
    if (n==2) return x*x;

    if (n%2==0) return myPow( myPow(x, n/2), 2);
    else return x*myPow( myPow(x, n/2), 2);
}


int main () {
    double x = 2.0000; 
    int n = 10;
    double r = myPow(x, n);
    printf("result is %f\n", r);
    printf("result is %f\n", myPow(2.10000, 3));

}
