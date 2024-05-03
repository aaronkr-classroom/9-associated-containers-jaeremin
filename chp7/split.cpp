#include <algorithm>
#include <cctype> //isspace
#include <iostream>
#include <vector>
#include <string>

using namespace std;

//인수가 공백일때 true, 그렇지 않을 때는 false
 bool space(char c)
{
	return isspace(c);
}

//인수가 공백일때 false, 그렇지 않을 때는 true
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

		//선행 공백을 무시
		//지금 아이 위치부터
		i = find_if(i, str.end(), not_space);//첫번째 문자 찾기

		//다음 단어의 끝을 찾음
		//while 반복할 때 항상 새로운 반복자 j를 생성
		//지금 i위치부터 첫 번째 띄어쓰기 문자 찾기
		iter j = find_if(i, str.end(), space);

		//[i,j) 범위의 문자를 복사
		if (i != str.end())
		{
			ret.push_back(string(i, j));
		}

		//i 반복자 위치가 j반복자의 위치를 저장하기
		i = j;
	}

	return ret;
}
