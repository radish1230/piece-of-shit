#include "Word_Store.h"
#include"Findx.h"
fstream file;

vector<Word_Store>word;				/*����vector,ȫ�ֱ���*/

bool Fsort(Word_Store a, Word_Store b) { return a.spell < b.spell; }  //����sort�������򣬴���С�ڿ���������

void Word_Store::Inster()
{
	file.open("���ʱ�.txt", ios::in | ios::app);
	if (file.is_open() == 1)
	{
		Word temp;
		cout << "���뵥�ʵ�ƴд" << endl;
		cin >> temp.spell;
		//getline(cin, temp.spell);

		cout << "���뵥�ʵĴ���" << endl;
		cin >> temp.pos;
		//getline(cin, temp.pos);

		cout << "���뵥�ʵ���˼" << endl;
		cin >> temp.meaning;
		//getline(cin, temp.meaning);
		getchar();
		cout << "���뵥�ʵ�����" << endl;
		getline(cin, temp.sen);
		file << temp.spell << "  " <<temp.pos<<"  "<< temp.meaning <<"  "<<temp.sen<< endl;
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
	char buffer[100];
	int num = 0;
	file.open("���ʱ�.txt", ios::in | ios::out);
	while (!file.eof())
	{

		file.getline(buffer, 100);
		istringstream is(buffer);    //�ַ���д���ڴ�
		string s1, s2,s3,s4;
		is >> s1 >> s2>>s3>>s4;			//�ַ���д���ڴ�
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
	cout << "���뵥��" << endl;
	cin >> test;
	vector<Word_Store>::iterator loc;
	loc = find_if(word.begin(), word.end(), findx(test));
	cout << "λ����" << loc - word.begin() + 1 << endl;
	cout << (*loc).spell << " " << (*loc).pos<<" "<<(*loc).meaning << "  "<< (*loc).sen<<endl;
}

void Word_Store::Erase()
{
	SetVector();
	cout << "����Ҫɾ���ĵ���" << endl;
	string test;
	cin >> test;
	vector<Word_Store>::iterator loc;
	loc = find_if(word.begin(), word.end(), findx(test));
	word.erase(loc);
	
	file.open("���ʱ�.txt", ios::in | ios::out | ios::trunc);
	for (int i = 0; i < word.size(); i++)
		if (file.is_open() == 1)
		{
			file << word[i].spell << "  " << word[i].meaning << endl;
		}

	file.close();

}
#include"pch.h"