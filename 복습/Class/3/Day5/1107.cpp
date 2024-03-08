#include <iostream>

using namespace std;

int broken[10];

bool can_click(int i)
{
    int digit;
    while(i > 0)
    {
        digit = i % 10;
        if(broken[digit] == 1){
            return false;
        }
        i /= 10;
    }
    return true;
}

int main(void)
{
    int n;
    cin >> n;
    int ch = 100; // 현재 채널
    int m;
    cin >> m;
    int temp;
    for(int i = 0; i < m; i++){
        cin >> temp;
        broken[temp] = 1;
    }
    // 목표 채널과 버튼 조합으로 가장 가까이 갈 수 있는 위치 선정
    // 1. +, - 로만 도달하는 경우 => abs(n - ch)
    // 2. i라는 숫자에 도달한 다음 클릭을 통해 가는 방법
    // 2. 0으로 간 뒤 +로 가는 방법
    int min_cnt = abs(n - ch); // case #1
    if(min_cnt > abs(n) && broken[0] == 0) // case #3
        min_cnt = abs(n) + 1;
    for(int i = 1; i <= 1000000; i++) // case #2
    {
        int cnt = 0;
        if(can_click(i)){
            int temp = i;
            while(temp > 0){
                temp /= 10;
                cnt++;
            }
            cnt += abs(n - i);
            if(min_cnt > cnt){
                min_cnt = cnt;
            }
        }
    }
    cout << min_cnt << '\n';
    return 0;
}