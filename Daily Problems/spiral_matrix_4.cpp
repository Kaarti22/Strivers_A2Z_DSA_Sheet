/*
Link: https://leetcode.com/problems/spiral-matrix-iv/description/

You are given two integers m and n, which represent the dimensions of a matrix.

You are also given the head of a linked list of integers.

Generate an m x n matrix that contains the integers in the linked list presented in spiral order (clockwise), starting from the top-left of the matrix. If there are remaining empty spaces, fill them with -1.

Return the generated matrix.

 

Example 1:


Input: m = 3, n = 5, head = [3,0,2,6,8,1,7,9,4,2,5,5,0]
Output: [[3,0,2,6,8],[5,0,-1,-1,1],[5,2,4,9,7]]
Explanation: The diagram above shows how the values are printed in the matrix.
Note that the remaining spaces in the matrix are filled with -1.
Example 2:


Input: m = 1, n = 4, head = [0,1,2]
Output: [[0,1,2,-1]]
Explanation: The diagram above shows how the values are printed from left to right in the matrix.
The last space in the matrix is set to -1.
 

Constraints:

1 <= m, n <= 105
1 <= m * n <= 105
The number of nodes in the list is in the range [1, m * n].
0 <= Node.val <= 1000
*/

#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>ans(m, vector<int>(n, -1));
        pair<int, int>topLeft = {0, 0};
        pair<int, int>topRight = {0, n - 1};
        pair<int, int>bottomLeft = {m - 1, 0};
        pair<int, int>bottomRight = {m - 1, n - 1};
        ListNode* temp = head;
        while(temp){
            for(int i=topLeft.second; i<=topRight.second && temp; i++){
                ans[topLeft.first][i] = temp->val;
                temp = temp->next;
            }
            for(int i=topRight.first+1; i<=bottomRight.first && temp; i++){
                ans[i][topRight.second] = temp->val;
                temp = temp->next;
            }
            for(int i=bottomRight.second-1; i>=bottomLeft.second && temp; i--){
                ans[bottomLeft.first][i] = temp->val;
                temp = temp->next;
            }
            for(int i=bottomLeft.first-1; i>topLeft.first && temp; i--){
                ans[i][topLeft.second] = temp->val;
                temp = temp->next;
            }
            topLeft.first++, topLeft.second++;
            topRight.first++, topRight.second--;
            bottomLeft.first--, bottomLeft.second++;
            bottomRight.first--, bottomRight.second--;
        }
        return ans;
    }
};