#include <iostream>
using namespace std;

int max_vote(int arr[], int size)
{
    int max = 0;
    int index = 0;
    for(int i = 1; i <= size; i++)
    {
        if(max <= arr[i]) // 동일 득표도 없애야 함
        {
            max = arr[i];
            index = i;
        }
    }
    return index; 
}

int vote(int arr[], int cnt, int size)
{
    // 최대 득표수 후보 고르기 -> 1표 매수 진행 -> 반복
    while(true)
    {
        int index = max_vote(arr,size);
        // 최대 득표수의 index 얻음
        if(index == 1) // 1번 후보가 최다 득표라면
        {
            return cnt;
        }
        else {
            arr[index]--; // 1표 감소
            arr[1]++; // 1표 증가
            cnt++; // 매수 증가
        }
    }
}


int main(void)
{
    int n;
    cin >> n;
    int arr[51]; // 정치인의 수
    int cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i]; // 현재 표수 입력
    }
    // 1번 후보가 우승하도록 매수해야 함
    // 최대 득표를 가진 후보에게서 훔쳐오는게 나음
    cnt = vote(arr,cnt,n);
    cout << cnt << "\n";
    return 0;
}