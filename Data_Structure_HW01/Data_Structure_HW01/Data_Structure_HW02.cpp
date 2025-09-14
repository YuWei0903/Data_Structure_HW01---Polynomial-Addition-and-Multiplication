#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <map>
#include <sstream>

using namespace std;

// 檢查括號是否對稱
bool isBalanced(const string& expression) {
    stack<char> s;
    for (char ch : expression) {
        if (ch == '(') {
            s.push(ch);
        }
        else if (ch == ')') {
            if (s.empty() || s.top() != '(') {
                return false;
            }
            s.pop();
        }
    }
    return s.empty();
}

// 定義運算子的優先順序
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// 將中序表達式轉換成後序表達式
string infixToPostfix(const string& expression) {
    stack<char> s;
    string postfix;
    for (char ch : expression) {
        if (isdigit(ch)) {
            postfix += ch;  // 若是數字則直接加到結果中
        }
        else if (ch == '(') {
            s.push(ch);
        }
        else if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop(); // 去掉 '('
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            while (!s.empty() && precedence(s.top()) >= precedence(ch)) {
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }
    return postfix;
}

// 計算後序表達式的結果
int evaluatePostfix(const string& postfix) {
    stack<int> s;
    for (char ch : postfix) {
        if (isdigit(ch)) {
            s.push(ch - '0');  // 將字元轉成整數
        }
        else {
            int val2 = s.top(); s.pop();
            int val1 = s.top(); s.pop();
            switch (ch) {
            case '+': s.push(val1 + val2); break;
            case '-': s.push(val1 - val2); break;
            case '*': s.push(val1 * val2); break;
            case '/': s.push(val1 / val2); break;
            }
        }
    }
    return s.top();
}

int main() {
    string expression;
    char continueTesting;

    do {
        cout << "請輸入一個運算式（僅包含 +, -, *, /, (, ) 以及數字 1~9）：";
        cin >> expression;

        // 檢查括號是否對稱
        if (!isBalanced(expression)) {
            cout << expression << " 運算式的括號不對稱，無法繼續運算" << endl;
        }
        else {
            cout << expression << " 運算式的左右括號對稱" << endl;

            // 轉換成後序表達式
            string postfix = infixToPostfix(expression);
            cout << expression << " 運算式的後序表式法為： " << postfix << endl;

            // 計算後序表達式的結果
            int result = evaluatePostfix(postfix);
            cout << expression << " 運算式的運算結果為：" << result << endl;
        }

        cout << "是否要繼續測試？(Y/y 繼續, 其他鍵退出)：";
        cin >> continueTesting;
    } while (continueTesting == 'Y' || continueTesting == 'y');

    return 0;
}
