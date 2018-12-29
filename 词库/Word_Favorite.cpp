#include"Word_Favorite.h"
#include"Word_Findx.h"

fstream file_f;
vector<Word_Favorite>word_f;				/*����vector,ȫ�ֱ���*/
extern vector<Word_Store>word;				/*����vector,ȫ�ֱ���*/
extern 	vector<Word_Store>::iterator loc;
void Word_Favorite::Insert_Fa()       //�ڴʿ���ѡ���ʲ��뵽�ղر���
{
	int i;
	SetVector();
	Acc_Find();
	cout << "�Ƿ񽫸õ��ʼ����ղر�:  1.��  2.����" << endl;
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
		file_f.open("�ղر�.txt", ios::in | ios::app);
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
	file_f.open("�ղر�.txt", ios::in | ios::out);
	while (!file_f.eof())
	{
		file_f.getline(buffer, 200);
		istringstream is(buffer);    //�ַ���д���ڴ�
		string s1, s2, s3, s4;
		//is >> s1 >> s2 >> s3;			//�ַ���д���ڴ�
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
	cout << "����Ҫ�޸ĵĵ���" << endl;
	string test;
	string s1, s2, s3, s4;
	cin >> test;
	vector<Word_Favorite>::iterator loc_fa;
	loc_fa = find_if(word_f.begin(), word_f.end(), findx(test));
	if (loc_fa != word_f.end())
	{
		cout << "�õ��ʵ�����Ϊ" << endl;
		cout << (*loc_fa).spell << " " << (*loc_fa).pos << " " << (*loc_fa).meaning << "  " << (*loc_fa).sen << endl;

		int k = 0;
		while (k != 5)
		{
			cout << "��ѡ��Ҫ�޸ĵ�����:1.ƴд  2.����   3.����  4.���� 5.�޸����" << endl;
			cin >> k;
			switch (k)
			{
			case 1:	cout << "���뵥��ƴд" << endl;
				cin >> (*loc_fa).spell;
				break;
			case 2:
				cout << "���뵥�ʴ���" << endl;
				cin >> (*loc_fa).pos;
				break;
			case 3:
				cout << "���뵥������" << endl;
				cin >> (*loc_fa).meaning;
				break;
			case 4:
				cout << "���뵥������" << endl;
				getline(cin, (*loc_fa).sen);
				break;

			default:
				break;
			}
		}

		file_f.open("�ղر�.txt",  ios::out );
		for (int i = 0; i < word_f.size(); i++)
			if (file_f.is_open() == 1)
			{
				file_f << word_f[i].spell << '#' << word_f[i].pos << '#' << word_f[i].meaning << '#' << word_f[i].sen << '#' << endl;
			}

		file_f.close();

	}
	else
	{
	cout << "δ�鵽����" << endl;
	}
}
void Word_Favorite::Erase_Fa()
{
	SetVector_Fa();
	cout << "����Ҫɾ���ĵ���" << endl;
	string test;
	string s1, s2, s3, s4;
	cin >> test;
	int k;
	vector<Word_Favorite>::iterator loc_fa;
	loc_fa = find_if(word_f.begin(), word_f.end(), findx(test));
	if (loc_fa != word_f.end())
	{
		cout << (*loc_fa).spell << " " << (*loc_fa).pos << " " << (*loc_fa).meaning << "  " << (*loc_fa).sen << endl;

		cout << "�Ƿ�Ҫɾ���õ��� 1.�� 2.����" << endl;
		cin >> k;
		switch (k)
		{
		case 1:
			word_f.erase(loc_fa);
			cout << "�ѴӴʿ���ɾ���õ���" << endl;
			break;
		case 2:
			cout << "δɾ��" << endl;
			break;
		}

	}
	else
		cout << "δ���ҵ��õ���" << endl;
	file_f.open("�ղر�.txt", ios::in | ios::out | ios::trunc);
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
		cout << "��ѡ��Ҫ���еĲ���  1.�ղ��µ���  2.չʾ�ղر� 3.�޸��ղر��еĵ��� 4.ɾ�����ղص��� 9.�˳�" << endl;
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
