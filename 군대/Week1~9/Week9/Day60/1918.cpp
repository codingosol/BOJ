#include <iostream>
#include <stack>
#include <queue>
#include <string>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string str;
    cin >> str; // 문자열을 입력받음
    // 후위표기식으로 표현
    stack<char> oper; // 연산자를 저장할 스택
    // 알파벳은 그냥 쌓이고 우선순위가 더 낮은 연산자가 나올 때까지는 계속 쌓아둠
    // 우선순위가 더 높은 연산자를 만난다면 거꾸로 전부 뱉음
    // 괄호의 경우에는 열린 괄호가 나온다면 닫힌 괄호가 나오기 전까지 다른 계가 됨
    // ex) A+B+C -> ABC++ // A+B*C -> ABC*+
    // A*(B+C) -> ABC+* // A*B+C // A*B*C+D -> ABC**D+
    string ans = ""; // 답을 저장할 문자열
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] >= 'A' && str[i] <= 'Z') // 알파벳일 경우
        {
            cout << str[i]; // 그냥 출력해도 됨
        }
        else if(str[i] == '+' || str[i] == '-') // 덧셈이나 뺄셈일 경우
        {
            while (!oper.empty() && oper.top() != '(')
                {
                    cout << oper.top();
                    oper.pop();
                }
                oper.push(str[i]);
        }
        // 괄호만 해결하면 된다!!
        else if(str[i] == '(') // 열린 괄호
        {
            oper.push(str[i]); // 열린 괄호를 push함
        }
        else if(str[i] == ')') // 닫힌 괄호
        {
            while(oper.top() != '(') // 열린 괄호를 만날 때까지 출력
            {
                cout << oper.top();
                oper.pop();
            }
            oper.pop(); // '(' 빼줌
        }
        else if(str[i] == '*' || str[i] == '/') // 덧셈이나 나눗셈(우선순위가 높음)
        {
            while (!oper.empty() && (oper.top() == '*' || oper.top() == '/'))
            {
                cout << oper.top();
                oper.pop();
            }
            oper.push(str[i]);
        }
        if(i == str.length() - 1) // 마지막 원소에 도달했을 경우 뱉지 못한 연산자가 남았다면 전부 뱉음
        {
            while(!oper.empty()) // 연산자 나중
            {
                cout << oper.top();
                oper.pop();
            }
        }
    }
    cout << '\n';
    return 0;
}