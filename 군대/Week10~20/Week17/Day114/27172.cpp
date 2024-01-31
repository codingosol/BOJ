#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int score[1000001]; // 1~1000000의 배열
int minval = -987654321;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int temp;
    vector<int> arr; // 각 수 저장
    fill_n(score,1000001,minval);
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        arr.push_back(temp);
        score[temp] = 0;
    }
    // 같은 수가 등장하지 않으므로 오름차순으로 정렬하면 차례대로 계산할 수 있음 -> 정렬해버려서 답이 순서대로 출력되지 않음
    // sort(arr.begin(),arr.end());
    for(int i = 0; i < arr.size(); i++)
    {   
        int cur = arr[i]; // 현재 계산할 값
        for(int j = cur * 2; j <= 1000000; j += cur)
        {
            // 반복하면서 나눌 수 있는 수(즉 cur의 배수가 -987654321이 아니라면)을 찾으면 +1 그리고 그 수는 -1
            if(score[j] != -987654321)
            {
                score[cur]++;
                score[j]--;
            }
        }
    }
    for(int i = 0; i < arr.size(); i++)
    {
        cout << score[arr[i]] << ' ';
    }
    cout << '\n';
    return 0;
}