/*URL:https://leetcode.com/problems/two-sum/#/description
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 *
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 *
 * Example:
 * Given nums = [2, 7, 11, 15], target = 9,
 *
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 *
 * */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 * */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    int idx;
    int data;
} Node;

int compar (const void  *p1, const void *p2) {
    if ( ((Node *)p1)->data < ((Node *)p2)->data ) return -1;
    else if ( ((Node *)p1)->data > ((Node *)p2)->data ) return 1;
    else return 0;
}

int* twoSum(int* numbers, int n, int target) {
    int i,j;
    static int ret[2] = {0,0};
    Node *num_nodes = (Node *) calloc(n,sizeof(Node));

    for (i = 0; i<n; i++) {
        num_nodes[i].idx = i+1;
        num_nodes[i].data = numbers[i];
    }
        
    qsort(num_nodes, n, sizeof(Node), compar); 

    i = 0; j = n-1;   
    while(i<n && j>=0) {
        if (num_nodes[i].data + num_nodes[j].data == target) {
            ret[0] = num_nodes[i].idx;
            ret[1] = num_nodes[j].idx;
            if(ret[0] > ret[1]) {
                int t = ret[1];
                ret[1] = ret[0];
                ret[0] = t;
            }
            return ret;
        }
        else if (num_nodes[i].data + num_nodes[j].data < target){
            i++;
        }
        else {
            j++;
        }
    }
    return ret;
}

int main () {
    int numbers[] = {0,2,4,5,6,8,10};
    int target = 11;

    int *index = twoSum(numbers, sizeof(numbers)/sizeof(numbers[0]), target);

    int i;
    for(i = 0; i<2; i++) {
        printf("index%d = %d, ", i+1, index[i]);
    }

    printf("\n");
    return 0;

}
