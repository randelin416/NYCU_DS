#include <iostream>
#include <queue>
#include <sstream>
#include <memory>
#include <algorithm>

using namespace std;

class ListNode {
    int val;

public:
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}

    bool operator>(const ListNode& other) const {
        return val > other.val;
    }

    void print() {
        ListNode* tmp = this;
        while (tmp) {
            cout << tmp->val << " ";
            tmp = tmp->next;
        }
        cout << endl;
    }
};

/// You need to implement this
ListNode* mergeRoutes(const vector<ListNode*>& routes);

// Helper function to build linked list from vector
ListNode* buildList(const vector<int>& values) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    for (int val : values) {
        tail->next = new ListNode(val);
        tail = tail->next;
    }
    return dummy.next;
}

void deleteList(ListNode* head) {
    while (head) {
        ListNode* tmp = head;
        head = head->next;
        delete tmp;
    }
}

int main() {
    int testCases;
    cin >> testCases;

    for (int t = 0; t < testCases; ++t) {
        int n;
        cin >> n;

        vector<ListNode*> routes;
        for (int i = 0; i < n; ++i) {
            string line;
            getline(cin >> ws, line);
            istringstream iss(line);
            vector<int> values;
            int val;
            while (iss >> val) {
                values.push_back(val);
            }
            routes.push_back(buildList(values));
        }

        ListNode* merged = mergeRoutes(routes);

        if (merged) {
            merged->print();
            deleteList(merged);  
        }
    }

    return 0;
}

// Your code starts here
ListNode* mergeRoutes(const vector<ListNode*>& routes) {
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return *a > *b;  
        }
    };

    priority_queue<ListNode*, vector<ListNode*>, Compare> pq;

    for (ListNode* head : routes) {
        if (head != nullptr) {
            pq.push(head);
        }
    }

    ListNode dummy(0);
    ListNode* tail = &dummy;

    while (!pq.empty()) {
        ListNode* cur = pq.top();
        pq.pop();

        if (cur->next != nullptr) {
            pq.push(cur->next);
        }

        tail->next = cur;
        tail = tail->next;
    }

    tail->next = nullptr;

    return dummy.next;
}