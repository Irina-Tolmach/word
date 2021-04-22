#include <iostream>
#include <fstream>
#include "wordlist.h"
#include <string>

using namespace std;

//typedef struct {
//	char word[40];
//	int count;
//} TPair;
//
//typedef struct {
//	TPair* data;
//	int capacity;
//	int size;
//} TWordList;

int Find(TWordList &L, char* s)
{
	int i, p;
	p = -1;
	for (i = 0; i < L.size; i++)
		if (strcmp(L.data[i].word,s)==0)
			p=i;
	return p;
}
//
//int FindPlace(TWordList L, char* s)
//{
//	int i;
//	for(i=0; i < L.size ;i++)
//		if(strcmp(L.data[i].word, s)>0)
//			return i;
//}
//
//void IncSize(TWordList *pl)
//{
//	pl->size++;
//	if (pl->size > pl->capacity)
//	{
//		pl->capacity += 10;
//		pl->data = (TPair*)realloc(pl->data, sizeof(TPair) * pl->capacity);
//	}
//}
//void InsertWord(TWordList* pl, int k, char* s)
//{
//	int i;
//	IncSize(pl);
//	for (i = pl->size; i > k; i--)
//		pl->data[i] = pl->data[i - 1];
//	strcpy_s(pl->data[k].word, s);
//	pl->data[k].count=1;
//}
//
//void PrintList(TWordList L)
//{
//	int i;
//	for (i = 0; i < L.size; i++)
//		printf("%s %d\n", L.data[i].word, L.data[i].count);
//}
void Bukva(char a)
{
	if ((int)a <= 90 && (int)a >= 65)
		a = (char)((int)a + 32);
}

void Cleaner(char* first , char * second)
{
	ifstream in;
	in.open(first);
	ofstream out;
	out.open(second);
	string s;
	while (getline(in, s))
	{
		for(int i=0; i<s.size(); i++)
			if (s[i] >= 'A' && s[i] <= 'Z')
			{
				s[i] = s[i] + 'a' - 'A';
			}
			else if (s[i] < 'a' || s[i] > 'z')
				s[i]=' ';
		if (s.size() > 0)
			out << s ;
		if (!in.eof())
			out << endl;
	}
	in.close();
	out.close();
}

void PrintFile(TWordList L, char* name)
{
	int i;
	ofstream out;
	out.open(name);
	out << L.size << endl;
	for (i = 0; i < L.size; i++)
		out << L.data[i].word << " " << L.data[i].count << endl;
	out.close();
}

int main()
{
	char s[40], name2[40] = "out.txt", name1[40]="in.txt", clist[40]="list.txt";
	int p;
	string k;
	TWordList L;
	L.size = 0;
	L.capacity = 10000;
	L.data = (TPair*)calloc(L.capacity, sizeof(TPair));
	Cleaner(name1, name2);
	ifstream in;
	in.open("out.txt");
	while (!in.eof())
	{
		in >> s;
		p = Find(L, s);
		if (p >= 0)
			L.data[p].count++;
		else
		{
			p = FindPlace(L, s);
			InsertWord(&L, p, s);
		}
	}
	PrintList(L);
	PrintFile(L, clist);
	in.close();
	return 0;
}

