#include<iostream>
#include<cstring>

using namespace std;

int main(void)
{
    int arr[26]; // 알파벳이 26개
    memset(arr,-1,sizeof(int) * 26);
    string str;
    cin >> str;
    // 알파벳이 처음 나오는 위치를 찾아야 함
    // a~z까지 전부 탐색하는건 무지 비효율적
    // 'a'가 수로 97임을 이용
    for(int i = 0; i < str.size(); i++) // 문자열의 길이 
    {
        if(arr[str[i] - 97] == -1)
        {
            arr[str[i] - 97] = i;
        }
    }
    for(int i = 0; i < 26; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}