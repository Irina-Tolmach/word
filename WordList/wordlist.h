#pragma once
#include <iostream>
#include <fstream>
using namespace std;

typedef struct {
	char word[40];
	int count;
} TPair;

typedef struct {
	TPair* data;
	int capacity;
	int size;
} TWordList;

//int Find(TWordList &L, char* s);
//{
//	int i, p;
//	p = -1;
//	for (i = 0; i < L.size; i++)
//	{
//		if (L.data[i].word == s)
//			p = i;
//		break;
//	}
//	return p;
//}

int FindPlace(TWordList L, char* s);
//{
//	int i;
//	for (i = 0; i < L.size; i++)
//		if (strcmp(L.data[i].word, s) > 0)
//			return i;
//}

void IncSize(TWordList* pl);
//{
//	pl->size++;
//	if (pl->size > pl->capacity)
//	{
//		pl->capacity += 10;
//		pl->data = (TPair*)realloc(pl->data, sizeof(TPair) * pl->capacity);
//	}
//}
void InsertWord(TWordList* pl, int k, char* s);
//{
//	int i;
//	IncSize(pl);
//	for (i = pl->size; i > k; i--)
//		pl->data[i] = pl->data[i - 1];
//	strcpy_s(pl->data[k].word, s);
//	pl->data[k].count++;
//}

void PrintList(TWordList L);
//{
//	int i;
//	for (i = 0; i < L.size; i++)
//		printf("%s %d\n", L.data[i].word, L.data[i].count);
//}