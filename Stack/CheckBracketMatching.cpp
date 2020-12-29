#include "ArrayStackTemplate.h"
#include <fstream>
#include <iostream> 
#include <string>
using namespace std; 

bool CheckMatching(const char* filename){
    ifstream is(filename);
    if(!is.is_open()){
        error("Error: 파일이 제대로 열리지 않았습니다\n");
    }
    int nLine = 1;
    int nChar = 0;
    ArrayStack<char> stack;
    char ch;
    while(is.get(ch)){
        if(ch == '\n') { nLine++; }
        nChar++;
        if(ch == '[' || ch == '(' || ch == '{')
            stack.push(ch);
        else if(ch == ']' || ch == ')' || ch == '}') {
            char prev = stack.pop();
            if((ch == ']' && prev != '[')
                ||  (ch == ')' && prev != '(')
                ||  (ch == '}' && prev != '{')){ break; }
        }
    }
    is.close();
    cout << filename << " 파일 검사결과: \n";
    
    if(!stack.isEmpty()){
        cout << "Error: 문제발견! (총라인수:" << nLine << ", 총문자수:" << nChar << ")\n";
    } else{
        cout << "OK: 괄호닫기 정상! (총라인수:" << nLine << ", 총문자수:" << nChar << ")\n";
    }
    return stack.isEmpty();
}

int main()
{
    CheckMatching("ArrayStack.h");
    CheckMatching("CheckBracketMatching.cpp");
    return 0;
}