#include "Word_Store.h"
#include"Findx.h"
fstream file;

vector<Word_Store>word;				/*声明vector,全局变量*/

bool Fsort(Word_Store a, Word_Store b) { return a.spell < b.spell; }  //用于sort函数排序，大于小于控制升序降序

void Word_Store::Inster()
{
	file.open("生词本.txt", ios::in | ios::app);
	if (file.is_open() == 1)
	{
		Word temp;
		cout << "输入单词的拼写" << endl;
		cin >> temp.spell;
		//getline(cin, temp.spell);

		cout << "输入单词的词性" << endl;
		cin >> temp.pos;
		//getline(cin, temp.pos);

		cout << "输入单词的意思" << endl;
		cin >> temp.meaning;
		//getline(cin, temp.meaning);
		getchar();
		cout << "输入单词的例句" << endl;
		getline(cin, temp.sen);
		file << temp.spell << "  " <<temp.pos<<"  "<< temp.meaning <<"  "<<temp.sen<< endl;
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
	char buffer[100];
	int num = 0;
	file.open("生词本.txt", ios::in | ios::out);
	while (!file.eof())
	{

		file.getline(buffer, 100);
		istringstream is(buffer);    //字符串写入内存
		string s1, s2,s3,s4;
		is >> s1 >> s2>>s3>>s4;			//字符串写入内存
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
void Word_Store::Show_V_S()
{
	for (int i = 0; i < word.size(); i++)
		cout << word[i].spell << "  "<<word[i].pos<<"  " << word[i].meaning << endl;
		
}

void Word_Store::Acc_Find()
{
	SetVector();
	string test;
	cout << "输入单词" << endl;
	cin >> test;
	vector<Word_Store>::iterator loc;
	loc = find_if(word.begin(), word.end(), findx(test));
	cout << "位置是" << loc - word.begin() + 1 << endl;
	cout << (*loc).spell << " " << (*loc).pos<<" "<<(*loc).meaning << "  "<< (*loc).sen<<endl;
}

void Word_Store::Erase()
{
	SetVector();
	cout << "输入要删除的单词" << endl;
	string test;
	cin >> test;
	vector<Word_Store>::iterator loc;
	loc = find_if(word.begin(), word.end(), findx(test));
	word.erase(loc);
	
	file.open("生词本.txt", ios::in | ios::out | ios::trunc);
	for (int i = 0; i < word.size(); i++)
		if (file.is_open() == 1)
		{
			file << word[i].spell << "  " << word[i].meaning << endl;
		}

	file.close();

}
#include"pch.h"