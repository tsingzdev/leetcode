//
//
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
		int k = 0;
		while (1) {
            if(n>m) {
                k = k+1;
            } else {
                return m<<k;
            }
            m = m>>1;
            n = n>>1;
		}
        return m;
    }
};

// Solution 2: 
//
class Solution {
    public:
        int rangeBitwiseAnd (int m , int n) {
            if (n>m) {
                return rangeBitwiseAnd(m>>1, n>>1) <<1;
            } else {
                return m;
            }
        }
}
