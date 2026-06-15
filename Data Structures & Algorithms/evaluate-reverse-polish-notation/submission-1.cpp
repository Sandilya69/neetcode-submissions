class Solution {
public:
    bool isOperator(string s) {
        if (s == "+" || s == "-" || s == "*" || s == "/") {
            return true;
        }

        return false;
    }

    int operate(string op, int a, int b) {
        if (op == "+") return a + b;
        if (op == "*") return a * b;
        if (op == "/") return a / b;
        if (op == "-") return a - b;
    }
    
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(int i = 0; i < tokens.size(); i++) {
            if (!isOperator(tokens[i])) {
                s.push(stoi(tokens[i]));
            } else {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();

                int res = operate(tokens[i], b, a);
                s.push(res);
            }
        }

        return s.top();
    }
};
