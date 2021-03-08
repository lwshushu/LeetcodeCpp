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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        ListNode* previous = new ListNode(0, head);
        ListNode* cursor = head;
        ListNode* newHeader = nullptr;
        
        while(cursor)
        {
            if(!cursor->next)
            {
                previous->next = cursor;
                return !newHeader? cursor:newHeader;
            }
            else if(cursor->next->val == cursor->val)
            {
                while(cursor->next && cursor->next->val == cursor->val)
                {
                    cursor = cursor->next;
                }
                if(cursor)
                {
                    cursor = cursor->next;
                }
            }
            else
            {
                previous->next = cursor;
                cursor = cursor->next;
                previous = previous->next;
                if(!newHeader)
                {
                    newHeader = previous;
                }
            }
        }
        previous->next = cursor;
        return newHeader;
    }
};