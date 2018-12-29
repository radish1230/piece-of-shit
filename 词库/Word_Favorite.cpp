#include"Word_Favorite.h"
#include"Word_Findx.h"

fstream file_f;
vector<Word_Favorite>word_f;				/*声明vector,全局变量*/
extern vector<Word_Store>word;				/*声明vector,全局变量*/
extern 	vector<Word_Store>::iterator loc;
void Word_Favorite::Insert_Fa()       //在词库中选单词插入到收藏本中
{
	int i;
	SetVector();
	Acc_Find();
	cout << "是否将该单词加入收藏本:  1.是  2.不是" << endl;
	cin >> i;
	switch (i)
	{
	case 1:
	{	Word_Favorite temp_f;
		temp_f.meaning = word[loc - word.begin()].Getmeaning();
		temp_f.pos = word[loc - word.begin()].Getpos();
		temp_f.sen = word[loc - word.begin()].Getsen();
		temp_f.spell = word[loc - word.begin()].Getspell();
		word_f.push_back(temp_f);
		file_f.open("收藏本.txt", ios::in | ios::app);
		if (file_f.is_open() == 1)
		{
			file_f << temp_f.spell <<'#' << temp_f.pos << '#' << temp_f.meaning << '#' << temp_f.sen << endl;
			file_f.close();
		}
		break;
	}
	case 2:
		break;
	}
}
void Word_Favorite::SetVector_Fa()
{
	char buffer[200];
	int num = 0;
	file_f.open("收藏本.txt", ios::in | ios::out);
	while (!file_f.eof())
	{
		file_f.getline(buffer, 200);
		istringstream is(buffer);    //字符串写入内存
		string s1, s2, s3, s4;
		//is >> s1 >> s2 >> s3;			//字符串写入内存
		//getline(is, s4);
		getline(is, s1, '#');
		getline(is, s2, '#');
		getline(is, s3, '#');
		getline(is, s4, '#');
		Word_Favorite temp;
		temp.spell = s1;
		temp.pos = s2;
		temp.meaning = s3;
		temp.sen = s4;
		word_f.push_back(temp);
	}
	file_f.close();
}
void Word_Favorite::Show_S_Fa()
{
	word_f.clear();
	SetVector_Fa();
	VectorSort_Fa();
	for (int i = 0; i < word_f.size(); i++)
		cout << word_f[i].spell << "  " << word_f[i].pos << "  " << word_f[i].meaning << "  "<<word_f[i].sen<<endl;
	word_f.clear();
}
bool Fsort_Fa(Word_Favorite a, Word_Favorite b) 
{ 
	return a.spell < b.spell; 
}
void Word_Favorite::VectorSort_Fa()
{
	sort(word_f.begin(), word_f.end(), Fsort_Fa);

}
void Word_Favorite::Change_Fa()
{
	SetVector_Fa();
	cout << "输入要修改的单词" << endl;
	string test;
	string s1, s2, s3, s4;
	cin >> test;
	vector<Word_Favorite>::iterator loc_fa;
	loc_fa = find_if(word_f.begin(), word_f.end(), findx(test));
	if (loc_fa != word_f.end())
	{
		cout << "该单词的内容为" << endl;
		cout << (*loc_fa).spell << " " << (*loc_fa).pos << " " << (*loc_fa).meaning << "  " << (*loc_fa).sen << endl;

		int k = 0;
		while (k != 5)
		{
			cout << "请选择要修改的内容:1.拼写  2.词性   3.释义  4.例句 5.修改完毕" << endl;
			cin >> k;
			switch (k)
			{
			case 1:	cout << "输入单词拼写" << endl;
				cin >> (*loc_fa).spell;
				break;
			case 2:
				cout << "输入单词词性" << endl;
				cin >> (*loc_fa).pos;
				break;
			case 3:
				cout << "输入单词释义" << endl;
				cin >> (*loc_fa).meaning;
				break;
			case 4:
				cout << "输入单词例句" << endl;
				getline(cin, (*loc_fa).sen);
				break;

			default:
				break;
			}
		}

		file_f.open("收藏本.txt",  ios::out );
		for (int i = 0; i < word_f.size(); i++)
			if (file_f.is_open() == 1)
			{
				file_f << word_f[i].spell << '#' << word_f[i].pos << '#' << word_f[i].meaning << '#' << word_f[i].sen << '#' << endl;
			}

		file_f.close();

	}
	else
	{
	cout << "未查到单词" << endl;
	}
}
void Word_Favorite::Erase_Fa()
{
	SetVector_Fa();
	cout << "输入要删除的单词" << endl;
	string test;
	string s1, s2, s3, s4;
	cin >> test;
	int k;
	vector<Word_Favorite>::iterator loc_fa;
	loc_fa = find_if(word_f.begin(), word_f.end(), findx(test));
	if (loc_fa != word_f.end())
	{
		cout << (*loc_fa).spell << " " << (*loc_fa).pos << " " << (*loc_fa).meaning << "  " << (*loc_fa).sen << endl;

		cout << "是否要删除该单词 1.是 2.不是" << endl;
		cin >> k;
		switch (k)
		{
		case 1:
			word_f.erase(loc_fa);
			cout << "已从词库中删除该单词" << endl;
			break;
		case 2:
			cout << "未删除" << endl;
			break;
		}

	}
	else
		cout << "未查找到该单词" << endl;
	file_f.open("收藏本.txt", ios::in | ios::out | ios::trunc);
	for (int i = 0; i < word.size(); i++)
		if (file_f.is_open() == 1)
		{
			file_f << word_f[i].spell << '#' << word_f[i].pos << '#' << word_f[i].meaning << '#' << word_f[i].sen <<'#'<< endl;
		}

	file_f.close();
}
void Word_Favorite::Menu_Fa()
{
	int k_f=0;
	while (k_f != 9)
	{
		cout << "请选择要进行的操作  1.收藏新单词  2.展示收藏本 3.修改收藏本中的单词 4.删除已收藏单词 9.退出" << endl;
		cin >> k_f;
		switch (k_f)
		{
		case 1:
			Insert_Fa();
			break;
		case 2:
			Show_S_Fa();
			break;
		case 3:
			Change_Fa();
		case 4:
			Erase_Fa();
		default:
			break;
		}
	}
}
