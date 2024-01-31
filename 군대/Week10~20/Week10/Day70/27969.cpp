#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
    string str;
    // getline으로 전부 받고 나누기 vs cin으로 하나씩 받기 -> 빈 괄호를 어떻게 처리하느냐(빈괄호도 용량을 가지기 때문)
    // getline(cin,str); // 끝까지 전부 받고 나누기로 결정
    /* 양의 정수 자료형 원소의 용량은 $8$byte, 문자열 자료형 원소의 용량은 (문자열의 길이 $+ 12$byte)다. 
    빈 ASON 객체는 어떤 다른 원소도 소유하지 않으므로 $8$byte만큼의 용량을 차지한다.*/
    stack<char> brk;
    stack<int> int_comp; // component의 용량을 저장함
    stack<int> str_cmp; // component
    int cmp_num = 0;
    int cmp_str = 0;
    int ans = 0; // 총 용량을 저장할 변수
    while(cin >> str)
    {
        if(str == "[")
        {
            brk.push('[');
        }
        else if(str == "]")
        {
            // 닫힌 괄호를 만나면 brk을 하나 pop하고
            // 8을 더해줌
            brk.pop();
            ans += 8;
        }
        else 
        {
            // 문자열 cmp인지 정수 cmp인지 분리해서 판단
            if(str[0] >= '1' && str[0] <= '9') // 정수형이라면
            {
                ans += 8;
            }
            else {
                ans += str.length() + 12;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}