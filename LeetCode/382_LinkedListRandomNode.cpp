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
    ListNode *node;
    Solution(ListNode* head) {
        node = head;
    }
    
    int getRandom() {
        int ans, len = 1;
        ListNode *tmp = node;
        while(tmp){
            if(rand() % len == 0){
                ans = tmp->val;
            }
            len++;
            tmp = tmp->next;
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
