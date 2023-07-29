#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long int_64;

int_64 n;

// 1000000의 최대 크기를 가지므로 최대 분기가 10^12까지 치솟아 메모리 오류가 남 ㅠ

int main(void)
{
    // 기본적으로 12738과 동일하나 경로를 출력해야 함
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    //cout << n << '\n';
    vector<vector<int_64>> ans; // 이중벡터
    int max_len = 0; // 최대 길이
    int_64 temp;
    for(int_64 i = 0; i < n; i++)
    {
        cin >> temp;
        if(ans.empty()) // 처음 들어오는 경우
        {
            //cout << "first\n";
            vector<int_64> v; // 최초 벡터 생성
            v.push_back(temp);
            max_len++;
            ans.push_back(v);
        }
        else {
            for(int j = 0; j < ans.size(); j++) // ans에 있는 모든 분기점 벡터에 대해
            {
                if(ans[j].empty() || ans[j].back() < temp) // 증가할 수 있다면
                {
                    ans[j].push_back(temp);
                    //cout << "pushed.\n";
                    if(ans[j].size() > max_len)
                    {
                        max_len = ans[j].size();
                        //cout << max_len << '\n';
                    }
                }
                else if(ans[j].back() > temp)
                { // 아니라면
                    vector<int_64>::iterator iter = lower_bound(ans[j].begin(),ans[j].end(),temp); // 이 값 이전의 최솟값을 찾음
                    // 이 이후의 모든 공간은 비움
                    vector<int_64> cur; // 새로운 분기점 추가
                    for(vector<int_64>::iterator iter2 = ans[j].begin(); iter2 != iter; iter2++)
                    {
                        cur.push_back(*iter2); // lower_bound까지의 기존 구성요소들 추가
                        // cout << "pushed : " << *iter2 << '\n';
                    }
                    // cout << index << '\n';
                    cur.push_back(temp); // 새로 temp 추가
                    ans.push_back(cur);
                }
            }
        }
    }
    // 이 풀이의 문제점은 10 20 40 80 100 -20 의 수열이 주어지는 경우에 
    // cnt가 꾸준히 증가하였다가 마지막 -20에 첫 번째자리를 차지하고 수정하지 않기 떄문임
    // 출력이 -20 20 40 80 100 으로 변해버릴 것
    // 이 수열의 순서가 바뀌어서는 안 되므로 -20이 처음에 올 수는 없음
    // 그렇다면 어떻게 고쳐야 할까...
    // !기존 최장 수열을 유지했다가 그 길이를 넘는 순간 최장 수열을 바꿔야 함!
    // 최장 수열도 마찬가지로 연장될 수 있기 떄문에 분기가 많이 생김,, 벡터 한 두개로는 안될거같은데?
    cout << max_len << '\n';
    for(int i = 0; i < ans.size(); i++)
    {
        if(ans[i].size() == max_len)
        {
            for(int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << ' ';
            }
            break;
        }
    }
    cout << '\n';
    return 0;
}