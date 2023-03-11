#include <iostream>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int year;
    cin >> year;

    if(year%400==0 || (year%4==0 && year%100!=0))
        cout << 1 << endl;
    else
        cout << 0 << endl;
    return 0;
}