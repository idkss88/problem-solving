
/**
 * Definition for singly-linked list.
 **/
 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* cur1 = list1;
        ListNode* cur2 = list2;
        ListNode* front = nullptr;    
        ListNode* tail = nullptr;    
        while (cur1 != nullptr || cur2 != nullptr) {
            while( cur1 != nullptr) {
                if (cur2 == nullptr || (cur1->val <= cur2->val)) {
                    if (front == nullptr) {
                        front = new ListNode(cur1->val);
                        tail = front;
                    } else {
                         ListNode* temp = new ListNode(cur1->val);
                         tail->next = temp;
                         tail = temp;
                    }
                    
                    cur1 = cur1->next;
                } else {
                    break;
                }
            }
            while( cur2 != nullptr) {
                if (cur1 == nullptr || (cur1->val > cur2->val)) {
                    if (front == nullptr) {
                        front = new ListNode(cur2->val);
                        tail = front;
                    } else {
                        ListNode* temp = new ListNode(cur2->val);
                         tail->next = temp;
                         tail = temp;
                    }
                    cur2 = cur2->next;
                } else {
                    break;
                }
            }
        }

        return front;
    }
};