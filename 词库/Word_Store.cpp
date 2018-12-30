#include "Word_Store.h"
#include"Word_Findx.h"
fstream file;
 vector<Word_Store>word;				//����ȫ�ֱ�����������word�����ŵ���
 vector<Word_Store>::iterator loc;     //�õ�������������������word�в�ѯ����

bool Fsort(Word_Store a, Word_Store b) { return a.spell < b.spell; }  //����vector<word>��sort���򣬴���С�ڷ��ſ���������

void Word_Store::Insert()    //��ӵ��������ʱ�.txt����getline�����������ո�Ҳ���Զ��룬����¼��Ӣ�Ĵ��飬getchar�������ԳԵ������е�һ���س���д���ļ��ĵ��ʵĸ���������#�ֿ�����ո����ֿ�������ݴ���
{
	file.open("���ʱ�.txt", ios::in | ios::app);//���ı�ĩ׷�ӵķ�ʽ���ļ�
	if (file.is_open() == 1)
	{
		Word temp;
		getchar();				//�̵���������һ���ո񣬷����ֱ�ӵ�������ԵĲ���
		cout << "���뵥�ʵ�ƴд" << endl;
		getline(cin, temp.spell);		//��getline������ȡ��������ݣ��пո�Ҳ���ᵱ���ָ�����������������
		//cin >> temp.spell;
		cout << "���뵥�ʵĴ���" << endl;
		getline(cin, temp.pos);
		//cin >> temp.pos;
		cout << "���뵥�ʵ���˼" << endl;
		getline(cin, temp.meaning);
		//cin >> temp.meaning;
		cout << "���뵥�ʵ�����" << endl;
		getline(cin, temp.sen);
		file << temp.spell << '#' <<temp.pos<<'#'<< temp.meaning <<'#'<<temp.sen<<'#'<< endl; //д���ļ���ʱ���ڵ��ʵ�ÿ������֮���á�#���ֿ�������#����Ϊ�ָ���������֮��ķֲ����ж��ļ�
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
void Word_Store::Show_V_S()  //����������ʱ��е�����
{
	word.clear();//�Ƚ������е�Ԫ�����
	SetVector();//�����ʱ��ж����ݳ�ʼ������
	VectorSort();//�����еĵ�������
	for (int i = 0; i < word.size(); i++)
		if(!word[i].spell.empty())                   //�ж��Ƿ�Ϊ�գ�Ϊ�˽��Ͷ��η���ʱ�ĳɱ���
													//vectorʵ�����õĴ�С���ܱȿͻ�����ĸ���һЩ
		cout << "ƴд:"<<word[i].spell << "  ���ԣ�"<<word[i].pos<<"  ���壺" << word[i].meaning << endl;
	word.clear();
}

void Word_Store::Acc_Find()
{
	SetVector();					//�����ʱ��ж����ݳ�ʼ������
	string test;					//�����ַ�����������ż���ĵ���ƴд
	getchar();						//�̻س�
	cout << "���뵥��" << endl;
	getline(cin, test);
	loc = find_if(word.begin(), word.end(), findx(test));	//������������fine_if����������ƴд����
	if (loc!=word.end())
	{
	//	cout << "λ����" << loc - word.begin() + 1 << endl;
		cout << (*loc).spell << " " << (*loc).pos << " " << (*loc).meaning << "  " << (*loc).sen << endl;
															//����õ��ʵ���������
	}
	else
	{
		cout << "δ�鵽" << endl;
	}
}

void Word_Store::Erase()                            //ɾ������  
{
	SetVector();									//��ʼ������
	cout << "����Ҫɾ���ĵ���" << endl;				
	string test;
	cin >> test;
	int k;
	loc = find_if(word.begin(), word.end(), findx(test));		//���Ҹõ���
	if (loc != word.end())
	{
		cout << (*loc).spell << " " << (*loc).pos << " " << (*loc).meaning << "  " << (*loc).sen << endl;
		cout << "�Ƿ�Ҫɾ���õ��� 1.�� 2.����" << endl;				//�ж��Ƿ�ɾ��
		cin >> k;
		switch (k)
		{
		case 1:
			word.erase(loc);											//��������erase����ɾ���õ���
			cout << "�ѴӴʿ���ɾ���õ���" << endl;
			break;
		case 2:
			cout << "δɾ��" << endl;
			break;
		}

	}
	else
		cout << "δ���ҵ��õ���" << endl;
	file.open("���ʱ�.txt", ios::in | ios::out | ios::trunc);		//��ɾ����������������ݸ��ǵ����ʱ�txt�У����ڸ���
	for (int i = 0; i < word.size(); i++)
		if (file.is_open() == 1)
		{
			file << word[i].spell << '#' <<word[i].pos<< '#' << word[i].meaning << '#' <<word[i].sen<< endl;
		}
	file.close();
}
void Word_Store::Change()						//�޸ĵ�������
{
	SetVector();								//��ʼ������
	cout << "����Ҫ�޸ĵĵ���" << endl;
	string test;
	string s1, s2, s3, s4;
	cin >> test;
	vector<Word_Store>::iterator loc;	
	loc = find_if(word.begin(), word.end(), findx(test));		//���Ҹõ���
	if (loc != word.end())	
	{
		cout << "�õ��ʵ�����Ϊ" << endl;
		cout << (*loc).spell << " " << (*loc).pos << " " << (*loc).meaning << "  " << (*loc).sen << endl;
		int k = 0;
		while (k != 5)
		{
			cout << "��ѡ��Ҫ�޸ĵ�����:1.ƴд  2.����   3.����  4.���� 5.�޸����" << endl;//����ѡ��Ҫ�޸ĵ��ʵ��ĸ�����
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
		file.open("���ʱ�.txt", ios::in | ios::out | ios::trunc);		//���ǵ����ʱ�txt�����ڸ����ı�����
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