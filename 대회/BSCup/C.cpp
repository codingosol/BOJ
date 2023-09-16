#include <iostream>

using namespace std;

int main(void)
{
    string str; // yyyy-mm-dd 형태
    cin >> str;
    int year, month, day;
    year = 0;
    month = 0;
    day = 0;
    int temp = 0;
    for(int i = 0; i < 4; i++) // 연도 빼기
    {
        temp = temp*10 + str[i] - '0';
    }
    year = temp;
    // cout << year << ' ';
    temp = 0;
    for(int i = 5; i < 7; i++)
    {
        temp = temp*10 + str[i] - '0';
    }
    month = temp;
    // cout << month << ' ';
    temp = 0;
    for(int i = 8; i < 10; i++)
    {
        temp = temp*10 + str[i] - '0';
    }
    day = temp;
    // cout << day << '\n';
    int n; // 주기
    cin >> n;
    day += n;
    // 문제는 딱 60으로 나눠떨어지는 경우임
    if(day > 30)
    {
        if(day % 30 == 0)
        {
            month += day / 30 - 1;
            day = 30;
        }
        else {
            month += day / 30;
            day = day % 30;
        }
    }
    if(month > 12)
    {
        if(month % 12 == 0)
        {
            year += month / 12 -1;
            month = 12;
        }
        else {
            year += month / 12;
            month = month % 12;   
        }
    }
    cout << year << '-';
    if(month < 10)
    {
        cout << '0' << month;
    }
    else {
        cout << month;
    }
    cout << '-';
    if(day < 10)
    {
        cout << '0' << day << '\n';
    }
    else {
        cout << day << '\n';
    }
    return 0;
}