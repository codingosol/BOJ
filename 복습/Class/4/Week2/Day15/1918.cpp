#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
    string str;
    cin >> str;
    stack<char> oper;
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] >= 'A' && str[i] <= 'Z'){
            cout << str[i]; // 그냥 출력해도 됨
        }
        // 그냥 담다가 top보다 우선순위가 낮은 걸 만나면 다 뱉기
        // 연산 우선순위는 + - < * / 
        // ( 가 나온다면 )이 나오기 전까지는 다른 계
        else if(str[i] == '+' || str[i] == '-') // 덧셈 or 뺄셈
        {
            while (!oper.empty() && oper.top() != '(') // 다 비거나 괄호를 만나기 전까지 전부 뱉음
            {
                cout << oper.top();
                oper.pop();
            }
            oper.push(str[i]);
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