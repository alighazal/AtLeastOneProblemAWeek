class Solution {
public:
    inline int compute(char &op, int &x, int &y) {
        if (op == '+') {
            return x + y;
        } else if (op == '*') {
            return x * y;
        } else {
            return x - y;
        }
    }

    vector<int> diffWaysToCompute(string expression) {
        vector<int> ans;
        for (int i = 1; i < expression.length(); i++) {
            if (expression[i] == '+' || expression[i] == '-' ||
                expression[i] == '*') {
                auto left_hand_expr = expression.substr(
                    0, distance(expression.begin(), expression.begin() + i));
                auto left = diffWaysToCompute(left_hand_expr);
                auto right_hand_expr = expression.substr(
                    i + 1,
                    distance(expression.begin() + i + 1, expression.end()));
                auto right = diffWaysToCompute(right_hand_expr);

                for (auto& n1 : left) {
                    for (auto& n2 : right) {
                        ans.push_back(compute(expression[i], n1, n2));
                    }
                }
            }
        }
        if (ans.empty()) {
            return {stoi(expression)};
        }
        return ans;
    }
};
