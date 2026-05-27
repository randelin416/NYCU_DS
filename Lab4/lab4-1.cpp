#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

class ListNode {
    int val;

public:
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}

    void print() {
        ListNode* p = this;
        while (p) {
            printf("%d ", p->val);
            p = p->next;
        }
        printf("\n");
    }
};

ListNode* reverse_even_group(ListNode* head);

int main() {
    int T = 0;
    scanf("%d", &T);

    while (T--) {
        int n = 0, tmp = 0;
        ListNode* head = new ListNode(); // dummy head
        ListNode* tail = head;
        ListNode* reversed_head = nullptr;

        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &tmp);
            tail = tail->next = new ListNode(tmp);
        }
        tail->next = nullptr;

        reversed_head = reverse_even_group(head->next);
        reversed_head->print(); // Print the reversed list

        // Free the list
        while (reversed_head) {
            ListNode* temp = reversed_head;
            reversed_head = reversed_head->next;
            delete temp;
        }
        delete head; // Free the dummy head
    }

    return 0;
}

// Your code starts here

ListNode* reverse_segment(ListNode* start, int len, ListNode** new_tail) {
    ListNode* prev = nullptr;
    ListNode* curr = start;

    for (int i = 0; i < len; i++) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    // After reversing:
    // prev is the new head of this segment
    // start becomes the tail of this segment
    start->next = curr;
    *new_tail = start;

    return prev;
}

ListNode* reverse_even_group(ListNode* head) {
    if (!head) return nullptr;

    ListNode dummy(0);
    dummy.next = head;

    ListNode* prevGroupTail = &dummy;
    ListNode* curr = head;

    int groupSize = 1;

    while (curr) {
        ListNode* groupStart = curr;
        int actualLen = 0;

        // Count the actual length of this group
        while (curr && actualLen < groupSize) {
            curr = curr->next;
            actualLen++;
        }

        if (actualLen % 2 == 0) {
            ListNode* newTail = nullptr;
            ListNode* newHead = reverse_segment(groupStart, actualLen, &newTail);

            prevGroupTail->next = newHead;
            prevGroupTail = newTail;
        } else {
            // Move prevGroupTail to the end of this odd-length group
            prevGroupTail = groupStart;
            for (int i = 1; i < actualLen; i++) {
                prevGroupTail = prevGroupTail->next;
            }
        }

        groupSize++;
    }

    return dummy.next;
}