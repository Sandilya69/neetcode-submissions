class BrowserHistory {
    struct ListNode {
    public:
        string val;
        ListNode* prev;
        ListNode* next;

        ListNode(string val, ListNode* prev = nullptr, ListNode* next = nullptr)
            : val(val), prev(prev), next(next) {}
    };

    ListNode* cur;

public:
    BrowserHistory(string homepage) {
        cur = new ListNode(homepage);
    }

    void visit(string url) {
        cur->next = new ListNode(url, cur, nullptr);
        cur = cur->next;
    }

    string back(int steps) {
        while (cur->prev != nullptr && steps > 0) {
            cur = cur->prev;
            steps--;
        }
        return cur->val;
    }

    string forward(int steps) {
        while (cur->next != nullptr && steps > 0) {
            cur = cur->next;
            steps--;
        }
        return cur->val;
    }
};