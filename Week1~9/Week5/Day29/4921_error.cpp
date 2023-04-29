#include <iostream>
#include <deque>
using namespace std;

int main(void)
{
    string str = "start";
    int cnt = 0;
    while(str[0] != '0'){
        cnt++;
        cin >> str;
        if(str[0] == '0')
            break;
        //  이제 조건에 맞는지 판별
        /*
        가장 왼쪽 조각은 1번 조각, 가장 오른쪽 조각은 2번 조각이어야 한다.
        인접한 조각은 서로 맞물려야 한다. 예를 들어, 4번 조각과 5번 조각은 항상 1번 조각의 오른쪽에 있어야 한다. 또, 4번 조각은 1번이나 3번조각의 오른쪽에 있을 수 있다.
        1번 조각의 왼쪽과 2번 조각의 오른쪽에 맞물리는 조각은 없다.
        각각의 1번 조각에 대해서, 대응하는 2번 조각이 있어야 하고, 5번 조각에 대해서도 대응하는 6번 조각이 있어야 한다.
        */
        bool flag = true;
        if(str[0] != '1' || str[str.length() - 1] != '2') // 맨 오른쪽 왼쪽 조각이 1과 2가 아니라면
        {
            cout << cnt << ". NOT\n";
            continue;
        } 
        for(int i = 0; i < str.length(); i++){
            if(str[i] == '1'){
                if(str[i + 1] != '4' && str[i + 1] != '5'){
                    flag = false;
                }
            }
            else if(str[i] == '2'){
                if(str[i - 1] != '4' && str[i - 1] != '6'){
                    flag = false;
                }
            }
            else if(str[i] == '3'){
                if(str[i - 1] != '4' && str[i - 1] != '6'){
                    flag = false;
                }
                if(str[i + 1] != '4' && str[i + 1] != '5'){
                    flag = false;
                }
            }
            else if(str[i] == '4'){
                if(str[i - 1] != '1' && str[i - 1] != '3'){
                    flag = false;
                }
                if(str[i + 1] != '2' && str[i + 1] != '3'){
                    flag = false;
                }
            }
            else if(str[i] == '5'){
                if(str[i - 1] != '1' && str[i - 1] != '3'){
                    flag = false;
                }
                if(str[i+1] != '8'){
                    flag = false;
                }
            }
            else if(str[i] == '6'){
                if(str[i + 1] != '2' && str[i + 1] != '3'){
                    flag = false;
                }
                if(str[i - 1] != '8'){
                    flag = false;
                }
            }
            else if(str[i] == '7'){
                if(str[i-1] != '8' || str[i+1] != '8'){
                    flag = false;
                }
            }
            else if(str[i] == '8'){
                if(str[i-1] != '5' && str[i-1] != '7'){
                    flag = false;
                }
                if(str[i+1] != '6' && str[i+1] != '7'){
                    flag = false;
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
    return 0;
}