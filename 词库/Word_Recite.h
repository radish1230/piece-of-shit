#pragma once
#include"WORD.h"

class Word_Recite:public Word
{
public:
	Word_Recite() { state_choose = 2; state_recite = 0; }
	void Show_Re();
	void Choose_Re();
	void SetTxt_Re_fromstore();   //从词库中初始化背词本
	void SetVec_Re_Ch();    //从背词本初始化vector
	void Random_Re();
	void Keep_File();
	void SetTxt_Re();
	void menu_re();
	friend class Word_Store;
	friend bool Fsort_re(Word_Recite a, Word_Recite b);
	friend bool operator ==(const  Word_Recite& q, const Word_Recite & p);

private:
	 int state_choose;  //选择次数，初始为两次，对一次减一，错一次加一，背到零就不背了；
	 int state_recite;	 //该单词背诵总次数，背对了几次，背错了几次。
	 int choose_times;   //该次启动程序后，要背诵几个单词。
};