#pragma once
#include "ArrayStackTemplate.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

/* 후위 표기 수식 계산(파라미터 입력이 없는 경우 키보드에서 받음) */
double calcPostfixExpr() {
    char c;
    double val;
    ArrayStack<double> st;
    while(cin.get(c) && c != '\n') {
        if(c=='+' || c=='-' || c=='*' || c=='/') {
            double val2 = st.pop();
            double val1 = st.pop();
            switch(c) {
                case '+': st.push(val1 + val2); break;
                case '-': st.push(val1 - val2); break;
                case '*': st.push(val1 * val2); break;
                case '/': st.push(val1 / val2); break;
            }
        } else if(c>='0' && c<='9') {
            cin.unget();
            cin >> val;
            st.push(val);
        }
    }
    return st.pop();
}

/* 후위 표기 수식 계산(파라미터 입력이 있는 경우) */
double calcPostfixExpr(string str) {
    istringstream iss(str);
    char c;
    double val;
    ArrayStack<double> st;
    while(iss.get(c) && c != '\n') {
        if(c=='+' || c=='-' || c=='*' || c=='/') {
            double val2 = st.pop();
            double val1 = st.pop();
            switch(c) {
                case '+': st.push(val1 + val2); break;
                case '-': st.push(val1 - val2); break;
                case '*': st.push(val1 * val2); break;
                case '/': st.push(val1 / val2); break;
            }
        } else if(c>='0' && c<='9') {
            iss.unget();
            iss >> val;
            st.push(val);
        }
    }
    return st.pop();
}

inline int priority(char op) {
    switch (op) {
        case '(': case ')': return 0;
        case '+': case '-': return 1;
        case '*': case '/': return 2;
    }
    return -1;
}

/* 중위 표기 수식 -> 후위 표기 수식 계산 */
string infix2Postfix() {
    char c, op;
    double val;
    ostringstream oss;
    ArrayStack<char> st;
    while(cin.get(c) && c != '\n') {
        if(c>='0' && c <= '9') {
            cin.unget();
            cin >> val;
            oss << val << " ";
        } else if(c == '(') {
            st.push(c);
        } else if(c == ')') {
            while(!st.isEmpty()) {
                op = st.pop();
                if(op == '(') break;
                else oss << op << " ";
            }
        } else if(c=='+' || c=='-' || c=='*' || c=='/') {
            while(!st.isEmpty()) {
                op = st.peek();
                if(priority(c) <= priority(op)) {
                    oss << op << " ";
                    st.pop();
                } else break;
            }
            st.push(c);
        }
    }
    while(!st.isEmpty()) {
        oss << st.pop() << " ";
    }
    return oss.str();
}

/* 중위 표기 수식 -> 후위 표기 수식 계산(파라미터 입력이 있는 경우) */
string infix2Postfix(string istr) {
    char c, op;
    double val;
    ostringstream oss;
    istringstream iss(istr);
    ArrayStack<char> st;
    while(iss.get(c) && c != '\n') {
        if(c>='0' && c <= '9') {
            iss.unget();
            iss >> val;
            oss << val << " ";
        } else if(c == '(') {
            st.push(c);
        } else if(c == ')') {
            while(!st.isEmpty()) {
                op = st.pop();
                if(op == '(') break;
                else oss << op << " ";
            }
        } else if(c=='+' || c=='-' || c=='*' || c=='/') {
            while(!st.isEmpty()) {
                op = st.peek();
                if(priority(c) <= priority(op)) {
                    oss << op << " ";
                    st.pop();
                } else break;
            }
            st.push(c);
        }
    }
    while(!st.isEmpty()) {
        op = st.peek();
        oss << st.pop() << " ";
    }
    return oss.str();
}