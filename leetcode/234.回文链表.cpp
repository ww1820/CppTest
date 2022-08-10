/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 */

// @lc code=start
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
#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// class Solution {
// public:
//     bool isPalindrome(ListNode* head) {
//         // int n = 0;
//         vector<int> vec;
//         ListNode *ptr = head;
//         while (ptr != nullptr)
//         {
//             // ++n;
//             vec.emplace_back(ptr->val);
//             ptr = ptr->next;
//         }

//         int l = 0;
//         int r = vec.size() - 1;
//         while (l < r)
//         {
//             if(vec[l] != vec[r])
//                 return false;
//             ++l;
//             --r;
//         }

//         return true;
//     }
// };

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        int n = 0;
        ListNode *cur = head;
        while (cur != nullptr)
        {
            ++n;
            cur = cur->next;
        }

        // 反转前 n/2 个链表
        ListNode *prev = nullptr;
        cur = head;
        ListNode *next = cur->next;
        int i = 0;
        while (++i <= n / 2)
        {
            cur->next = prev;
            prev = cur;
            cur = next;
            next = next->next;
        }

        if(n&1) {
            cur = cur->next;
        }

        while (prev != nullptr && cur != nullptr && prev->val == cur->val)
        {
            prev = prev->next;
            cur = cur->next;
        }

        return prev == nullptr && cur == nullptr;
    }
};


// @lc code=end

