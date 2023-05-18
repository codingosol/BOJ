#include <iostream>
#include <vector>

using namespace std;
typedef long long int_64;

int_64 max_val = 0;
int_64 min_val = 100000000000;

string max_str;
string min_str;
int k;
int used[10]; // 0~9까지 쓰였는지 체크

void solve(string &str, int k, vector<char> &v) // 각각 현재 문자열, 더 골라야 할 자릿수, 부등호
{
    if(k == 0) // 다 고른 경우
    {
        // 문자열을 정수로 만들어 최댓값과 비교한 뒤 교체
        int_64 cur = 0;
        for(int i = 0; i < str.length(); i++)
        {
            cur += str[i] - 48;
            cur *= 10;
        }
        if(cur > max_val)
        {
            max_str = str;
            max_val = cur;
        }
        if(cur < min_val)
        {
            min_str = str;
            min_val = cur;
        }
    }
    else {
        // cout << "current string is : " << str << '\n';
        char op = v[v.size() - k]; // 이번에 필요한 수
        // cout << op << '\n';
        // cout << op << '\n' << str << '\n';
        if(op == '<') // 더 큰 수 고르기
        {
            for(int i = str[str.length()-1] - 47; i <= 9; i++)
            {
                if(used[i] != 1) // 미사용인 경우만
                {
                    // cout << "current string is : " << str << '\n';
                    str += char(i+48);
                    used[i] = 1;
                    solve(str,k-1,v);
                    // str에 추가된 수 다시 빼기
                    str.erase(str.length()-1);
                    used[i] = 0;
                }
            }
        }
        else if(op == '>') // 더 작은 수 고르기
        {
            for(int i = str[str.length()-1] - 49; i >= 0; i--)
            {
                if(used[i] != 1) // 미사용인 경우만
                {
                    // cout << "current string is : " << str << '\n';
                    str += char(i+48);
                    used[i] = 1;
                    solve(str,k-1,v);
                    // str에 추가된 수 다시 빼기
                    str.erase(str.length()-1);
                    used[i] = 0;
                }
            }
        }
    }
}

int main(void)
{
    cin >> k;
    char ch;
    vector<char> v;
    for(int i = 0; i < k; i++)
    {
        cin >> ch;
        v.push_back(ch);
    }
    string str;
    for(int i = 0; i <= 9; i++)
    {
        str += char(i+48);
        used[i] = 1;
        solve(str,k,v);
        used[i] = 0;
        str = "";
    }
    cout << max_str << '\n' << min_str << '\n';
    return 0;
}