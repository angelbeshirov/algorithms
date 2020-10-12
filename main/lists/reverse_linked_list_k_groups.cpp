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


 /**
    Link: https://leetcode.com/problems/reverse-nodes-in-k-group

    Approach:
    @author angel.beshirov
 **/
#include<bits/stdc++.h>
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) {
            return head;
        }

        int len = 0;
        ListNode* temp = head;
        while(temp) {
            len++;
            temp = temp->next;
        }

        if(len < k) {
            return head;
        }

        ListNode* current = head;
        ListNode* next = head->next;
        ListNode* prev = NULL;

        int cnt = 0;

        while(current) {
            next = current->next;
            current->next = prev;

            prev = current;
            current = next;

            cnt++;
            if(cnt >= k) {
                break;
            }
        }

        if(next) {
            head->next = reverseKGroup(next, k);
        }

        return prev;

    }
};

int main() {
    ListNode* start = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    Solution m;

    ListNode* t = m.reverseKGroup(start, 3);

    while(t) {
        cout << t->val << " ";
        t = t->next;
    }
}
