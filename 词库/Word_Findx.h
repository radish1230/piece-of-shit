#pragma once
#include<string>
#include"Word_Store.h"
class findx											//���ڲ��Һ���
{
public:
	findx(const string str)
	{
		input = str;
	}
	string GetTest()
	{
		return input;
	}
	bool operator()(Word_Store& dvalue)                  //������������������ڲ���find_if����
	{

		if (dvalue.Getspell().compare(input) == 0)
			return true;
		else
			return false;
	}
private:
	string input;
};