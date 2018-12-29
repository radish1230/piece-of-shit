#include "Word_Store.h"
#include"Word_Findx.h"
fstream file;
 vector<Word_Store>word;				/*����vector,ȫ�ֱ���*/
 vector<Word_Store>::iterator loc;     //���ڲ�ѯ����

bool Fsort(Word_Store a, Word_Store b) { return a.spell < b.spell; }  //����sort�������򣬴���С�ڿ���������

void Word_Store::Insert()
{
	file.open("���ʱ�.txt", ios::in | ios::app);
	if (file.is_open() == 1)
	{
		Word temp;
		getchar();
		cout << "���뵥�ʵ�ƴд" << endl;
		getline(cin, temp.spell);
		//cin >> temp.spell;
		cout << "���뵥�ʵĴ���" << endl;
		getline(cin, temp.pos);
		//cin >> temp.pos;
		cout << "���뵥�ʵ���˼" << endl;
		getline(cin, temp.meaning);
		//cin >> temp.meaning;
		cout << "���뵥�ʵ�����" << endl;
		getline(cin, temp.sen);
		file << temp.spell << '#' <<temp.pos<<'#'<< temp.meaning <<'#'<<temp.sen<<'#'<< endl;
		file.close();
	}
}

void Word_Store::Show_W_txt()
{
	char buffer[100];
	int num = 0;
	file.open("���ʱ�.txt", ios::in | ios::app);
	while (!file.eof())
	{
		file.getline(buffer, 100);
		istringstream is(buffer);    //�ַ���д���ڴ�
		string s1, s2,s3;
		is >> s1 >> s2>>s3;			//�ַ���д���ڴ�
		cout << s1 << " " << s2 <<" "<<s3<< endl;
	}
	file.close();
}
void Word_Store::SetVector()
{
	char buffer[200];
	
	file.open("���ʱ�.txt", ios::in | ios::out);
	while (!file.eof())
	{	
		file.getline(buffer, 200);			//�����С����Ҫ������д��������
		
		istringstream is(buffer);    //�ַ���д���ڴ�
		string s1,s2,s3,s4;
		//is >> s1 >> s2>>s3>>s4;			//�ַ���д���ڴ�
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
void Word_Store::Show_V_S()
{
	word.clear();
	SetVector();
	VectorSort();
	for (int i = 0; i < word.size(); i++)
		if(!word[i].spell.empty())                   //�ж��Ƿ�Ϊ�գ�Ϊ�˽��Ͷ��η���ʱ�ĳɱ���
													//vectorʵ�����õĴ�С���ܱȿͻ�����ĸ���һЩ
		cout << "ƴд:"<<word[i].spell << "  ���ԣ�"<<word[i].pos<<"  ���壺" << word[i].meaning << endl;
	word.clear();
}

void Word_Store::Acc_Find()
{
	SetVector();
	string test;
	getchar();
	cout << "���뵥��" << endl;
	getline(cin, test);
	loc = find_if(word.begin(), word.end(), findx(test));
	if (loc!=word.end())
	{
	//	cout << "λ����" << loc - word.begin() + 1 << endl;
		cout << (*loc).spell << " " << (*loc).pos << " " << (*loc).meaning << "  " << (*loc).sen << endl;
	}
	else
	{
		cout << "δ�鵽" << endl;
	}
}

void Word_Store::Erase()                              
{
	SetVector();
	cout << "����Ҫɾ���ĵ���" << endl;
	string test;
	cin >> test;
	int k;
	loc = find_if(word.begin(), word.end(), findx(test));
	if (loc != word.end())
	{
		cout << (*loc).spell << " " << (*loc).pos << " " << (*loc).meaning << "  " << (*loc).sen << endl;

		cout << "�Ƿ�Ҫɾ���õ��� 1.�� 2.����" << endl;
		cin >> k;
		switch (k)
		{
		case 1:
			word.erase(loc);
			cout << "�ѴӴʿ���ɾ���õ���" << endl;
			break;
		case 2:
			cout << "δɾ��" << endl;
			break;
		}

	}
	else
		cout << "δ���ҵ��õ���" << endl;
	file.open("���ʱ�.txt", ios::in | ios::out | ios::trunc);
	for (int i = 0; i < word.size(); i++)
		if (file.is_open() == 1)
		{
			file << word[i].spell << '#' <<word[i].pos<< '#' << word[i].meaning << '#' <<word[i].sen<< endl;
		}

	file.close();

}
void Word_Store::Change()
{
	SetVector();
	cout << "����Ҫ�޸ĵĵ���" << endl;
	string test;
	string s1, s2, s3, s4;
	cin >> test;
	vector<Word_Store>::iterator loc;
	loc = find_if(word.begin(), word.end(), findx(test));
	if (loc != word.end())
	{
		cout << "�õ��ʵ�����Ϊ" << endl;
		cout << (*loc).spell << " " << (*loc).pos << " " << (*loc).meaning << "  " << (*loc).sen << endl;

		int k = 0;

		while (k != 5)
		{
			cout << "��ѡ��Ҫ�޸ĵ�����:1.ƴд  2.����   3.����  4.���� 5.�޸����" << endl;
			cin >> k;
			switch (k)
			{
			case 1:	cout << "���뵥��ƴд" << endl;
				cin >> (*loc).spell;
				break;
			case 2:
				cout << "���뵥�ʴ���" << endl;
				cin >> (*loc).pos;
				break;
			case 3:
				cout << "���뵥������" << endl;
				cin >> (*loc).meaning;
				break;
			case 4:
				cout << "���뵥������" << endl;
				getline(cin, (*loc).sen);
				break;

			default:
				break;
			}
		}
		file.open("���ʱ�.txt", ios::in | ios::out | ios::trunc);
		for (int i = 0; i < word.size(); i++)
			if (file.is_open() == 1)
			{
				file << word[i].spell << '#' << word[i].pos << '#' << word[i].meaning << '#' << word[i].sen <<'#'<< endl;
			}

		file.close();

	}
	else
	{
		cout << "δ�鵽����" << endl;
	}

}
#include"pch.h"