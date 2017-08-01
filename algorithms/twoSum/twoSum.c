// date:2016.03.08
// https://leetcode.com/problems/two-sum/
/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

UPDATE (2016/2/13):
The return format had been changed to zero-based indices. Please read the above updated description carefully. 

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int val;
    int index;
};
/****Solution1 :node qsort ******/
static int cmp (const void *a, const void *b) {
    return ((struct node *)a)->val - ((struct node *)b)->val;
}

int* twoSum_qsort(int* nums, int numsSize, int target) {
    int *ret;
    struct node *head;
    int i,j;
    int sum;    

    ret = (int *) malloc (sizeof(int)*2);
    head = (struct node *) malloc (sizeof (struct node) * numsSize) ;
    for (i = 0; i < numsSize; ++i) {
        head[i].index = i;
        head[i].val = nums[i];
    }

    qsort(head, numsSize, sizeof(struct node), cmp);

    i = 0;
    j = numsSize - 1;
    while (i<j) {
        sum = head[i].val + head[j].val;
        if (sum == target) {
            ret[0] = head[i].index < head[j].index ? head[i].index : head[j].index;
            ret[1] = head[i].index >= head[j].index ? head[i].index : head[j].index;
            break;
        } else if (sum > target) {
            --j;
        } else if (sum < target) {
            ++i;
        }
    }
    return ret;
}

/*****Solution2: hash table******/

typedef struct HashNode {
    int val;
    int key;
    struct HashNode * next;
} HashNode;

static inline int hash (int val, int n) {
    int index = val % n;
    return (index > 0) ? (index) : (-index);
}

int *twoSum (int numbers[], int n, int target) {
    static int ret[2] = {0,0};
    int i;

    HashNode **hashtable = (HashNode **) calloc (n, sizeof(HashNode *)); 

    int idx;
    HashNode *p, *tail;
    for (i = 0; i<n; i++) {
        idx = hash(numbers[i], n);
        p = hashtable[idx];
        tail = NULL;
        while (p!=NULL) {
            tail = p;
            p = p->next;
        }

        HashNode *new_node = (HashNode *) calloc (1, sizeof (HashNode)) ;
        new_node->val = numbers[i];
        new_node->key = i;
        new_node->next = NULL;
        
        if (tail) {
            tail->next = new_node;
        } else {
            hashtable [idx] = new_node;
        }
    }
    
    for (i = 0; i<n; i++) {
        int diff = target - numbers[i];
        idx = hash(diff, n);

        p = hashtable[idx];
        while ( p != NULL) {
            if (p->val ==diff && p->key != i) {
                ret[0] = p->key;
                ret[1] = i ;

                if (ret[0] > ret[1]) {
                    ret[0] = ret[0] ^ ret[1];
                    ret[1] = ret[0] ^ ret[1];
                    ret[0] = ret[0] ^ ret[1];
                }
                return ret;
            }
            p = p->next;
        }
    
    }

    return ret;
}

int main () {
    int nums[] = {3, 2, 4};
    int target = 6;
    
    int *index = twoSum_qsort(nums, sizeof(nums) / sizeof(nums[0]), target);

    printf("index0 = %d, index1 = %d\n", index[0], index[1] );

    return 0;
}

