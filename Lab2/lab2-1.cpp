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

ListNode* reverse_k_group(ListNode* head, int k);

int main() {
    int T = 0;
    scanf("%d", &T);

    while (T--) {
        int n = 0, k = 0, tmp = 0;
        ListNode* head = new ListNode(); // dummy head
        ListNode* tail = head;
        ListNode* p = nullptr;
        ListNode* reversed_head = nullptr;

        scanf("%d%d", &n, &k);
        for (int i = 0; i < n; i++) {
            scanf("%d", &tmp);
            tail = tail->next = new ListNode(tmp);
        }
        tail->next = nullptr;

        reversed_head = reverse_k_group(head->next, k);
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


ListNode* reverse_k_group(ListNode* head, int k) {
    // check if there is over k nodes]
    ListNode* check = head;
    for(int i = 0; i < k; i++) {
        if(!check)
            return head;
        check = check -> next;
    }

    // reverse k nodes for first group
    ListNode* prev = nullptr;
    ListNode* cur = head;
    for(int i = 0; i < k; i++) {
        ListNode* nextNode = cur -> next;
        cur -> next = prev;
        prev = cur;
        cur = nextNode;
    }

    // keep doing next group
    if(cur != nullptr) {
        head -> next = reverse_k_group(cur, k); // cause cur is the head of next group
    }
    return prev; // will be the head of reserved group
}