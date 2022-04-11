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

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode *l1Node = l1;
        ListNode *l2Node = l2;
        ListNode *newNode =  nullptr;
        ListNode *nextNode = nullptr;
        int carry = 0;
        while (l1Node != nullptr || l2Node != nullptr) {
            int value = 0;
            int value2 = 0;
            int remains = 0;
         
            if (l1Node != nullptr) {
                value += l1Node->val;
                l1Node =  l1Node->next;
            }

            if (l2Node != nullptr) {
                value += l2Node->val;
                l2Node = l2Node->next;        
            }

           
            remains = (value+carry) %10;
            carry = (value+carry)/10;
            
            if (newNode == nullptr) {
                cout<<"create head Node" <<endl;
                newNode = new ListNode(remains);
                nextNode = newNode;
            } else {
                 cout<<"append new Node" <<endl;
                ListNode* temp = new ListNode(remains);
                nextNode->next = temp;
                nextNode = nextNode->next;
            }

        }
        
        //last carry applied .
        if (carry) {
                ListNode* temp = new ListNode(1);
                nextNode->next = temp;
                nextNode = nextNode->next;
        }

        return newNode;
    }
};

int main(void) {

    ListNode *s1 = new ListNode(2);
    s1->next =  new ListNode(4);
    s1->next->next = new ListNode(3);

    ListNode *s2 = new ListNode(5);
    s2->next =  new ListNode(6);
    s2->next->next = new ListNode(4);

    Solution s;
    
    ListNode *result = s.addTwoNumbers(s1,s2);

    ListNode *curr = result;
    while (curr!= nullptr) {
        cout << curr->val <<endl;
        curr = curr->next;
    }
    
    return 0;
}