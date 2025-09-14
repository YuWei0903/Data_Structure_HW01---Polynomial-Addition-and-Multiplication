#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

// 解析多項式格式 (係數, 次數)，轉換為 vector 表示法
vector<int> parsePolynomial(const string& input) {
    vector<pair<int, int>> terms;
    stringstream ss(input);
    int coefficient, exponent;

    // 解析多項式的係數與次數
    while (ss >> coefficient >> exponent) {
        terms.push_back({ exponent, coefficient });
    }

    // 找出最大次數
    int maxExponent = 0;
    for (const auto& term : terms) {
        maxExponent = max(maxExponent, term.first);
    }

    // 建立一個大小為 (maxExponent + 1) 的 vector，並初始化為 0
    vector<int> polynomial(maxExponent + 1, 0);

    // 將係數依次數存入 vector 中
    for (const auto& term : terms) {
        polynomial[term.first] = term.second;
    }

    return polynomial;
}

// 將 vector 表示法的多項式轉換為字串
string polynomialToString(const vector<int>& polynomial) {
    stringstream ss;
    bool first = true;

    for (int i = polynomial.size() - 1; i >= 0; --i) {
        if (polynomial[i] == 0) continue;

        if (!first && polynomial[i] > 0) {
            ss << " + ";
        }
        else if (polynomial[i] < 0) {
            ss << " - ";
        }

        if (abs(polynomial[i]) != 1 || i == 0) {
            ss << abs(polynomial[i]);
        }

        if (i > 0) {
            ss << "x";
            if (i > 1) {
                ss << "^" << i;
            }
        }

        first = false;
    }

    return ss.str();
}

// 多項式相加
vector<int> addPolynomials(const vector<int>& p1, const vector<int>& p2) {
    int maxSize = max(p1.size(), p2.size());
    vector<int> result(maxSize, 0);

    for (int i = 0; i < maxSize; ++i) {
        if (i < p1.size()) result[i] += p1[i];
        if (i < p2.size()) result[i] += p2[i];
    }

    return result;
}

// 多項式相乘
vector<int> multiplyPolynomials(const vector<int>& p1, const vector<int>& p2) {
    vector<int> result(p1.size() + p2.size() - 1, 0);

    for (int i = 0; i < p1.size(); ++i) {
        for (int j = 0; j < p2.size(); ++j) {
            result[i + j] += p1[i] * p2[j];
        }
    }

    return result;
}

int main() {
    // 輸入格式：每個多項式用 (係數, 次數) 的方式表示
    string poly1_input = "3 3 -5 1 7 0";  // 3x^3 - 5x + 7
    string poly2_input = "2 2 4 0";       // 2x^2 + 4

    // 解析多項式
    vector<int> poly1 = parsePolynomial(poly1_input);
    vector<int> poly2 = parsePolynomial(poly2_input);

    // 輸出原始多項式
    cout << "Polynomial 1: " << polynomialToString(poly1) << endl;
    cout << "Polynomial 2: " << polynomialToString(poly2) << endl;

    // 多項式加法
    vector<int> sum = addPolynomials(poly1, poly2);
    cout << "Sum: " << polynomialToString(sum) << endl;

    // 多項式乘法
    vector<int> product = multiplyPolynomials(poly1, poly2);
    cout << "Product: " << polynomialToString(product) << endl;

    return 0;
}
