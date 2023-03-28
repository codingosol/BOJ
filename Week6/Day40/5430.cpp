#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int testcase;
    cin >> testcase;
    for(int i = 0; i < testcase; i++)
    {
        string p;
        cin >> p; // 실행할 명령
        int num; // 입력받은 수의 개수
        string str; // 입력받은 수
        cin >> num;
        deque<int> dq;
        int temp = 0;
        cin >> str;
        for(int j = 0; j < str.length(); j++) // 문자열을 파싱해서 덱에 삽입
        {
            if(str[j] == '[') // 무시할 수
            {
                continue;
            }
            else if(str[j] == ',' || str[j] == ']') // 문자열 수 끊음
            {
                if(temp != 0)
                    dq.push_back(temp);
                temp = 0; // 초기화
            }
            else { // 수라면
                temp = temp * 10 + (str[j] - '0');
            }
        } // input
        // 이제 명령을 수행해야 함
        bool flag = true;
        int reverse = 0;
        for(int j = 0; j < p.length(); j++)
        {
            if(p[j] == 'R') // 뒤집어야 함
            {
                if(reverse == 0)
                    reverse = 1;
                else
                    reverse = 0;
            }
            else if(p[j] == 'D') // 맨 앞 수를 삭제함
            {
                if(dq.empty())
                {
                    cout << "error\n";
                    flag = false;
                    break;
                }
                else {
                    if(reverse == 0)
                        dq.pop_front();
                    else
                        dq.pop_back();
                }
            }
        }
        // 명령 끝나고 출력
        if(reverse == 1)
        {
            int tmp;
            for(int k = 0; k < dq.size() / 2; k++)
            {
                tmp = dq[k];
                dq[k] = dq[dq.size() - (k + 1)];
                dq[dq.size() - (k + 1)] = tmp;
            }
        }
        if(flag)
        {
            cout << '[';
            for(int j = 0; j < dq.size(); j++)
            {
                if(j != dq.size() - 1)
                    cout << dq[j] << ',';
                else
                    cout << dq[j];
            }
            cout << "]\n";
        }
    }
    return 0;
}