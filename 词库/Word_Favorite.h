#pragma once
#ifndef _Word_Favorite_H
#define _Word_Favorite_H
#include"Word_Store.h"
class Word_Favorite :public Word_Store
{
public:
	void Insert_Fa();               //��
	void Erase_Fa();				//ɾ
	void Change_Fa();				//��
	void Acc_Find_Fa();				//��
	void Show_S_Fa();				//���
	void SetVector_Fa();			//���ı���ʼ���ղ�������
	void VectorSort_Fa();
	void Menu_Fa();
	friend bool Fsort_Fa(Word_Favorite a, Word_Favorite b);
	friend class Word_Store;
};

#endif // !_Word_Favorite_H