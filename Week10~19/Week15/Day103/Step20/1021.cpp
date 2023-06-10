#include <iostream>
#include <deque>

using namespace std;

//int arr[51];

int main(void)
{
    //fill_n(arr,51,0);
    int n, m;
    cin >> n >> m;
    deque<int> dq;
    for(int i = 1; i <= n; i++)
    {
        dq.push_back(i);
    }
    // input;
    int cnt = 0;
    int temp;
    // 돌리는 연산의 수를 체크해야 함
    int cur = dq.front();
    for(int i = 0; i < m; i++)
    {
        cin >> temp;
        // 이 수 temp를 뽑아내야 함
        cur = dq.front();
        if(cur == temp) // 뽑아낼 수 있는 경우
        {
            dq.pop_front();
            // arr[cur] = 1;
        }
        else {
            // cout << cur << '\n';
            // 뒤로 돌리는것과 앞으로 돌리는 것 중 어느게 빠른지 판단
            // 중간을 다 뽑아서 1239만 남은 경우 3->9가 3->2->1->9보다 빠름을 인식
            // arr배열 추가, 0이면 남아있고 1이면 뽑아버린 상태
            // arr배열같이 헷갈리는 방식 대신 진짜 덱 돌기
            int wcnt = 0;
            for(int i = 0; i < dq.size(); i++) // 뒤로 가면서 탐색
            {
                if(dq[i] == temp)
                {
                    break;
                }
                else {
                    wcnt++;
                }
            }
            // 전부 탐색한 이후 wcnt와 dp.size() - wcnt 중 작은 수를 찾는다
            // cout << wcnt << ' ' << dq.size() - wcnt << '\n';
            // 더 덜 도는쪽으로 돔
            int rcnt = dq.size() - wcnt;
            if(wcnt < dq.size() - wcnt) // 앞을 뒤로 붙이기
            {
                while(wcnt--)
                {
                    int temp = dq.front();
                    dq.push_back(temp);
                    dq.pop_front();
                    cnt++;
                }
            }
            else { // 뒤를 앞으로 붙이기
                while(rcnt--)
                {
                    int temp = dq.back();
                    dq.push_front(temp);
                    dq.pop_back();
                    cnt++;
                }
            }
            dq.pop_front();
        }
        //cout << cnt << '\n';
        // cout << dq.front() << '\n';
    }
    cout << cnt << '\n';
    return 0;
}