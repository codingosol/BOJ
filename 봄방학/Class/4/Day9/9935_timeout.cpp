#include <iostream>
#include <deque>
#include <stack>
#include <string>

using namespace std;

void solve(string str, string bomb)
{
    int streak = 0;
    int i = 0;
    for(int i = 0; i < str.length(); i++)
    {
        while(str[i + streak] == bomb[streak]){
            streak++;
            if(streak == bomb.length()){ // 만약 폭탄이 완성됐다면
                // 폭발이 일어난 후의 문자열을 만들어야 함
                string f, e; // 폭발 앞 뒤부분
                f = str.substr(0,i);
                e = str.substr(i+streak);
                str = f+e;
                streak = 0; // 새로운 문자열이 만들어졌으므로 초기화
                i = 0;
            }
        }
    }
    if(str.length() == 0){
        cout << "FRULA\n";
    }
    else{
        cout << str << '\n';
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string str;
    cin >> str;
    string bomb;
    cin >> bomb;
    solve(str,bomb);
    return 0;
}