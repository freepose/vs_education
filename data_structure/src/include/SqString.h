/*
*
* Create By Kaijin Cui
*
*/


#pragma once
#include "basic.h"

typedef struct 
{
	char data[MAX_SIZE];
	int length;
} SqString;

typedef struct snode
{
	char data;
	snode *next;
}LinkStrNode;

void StrAssign(SqString &s, char cstr[])
{

	int i;
	for (i = 0; cstr[i] != '\0'; i++)
	{
		s.data[i] = cstr[i];
	}
	s.length = i;
}

void StrCopy(SqString &s, SqString t)
{
	int i;
	for (i = 0; i < t.length; i++)
	{
		s.data[i] = t.data[i];
	}
	s.length = t.length;
}

bool StrEqual(SqString s, SqString t)
{
	if (s.length != t.length)
		return false;
	else
	{
		for (int i = 0; i < s.length; i++)
		{
			if (s.data[i] != t.data[i])
				return false;
		}
	}
	return true;
}

int StrLength(SqString s)
{
	return s.length;
}

SqString Concat(SqString s, SqString t)
{
	SqString str;
	str.length = s.length + t.length;
	for (int i = 0; i < s.length; i++)
	{
		str.data[i] = s.data[i];
	}
	for (int i = 0; i < t.length; i++)
	{
		str.data[i + s.length] = t.data[i];
	} 
	return str;
}

SqString SubStr(SqString s, int i, int j)
{
	int k;
	SqString str;
	str.length = 0;
	if (i <= 0 || i > s.length || j < 0 || i + j - 1 > s.length)
		return str;
	for (k = i - 1; k < i + j - 1; k++)
	{
		str.data[k - i + 1] = s.data[k];
	}
	str.length = j;
	return str;
}

SqString InsStr(SqString s1, int i, SqString s2)
{
	int j;
	SqString str;
	str.length = 0;
	if (i <= 0 || i > s1.length + 1)
	{
		return str;
	}
	for (j = 0; j < i - 1; j++)
	{
		str.data[j] = s1.data[j];
	}
	for (j = 0; j < s2.length; j++)
	{
		str.data[i + j - 1] = s2.data[j];
	}
	for (j = i - 1; j < s1.length; j++)
	{
		str.data[s2.length + 1] = s1.data[j];
	}
	str.length = s1.length + s1.length;
	return str;
}

SqString DelStr(SqString s, int i, int j)
{
	int k;
	SqString str;
	str.length = 0;
	if (i < 0 || i > s.length || i + j > s.length + 1)
		return str;
	for (k = 0; k < i - 1; k++)
	{
		str.data[k] = s.data[k];
	}
	for (k = i + j - 1; k < s.length; k++)
	{
		str.data[k - j] = s.data[k];
	}
	str.length = s.length - j;
	return str;
}

SqString RepStr(SqString s, int i, int j, SqString t)
{
	int k;
	SqString str;
	str.length = 0;
	if (i <= 0 || i > s.length || i + j - 1 > s.length)
	{
		return str;
	}
	for (k = 0; k < i - 1; k++)
	{
		str.data[k] = s.data[k];
	}
	for (k = 0; k < t.length; k++)
	{
		str.data[i + k - 1] = t.data[k];
	}
	for (k = i + j - 1; k < s.length; k++)
	{
		str.data[t.length + k - j] = s.data[k];
	}
	str.length = s.length - j + t.length;
	return str;
}

void DispStr(SqString s)
{
	int i;
	if (s.length > 0)
	{
		for (i = 0; i < s.length; i++)
		{
			cout << s.data[i];
		}
		cout << endl;
	}
}

void StrAssignLink(LinkStrNode *&s, char cstr[])
{
	int i;
	LinkStrNode *r, *p;
	s = new LinkStrNode;
	r = s;
	for (i = 0; cstr[i] != '\0'; i++)
	{
		p = new LinkStrNode;
		p->data = cstr[i];
		r->next = p;
		r = p;
	}
	r->next = NULL;
}

void DestroyStrLink(LinkStrNode *&s)
{
	LinkStrNode *pre = s, *p = s->next;
	while (p != 0)
	{
		delete pre;
		pre = p;
		p = p->next;
	}
	delete pre;
}

void StrCopyLink(LinkStrNode *&s, LinkStrNode *t)
{
	LinkStrNode *p = t->next, *q, *r;
	s = new LinkStrNode;
	r = s;
	while (p != 0)
	{
		q = new LinkStrNode;
		q->data = p->data;
		r->next = q;
		r = q;
		p = p->next;
	}
	r->next = NULL;
}

bool StrEqualLink(LinkStrNode *s, LinkStrNode *t)
{
	LinkStrNode *p = s->next, *q = t->next;
	while (p != 0 && q != 0 && p->data == t->data)
	{
		p = p->next;
		q = q->next;
	}
	if (p == 0 && q == 0)
		return true;
	else
		return false;
}

int StrLengthLink(LinkStrNode *s)
{
	int i = 0;
	LinkStrNode *p = s->next;
	while (p != NULL)
	{
		i++;
		p = p->next;
	}
	return i;
}

LinkStrNode *ConcatLink(LinkStrNode *s, LinkStrNode *t)
{
	LinkStrNode *str, *p = s->next, *q, *r;
	str = new LinkStrNode;
	r = str;
	while (p != NULL)
	{
		q = new LinkStrNode;
		q->data = p->data;
		r->next = q;
		r = q;
		p = p->next;
	}
	p = p->next;
	while (p != NULL)
	{
		q = new LinkStrNode;
		q->data = p->data;
		r->next = q;
		r = q;
		p = p->next;
	}
	r->next = NULL;		
	return str;
}

LinkStrNode *SubStrLink(LinkStrNode *s, int i, int j)
{
	int k;
	LinkStrNode *str, *p = s->next, *q, *r;
	str = new LinkStrNode;
	str->next = NULL;
	r = str;
	if (i <= 0 || i > StrLengthLink(s) || j < 0 || i + j - 1 > StrLengthLink(s))
	{
		return str;
	}
	for (k = 1; k < i; k++)
	{
		p = p->next;
	}
	for (k = 1; k <= j; k++)
	{
		q = new LinkStrNode;
		q->data = p->data;
		r->next = q;
		r = q;
		p = p->next;
	}
	r->next = NULL;
	return str;
}

LinkStrNode *InsStrLink(LinkStrNode *s, int i, LinkStrNode *t)
{
	int k;
	LinkStrNode *str, *p = s->next, *p1 = t->next, *q, *r;
	str = new LinkStrNode;
	str->next = NULL;
	r = str;
	if (i <= 0 || i > StrLengthLink(s) + 1)
		return str;
	for (k = 1; k < i; k++)
	{
		q = new LinkStrNode;
		q->data = p->data;
		r->next = q;
		r = q;
		p = p->next;
	}
	while (p1 != NULL)
	{
		q = new LinkStrNode;
		q->data = p1->data;
		r->next = q;
		r = q;
		p1 = p1->next;
	}
	while (p != NULL)
	{
		q = new LinkStrNode;
		q->data = p->data;
		r->next = q;
		r = q;
		p = p->next;
	}
	r->next = NULL;
	return str;
}

LinkStrNode *DelStrLink(LinkStrNode *s, int i, int j)
{
	int k;
	LinkStrNode *str, *p = s->next, *q, *r;
	str = new LinkStrNode;
	str->next = NULL;
	r = str;
	if (i <= 0 || i > StrLengthLink(s) || j < 0 || i + j - 1 > StrLengthLink(s))
		return str;
	for (k = 1; k < i; k++)
	{
		q = new LinkStrNode;
		q->data = p->data;
		r->next = q;
		r = q;
		p = p->next;
	}
	for (k = 0; k < j; k++)
		p = p->next;
	while (p != NULL)
	{
		q = new LinkStrNode;
		q->data = p->data;
		r->next = q;
		r = q;
		p = p->next;
	}
	r->next = NULL;
	return str;
}

LinkStrNode *RepStr(LinkStrNode *s, int i, int j, LinkStrNode *t)
{
	int k;
	LinkStrNode *str, *p = s->next, *p1 = t->next, *q, *r;
	str = new LinkStrNode;
	str->next = NULL;
	r = str;
	if (i <= 0 || i > StrLengthLink(s) || j < 0 || i + j - 1 > StrLengthLink(s))
		return str;
	for (k = 0; k < i - 1; k++)
	{
		q = new LinkStrNode;
		q->data = p->data;
		q->next = NULL;
		r->next = q;
		r = q;
		p = p->next;
	}
	for (k = 0; k < j; k++)
		p = p->next;
	while (p1 != NULL)
	{
		q = new LinkStrNode;
		q->data = p1->data;
		q->next = NULL;
		r->next = q;
		r = q;
		p1 = p1->next;
	}
	while (p != NULL)
	{
		q = new LinkStrNode;
		q->data = p->data;
		q->next = NULL;
		r->next = q;
		r = q;
		p = p->next;
	}
	r->next = NULL;
	return str;
}

void DispStrLink(LinkStrNode *s)
{
	LinkStrNode *p = s->next;
	while (p != NULL)
	{
		cout << p->data;
		p = p->next;
	}
	cout << endl;
}

/*
*Examples
*/

//P127 ����4.1��Compare the size of two strings in a dictionary order.
int Strcmp(SqString s, SqString t)
{
	int i, comlen;
	if (s.length < t.length) comlen = s.length;		//��s��t�Ĺ�ͬ����
	else comlen = t.length;
	for (i = 0; i < comlen; i++)		//�ڹ�ͬ����������Ƚ�
	{
		if (s.data[i] > t.data[i])
			return 1;
		else if (s.data[i] < t.data[i])
			return -1;
	}
	if (s.length == t.length)		//s == t
		return 0;
	else if (s.length > t.length)	//s > t
		return 1;
	else return -1;					//s < t
}

//P127 ����4.2��A platform for the first longest continuous same character in a string.
void LongestString(SqString s, int &index, int &maxlen)
{
	int length, i = 1, start;		//length����ֲ�ƽ̨�ĳ���
	index = 0, maxlen = 1;			//index�����ƽ̨��s�еĿ�ʼλ�ã�maxlen�����䳤��
	while (i < s.length)
	{
		start = i - 1;				//���Ҿֲ��ظ��Ӵ�
		length = 1;
		while (i < s.length && s.data[i] == s.data[i - 1])
		{
			i++;
			length++;
		}
		if (maxlen < length)		//��ǰƽ̨���ȴ������maxlen
		{
			maxlen = length;
			index = start;
		}
		i++;
	}
}

//P133 ����4.3��Change the first substring "ab" in the string s to "xyz"
void Repl(LinkStrNode *&s)
{
	LinkStrNode *p = s->next, *q;
	bool find = false;
	while (p != NULL && p->next != NULL && !find)
	{
		if (p->data == 'a' && p->next->data == 'b')
		{
			p->data = 'x';
			p->next->data = 'z';
			q = new LinkStrNode;
			q->data = 'y';
			q->next = p->next;
			p->next = q;
			find = true;
		}
		else p = p->next;
	}
}


/*Algorithm by CXD*/

//Brute-Force
int index(SqString s, SqString t)
{
	int j = 0, i = 0;
	while (i<s.length&&j < t.length) {
		if (s.data[i] == t.data[j]) {
			i++;
			j++;
		}
		else {
			i = i - j + 1;//�Ƶ�i����һ��
			j = 0;
		}
	}
	if (j >= t.length) {
		return (i - t.length);//����i���±��ȥģʽ�����ȣ����ڵ�һ���ַ����ڵ��±�
	}
	else {
		return -1;
	}
}

//KMP
void GetNext(SqString t, int *next)
{
	int  j = 0, k = -1;
	next[0] = -1;//next[j]����jǰ�м����뿪ͷ��ͬ����
	while (j < t.length - 1) {//��j=length-1ʱ���Ѿ���ÿ���ַ���next��ע��
		if (k == -1 || t.data[k] == t.data[j]) {
			j++;
			k++;
			next[j] = k;
		}
		else {
			k = next[k];
		}
	}
}

int KMPIndex(SqString s, SqString t)
{
	int i = 0, j = 0;
	int next[MAX_SIZE];
	GetNext(t, next);
	while (i < s.length&&j < t.length) {
		if (j == -1 || s.data[i] == t.data[j]) {
			i++;
			j++;
		}
		else {
			j = next[j];
		}
	}
	if (j >= t.length) {
		return (i - t.length);
	}
	else {
		return -1;
	}
}

//better KMP
void GetNextval(SqString t, int *nextval)
{
	int j = 0, k = -1;
	nextval[0] = -1;
	while (j < t.length) {
		if (k == -1 || t.data[k] == t.data[j]) {
			k++;
			j++;
			if (t.data[k] == t.data[j]) {
				nextval[j] = nextval[k];
			}
			else {
				nextval[j] = k;
			}
		}
		else {
			k = nextval[k];
		}
	}
}

int KMPIndex1(SqString s, SqString t) {
	int nextval[MAX_SIZE];
	int i = 0, j = 0;
	GetNextval(t, nextval);
	while (i < s.length&&j < t.length) {
		if (j == -1 || s.data[i] == t.data[j]) {
			i++;
			j++;
		}
		else {
			j = nextval[j];
		}
	}
	if (j >= t.length) {
		return (i - t.length);
	}
	else {
		return -1;
	}
}


void SqStringexample()
{
	
	
	int i;
	SqString t, s;
	char a[5] = "abab";
	char b[13] = "abbaababbaab";
	for (i = 0; i < 4; i++) {
		t.data[i] = a[i];
	}
	t.length = 4;
	for (i = 0; i < 12; i++) {
		s.data[i] = b[i];
	}
	s.length = 12;
	cout << "The position of the substring is:"<<endl;
	cout << index(s, t)<< endl;
	cout << KMPIndex(s, t)<< endl;
	cout << KMPIndex1(s, t)<< endl;
}