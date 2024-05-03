//grammer.cpp
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstdlib>
#include <stdexcept>
#include "split.h"

using namespace std;

// ["dog", "cat", "cup", "table"]
typedef vector<string> Rule;
// ["hat", "car"] +  ["dog", "cat"]
typedef vector<string> Rule_collection;
// {"noun" : ["hat", "car"] , ["dog", "cat"]}
typedef map<string, Rule_collection> Grammer;

//�־��� �Է� ��Ʈ������ ���� ���̺��� ����
Grammer read_grammer(istream& in)
{
	Grammer ret;
	string line;

	//�Է� �����͸� ����
	while (getline(in, line))
	{
		//�Է� �����͸� �ܾ�� ����
		vector <string> entry = split(line);
		if(!entry.empty())
		{
			//ī�װ� �� ������ ��Ģ�� �ʿ� ����
			ret[entry[0]].push_back(Rule(entry.begin() + 1, entry.end()));

		}
  	}
	return ret;
}



bool bracketed(const string& s)
{
	return s.size() > 1
		&& s[0] == '<' && s[s.size() - 1] == '>';
}
int nrand(int n)
{
	if (n <= 0 || n > RAND_MAX)
		throw domain_error("nrand is out of range!");
	const int bucket_size = RAND_MAX/n;
	int r;
	do r = rand() / bucket_size;
	while (r >= n);
	return r;

}
void gen_aux(const Grammer& g, const string& word, vector<string>& ret)
{
	if (!bracketed(word))
		ret.push_back(word);
	else {
		//word�� ������ ��Ģ�� ã��
		Grammer::const_iterator it = g.find(word);
		if (it == g.end())
			throw logic_error("Empty rule!");

		//���� ������ ��Ģ�� ��� ���� ���͸� ������
		const Rule_collection& c = it->second;

		//���Ƿ� �ϳ��� ����
		const Rule& r = c[nrand(c.size())];

		//������ ��Ģ�� ��������� Ȯ��
		for (Rule::const_iterator i = r.begin();
			i != r.end(); ++i)
		{
			gen_aux(g, *i, ret);
		}
	}
}

vector<string> gen_sent(const Grammer& g)
{
	vector<string> ret;
	gen_aux(g, "<sentence>", ret);
	return ret;
}

int main() {
	//���� ����
	vector<string> sectence = gen_sent(read_grammer(cin));

	//ù ��° �ܾ� ���
	vector<string>::const_iterator it = sectence.begin();
	if (it != sectence.end())
	{
		cout << " " << *it;
		++it;
	}


	cout << endl;
	return 0;
}