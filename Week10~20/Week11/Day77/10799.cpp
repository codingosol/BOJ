#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string str;
    cin >> str;
    int cnt = 0; // 현재 위치
    vector<int> lazer;
    stack<int> pipe;
    // ( 다음에 (이 또 열리면 쇠막대기의 시작점임
    int ans = 0;
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == '(')
        {
            if(str[i+1] == ')')
            {
                // 레이저 위치 기록
                lazer.push_back(cnt);
                cnt++;
                i++;
            }
            else { // 그냥 '('라면
                pipe.push(cnt); // 시작점 저장
                cnt++;
            }
        }
        else { // ')'를 만나면
            // 쇠막대기 하나의 종점
            int start = pipe.top();
            int end = cnt; // 끝점은 cnt
            pipe.pop();
            // cout << start << ' ' << end << '\n';
            int piece = 1; // 안잘려도 하나
            for(int i = 0; i < lazer.size(); i++)
            {
                if(lazer[i] > start && lazer[i] < end)
                {
                    piece++;
                }
            }
            ans += piece;
            cnt++;
        }
    }
    cout << ans << '\n';
    return 0;
}