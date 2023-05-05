#include <iostream>

using namespace std;

bool isorenge(string str, int len) // str에서 len길이의 부분 문자열이 오랜지 문자열임을 판
{
    /* 길이가 동일하며 각각 맨 앞, 맨 뒤 문자를 포함하는 어떤 두 부분 문자열이 앞에서부터 하나씩 비교했을 때 정확히 한 문자만 다른 경우, 전체 문자열을 "비타민 문자열"이라고 부름
        '어떤'은 '임의의' 라는 뜻이므로 길이를 전부 검사해야 함
    */
    string front;
    string end;
    front = str.substr(0,len);
    end = str.substr(str.size()-len);
    // cout << front << ' ' << end << '\n';
    int dif = 0;
    for(int i = 0; i <= len; i++)
    {
        if(front[i] != end[i])
        {
            dif++;
        }
    }
    if(dif == 1)
    {
        return true;
    }
    else {
        return false;
    }
}


int main(void)
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    // 부분 문자열을 앞에서부터 비교해야 함
    bool flag = false;
    // 내일 다시 풀자
    // 부분 문자열은 n-1의 길이까지 검사하면 됨 n의 부분 문자열은 자신이기 때문
    // 1의 길이일 경우 전부 같은 문자의 나열이 아니라면 오랜지 문자열임
    for(int i = 1; i <= n-1; i++)
    {
        if(isorenge(str,i) == true)
        {
            flag = true;
            break;
        }
    }
    if(flag)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}