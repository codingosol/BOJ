#include <iostream>
#include <cmath>
using namespace std;

int alphabet[100][26]; // 알파벳 수를 결정함

bool issim(int index)
{
    // 하나 빼거나, 더하거나, 바꾸는 경우
    // 더하거나 빼는 경우 dif는 1
    // 바꾸는 경우 길이가 같고 dif가 2
    int dif = 0;
    int len_origin = 0, len_cmp = 0;
    for(int i = 0; i < 26; i++)
    {
        dif = dif + abs(alphabet[0][i] - alphabet[index][i]);
        len_origin += alphabet[0][i];
        len_cmp += alphabet[index][i];
    }
    if(dif <= 1 || (dif == 2 && len_origin == len_cmp))
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
    string str; // 첫 번째 문자열을 저장
    string temp; // 두 번째 문자열부터 저장
    cin >> str;
    int ch;
    int cnt = 0;
    for(int i = 0; i < str.length(); i++) // 첫번째 문자열
    {
        ch = str[i] - 'A';
        alphabet[0][ch]++;
    }
    for(int i = 1; i <= n - 1; i++) // 나머지 문자열 입력
    {
        cin >> temp;
        for(int j = 0; j < temp.length(); j++) // 문자열의 알파벳 입력
        {
            ch = temp[j] - 'A';
            alphabet[i][ch]++;
        }
        if(issim(i)) // 비슷한지 판별
        {
            cnt++;
        }
    }
    cout << cnt << '\n';
}