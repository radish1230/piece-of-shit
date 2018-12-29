#ifndef _WORD_STORE_H
#define _WORD_STORE_H
#include"WORD.h"

class Word_Store :public Word
{
public:
	void Insert();    //��ӵ��� ��д�ļ�
	void Show_W_txt();     //չʾ����txt���� �����ļ�
	void Show_V_S();		//չʾvector�����ĵ���
	void SetVector(); //���ļ�����vector��
	void VectorSort(); //��vector�е����ݰ�ƴд����
	void Acc_Find();	//��vector�о�ȷ���ҵ��ʣ�����ʾ��������
	string Getspell() { return spell; }
	string Getpos() { return pos; }
	string Getsen() { return sen; }
	string Getmeaning() { return meaning; }
	friend class Word_Recite;
	void Erase();		//��vector��ɾ�����ʣ���д���ļ�
	void Change();		//��vector���޸ĵ��ʣ���д���ļ�
	friend bool Fsort(Word_Store a, Word_Store b);
private:
};

#endif // !_WORD_STORE_H