#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ���ڿ����� �ߺ��� ���ĺ��� ã�� �׵��� �ε����� ������ ���͸� �����ϴ� �Լ�
vector<int> FindDuplicateAlpha(const string str);
bool IsTwoVectorSame(vector<int> v1, vector<int> v2);

int main(void) 
{
	int test_case;
	cin >> test_case;
	for (int i = 0; i < test_case; i++)
	{
		// ��ȣȭ�� ������ ���� �Է�
		int num_of_code_sen;
		cin >> num_of_code_sen;

		// ��ȣȭ�� ���� ��� �Է�
		string* code_sen_arr = new string[num_of_code_sen];
		for (int j = 0; j < num_of_code_sen; j++)
			cin >> code_sen_arr[j];

		// �ص��� ���� �� �ص��ϰ��� �ϴ� ��Ź� �Է�
		string encoded_sen, sen_to_encode;
		cin >> encoded_sen >> sen_to_encode;

		// �־��� �ص����� �����Ǵ� ��ȣ���� ã�� ����
		vector<int>* code_sen_dup_v = new vector<int>[num_of_code_sen];
		for (int j = 0; j < num_of_code_sen; j++)
			code_sen_dup_v[j] = FindDuplicateAlpha(code_sen_arr[j]);
		vector<int> encoded_sen_dup_v = FindDuplicateAlpha(encoded_sen);

		vector<string> corresponding_code_sen_v;
		int corresponding_cnt = 0;
		for (int j = 0; j < num_of_code_sen; j++)
		{
			if (IsTwoVectorSame(code_sen_dup_v[j], encoded_sen_dup_v) &&
				code_sen_arr[j].length() == encoded_sen.length())
			{
				corresponding_code_sen_v.push_back(code_sen_arr[j]);
				corresponding_cnt++;
			}
		}
		
		char alpha_code_table[26];
		for (int j = 0; j < 26; j++)
			alpha_code_table[j] = '?';

		if (corresponding_cnt == 0) // �����Ǵ� ��ȣ���� �ϳ��� ���� ���,
		{
			cout << "IMPOSSIBLE\n";
		}
		else if (corresponding_cnt == 1) // �����Ǵ� ��ȣ���� �ϳ��ۿ� ���� ���,
		{
			string cor_code_sen = corresponding_code_sen_v[0];
			int alpha_cnt = 0;
			bool used_alpha[26];
			for (int j = 0; j < 26; j++)
				used_alpha[j] = false;

			for (int j = 0; j < cor_code_sen.length(); j++)
			{
				alpha_code_table[cor_code_sen[j] - 97] = encoded_sen[j];
				alpha_cnt++;
				used_alpha[encoded_sen[j] - 97] = true;
			}

			if (alpha_cnt == 25)
			{
				int a;
				char left_alpha;
				for (int j = 0; j < 26; j++)
				{
					if (used_alpha[j] == false)
						left_alpha = j + 97;

					if (alpha_code_table[j] == '?')
						a = j;
				}
				alpha_code_table[a] = left_alpha;
			}

			for (int j = 0; j < sen_to_encode.length(); j++)
				cout << alpha_code_table[sen_to_encode[j] - 97];
			cout << '\n';
		}
		else // �����Ǵ� ��ȣ���� �� �̻��� ���,
		{
			int alpha_cnt = 0;
			bool used_alpha[26];
			for (int j = 0; j < 26; j++)
				used_alpha[j] = false;

			for (int j = 0; j < encoded_sen.length(); j++)
			{
				bool is_all_cor_code_same = true;
				for (int k = 1; k < corresponding_code_sen_v.size(); k++)
				{
					if (corresponding_code_sen_v[0][j] != corresponding_code_sen_v[k][j])
						is_all_cor_code_same = false;
				}

				if (is_all_cor_code_same)
				{
					alpha_code_table[corresponding_code_sen_v[0][j] - 97] = encoded_sen[j];
					alpha_cnt++;
					used_alpha[encoded_sen[j] - 97] = true;
				}
			}

			if (alpha_cnt == 25)
			{
				int a;
				char left_alpha;
				for (int j = 0; j < 26; j++)
				{
					if (used_alpha[j] == false)
						left_alpha = j + 97;

					if (alpha_code_table[j] == '?')
						a = j;
				}
				alpha_code_table[a] = left_alpha;
			}

			for (int j = 0; j < sen_to_encode.length(); j++)
				cout << alpha_code_table[sen_to_encode[j] - 97];
			cout << '\n';
		}
		delete[] code_sen_arr;
		delete[] code_sen_dup_v;
	}
	return 0;
}

vector<int> FindDuplicateAlpha(const string str)
{
	vector<int> dup_idx;
	bool* isDup = new bool[str.length()];
	for (int i = 0; i < str.length(); i++)
	{
		isDup[i] = false;
	}
	for (int i = 0; i < str.length() - 1; i++) 
	{
		for (int j = i + 1; j < str.length(); j++)
		{
			if (str[i] == str[j])
			{
				if (isDup[i] == false && isDup[j] == false)
				{
					isDup[i] = true;
					isDup[j] = true;
				}
				else if (isDup[j] == false)
				{
					isDup[j] = true;
				}
			}
		}
	}
	for (int i = 0; i < str.length(); i++)
	{
		if (isDup[i] == true)
			dup_idx.push_back(i);
	}
	return dup_idx;
}

bool IsTwoVectorSame(vector<int> v1, vector<int> v2)
{
	if (v1.size() != v2.size())
		return false;
	else
	{
		for (int i = 0; i < v1.size(); i++)
		{
			if (v1[i] != v2[i])
				return false;
		}
		return true;
	}
}