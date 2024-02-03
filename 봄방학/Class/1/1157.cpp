#include <iostream>

using namespace std;

int main(void)
{
    string str;
    cin >> str;
    int arr[26] = {0,};
    for(int i = 0; i < str.length(); i++) // 나온 횟수 기록
    {
        int alphabet;
        if(str[i] >= 'A' && str[i] <= 'Z')
        {
            alphabet = str[i] - 65;
        }
        else if(str[i] >= 'a' && str[i] <= 'z')
        {
            alphabet = str[i] - 97;
        }
        arr[alphabet]++;
    }
    // 최대로 나온 횟수 찾기
    int max = 0;
    int index = -1;
    bool flag = false; // 중복된 수 있는지 체크
    for(int i = 0; i < 26; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
            index = i;
            flag = false;
        }
        else if(arr[i] == max)
        {
            flag = true;
        }
    }
    if(flag) // 중복 있을 경우
    {
        cout << "?\n";
    }
    else
    {
        cout << char(index + 65) << '\n';
    }
    return 0;
}