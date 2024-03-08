#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    string str;
    cin >> str;
    vector<int> v;
    vector<char> oper;
    bool flag = false; // -가 식 내에 존재하는지 판별
    int temp = 0;
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] >= '0' && str[i] <= '9')
        {
            temp *= 10;
            temp += str[i] - '0';
            if(i == str.length() - 1){
                //cout << temp << '\n';
                v.push_back(temp);
                temp = 0;
            }
        }
        else if(str[i] == '-' || str[i] == '+')
        {
            //cout << temp << '\n';
            v.push_back(temp);
            temp = 0;
            oper.push_back(str[i]);
        }
    }
    // 순서를 바꿀 수는 없음
    // 최소의 값을 만드는 방법은 -가 나온 이후에 -가 나오기 전까지의 항을 묶는 것
    // -가 다시 나온다면 -전에 괄호를 닫고 다시 열면 됨
    // 첫 항은 기본값으로 두고, 뒤에 -가 있다면 그 뒤의 모든 값을 더해서 빼주면 됨
    int ans = v[0];
    for(int i = 0; i < oper.size(); i++)
    {
        if(oper[i] == '-') // 뒤에 있는 모든 수를 더해서 뺌
        {
            for(int j = i + 1; j < v.size(); j++)
            {
                ans -= v[j];
            }
            break;
        }
        else // 그냥 더함
        {
            ans += v[i+1];
        }
    }
    cout << ans << '\n';
    return 0;
}