# Data_Structure_HW01---Polynomial-Addition-and-Multiplication
Use C++ to implement a data structure program.
Write a program with the C++ STL library to calculate the addition and multiplication of two polynomials.

本專案使用 C++ 與 STL 實作多項式的 相加 與 相乘。
輸入的多項式格式為一組 (係數, 次數) 的序列，程式會將其解析為向量 (vector) 形式，並輸出：
1. 原始多項式的字串形式
2. 兩個多項式的相加結果
3. 兩個多項式的相乘結果

輸入格式
3 3 -5 1 7 0  
$3x^3 - 5x + 7$

2 2 4 0  
$2x^2 + 4$

輸出範例  
輸入：  
poly1 = 3 3 -5 1 7 0  
poly2 = 2 2 4 0  
輸出：  
Polynomial 1: 3x^3 - 5x + 7  
Polynomial 2: 2x^2 + 4  
Sum: 3x^3 + 2x^2 - 5x + 11  
Product: 6x^5 - 10x^3 + 14x^2 - 20x + 28  
