#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <map>
#include <sstream>

using namespace std;

// �ˬd�A���O�_���
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

// �w�q�B��l���u������
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// �N���Ǫ�F���ഫ����Ǫ�F��
string infixToPostfix(const string& expression) {
    stack<char> s;
    string postfix;
    for (char ch : expression) {
        if (isdigit(ch)) {
            postfix += ch;  // �Y�O�Ʀr�h�����[�쵲�G��
        }
        else if (ch == '(') {
            s.push(ch);
        }
        else if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop(); // �h�� '('
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

// �p���Ǫ�F�������G
int evaluatePostfix(const string& postfix) {
    stack<int> s;
    for (char ch : postfix) {
        if (isdigit(ch)) {
            s.push(ch - '0');  // �N�r���ন���
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
        cout << "�п�J�@�ӹB�⦡�]�ȥ]�t +, -, *, /, (, ) �H�μƦr 1~9�^�G";
        cin >> expression;

        // �ˬd�A���O�_���
        if (!isBalanced(expression)) {
            cout << expression << " �B�⦡���A������١A�L�k�~��B��" << endl;
        }
        else {
            cout << expression << " �B�⦡�����k�A�����" << endl;

            // �ഫ����Ǫ�F��
            string postfix = infixToPostfix(expression);
            cout << expression << " �B�⦡����Ǫ��k���G " << postfix << endl;

            // �p���Ǫ�F�������G
            int result = evaluatePostfix(postfix);
            cout << expression << " �B�⦡���B�⵲�G���G" << result << endl;
        }

        cout << "�O�_�n�~����աH(Y/y �~��, ��L��h�X)�G";
        cin >> continueTesting;
    } while (continueTesting == 'Y' || continueTesting == 'y');

    return 0;
}
