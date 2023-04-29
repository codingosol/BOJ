#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    // 일반적인 substr을 사용했을 때 메모리 초과가 남
    // stack으로 함 해보자
    ios::sync_with_stdio(false);
    cin.tie(0);
    string str;
    cin >> str;
    string bomb;
    cin >> bomb;
    int str_size = str.size();
    int bomb_size = bomb.size();
    vector<char> v;
    for(int i = 0; i < str.length(); i++)
    {
        v.push_back(str[i]);
        if(v.size() >= bomb_size) // 폭탄보다 길이가 길어지면
        {
            //for(int j = 0; j <= v.size() - bomb_size; j++) // j는 탐색 시작 지점임 -> 검색할 필요가 없음 why 전에 한번씩 다 검사했으니까
            // {
            bool flag = true; // 폭탄인지의 여부
            int cnt = 0;
            while(cnt < bomb_size)
            {
                if(v[v.size()-bomb_size+cnt] != bomb[cnt]) // 틀리면 폭탄 아님
                {
                    flag = false;
                    break;
                }
                cnt++;
            }
            if(flag) // 끝까지 탐색한 결과 폭탄이라면
            {
                for(int j = 0; j < bomb_size; j++)
                {
                    v.pop_back();
                }
            }
            // }
        }
    }
    if(v.empty())
    {
        cout << "FRULA\n";
    }
    else {
        for(int i = 0; i < v.size(); i++)
        {
            cout << v[i];
        }
        cout << '\n';
    }
    return 0;
    
}