class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // if (!head) return head;

        // stack<int> st;
        // ListNode* temp = head;

        // // Push values to stack
        // while (temp != nullptr) {
        //     st.push(temp->val);
        //     temp = temp->next;
        // }

        // // Replace values from stack
        // temp = head;
        // while (temp != nullptr) {
        //     temp->val = st.top();
        //     st.pop();
        //     temp = temp->next;
        // }

        // return head;
        ListNode* prev = nullptr;
        ListNode* curr = head;
        
        while (curr != nullptr) {
            ListNode* nextNode = curr->next; // 1. Save the rest of the list
            curr->next = prev;              // 2. Reverse the link
            prev = curr;                    // 3. Move prev forward
            curr = nextNode;                // 4. Move curr forward
        }
        
        return prev;

    }
};
