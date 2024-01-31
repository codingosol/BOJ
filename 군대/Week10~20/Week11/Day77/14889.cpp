#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int points[21][21];
int n;
int picked[21];
int min_val = 987654321;

pair<int,int> calc(vector<int> &start) // 점수 계산
{
    int st_p=0; // 스타트 팀의 점수
    int li_p=0; // 링크 팀의 점수
    for(int i = 0; i < start.size() - 1; i++)
    {
        for(int j = i + 1; j < start.size(); j++)
        {
            st_p += points[start[i]][start[j]];
            st_p += points[start[j]][start[i]];
        }
    } // 스타트팀 점수계산
    vector<int> link;
    for(int i = 1; i <= n; i++)
    {
        if(picked[i] != 1) // 안골라졌다면
        {
            link.push_back(i);
        }
    }
    for(int i = 0; i < link.size() - 1; i++)
    {
        for(int j = i + 1; j < link.size(); j++)
        {
            li_p += points[link[i]][link[j]];
            li_p += points[link[j]][link[i]];
        }
    } // 스타트팀 점수계산
    return {st_p,li_p};
}

void pick(int cnt, vector<int> &start)
{
    // n명의 선수를 두 그룹으로 나눠야 함
    if(cnt == n/2) // 선수를 다 뽑았다면
    {
        // 각 팀의 점수 계산
        /*cout << "pick completed : ";
        for(int i = 0; i < start.size(); i++)
        {
            cout << start[i] << ' ';
        }
        cout << '\n';*/
        pair<int,int> p = calc(start);
        if(abs(p.first - p.second) < min_val)
            min_val = abs(p.first - p.second);
    }
    else {
        if(start.empty())
        {
            for(int i = 1; i <= n; i++) // 시간초과가 나는 원흉(한 경우를 여러번 탐색하게 됨) -> 자기보다 큰 경우의 수만 탐색하도록
            {
                if(picked[i] != 1) // 안골라졌다면
                {
                    picked[i] = 1;
                    start.push_back(i);
                    pick(cnt+1,start);
                    start.pop_back();
                    picked[i] = 0; // 백트래킹
                }
            }
        }
        else {
            for(int i = start[cnt-1]; i <= n; i++)
            {
                if(picked[i] != 1) // 안골라졌다면
                {
                    picked[i] = 1;
                    start.push_back(i);
                    pick(cnt+1,start);
                    start.pop_back();
                    picked[i] = 0; // 백트래킹
                }
            }
        }
    }

}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> points[i][j];
        }
    } // input;
    // n명을 두 팀으로 나눠야 함
    // 팀이 스타트인지 링크인지는 딱히 중요치 않음 -> 절반만 탐색해도 됨
    // nC2 의 경우의 수를 탐색해야 함
    vector<int> start;
    pick(0,start);
    cout << min_val << '\n';
}