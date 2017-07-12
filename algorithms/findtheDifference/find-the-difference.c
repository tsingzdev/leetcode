/*URL: https://leetcode.com/problems/find-the-difference/#/description
 * Given two strings s and t which consist of only lowercase letters.
 *
 * String t is generated by random shuffling string s and then add one more letter at a random position.
 *
 * Find the letter that was added in t.
 *
 * Example:
 *
 * Input:
 * s = "abcd"
 * t = "abcde"
 *
 * Output:
 * e
 *
 * Explanation:
 * 'e' is the letter that was added.
 *
 * */
char findTheDifference(char* s, char* t) {
    char r = 0;
    int i = 0, j =0;
    while (s[i]) {
        r^=s[i];
        i++;
    }
    while(t[j]) {
        r^=t[j];
        j++;
    }
    return r;
}

