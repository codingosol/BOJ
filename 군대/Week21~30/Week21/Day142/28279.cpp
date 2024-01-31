#include <iostream>
#include <deque>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int oper, num;
    deque<int> dq;
    while(n--)
    {
        cin >> oper;
        if(oper == 1)
        {
            cin >> num;
            dq.push_front(num);
        }
        else if(oper == 2){
            cin >> num;
            dq.push_back(num);
        }
        else if(oper == 3){
            if(!dq.empty())
            {
                cout << dq.front() << '\n';
                dq.pop_front();
            }
            else{
                cout << "-1\n";
            }
        }
        else if(oper == 4){
            if(!dq.empty())
            {
                cout << dq.back() << '\n';
                dq.pop_back();
            }
            else{
                cout << "-1\n";
            }
        }
        else if(oper == 5){
            cout << dq.size() << '\n';
        }
        else if(oper == 6){
            if(dq.empty())
                cout << "1\n";
            else
                cout << "0\n";
        }
        else if(oper == 7){
            if(!dq.empty())
                cout << dq.front() << '\n';
            else
                cout << "-1\n";
        }
        else if(oper == 8){
            if(!dq.empty())
            {
                cout << dq.back() << '\n';
            }
            else {
                cout << "-1\n";
            }
        }
    }
    return 0;
}