//https://leetcode.com/problems/unique-binary-search-trees/description/
/*Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
   
*/

/*Strategy: consider each value could be root, 
 * recur find the size of the left and right subtrees*/
//
// Run Code Status: Time Limit Exceeded
int numTrees(int n) {
    struct node * node;
    if(n<=1) return 1;
    else {
        int sum = 0;
        int left, right, root;
        for(int root=1; root<=n; root++) {
            left = numTrees(root-1);
            right = numTrees(n-root);
            sum+=left*right;
        }
        return sum;
    }
}

// Solution 2: Accepted
int numTrees(int n) {
    int count[128] = {0};
    count[0] = count[1] = 1;
    count[2] = 2; 
    for (int i = 3; i<128; i++) {
        for (int j = 0; j<i; j++) {
            count[i]+=count[j]*count[i-j-1];
        }
    
    }
    return count[n];
}

// Solution 3: Accepted
int numTrees(int n) {
    if(n<3) return n;
    int *d = (int*) calloc(n+1, sizeof(int));
    int i, j;
    d[0] = 1; /*dummy*/
    d[1] = 1;
    d[2] = 2;

    for(i = 3; i<=n;i++){
        for(j=0; j<i; j++) {
            d[i]+=d[j]*d[i-1-j];
        }
    }
    return d[n];
}

