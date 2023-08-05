#include <iostream>

using namespace std;

string c[4];
// 0부터 12시 ~ 7은 10시 반
// N극은 0, S극은 1
int isspin[4]; // 회전한다면 1 or -1 아니면 0

void left_spin(int num, int d) // 각 톱니바퀴의 연결상태 수정
{
    // num의 왼쪽 톱니바퀴의 회전 가능 여부를 판단
    if(num <= 0)
        return;
    if(c[num][6] != c[num-1][2]) // 회전 가능
    {
        isspin[num-1] = -d; // 서로 반대방향으로 돔
        left_spin(num-1, -d); // 그 옆의 시계도 확인
    }
    else {
        // 안돈다면
        isspin[num-1] = 0; // 안돌아!
    }
}

void right_spin(int num, int d)
{
    if(num >= 3)
        return;
    if(c[num][2] != c[num+1][6]) // 회전 가능
    {
        isspin[num+1] = -d; // 서로 반대방향으로 돔
        right_spin(num+1, -d); // 그 옆의 시계도 확인
    }
}

void spin(int num, int d) // num번 시계를 d 방향으로 회전시킴
{
	if (d == 1)
		c[num] = c[num].substr(7) + c[num].substr(0, 7);
	else if(d == -1)
		c[num] = c[num].substr(1, 7) + c[num].substr(0, 1);
}

void solve(int num, int d)
{
    isspin[num] = d;
    left_spin(num,d);
    right_spin(num,d);
    for(int i = 0; i < 4; i++)
    {
        spin(i,isspin[i]);
    }
    /*cout << '\n';
    for(int i = 0; i < 4; i++)
    {
        cout << c[i] << '\n';
    }*/
}

int ans()
{
    int ret = 0;
    if(c[0][0] - '0' == 1)
        ret += 1;
    if(c[1][0] - '0' == 1)
        ret += 2;
    if(c[2][0] - '0' == 1)
        ret += 4;
    if(c[3][0] - '0' == 1)
        ret += 8;
    return ret;
}


int main(void)
{
    for(int i = 0; i < 4; i++)
    {
        cin >> c[i];
    } // input
    /*cout << '\n';
    for(int i = 0; i < 4; i++)
    {
        cout << c[i] << '\n';
    }*/
    int k;
    cin >> k;
    int num, d; // 각각 회전시킬 톱니바퀴와 방향
    while(k--)
    {
        cin >> num >> d;
        fill_n(isspin,4,0);
        solve(num-1,d);
    }
    cout << ans() << '\n';
    return 0;
}