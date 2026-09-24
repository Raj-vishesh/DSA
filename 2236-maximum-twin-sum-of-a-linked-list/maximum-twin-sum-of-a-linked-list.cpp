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
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* prev = nullptr;
        ListNode* curr = slow;
        while(curr != nullptr){
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        ListNode* firsthalf = head;
        ListNode* secondhalf = prev;
        int max_sum = 0;

        while(secondhalf != nullptr){
            int curr_sum = firsthalf->val + secondhalf->val;

            max_sum = max(curr_sum , max_sum);

            firsthalf = firsthalf->next;
            secondhalf = secondhalf->next;
        }

        return max_sum;

    }
};