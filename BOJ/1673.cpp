#include <iostream>
using namespace std;

int main(void) 
{
	int coupon, convert_cnt, stamp;
	// �������� �Է°��� ������ �־����� �ʾ����Ƿ� �Է� ������ ��(EOF)���� �Է¹���
	// cin�� cin ��ü�� ��ȯ������ iostream ������� ���� �̸� bool �Ǵ� �ٸ� Ÿ������
	// �ٲپ� �� �� �ִ� conversion operator�� ���ǵǾ� �־
	// if�� while �ȿ� ���� ���������� operator�� ���� �ڵ����� bool�� �ٲ�
	// ���� scanf�� ����Ѵٸ� ������ ���� ������ ���� �� ����(!=EOF)�� ������ �ٲ�� ��
	while (cin >> coupon >> convert_cnt) 
	{
		int stamp = 0, eatable_chicken = 0;
		while (coupon > 0) 
		{
			eatable_chicken += coupon; // ������ ������ŭ ġŲ�� �ٲ����
			stamp += coupon; // �������� �ٲ���� ġŲ��ŭ ������ ����
			coupon = stamp / convert_cnt; // ���� �������� ������ �ٲ�
			stamp = stamp % convert_cnt; // ������ �ٲٰ� ���� ����
			// ���Ŀ��� �������� �ٲ� ������ ���� ������ ��� ����� ������ �ݺ�
		}
		cout << eatable_chicken << endl; // �� ���� �� �ִ� ġŲ�� �� ���
	}
	return 0;
}