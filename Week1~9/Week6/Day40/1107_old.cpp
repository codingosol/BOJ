#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int button[10]; // 0~9까지의 버튼 1일 경우 고장남

int main(void)
{
    int chan;
    cin >> chan;
    int num;
    cin >> num;
    int temp;
    int cnt = 0;
    for(int i = 0; i < num; i++)
    {
        cin >> temp;
        button[temp] = 1; // 고장남 표기
    }
    // 먼저 num과 가장 가까운 수를 만들어야 함 -> 그 후 + - 연산
    int adjchan = 0; // 인접수를 저장할 변수
    int gap = chan - 100; // 그냥 -,+로 도달할 경우
    int gap_zero = 1 + (chan); // 0 누르고 +로 도달하는 경우
    vector<int> v;
    int mult = 0; // 자릿수를 저장할 변수
    for(int i = chan; i > 0; i /= 10)
    {
        int deci = i % 10; // 이러면 맨 뒤 숫자가 나옴
        v.push_back(deci); 
        mult++;
    }
    // !!! v에 저장되는건 역순으로 된 수임 -> 역순으로 만들어야 함
    // 역순인 v를 거꾸로 뒤집어야 함
    int cur_num = 0;
    mult = pow(10,mult - 1);
    for(int i = v.size() - 1; i >= 0; i--)
    {
        cur_num = cur_num + (v[i] * mult); // 원래 현재 수
        int tmp; // 최근접 자릿수를 저장할 변수
        int dif = 987654321;
        for(int j = 0; j < 10; j++)
        {
            if((abs(cur_num - (adjchan + j * mult)) < dif) && button[j] != 1) // 차이가 적고 고장난 버튼이 아니라면 -> 자릿수끼리 하니까 안됨
            {
                tmp = j;
                dif = abs(cur_num - (adjchan + j * mult));
            }
        }
        // 이제 tmp에는 최솟값이 저장되어있음
        adjchan = adjchan + (tmp * mult);
        mult /= 10;
        cnt++;
    }
    cout << chan << ' ' << adjchan << '\n';
    // 이제 +,-를 이용해 그 채널로 이동하면 됨
    cnt = cnt + abs(chan - adjchan);
    cout << min(min(cnt,abs(gap)),gap_zero) << '\n';
    return 0;
}