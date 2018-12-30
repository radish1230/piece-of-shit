#include "Word_Store.h"
#include"Word_Findx.h"
fstream file;
 vector<Word_Store>word;				//声明全局变量向量容器word用与存放单词
 vector<Word_Store>::iterator loc;     //该迭代器用于在向量容器word中查询单词

bool Fsort(Word_Store a, Word_Store b) { return a.spell < b.spell; }  //用于vector<word>的sort排序，大于小于符号控制升序降序

void Word_Store::Insert()    //添加单词至生词本.txt，用getline函数，遇到空格也可以读入，方便录入英文词组，getchar（）可以吃掉缓冲中的一个回车，写入文件的单词的各个属性用#分开，与空格区分开，提高容错率
{
	file.open("生词本.txt", ios::in | ios::app);//在文本末追加的方式打开文件
	if (file.is_open() == 1)
	{
		Word temp;
		getchar();				//吞掉缓冲区的一个空格，否则会直接到输入词性的部分
		cout << "输入单词的拼写" << endl;
		getline(cin, temp.spell);		//用getline函数获取键入的数据，有空格也不会当作分隔符，方便词组的输入
		//cin >> temp.spell;
		cout << "输入单词的词性" << endl;
		getline(cin, temp.pos);
		//cin >> temp.pos;
		cout << "输入单词的意思" << endl;
		getline(cin, temp.meaning);
		//cin >> temp.meaning;
		cout << "输入单词的例句" << endl;
		getline(cin, temp.sen);
		file << temp.spell << '#' <<temp.pos<<'#'<< temp.meaning <<'#'<<temp.sen<<'#'<< endl; //写入文件的时候，在单词的每个属性之间用‘#’分开，将‘#’作为分隔符，方便之后的分部逐行读文件
		file.close();
	}
}

void Word_Store::Show_W_txt()
{
	char buffer[100];
	int num = 0;
	file.open("生词本.txt", ios::in | ios::app);
	while (!file.eof())
	{
		file.getline(buffer, 100);
		istringstream is(buffer);    //字符串写入内存
		string s1, s2,s3;
		is >> s1 >> s2>>s3;			//字符串写入内存
		cout << s1 << " " << s2 <<" "<<s3<< endl;
	}
	file.close();
}
void Word_Store::SetVector()
{
	char buffer[200];
	
	file.open("生词本.txt", ios::in | ios::out);
	while (!file.eof())
	{	
		file.getline(buffer, 200);			//这个大小很重要…可以写进报告里
		istringstream is(buffer);    //字符串写入内存
		string s1,s2,s3,s4;
		//is >> s1 >> s2>>s3>>s4;			//字符串写入内存
		getline(is, s1, '#');
		getline(is, s2, '#');
		getline(is, s3, '#');
		getline(is, s4,'#');
		Word_Store temp;
		temp.spell = s1;
		temp.pos = s2;
		temp.meaning = s3;
		temp.sen = s4;
		word.push_back(temp);
	}
	file.close();
}
void Word_Store::VectorSort()
{
	sort(word.begin(), word.end(), Fsort);
}
void Word_Store::Show_V_S()  //升序输出生词本中的内容
{
	word.clear();//先将容器中的元素清空
	SetVector();//从生词本中读数据初始化容器
	VectorSort();//容器中的单词排序
	for (int i = 0; i < word.size(); i++)
		if(!word[i].spell.empty())                   //判断是否为空，为了降低二次分配时的成本，
													//vector实际配置的大小可能比客户需求的更大一些
		cout << "拼写:"<<word[i].spell << "  词性："<<word[i].pos<<"  释义：" << word[i].meaning << endl;
	word.clear();
}

void Word_Store::Acc_Find()
{
	SetVector();					//从生词本中读数据初始化容器
	string test;					//声明字符串变量，存放键入的单词拼写
	getchar();						//吞回车
	cout << "输入单词" << endl;
	getline(cin, test);
	loc = find_if(word.begin(), word.end(), findx(test));	//利用向量容器fine_if函数，按照拼写查找
	if (loc!=word.end())
	{
	//	cout << "位置是" << loc - word.begin() + 1 << endl;
		cout << (*loc).spell << " " << (*loc).pos << " " << (*loc).meaning << "  " << (*loc).sen << endl;
															//输出该单词的所有属性
	}
	else
	{
		cout << "未查到" << endl;
	}
}

void Word_Store::Erase()                            //删除单词  
{
	SetVector();									//初始化容器
	cout << "输入要删除的单词" << endl;				
	string test;
	cin >> test;
	int k;
	loc = find_if(word.begin(), word.end(), findx(test));		//查找该单词
	if (loc != word.end())
	{
		cout << (*loc).spell << " " << (*loc).pos << " " << (*loc).meaning << "  " << (*loc).sen << endl;
		cout << "是否要删除该单词 1.是 2.不是" << endl;				//判断是否删除
		cin >> k;
		switch (k)
		{
		case 1:
			word.erase(loc);											//利用容器erase函数删除该单词
			cout << "已从词库中删除该单词" << endl;
			break;
		case 2:
			cout << "未删除" << endl;
			break;
		}

	}
	else
		cout << "未查找到该单词" << endl;
	file.open("生词本.txt", ios::in | ios::out | ios::trunc);		//将删除操作后的容器内容覆盖到生词本txt中，用于更新
	for (int i = 0; i < word.size(); i++)
		if (file.is_open() == 1)
		{
			file << word[i].spell << '#' <<word[i].pos<< '#' << word[i].meaning << '#' <<word[i].sen<< endl;
		}
	file.close();
}
void Word_Store::Change()						//修改单词内容
{
	SetVector();								//初始化容器
	cout << "输入要修改的单词" << endl;
	string test;
	string s1, s2, s3, s4;
	cin >> test;
	vector<Word_Store>::iterator loc;	
	loc = find_if(word.begin(), word.end(), findx(test));		//查找该单词
	if (loc != word.end())	
	{
		cout << "该单词的内容为" << endl;
		cout << (*loc).spell << " " << (*loc).pos << " " << (*loc).meaning << "  " << (*loc).sen << endl;
		int k = 0;
		while (k != 5)
		{
			cout << "请选择要修改的内容:1.拼写  2.词性   3.释义  4.例句 5.修改完毕" << endl;//用于选择要修改单词的哪个部分
			cin >> k;
			switch (k)
			{
			case 1:	cout << "输入单词拼写" << endl;
				cin >> (*loc).spell;
				break;
			case 2:
				cout << "输入单词词性" << endl;
				cin >> (*loc).pos;
				break;
			case 3:
				cout << "输入单词释义" << endl;
				cin >> (*loc).meaning;
				break;
			case 4:
				cout << "输入单词例句" << endl;
				getline(cin, (*loc).sen);
				break;

			default:
				break;
			}
		}
		file.open("生词本.txt", ios::in | ios::out | ios::trunc);		//覆盖到生词本txt，用于更新文本内容
		for (int i = 0; i < word.size(); i++)
			if (file.is_open() == 1)
			{
				file << word[i].spell << '#' << word[i].pos << '#' << word[i].meaning << '#' << word[i].sen <<'#'<< endl;
			}

		file.close();

	}
	else
	{
		cout << "未查到单词" << endl;
	}

}
#include"pch.h"