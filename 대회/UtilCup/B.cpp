#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    /*
    이 게임은 문자열을 규칙에 따라 나누는 게임이다.
    문자열을 공백과 주어진 구분자들로 나눈다.
    각 문자 구분자는 영어 대소문자 중 하나이다.
    각 숫자 구분자는 0부터 9까지의 숫자 중 하나이다.
    병합자로 주어진 문자들은 구분자로 취급하지 않는다.
    구분자와 병합자는 모두 한 글자로 이루어져 있다.
    나눌 문자열인 기준 문자열은 영어 대소문자, 숫자, 공백으로 이루어져 있다.
    같은 구분자 및 병합자가 주어질 수 있다.
    */
    int n, m, k, s;
    char str[1001]; // 문자열
    int deli[200]; // 구분자 여부
    int con[200]; // 병합자 여부
    deli[' '] = 1;
    cin >> n;
    char ch;
    for(int i = 0; i < n; i++)
    {
        cin >> ch;
        deli[ch] = 1; // 문자 구분자 여부 표기
    }
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> ch;
        deli[ch] = 1; // 숫자 구분자 표기
    }
    cin >> k;
    for(int i = 0; i < k; i++)
    {
        cin >> ch;
        if(deli[ch] == 1)
        {
            deli[ch] = 0; // 병합자는 구분자로 쓰일 수 없음
            con[ch] = 1;
        }
    }
    cin >> s;
    cin.get();
    for(int i = 1; i <= s; i++)
    {
        str[i] = cin.get();
    }
    vector<string> vs;
    string temp = "";
    for(int i = 1; i <= s; i++)
    {
        // cout << str[i];
        if(deli[str[i]] == 1) // 이 수가 구분자라면
        {
            cout << str[i] << "is delimeter \n";
            // cout << ' ' << temp << '\n';
            if(temp != "")
            {
                vs.push_back(temp);
                temp = "";
            }
        }
        else if(con[str[i]] == 1) // 이 수가 병합자라면
        {
            temp += str[i];
            // cout << ' ' << temp << '\n';
            // 전에 문자열이 있다면 합침 -> 아니면 그냥 현상유지
            if(!vs.empty())
            {
                cout << vs.back();
                cout << "\nmerging\n";
                string merg = vs.back() + temp;
                vs.pop_back();
                vs.push_back(merg);
                temp = "";
            }
        }
        else { // 일반적인 수라면
            temp += str[i];
        }
    }
    cout << '\n';
    for(int i = 0; i < vs.size(); i++)
    {
        cout << vs[i] << '\n';
    }
    return 0;
}