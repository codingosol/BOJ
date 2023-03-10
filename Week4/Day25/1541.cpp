#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main(void)
{
    string str;
    cin >> str;
    bool flag = false;
    int temp = 0;
    int sum = 0;
    for(int i = 0; i <= str.length(); i++)
    {
        if(str[i] >= 48 && str[i] <= 57 && i != str.length()) // 받은 문자가 수라면
        {
            temp = temp * 10 + str[i] - 48; // 수 누적
        }
        else { // 받은 문자가 연산자라면
            if(flag == false)
            {
                sum += temp; // 전체값에 추가
            }
            else if(flag == true) // 
            {
                sum -= temp;
            }
            if(str[i] == '-') // - 뒤로는 뭐가 오든 전부 -로 만들 수 있음
            {
                flag = true;
            }
            temp = 0; // 초기화
        }
    } 
    cout << sum << "\n";
}