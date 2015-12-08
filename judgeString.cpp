#include <iostream>
#include <string>
#include <vector>

using namespace std;

int judgeString(string temp) //获得输入有几个节点
{
	int len = temp.length(); //用于获得字符串长度
	vector<char> v(26);
	int flag = 0; //统计字符

	for (int i = 0; i < len; ++i)
	{	
		char tempChar = temp[i];
		if (tempChar == '{' || tempChar == '}' || tempChar == '<' || 
			tempChar == '>' || tempChar == ',')
			continue;
		else
			if(v[tempChar - 'a'] == tempChar)
				continue;
			else
			{
				v[tempChar - 'a'] = tempChar;
				++flag; //元素加一
			}
	}
}
