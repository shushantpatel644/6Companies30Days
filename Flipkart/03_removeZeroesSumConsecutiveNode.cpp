/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 Iterate LinkedList from left to right
Process each accumulative value in this datastructure. (unordered_map<int,ListNode*>um) um[ac] = currentNode;
Given a current accumulative value check if exists in our map (get previous element).
If they exist um[ac]->next = currentNode->next, then delete intermediate nodes in our map between um[ac] and currentNode

 */
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    ListNode *removeZeroSumSublists(ListNode *head)
    {
        ListNode *root = new ListNode(0);
        root->next = head;
        unordered_map<int, ListNode *> um;
        um[0] = root;
        int ac = 0;

        while (head != NULL)
        {
            ac += head->val;

            // found
            if (um.find(ac) != um.end())
            {
                ListNode *prev = um[ac];
                ListNode *start = prev;

                // bad reference
                int aux = ac;
                while (prev != head)
                {
                    prev = prev->next;
                    aux += prev->val;
                    if (prev != head)
                        um.erase(aux);
                }
                start->next = head->next;
            }
            else
            {
                um[ac] = head;
            }
            head = head->next;
        }
        return root->next;
    }
};

// Time Complexity: O(n) where n is the length of head
// Space Complexity: O(n) where n is the length of head