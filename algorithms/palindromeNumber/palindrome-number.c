//https://leetcode.com/problems/palindrome-number/description/

#define INT_MAX 2147483647
#define INT_MIN -INT_MAX-1

bool isPalindrome(int x) {
    if ( x < 0) {
        return false;
    }
    if (x == 0) {
        return true;
    }

    int reversed = 0;
    int tmp = x;
    while (tmp > 0) {
        reversed = reversed *10 + tmp%10;
        tmp/=10;
    }

    if (reversed > INT_MAX || reversed < INT_MIN )  
        return false;

    if (reversed == x) {
        return true;
    } else {
        return false;
    }
}

//Solution2: 
bool isPalindrome(int x) {
    if(x < 0) {
        return false;
    }

    int divisor = 1;
    while (x / divisor >= 10) {
        divisor *= 10;
    }

    for (; x > 0; x = (x % divisor) / 10, divisor /= 100) {
        int left = x / divisor;
        int right = x % 10;
        if (left != right) {
            return false;
        }
    }

    return true;
}

