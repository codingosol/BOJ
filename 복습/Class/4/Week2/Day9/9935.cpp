#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    string str;
    string bomb;
    cin >> str >> bomb;
    vector<char> stk;
    for(int i = 0; i < str.length(); i++)
    {
        stk.push_back(str[i]);
        /*for(int k = 0; k < stk.size(); k++)
        {
            cout << stk[k];
        }
        cout << '\n';*/
        if(stk.size() >= bomb.size())
        {
            bool isbomb = true;
            int cnt = 0;
            while(cnt < bomb.size())
            {
                if(stk[stk.size() - bomb.size()+cnt] != bomb[cnt])
                {
                    isbomb = false;
                    break;
                }
                cnt++;
            }
            if(isbomb){
                //cout << "isbomb\n";
                for(int j = 0; j < bomb.size(); j++){
                    stk.pop_back();
                }
            }
        }
    }
    if(stk.size() == 0){
        cout << "FRULA\n";
    }
    else{
        for(int i = 0; i < stk.size(); i++){
            cout << stk[i];
        }
        cout << '\n';
    }
    return 0;
}