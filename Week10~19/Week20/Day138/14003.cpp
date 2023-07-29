#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

typedef long long int_64;

int_64 n;

// 1000000의 최대 크기를 가지므로 최대 분기가 10^12까지 치솟아 메모리 오류가 남 ㅠ
// 인터넷 index 사용 풀이 참고함

int main(void)
{
    // 기본적으로 12738과 동일하나 경로를 출력해야 함
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    //cout << n << '\n';
    int_64 arr[1000001];
    fill_n(arr,1000001,0);
    vector<int_64> ans; // 모든 수 기록
    vector<int_64> index; // 그 수가 들어가야 할 위치 저장
    int_64 cnt = 0;

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    //cout << arr[0] << ' ';
    ans.push_back(arr[0]);
    cnt++;
    index.push_back(cnt);

    for(int_64 i = 1; i < n; i++)
    {
        //cout << arr[i] << ' ';
        if(ans[cnt-1] < arr[i]) // 계속 증가한다면
        {
            ans.push_back(arr[i]);
            //cout << arr[i] << ' ';
            cnt++;
            index.push_back(cnt);
        }
        else {
            int_64 idx = lower_bound(ans.begin(),ans.end(),arr[i]) - ans.begin(); // 최솟값까지의 위치 리턴
            // cout << idx << ' ';
            ans[idx] = arr[i]; 
            //cout << ans[idx] << ' ';
            index.push_back(idx+1);
        }
    }
    //cout << '\n';
    cout << cnt << '\n';
    stack<int_64> ret;
    for(int_64 i = n-1; i >= 0; i--)
    {
        //cout << index[i] << ' ';
        if(index[i] == cnt)
        {
            ret.push(arr[i]);
            cnt--;
        }
    }
    //cout << '\n';
    while(!ret.empty())
    {
        cout << ret.top() << ' ';
        ret.pop();
    }
    cout << '\n';
    return 0;
    // 이 풀이의 문제점은 10 20 40 80 100 -20 의 수열이 주어지는 경우에 
    // cnt가 꾸준히 증가하였다가 마지막 -20에 첫 번째자리를 차지하고 수정하지 않기 떄문임
    // 출력이 -20 20 40 80 100 으로 변해버릴 것
    // 이 수열의 순서가 바뀌어서는 안 되므로 -20이 처음에 올 수는 없음
    // 그렇다면 어떻게 고쳐야 할까...
    // !기존 최장 수열을 유지했다가 그 길이를 넘는 순간 최장 수열을 바꿔야 함!
    // 최장 수열도 마찬가지로 연장될 수 있기 떄문에 분기가 많이 생김,, 벡터 한 두개로는 안될거같은데?
}