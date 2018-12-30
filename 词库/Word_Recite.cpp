#include"Word_Recite.h"
#include"Word_Store.h"
#include<windows.h>

vector<Word_Recite>word_re;
extern vector<Word_Store>word;				
fstream file_re;
bool Fsort_re(Word_Recite a, Word_Recite b) { return a.spell < b.spell; }  //用于sort函数排序，大于小于控制升序降序
bool operator ==(const  Word_Recite& q, const Word_Recite & p)         //用于向量容器的unique函数，将重复的元素删除掉
{
	return q.spell == p.spell && q.spell == p.spell;
}
void Word_Recite::SetTxt_Re_fromstore()//从生词本中获取内容，初始化背词本txt的内容
{
	Word_Store store;						
	store.SetVector();					//初始化word容器
	for (int i = 0; i < word.size(); i++)
	{
		Word_Recite temp;			//声明背单词类的对象temp
		temp.meaning= word[i].meaning;	//各个属性直接赋值
		temp.pos = word[i].pos;
		temp.sen = word[i].sen;
		temp.spell = word[i].spell;
		word_re.push_back(temp);		//插入到word_re容器尾部
	}
	file_re.open("背词本.txt", ios::out|ios::in);      //以输入的方式打开文本
	for (int i = 0; i < word_re.size(); i++)
		if (file_re.is_open() == 1)
		{
			if (!word_re[i].spell.empty())
				file_re << word_re[i].spell << '#' << word_re[i].pos << '#' << word_re[i].meaning << '#' << word_re[i].sen << '@' << "  " << word_re[i].state_choose << "  " << word_re[i].state_recite << endl;
		}
	file_re.close();
}

void Word_Recite::SetVec_Re_Ch()
{
	char buffer[200];
	file_re.open("背词本.txt", ios::in | ios::out);
	while (!file_re.eof())
	{
		file_re.getline(buffer, 200,'@');			//这个大小很重要
		istringstream is(buffer);					 //字符串写入内存
		string s1, s2, s3, s4;
		int s5, s6;
		getline(is, s1, '#');
		getline(is, s2, '#');
		getline(is, s3, '#');
		getline(is, s4,'#');
		file_re >> s5 >> s6;
		Word_Recite temp;
		temp.spell = s1;
		temp.pos = s2;
		temp.meaning = s3;
		temp.sen = s4;
		temp.state_choose = s5;
		temp.state_recite = s6;
		word_re.push_back(temp);
	}
	file_re.close();
}
void Word_Recite::SetTxt_Re()						 //更新背词本txt文本内容
{
	//SetVec_Re_Ch();
	file_re.open("背词本.txt",  ios::out );
	for (int i = 0; i < word_re.size(); i++)
		if (file_re.is_open() == 1)
		{
			if(!word_re[i].spell.empty())
			file_re << word_re[i].spell << '#' << word_re[i].pos << '#' << word_re[i].meaning << '#' << word_re[i].sen <<'@'<<"  " << word_re[i].state_choose <<"  "<< word_re[i].state_recite<<endl;
		}
	file_re.close();
}

void Word_Recite::Choose_Re()
{
	cout << "您今天背几个单词" << endl;
	cin >> choose_times;					 //控制背单词的个数，用户键入个数
	SetVec_Re_Ch();
	vector<Word_Recite>::iterator loc;		//声明迭代器loc，该迭代器指向背诵过程中正在被操作的单词
	vector<Word_Recite>::iterator loc_wrong;	//声明迭代器loc_wrong，指向背诵过程中背错的单词
	vector<Word_Recite>random_re;				//声明向量容器random_re，存放背词本中的内容，用于之后的随机乱序，生成选项
	vector<Word_Recite>random_ch;				//声明向量容器random_ch，存放选项，再次乱序，生成选项
	vector<Word_Recite>wrong;					//声明容器wrong，存放背错的单词，用于之后的背诵
	loc = word_re.begin();						//初试化迭代器loc，指向word_re的第一个单词元素
	cout << endl << "英译汉选择" << endl;
	int wrong_num = 0;							//控制是否进入错题重做环节
	for (int i = 0; i < choose_times; )			//循环背单词操作，变量i是背对一个单词就加1.
	{
		int choose_key = 0;
			if ((*loc).state_choose != 0)		//先通过对象的数据成员state_choose判断该单词是否需要背诵。
			{
			random_ch.clear();					//清空选项容器的内容
			random_re.assign(word_re.begin(), word_re.end());//利用assign函数初始化random_re容器
			random_shuffle(random_re.begin(), random_re.end());//利用random_shuffle函数随机排列random_re中的单词
			random_ch.push_back((*loc));						//将要背的单词插入到选项容器中
			random_ch.push_back(random_re[1]);					//将随机排列后的容器的第二三四个元素插入选项容器中
			random_ch.push_back(random_re[2]);
			random_ch.push_back(random_re[3]);
			int len = random_ch.size();								//判断是否有重复的
			sort(random_ch.begin(), random_ch.end(), Fsort_re);		//调用unique函数删除重复的元素之前，要先排序
			random_ch.erase(unique(random_ch.begin(), random_ch.end()), random_ch.end());//我设计的选项算法，很有可能会有重复的可能，所以要先删除选项容器中重复的元素
			if(random_ch.size()!=len)								//如果选项容器的长度有变化就说明删除了某个选项
				random_ch.push_back(random_re[5]);					//再往选项容器中增补一个单词
			cout << "拼写"<<(*loc).spell<<endl;						//英译汉的题干为单词的拼写，输出拼写
			random_shuffle(random_ch.begin(), random_ch.begin()+4);	//将选项容器中的单词打乱顺序
			cout << "选项1"<<random_ch[0].meaning << endl;			//输出四个选项
			cout << "选项2" << random_ch[1].meaning<<endl;
			cout << "选项3" << random_ch[2].meaning<<endl;
			cout << "选项4" << random_ch[3].meaning<<endl;
			cin >> choose_key;										//用户选择选项
			if (choose_key < 1 || choose_key>4)						//判断输入内容是否合理
				cout << "输入有误请重新键入" << endl;
			else if (random_ch[choose_key-1].meaning == (*loc).meaning)	//判断输入的选项是否正确
			{
				cout << "恭喜选对了，下一词" << endl;					
				Sleep(500);
				(*loc).state_recite++;									//选对之后，该单词的背诵次数加1
				(*loc).state_choose--;									//选对之后，该单词需要再次背诵的次数减1
				loc++;													//移动到下一个单词
				i++;													//用户背诵的单词个数加1
				system("cls");											//清屏
			}
			else
			{
				cout << "选错了，重选" << endl;
				Sleep(500);
				(*loc).state_choose++;								//选对之后，该单词的背诵次数加1
				(*loc).state_recite++;								//选错之后，该单词需要再次背诵的次数减加1
				wrong.push_back((*loc));							//将该单词插入到背诵错误单词容器中
				wrong_num++;										//选择错误的次数加1
				system("cls");										//清屏

			}
		}
		else
			loc++;
	}
	sort(wrong.begin(), wrong.end(),Fsort_re);					//调用unique函数删除重复的元素之前，要先排序
	wrong.erase(unique(wrong.begin(), wrong.end()), wrong.end());//删除背诵错误单词容器中重复的元素，因为用户可能反复在一个单词选错选项
	//************************错题重做部分*************************
	if (wrong_num > 0)											//如果有背错的单词，就进入错题重做部分
	{
		cout << "*******进入英译汉错题重做部分******" << endl;
		loc_wrong = wrong.begin();								//初试化迭代器loc_wrong，指向wrong容器的第一个单词元素
		for (int k = 0; k < wrong.size();)
		{
			int choose_key = 0;
			if ((*loc_wrong).state_choose != 0)
			{
				random_ch.clear();
				random_re.clear();
				random_re.assign(word_re.begin(), word_re.end());
				random_shuffle(random_re.begin(), random_re.end());
				random_ch.push_back((*loc_wrong));
				random_ch.push_back(random_re[1]);
				random_ch.push_back(random_re[2]);
				random_ch.push_back(random_re[3]);
				int len = random_ch.size();
				sort(random_ch.begin(), random_ch.end(), Fsort_re);
				random_ch.erase(unique(random_ch.begin(), random_ch.end()), random_ch.end());
				if (random_ch.size() != len)
					random_ch.push_back(random_re[5]);
				cout << "拼写" << (*loc_wrong).spell << endl;
				random_shuffle(random_ch.begin(), random_ch.begin() + 4);
				cout << "选项1" << random_ch[0].meaning << endl;
				cout << "选项2" << random_ch[1].meaning << endl;
				cout << "选项3" << random_ch[2].meaning << endl;
				cout << "选项4" << random_ch[3].meaning << endl;
				cin >> choose_key;
				if (choose_key < 1 || choose_key>4)
					cout << "输入有误请重新键入" << endl;
				else if (random_ch[choose_key - 1].meaning == (*loc_wrong).meaning)
				{
					cout << "恭喜选对了，下一词" << endl;
					Sleep(500);
					(*loc_wrong).state_choose--;
					loc_wrong++;
					k++;
					system("cls");
				}
				else
				{
					cout << "错了，重新选" << endl;
					Sleep(500);
					(*loc_wrong).state_choose++;
					
					system("cls");

				}
			}
			else
				loc_wrong++;
		}
	}
	random_ch.clear();					//清空选项容器
	random_re.clear();				
	wrong.clear();						//清空错误单词容器
	//*****************************汉译英*********************************************
	SetVec_Re_Ch();
	loc = word_re.begin();
	wrong_num = 0;
	cout << endl << "汉译英选择" << endl;
	for (int i = 0; i < choose_times; )
	{

		int choose_key = 0;
		if ((*loc).state_choose != 0)
		{
			random_ch.clear();
			random_re.clear();
			random_re.assign(word_re.begin(), word_re.end());
			random_shuffle(random_re.begin(), random_re.end());
			random_ch.push_back((*loc));
			random_ch.push_back(random_re[1]);
			random_ch.push_back(random_re[2]);
			random_ch.push_back(random_re[3]);
			int len = random_ch.size();
			sort(random_ch.begin(), random_ch.end(), Fsort_re);
			random_ch.erase(unique(random_ch.begin(), random_ch.end()), random_ch.end());
			if (random_ch.size() != len)
				random_ch.push_back(random_re[5]);
			cout << "中文释义" << (*loc).meaning << endl;
			random_shuffle(random_ch.begin(), random_ch.begin() + 4);
			cout << "选项1" << random_ch[0].spell << endl;
			cout << "选项2" << random_ch[1].spell << endl;
			cout << "选项3" << random_ch[2].spell << endl;
			cout << "选项4" << random_ch[3].spell << endl;
			cin >> choose_key;
			if (choose_key < 1 || choose_key>4)
				cout << "输入有误请重新键入" << endl;
			else if (random_ch[choose_key - 1].spell == (*loc).spell)
			{
				cout << "恭喜选对了，下一词" << endl;
				Sleep(500);
				(*loc).state_recite++;
				(*loc).state_choose--;
				loc++;
				i++;
				system("cls");
			}
			else
			{
				cout << "错了，重新选" << endl;
				Sleep(500);
				(*loc).state_choose++;
				(*loc).state_recite++;
				wrong.push_back((*loc));
				wrong_num++;
				system("cls");
			}
		}
		else
			loc++;
	}
	sort(wrong.begin(), wrong.end(), Fsort_re);
	wrong.erase(unique(wrong.begin(), wrong.end()), wrong.end());
	//************************错题重做部分*************************
	if (wrong_num > 0)
	{
		cout << "*******进入汉译英错题重做部分******" << endl;
		loc_wrong = wrong.begin();
		for (int k = 0; k < wrong.size();)
		{
			int choose_key = 0;
			if ((*loc_wrong).state_choose != 0)
			{
				random_ch.clear();
				random_re.assign(word_re.begin(), word_re.end());
				random_shuffle(random_re.begin(), random_re.end());
				random_ch.push_back((*loc_wrong));
				random_ch.push_back(random_re[1]);
				random_ch.push_back(random_re[2]);
				random_ch.push_back(random_re[3]);
				int len = random_ch.size();
				sort(random_ch.begin(), random_ch.end(), Fsort_re);
				random_ch.erase(unique(random_ch.begin(), random_ch.end()), random_ch.end());
				if (random_ch.size() != len)
					random_ch.push_back(random_re[5]);
				cout << "中文释义" << (*loc_wrong).meaning << endl;
				random_shuffle(random_ch.begin(), random_ch.begin() + 4);
				cout << "选项1" << random_ch[0].spell << endl;
				cout << "选项2" << random_ch[1].spell << endl;
				cout << "选项3" << random_ch[2].spell << endl;
				cout << "选项4" << random_ch[3].spell << endl;
				cin >> choose_key;
				if (choose_key < 1 || choose_key>4)
					cout << "输入有误请重新键入" << endl;
				else if (random_ch[choose_key - 1].spell == (*loc_wrong).spell)
				{
					cout << "恭喜选对了，下一词" << endl;
					Sleep(500);
					(*loc_wrong).state_choose--;
					loc_wrong++;
					k++;
					system("cls");
				}
				else
				{
					cout << "错了，重新选" << endl;
					Sleep(500);
					(*loc_wrong).state_choose++;
					system("cls");

				}
			}
			else
				loc_wrong++;
		}
	}
	//SetTxt_Re();
}
void Word_Recite::menu_re()
{
	cout << "1.初始化背词本（从词库）" << endl;
	cout << "2.背单词" << endl;

	int k;
	cin >> k;
	switch (k)
	{
	case 1:
	{
		SetTxt_Re_fromstore();
		break;
	}
	case 2:
		Choose_Re(); 
		break;
	}
}