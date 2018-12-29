#ifndef _WORD_STORE_H
#define _WORD_STORE_H
#include"WORD.h"

class Word_Store :public Word
{
public:
	void Insert();    //添加单词 ，写文件
	void Show_W_txt();     //展示生词txt单词 ，读文件
	void Show_V_S();		//展示vector排序后的单词
	void SetVector(); //将文件读入vector中
	void VectorSort(); //将vector中的内容按拼写排序
	void Acc_Find();	//在vector中精确查找单词，并显示单词内容
	string Getspell() { return spell; }
	string Getpos() { return pos; }
	string Getsen() { return sen; }
	string Getmeaning() { return meaning; }
	friend class Word_Recite;
	void Erase();		//在vector中删除单词，并写入文件
	void Change();		//在vector中修改单词，并写入文件
	friend bool Fsort(Word_Store a, Word_Store b);
private:
};

#endif // !_WORD_STORE_H