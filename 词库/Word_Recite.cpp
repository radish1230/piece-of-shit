#include"Word_Recite.h"
#include"Word_Store.h"
#include<windows.h>

vector<Word_Recite>word_re;
extern vector<Word_Store>word;				
fstream file_re;
bool Fsort_re(Word_Recite a, Word_Recite b) { return a.spell < b.spell; }  //用于sort函数排序，大于小于控制升序降序
bool operator ==(const  Word_Recite& q, const Word_Recite & p)
{
	return q.spell == p.spell && q.spell == p.spell;
}
void Word_Recite::SetTxt_Re_fromstore()
{
	Word_Store store;

	store.SetVector();

	for (int i = 0; i < word.size(); i++)
	{
		Word_Recite temp;
		temp.meaning= word[i].meaning;
		temp.pos = word[i].pos;
		temp.sen = word[i].sen;
		temp.spell = word[i].spell;
		word_re.push_back(temp);
	}
	file_re.open("背词本.txt", ios::out);
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
		file_re.getline(buffer, 200,'@');			//这个大小很重要…可以写进报告里
		istringstream is(buffer);    //字符串写入内存
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
void Word_Recite::SetTxt_Re()
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
	//cout << "您今天背几个单词" << endl;
	//cin >> choose_times;
	SetVec_Re_Ch();
	vector<Word_Recite>::iterator loc;
	vector<Word_Recite>::iterator loc_wrong;
	vector<Word_Recite>random_re;
	vector<Word_Recite>random_ch;
	vector<Word_Recite>wrong;
	loc = word_re.begin();
	
	cout << endl << "英译汉选择" << endl;
	int wrong_num = 0;
	for (int i = 0; i < 5/*choose_times*/; )
	{

		int choose_key = 0;
		if ((*loc).state_choose != 0)
		{
			random_ch.clear();
			random_re.assign(word_re.begin(), word_re.end());
			random_shuffle(random_re.begin(), random_re.end());
			random_ch.push_back((*loc));
			random_ch.push_back(random_re[1]);
			random_ch.push_back(random_re[2]);
			random_ch.push_back(random_re[3]);
			int len = random_ch.size();
			sort(random_ch.begin(), random_ch.end(), Fsort_re);
			random_ch.erase(unique(random_ch.begin(), random_ch.end()), random_ch.end());
			if(random_ch.size()!=len)
				random_ch.push_back(random_re[5]);
			cout << "拼写"<<(*loc).spell<<endl;
			random_shuffle(random_ch.begin(), random_ch.begin()+4);
			cout << "选项1"<<random_ch[0].meaning << endl;
			cout << "选项2" << random_ch[1].meaning<<endl;
			cout << "选项3" << random_ch[2].meaning<<endl;
			cout << "选项4" << random_ch[3].meaning<<endl;

			cin >> choose_key;
			if (random_ch[choose_key-1].meaning == (*loc).meaning)
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
				cout << "选错了，重选" << endl;
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
	sort(wrong.begin(), wrong.end(),Fsort_re);
	wrong.erase(unique(wrong.begin(), wrong.end()), wrong.end());
	//错题重做部分
	if (wrong_num > 0)
	{
		cout << "*******进入英译汉错题重做部分******" << endl;
		loc_wrong = wrong.begin();
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
				if (random_ch[choose_key - 1].meaning == (*loc_wrong).meaning)
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
	random_ch.clear();
	random_ch.clear();
	wrong.clear();
	//*****************************汉译英*********************************************8
	loc = word_re.begin();
	wrong_num = 0;
	cout << endl << "汉译英选择" << endl;
	for (int i = 0; i < 5/*choose_times*/; )
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
			if (random_ch[choose_key - 1].spell == (*loc).spell)
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
	//错题重做部分
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
				if (random_ch[choose_key - 1].spell == (*loc_wrong).spell)
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