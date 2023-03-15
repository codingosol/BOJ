#include <iostream>
#include <stack>
#include <deque>
using namespace std;

int main(void)
{
    int cnt = 0;
    string str = "start";
    while(str[0] != '0')
    {
        cnt++;
        cin >> str;
        if(str[0] == '0')
        {
            return 0;
        }
        else {
            bool flag = true;
            if(str[0] != '1' || str[str.length() - 1] != '2') // 처음과 시작이 1과 2로 끝나지 않는다면
            {
                cout << cnt << ". NOT\n";
                continue;
            }
            else {
                for(int i = 0; i < str.length(); i++) // 앞에서부터 탐색하므로 다음 인덱스가 되는지만 신경쓰면 됨
                {
                    if(str[i] == '1')
                    {
                        if(i != 0 || (str[i + 1] != '4' && str[i + 1] != '5'))
                        {
                            flag = false;
                            break;
                        }
                    }
                    else if(str[i] == '2') // 2의 다음 인덱스는 존재하지 않음
                    {
                        if(i != str.length() - 1)
                        {
                            flag = false;
                            break;
                        }
                    }   
                    else if(str[i] == '3')
                    {
                        if(str[i + 1] != '4' && str[i + 1] != '5')
                        {
                            flag = false;
                            break;
                        }
                    }
                    else if(str[i] == '4')
                    {
                        if(str[i + 1] != '3' && str[i + 1] != '2')
                        {
                            flag = false;
                            break;
                        }
                    }
                    else if(str[i] == '5')
                    {
                        if(str[i + 1] != '8')
                        {
                            flag = false;
                            break;
                        }
                    }
                    else if(str[i] == '6')
                    {
                        if(str[i + 1] != '3' && str[i + 1] != '2')
                        {
                            flag = false;
                            break;
                        }
                    }
                    else if(str[i] == '7')
                    {
                        if(str[i + 1] != '8')
                        {
                            flag = false;
                            break;
                        }
                    }
                    else if(str[i] == '8')
                    {
                        if(str[i + 1] != '7' && str[i + 1] != '6')
                        {
                            flag = false;
                            break;
                        }
                    }
                }
                if(flag)
                {
                    cout << cnt << ". VALID\n";
                }
                else {
                    cout << cnt << ". NOT\n";
                }
            }
        }  
    }
    return 0;
}