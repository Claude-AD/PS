#include <bits/stdc++.h>
using namespace std;

void whatIsRecursion(int n, string str) {
    cout << str << "\"����Լ��� ������?\"\n";
    if (n == 0) {
        cout << str << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
    }
    else {
        cout << str << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n"
            << str << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n"
            << str << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";
        whatIsRecursion(n - 1, str + "____");
    }
    cout << str << "��� �亯�Ͽ���.\n";
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
    whatIsRecursion(n, "");
}