#ifndef _WORD_STORE_H
#define _WORD_STORE_H
#include"WORD.h"

class Word_Store :public Word
{
public:
	void Insert();          //��ӵ��� ��д�����ʱ�.txt�ļ�
	void Show_W_txt();      //չʾ���ʱ�.txt�еĵ��� �������򣬶��ļ�
	void Show_V_S();		//չʾ���ʱ�vector�����ĵ���
	void SetVector();       //���ļ�������������word��
	void VectorSort();      //����������word�е����ݰ�ƴд����
	void Acc_Find();	    //��vector�о�ȷ���ҵ��ʣ�����ʾ��������
	string Getspell() { return spell; }  //���ص���ƴд
	string Getpos() { return pos; }		//���ص��ʵĴ���
	string Getsen() { return sen; }		//���ص��ʵ�����
	string Getmeaning() { return meaning; }	//���ص��ʵ���������
	friend class Word_Recite;				//��Recite���е���Store���SecVector����
	void Erase();		//��vector��ɾ�����ʣ���д�����ʱ�.txt�ļ�
	void Change();		//��vector���޸ĵ��ʣ���д�����ʱ�.txt�ļ�
	friend bool Fsort(Word_Store a, Word_Store b);		//�����ʵ�ƴд���򣬵���vector��sort��������Ҫ�Լ�д����ʽ
private:
};

#endif // !_WORD_STORE_H