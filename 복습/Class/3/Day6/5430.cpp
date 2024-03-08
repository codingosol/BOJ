#include <iostream>
#include <deque>

using namespace std;

int main(void)
{
    int testcase;
    cin >> testcase;
    for(int i = 0; i < testcase; i++)
    {
        string oper;
        cin >> oper;
        string str;
        int n;
        cin >> n >> str;
        deque<int> dq;
        int temp = 0;
        for(int j = 0; j < str.length(); j++)
        {
            if(str[j] >= '0' && str[j] <= '9')
            {
                temp *= 10;
                temp += str[j] - '0';
            }
            else if(str[j] == ',' || str[j] == ']'){
                if(temp != 0)
                    dq.push_back(temp);
                temp = 0;
            }
        } // input
        /*for(int j = 0; j < dq.size(); j++)
        {
            cout << dq[i] << ' ';
        }
        cout << '\n';*/
        bool reversed = false;
        bool flag = false;
        for(int j = 0; j < oper.length(); j++)
        {
            if(oper[j] == 'R'){
                reversed = !reversed;
            }
            else if(oper[j] == 'D')
            {
                if(dq.empty())
                {
                    cout << "error\n";
                    flag = true;
                    break;
                }
                if(reversed){ // 뒤집힌 경우 뒤에서부터 
                    dq.pop_back();
                }
                else{ // 아니라면 앞에서부터
                    dq.pop_front();
                }
            }
        } // calc;
        if(flag)
            continue;
        cout << '[';
        for(int j = 0; j < dq.size(); j++)
        {
            if(reversed){
                cout << dq[dq.size() - j - 1];
            }
            else{
                cout << dq[j];
            }
            if(j != dq.size() - 1){
                cout << ",";
            }
        }
        cout << ']';
        cout << '\n';
    }
    return 0;
}