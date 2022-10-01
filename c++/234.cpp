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

    ListNode* reverse(ListNode* node) {
        if (node == nullptr) return nullptr;
        ListNode* head = node;
        while (node->next != nullptr) {
            ListNode* t = node->next;
            node->next = t->next;
            t->next = head;
            head = t;
        }
        return head;
    }

    bool isPalindrome(ListNode* head) {
        int n = 0;
        ListNode* ptr = head;
        while (ptr != nullptr) {
            n ++;
            ptr = ptr->next;
        }
        if (n == 0 || n == 1) return true;
        int ptr_begin = (n + 1) / 2;
        ptr = head;
        for (int i = 0; i < ptr_begin; i ++) 
            ptr = ptr->next;
        ListNode* r = reverse(ptr);
        ListNode* s = head;
        ListNode* t = r;
        bool is_palin = true;
        
        for (int i = 0; i < n - ptr_begin; i ++) {
            if (s->val != r->val) {
                is_palin = false;
                break;
            }
            s = s->next;
            r = r->next;
        }
        reverse(t);
        return is_palin;
    }
};
