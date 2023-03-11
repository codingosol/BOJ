#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    int temp;
    int tail = -1;
    vector<pair<int,int>> v;
    vector<pair<int,int>> ans;
    // n을 뽑으면 n번만큼 새치기를 해서 앞에 섬
    for(int i = 0; i < n; i++)
    {
        cin >> temp; // 뽑은 번호표
        v.push_back({i+1,temp});
    } // 학생 번호와 뽑은 번호표를 쌍으로 입력
    pair<int,int> p;
    for(int i = 0; i < n; i++) // 정렬할 시간
    {
        p = v[i];
        if(p.second == 0) // 0번을 뽑으면 그 자리에 있음
        {
            ans.push_back(p);
            tail++;
        }
        else
        {
            ans.push_back(p); // 먼저 추가한 뒤
            tail++;
            int cur = tail; // 현재 위치를 가리킬 변수
            for(int j = 0; j < p.second; j++)// 뽑은 번호만큼 새치기
            {
                pair<int,int> tempp; // swap을 위해 임시 pair 선언
                tempp = ans[cur - 1]; // 한칸 앞 저장
                ans[cur - 1] = ans[cur]; // 한칸 앞으로 이동
                ans[cur] = tempp;
                cur--;
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        cout << ans[i].first << " ";
    }
    cout << "\n";
    return 0;
}