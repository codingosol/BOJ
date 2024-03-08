#include <iostream>
#include <vector>

using namespace std;

int get_dist(string a, string b)
{
    int cnt = 0;
    for(int i = 0; i < 4; i++)
    {
        if(a[i] != b[i]){
            cnt++;
        }
    }
    return cnt;
}

int main(void)
{
    int testcase;
    cin >> testcase;
    for(int i = 0; i < testcase; i++)
    {
        int n;
        cin >> n;
        string str;
        vector<string> v;
        // vector를 통해 전부 비교하면 100000^2 시간초과 날거같음
        for(int i = 0; i < n; i++){
            cin >> str;
            v.push_back(str);
        }
        // 32명이 넘으면 무조건 겹치는 세 명이 생김 -> 0으로 출력
        if(n > 32){
            cout << "0\n";
            continue;
        }
        // 그렇지 않다면 32^3 정도의 연산은 충분히 시간 내에 가능 -> 브루트포스
        int min_dist = 987654321;
        for(int j = 0; j < n; j++)
        {
            for(int k = j+1; k < n; k++)
            {
                for(int l = k+1; l < n; l++)
                {
                    min_dist = min(min_dist,
                        (get_dist(v[j],v[k]) + get_dist(v[j],v[l]) + get_dist(v[k],v[l])));
                }
            }
        }
        cout << min_dist << '\n';
    }
    return 0;
}