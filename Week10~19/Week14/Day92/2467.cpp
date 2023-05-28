#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long int_64;

int n;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int_64 temp;
    vector<int_64> v;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(),v.end()); // 오름차순으로 정렬
    int start, end;
    start = 0, end = n-1; // 시작 위치 정하기
    int s_idx = 0, e_idx = n-1; // 정답 인덱스 저장
    // v가 정렬되어 잇으므로 전부 양수인 경우나 전부 음수인 경우를 제외하고 이분탐색으로 해결해주면 됨
    int_64 cval = 121110987654321; // 0에 최근접한 수를 저장 초기값 아주 크게
    while(start < end)
    {
        // cout << "current s : " << start << ' ' << "e : " << end << '\n';
        int mid = (start + end) / 2;
        int_64 tempval = v[start] + v[end]; // 현재 두 용액의 혼합값
        if(abs(tempval) < abs(cval)) // 최근접수 갱신
        {
            cval = tempval;
            s_idx = start;
            e_idx = end;
        } 
        if(tempval < 0) // 음수라면 start 증가
        {
            start++;
        }
        else if(tempval > 0) // 양수라면 end 감소
        {
            end--;
        }
        else { // 합성값이 0이라면
            break; // 깨고 나감
        }   
    }
    cout << v[s_idx] << ' ' << v[e_idx] << '\n';
}
