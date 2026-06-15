class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<int> st;

        for (string &x : tokens) {
            if (x == "+" || x == "-" || x == "*" || x == "/") {
                int op2 = st.top();
                st.pop();
                int op1 = st.top();
                st.pop();

                if (x == "+") {
                    st.push(op1 + op2);
                }
                if (x == "-") {
                    st.push(op1 - op2);
                }
                if (x == "*") {
                    st.push(op2 * op1);
                }
                if (x == "/") {
                    st.push(op1 / op2);
                }
            } else {
                st.push(stoi(x));
            }
        }
        return st.top();
    }
};