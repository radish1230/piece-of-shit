// 词库.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include"Word_Store.h"
#include"Word_Findx.h"
#include"Word_Favorite.h"
#include"Word_Recite.h"
int main()
{
	Word_Store a;
	char k = '0';
	cout << "输入9退出" << endl<<endl;
	while (k!='9')
	{
		cout << "1.插入单词" << endl;
		cout << "2.显示单词（顺序）" << endl;
		cout << "3.查找单词(精确)" << endl;
		cout << "4.删除单词" << endl;
		cout << "5.修改单词" << endl;
		cout << "6.收藏单词" << endl;
		cout << "7.背词" << endl;
		cin >> k;
		switch (k)
		{
		case '1':
		{
			a.Insert();
			break;
		}
		case '2':
		{	//getchar();
		//	a.SetVector();
			a.Show_V_S();
			break;
		}
		case '3':
		{
			a.Acc_Find();
			break;
		}
		case '4':
		{
			a.Erase();
			break;
		}


		case '5':
		{
			a.Change();
			break;
		}
		case '6':
		{
			Word_Favorite fa;
			fa.Menu_Fa();
		}
		case'7':
		{	
			Word_Recite re;
			re.menu_re();
		}
		}
	}
	exit(1);

}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
