/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
           vector<vector<int>> ans(m,vector<int>(n,-1));
        int r1=0,r2=m-1,c1=0,c2=n-1;
        
        while( (r1<=r2 && c1<=c2) && head){
            
            for(int i=c1;i<=c2 && head;i++){
                ans[r1][i]=head->val;
                head=head->next;
            }
            r1++;
            for(int i=r1;i<=r2 && head;i++){
                ans[i][c2]=head->val;
                head=head->next;
            }
            c2--;
            for(int i=c2;i>=c1 && head;i--){
                ans[r2][i]=head->val;
                head=head->next;
            }
            r2--;
            
            for(int i=r2;i>=r1 && head;i--){
                ans[i][c1]=head->val;
                head=head->next;
            }
            c1++;
            
            
        }
        return ans;
		// // Create a matrix of n x m with values filled with -1.
		// vector<vector<int>> spiral(n, vector<int>(m, -1));
		// int i = 0, j = 0;
		// // Traverse the matrix in spiral form, and update with the values present in the head list.
		// // If head reacher NULL pointer break out from the loop, and return the spiral matrix.
		// while (head != NULL)
		// {
		// if (j < m)
		// {
		// while (head != NULL && j < m && spiral[i][j] == -1)
		// {
		// spiral[i][j] = head->val;
		// head = head->next;
		// j++;
		// }
		// if (head == NULL)
		// break;
		// i++;
		// j--;
		// }
		// if (i < n)
		// {
		// while (head != NULL && i < n && spiral[i][j] == -1)
		// {
		// spiral[i][j] = head->val;
		// head = head->next;
		// i++;
		// }
		// i--;
		// j--;
		// }
		// if (j >= 0)
		// {
		// while (head != NULL && j >= 0 && spiral[i][j] == -1)
		// {
		// spiral[i][j] = head->val;
		// head = head->next;
		// j--;
		// }
		// j++;
		// i--;
		// }
		// if (i >= 0)
		// {
		// while (head != NULL && i >= 0 && spiral[i][j] == -1)
		// {
		// spiral[i][j] = head->val;
		// head = head->next;
		// i--;
		// }
		// i++;
		// j++;
		// }
		// n--;
		// m++;
		// }
		// // Rest values are itself -1.
		// return spiral;
    }
};