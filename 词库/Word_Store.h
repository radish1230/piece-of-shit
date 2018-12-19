#ifndef _WORD_STORE_H
#define _WORD_STORE_H
#include"WORD.h"

class Word_Store :public Word
{
public:
	void Inster();    //添加单词 ，写文件
	void Show_W_txt();     //展示生词txt单词 ，读文件
	void Show_V_S();		//展示vector排序后的单词
	void SetVector(); //将文件读入vector中
	void VectorSort(); //将vector中的内容按拼写排序
	void Acc_Find();
	string Getspell() { return spell; }
	void Erase();
	friend bool Fsort(Word_Store a, Word_Store b);
private:
};

#endif // !_WORD_STORE_H