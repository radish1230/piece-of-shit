#pragma once
#include"WORD.h"

class Word_Recite:public Word
{
public:
	Word_Recite() { state_choose = 2; state_recite = 0; }
	void Show_Re();
	void Choose_Re();
	void SetTxt_Re_fromstore();   //�Ӵʿ��г�ʼ�����ʱ�
	void SetVec_Re_Ch();    //�ӱ��ʱ���ʼ��vector
	void Random_Re();
	void Keep_File();
	void SetTxt_Re();
	void menu_re();
	friend class Word_Store;
	friend bool Fsort_re(Word_Recite a, Word_Recite b);
	friend bool operator ==(const  Word_Recite& q, const Word_Recite & p);

private:
	 int state_choose;  //ѡ���������ʼΪ���Σ���һ�μ�һ����һ�μ�һ��������Ͳ����ˣ�
	 int state_recite;	 //�õ��ʱ����ܴ����������˼��Σ������˼��Ρ�
	 int choose_times;   //�ô����������Ҫ���м������ʡ�
};