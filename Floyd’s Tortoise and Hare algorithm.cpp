
// Floyd’s Tortoise and Hare algorithm is a cycle detection algorithm used in linked lists or sequences. It involves two pointers:

// Tortoise (slow pointer): Moves one step at a time.
// Hare (fast pointer): Moves two steps at a time.
// The algorithm consists of two phases:

// Detecting a Cycle: If a cycle exists, the tortoise and hare will eventually meet inside the cycle.
// Finding the Cycle Start: After detecting the cycle, find the node where the cycle begins.
// Explanation:
// Phase 1: Detect Cycle:

// Use two pointers (slow and fast).
// Move slow by one step and fast by two steps.
// If they meet, a cycle exists. If fast reaches nullptr, there is no cycle.
// Phase 2: Find the Start of the Cycle:

// Reset slow to the head of the list.
// Move both slow and fast one step at a time. They will meet at the starting node of the cycle.
// Complexity:
// Time Complexity: O(n)
// Space complexity: O(1)

#include <iostream>
using namespace std;

// Definition for a linked list node
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        if (!head || !head->next) return nullptr;

        // Phase 1: Detect cycle
        ListNode* slow = head;
        ListNode* fast = head;
        do {
            slow = slow->next;            // Move slow pointer by 1 step
            fast = fast->next->next;      // Move fast pointer by 2 steps
            if (!fast || !fast->next) return nullptr;  // No cycle
        } while (slow != fast);

        // Phase 2: Find the start of the cycle
        slow = head;  // Reset slow pointer to the head
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;  // The start of the cycle
    }
};

int main() {
    // Create a linked list with a cycle
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next;  // Create a cycle

    Solution solution;
    ListNode* cycleStart = solution.detectCycle(head);

    if (cycleStart) {
        cout << "Cycle detected at node with value: " << cycleStart->val << endl;
    } else {
        cout << "No cycle detected." << endl;
    }

    return 0;
}
