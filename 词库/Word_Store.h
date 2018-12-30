#ifndef _WORD_STORE_H
#define _WORD_STORE_H
#include"WORD.h"

class Word_Store :public Word
{
public:
	void Insert();          //添加单词 ，写入生词本.txt文件
	void Show_W_txt();      //展示生词本.txt中的单词 ，不排序，读文件
	void Show_V_S();		//展示生词本vector排序后的单词
	void SetVector();       //将文件读入向量容器word中
	void VectorSort();      //将向量容器word中的内容按拼写排序
	void Acc_Find();	    //在vector中精确查找单词，并显示单词内容
	string Getspell() { return spell; }  //返回单词拼写
	string Getpos() { return pos; }		//返回单词的词性
	string Getsen() { return sen; }		//返回单词的例句
	string Getmeaning() { return meaning; }	//返回单词的中文释义
	friend class Word_Recite;				//在Recite类中调用Store类的SecVector（）
	void Erase();		//在vector中删除单词，并写入生词本.txt文件
	void Change();		//在vector中修改单词，并写入生词本.txt文件
	friend bool Fsort(Word_Store a, Word_Store b);		//按单词的拼写排序，调用vector的sort函数，需要自己写排序方式
private:
};

#endif // !_WORD_STORE_H