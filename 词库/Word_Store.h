#ifndef _WORD_STORE_H
#define _WORD_STORE_H
#include"WORD.h"

class Word_Store :public Word
{
public:
	void Inster();    //��ӵ��� ��д�ļ�
	void Show_W_txt();     //չʾ����txt���� �����ļ�
	void Show_V_S();		//չʾvector�����ĵ���
	void SetVector(); //���ļ�����vector��
	void VectorSort(); //��vector�е����ݰ�ƴд����
	void Acc_Find();
	string Getspell() { return spell; }
	void Erase();
	friend bool Fsort(Word_Store a, Word_Store b);
private:
};

#endif // !_WORD_STORE_H