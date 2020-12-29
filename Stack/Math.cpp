#include "EvalMathEq.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    /* calPostfix test */
    cout << "수식 입력 (Postfix) = " << "\n";
    double res = calcPostfixExpr();
    cout << "계산 결과 => " << res << "\n";
    const char* input = "30 20 100 + *";
    cout << "미리 입력된 수식 (Postfix) = " << input << "\n";
    res = calcPostfixExpr(input);
    cout << "계산 결과 => " << res << "\n";

    /* infix2Postfix test */
    cout << "수식 입력 (Infix) = " << "\n";
    string res2 = infix2Postfix();
    cout << "변환 결과 => " << res2 << "\n";
    const char* input2 = "30 + 20 * 100";
    cout << "미리 입력된 수식 (Infix) = " << input2 << "\n";
    res2 = infix2Postfix(input2);
    cout << "변환 결과 => " << res2 << "\n";
    
    /* 결합 테스트 */
    cout << "수식 입력 (Infix) = " << "\n";
    string res3 = infix2Postfix();
    cout << "변환 결과 => " << res3 << "\n";
    cout << "미리 입력된 수식 (Postfix) = " << res3 << "\n";
    cout << "계산 결과 => " << calcPostfixExpr(res3) << "\n";

    return 0;
}