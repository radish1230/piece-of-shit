#pragma once
#include<string>
#include"Word_Store.h"
class findx											//���ڲ��Һ���
{
public:
	findx(const string str)
	{
		test = str;
	}
	string GetTest()
	{
		return test;
	}
	bool operator()(Word_Store& dvalue)                  //������������������ڲ���find_if����
	{

		if (dvalue.Getspell().compare(test) == 0)
			return true;
		else
			return false;
	}
private:
	string test;
};