/*URL: https://leetcode.com/problems/convert-a-number-to-hexadecimal/#/description
 *Given an integer, write an algorithm to convert it to hexadecimal. For negative integer, two’s complement method is used.

Note:

All letters in hexadecimal (a-f) must be in lowercase.
The hexadecimal string must not contain extra leading 0s. If the number is zero, it is represented by a single zero character '0'; otherwise, the first character in the hexadecimal string will not be the zero character.
The given number is guaranteed to fit within the range of a 32-bit signed integer.
You must not use any method provided by the library which converts/formats the number to hex directly.
Example 1:

Input:
26

Output:
"1a"
Example 2:

Input:
-1

Output:
"ffffffff"
 * */
//Solution 1:
#define HEX_MAP(x)  ((x)["0123456789abcdef"])

char* toHex(int num) {
    static char tab[0x20];
    char *p = tab +0x20;
    unsigned int value = num;

    *--p = HEX_MAP(value&15);
    while (0!= (value>>=4))
        *--p = HEX_MAP (value &15);
    return (p);
}

// Solution 2:
//
char *toHex (int num) {
    unsigned int n = num;
    int size = 0;
    if(n==0) return "0";

    while (n>0) {
        n/=16;
        size++;
    }
    n = num;

    char *ans = (char*) malloc(sizeof(char*)*size);
    ans[size]='\0'; 
    while(n>0) {
        char c = n%16;
        (c<10)?(c+='0'):(c+='a'-10);
        n/=16;
        ans[--size] = c;
    }
    return ans;
}




