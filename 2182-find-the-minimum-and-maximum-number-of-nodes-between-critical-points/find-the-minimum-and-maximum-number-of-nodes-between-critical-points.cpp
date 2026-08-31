class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        int pos = 1;
        int first = -1;
        int prevCritical = -1;
        
        int minDist = INT_MAX;
        int maxDist = -1;

        ListNode* prev = head;
        ListNode* curr = head->next;

        while (curr->next != nullptr) {
            
            ListNode* next = curr->next;

            if ((curr->val > prev->val && curr->val > next->val) ||
                (curr->val < prev->val && curr->val < next->val)) {
                
                if (first == -1) {
                    first = pos;
                }

                if (prevCritical != -1) {
                    minDist = min(minDist, pos - prevCritical);
                }

                prevCritical = pos;
            }

            prev = curr;
            curr = next;
            pos++;
        }

        if (first == -1 || first == prevCritical) {
            return {-1, -1};
        }

        maxDist = prevCritical - first;

        return {minDist, maxDist};
    }
};