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

 struct ListNode {
      int val;
     ListNode *next;
      ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        
        ListNode* ans = nullptr; 
        if (head == nullptr) return nullptr;
        
        ListNode* first  = head;
        ListNode* second = first->next;
        ListNode* temp = nullptr;
        if (second == nullptr) return first;
        ans = second;
        
        while (first != nullptr && second != nullptr  ) {
            if (second->next == nullptr) {
                second->next = first;
                first->next =  nullptr;
                break;
            } else if (second->next->next == nullptr) {

                temp = second->next;

                second->next = first;
                first->next = temp;

                break;
            }
            
            first->next = second->next->next;
            temp = second->next;
            second->next = first;
            
            first = temp;
            second = first->next;
        }
    
        return ans;
    }
};