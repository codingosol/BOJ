#include <iostream>
#include <cmath>

using namespace std;
int arr[500001];

int main(void)
{
    /*음 하나를 연주해야 할 때마다 $1$부터 양의 정수 $N$까지의 정수 중 하나를 쓴다.
    직전에 연주한 음이 현재 연주할 음보다 낮으면 직전에 쓴 수보다 큰 수를 쓴다. 
    직전에 연주한 음이 현재 연주할 음보다 높으면 직전에 쓴 수보다 작은 수를 쓴다.
    직전에 연주한 음과 현재 연주할 음이 같으면 직전에 쓴 수를 쓴다 */
    // 연속으로 내려가는 혹은 올라가는 값의 최댓값을 찾으면 됨
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int move = 0; // -1은 내림 0은 그대로 1은 오름
    int len = 1; // 연속 길이
    int prev = arr[0];
    int down = 1;
    int up = 1;
    for(int i = 1; i < n; i++)
    {
        if(arr[i] > prev) // 더 커질때
        {
            if(move == 1) // 오를때
            {
                len++; // 길이 증가
            }
            else if(move == 0) // 유지일때
            {
                len = 2;
            }
            else { // 내릴때
                down = max(down,len);
                len = 2;
            }
            move = 1;
        }
        else if(arr[i] < prev) // 내릴때
        {
            if(move==0){
                len = 2;
            }
            else if (move==1)
            {
                up=max(up,len);
                len = 2;
            }
            else if (move==-1)
            {
                len++;
            }
            move = -1;
        }
        prev = arr[i];
    }
    if(move==1){
        up=max(up,len);
    }
    else if(move==-1){
        down=max(down,len);
    }
    cout<< max(up,down) << '\n';
    return 0;
}