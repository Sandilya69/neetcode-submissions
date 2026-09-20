/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        if (!root) return res;

        stack<pair<Node*, bool>> st;
        st.push({root, false});

        while (!st.empty()) {
            auto [node, visited] = st.top();
            st.pop();

            if (visited) {
                res.push_back(node->val);
            } else {
                st.push({node, true});
                for (int i = (int)node->children.size() - 1; i >= 0; i--) {
                    st.push({node->children[i], false});
                }
            }
        }

        return res;
    }
};