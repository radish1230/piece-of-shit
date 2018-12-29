#pragma once
#include<string>
#include"Word_Store.h"
class findx											//用于查找函数
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
	bool operator()(Word_Store& dvalue)                  //重载括号运算符，用于查找find_if函数
	{

		if (dvalue.Getspell().compare(input) == 0)
			return true;
		else
			return false;
	}
private:
	string input;
};