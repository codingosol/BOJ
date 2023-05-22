#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m; // n은 암호의 자릿수, m은 문자의 수
int alphabet[26];
int used[26];

bool ispossible(string ans) // 문자열의 조건 판단
{
    int v_cnt = 0;
    int c_cnt = 0;
    for(int i = 0; i < ans.length(); i++)
    {
        if(ans[i] == 'a' || ans[i] == 'e' || ans[i] == 'o' || ans[i] == 'i' || ans[i] == 'u')
        {
            v_cnt++;
        }
        else {
            c_cnt++;
        }
    }
    if(v_cnt == 0 || c_cnt < 2)
    {
        return false;
    }
    return true;
}

void pick(int num, string& ans) // num은 현재 고른 알파벳의 수, ans는 현재 문자열
{
    if(num == n) // 다 골랐다면
    {
        if(ispossible(ans))
        {
            cout << ans << '\n';
            return;
        }
    }
    else { // 아직 덜 골랐다면
        if(ans.size() == 0) // 하나도 고르지 않았다면
        {
            for(int i = 0; i <= 25; i++)
            {
                if(alphabet[i] == 1 && used[i] == 0)
                {
                    // cout << "picked " << char(i+'a') << '\n';
                    ans += char(i+'a');
                    // cout << ans << '\n';
                    used[i] = 1;
                    pick(num+1,ans);
                    ans.erase(ans.length()-1);
                    used[i] = 0;
                }
            }
        }
        else {
            for(int i = ans[ans.length()-1] - 'a'; i <= 25; i++) // 알파벳은 오름차순이어야 하므로
            {
                if(alphabet[i] == 1 && used[i] == 0)
                {
                    // cout << "picked " << char(i+'a') << '\n';
                    ans += char(i+'a');
                    used[i] = 1;
                    pick(num+1,ans);
                    ans.erase(ans.length()-1);
                    used[i] = 0;
                }
            }
        }
    }

}

int main(void)
{
    cin >> n >> m;
    char temp;
    for(int i = 0; i < m; i++)
    {
        cin >> temp;
        alphabet[temp - 'a'] = 1;
    }
    // 적어도 하나의 모음, 두 개의 자음이 들어가야 함
    // 모든 경우의 수를 나열하되, 이 문자열에 모음이 들어가지 않거나 자음이 두 개 이상 들어가지 않았다면 출력하지 않음
    // 첫번째 자리에 올 수 있는 수를 고름
    string ans = "";
    pick(0, ans);
    
}