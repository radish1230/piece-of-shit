#pragma once
#ifndef _Word_Favorite_H
#define _Word_Favorite_H
#include"Word_Store.h"
class Word_Favorite :public Word_Store
{
public:
	void Insert_Fa();               //增
	void Erase_Fa();				//删
	void Change_Fa();				//改
	void Acc_Find_Fa();				//查
	void Show_S_Fa();				//输出
	void SetVector_Fa();			//读文本初始化收藏类容器
	void VectorSort_Fa();
	void Menu_Fa();
	friend bool Fsort_Fa(Word_Favorite a, Word_Favorite b);
	friend class Word_Store;
};

#endif // !_Word_Favorite_H