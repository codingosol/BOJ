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
    int gap = chan - 100;
    vector<int> v;
    for(int i = chan; i > 0; i /= 10)
    {
        int deci = i % 10; // 이러면 맨 뒤 숫자가 나옴
        v.push_back(deci); 
    }
    // !!! v에 저장되는건 역순으로 된 수임 -> 역순으로 만들어야 함
    int mult = 1; // 역순이므로 이 변수를 10씩 곱해서 만들어줄 수 있음
    for(int i = 0; i < v.size(); i++)
    {
        int tmp; // 최근접 자릿수를 저장할 변수
        int dif = 1000;
        for(int j = 0; j < 10; j++)
        {
            if((abs(v[i] - j) < dif) && button[j] != 1) // 차이가 적고 고장난 버튼이 아니라면
            {
                tmp = j;
                dif = abs(v[i] - j);
            }
        }
        // 이제 tmp에는 최솟값이 저장되어있음
        adjchan = adjchan + (tmp * mult);
        cout << adjchan << '\n';
        mult *= 10;
        cnt++;
    }
    cout << chan << '\n' << adjchan << '\n';
    // 이제 +,-를 이용해 그 채널로 이동하면 됨
    cnt = cnt + abs(chan - adjchan);
    cout << min(cnt,abs(gap)) << '\n';
    return 0;
}