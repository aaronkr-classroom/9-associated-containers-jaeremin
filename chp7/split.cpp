#include <algorithm>
#include <cctype> //isspace
#include <iostream>
#include <vector>
#include <string>

using namespace std;

//�μ��� �����϶� true, �׷��� ���� ���� false
 bool space(char c)
{
	return isspace(c);
}

//�μ��� �����϶� false, �׷��� ���� ���� true
 bool not_space(char c)
{
	return !isspace(c);
}

 vector<string> split(const string& str)
{
	typedef string::const_iterator iter;
	iter i = str.begin();
	vector<string> ret;

	while (i != str.end())
	{

		//���� ������ ����
		//���� ���� ��ġ����
		i = find_if(i, str.end(), not_space);//ù��° ���� ã��

		//���� �ܾ��� ���� ã��
		//while �ݺ��� �� �׻� ���ο� �ݺ��� j�� ����
		//���� i��ġ���� ù ��° ���� ���� ã��
		iter j = find_if(i, str.end(), space);

		//[i,j) ������ ���ڸ� ����
		if (i != str.end())
		{
			ret.push_back(string(i, j));
		}

		//i �ݺ��� ��ġ�� j�ݺ����� ��ġ�� �����ϱ�
		i = j;
	}

	return ret;
}
