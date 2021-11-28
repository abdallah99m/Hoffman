#include <iostream>
#include<string>
#include<fstream>
#include<stdio.h>
using namespace std;
class ctnode
{
public:

	int info;
	char letter;
	char code[1000];
	ctnode *pleft;
	ctnode *prght;
};
class cnode
{
public:

	int lenum;
	char letter;
	char code[8];
	cnode *pnext;
	ctnode *pd;

};
class CCNode
{
public:
	char x;
	char code[8];
	int N;
	CCNode *pNext;
};


class ctree
{
public:
	ctnode *proot;
	ctree()
	{
		proot = NULL;
	}
	~ctree()
	{
		goodbye(proot);
	}
	void goodbye(ctnode *pt)
	{
		if (pt == NULL)
		{
			return;
		}
		goodbye(pt->pleft);
		goodbye(pt->prght);
		delete pt;
	}
	void dispall()
	{
		disp(proot);
	}
	void disp(ctnode*pt)
	{
		if (pt == NULL)
		{
			return;

		}
		disp(pt->pleft);
		cout << pt->info;
		disp(pt->prght);

	}

	void insert(ctnode*pnn)
	{
		if (proot == NULL)
		{
			proot = pnn;
		}
		else
		{
			ctnode*ptrave = proot;
			ctnode *pb = NULL;
			while (ptrave != NULL)
			{
				pb = ptrave;
				if (pnn->info < ptrave->info)
				{
					ptrave = ptrave->pleft;
				}
				else
				{
					ptrave = ptrave->prght;
				}
				if (pnn->info > pb->info)
				{
					pb->prght = pnn;
				}
				else
				{
					pb->pleft = pnn;
				}
			}
		}
	}




};



class clist
{
public:
	cnode * phead;
	cnode * ptail;
	clist()
	{
		phead = '\0';
		ptail = '\0';
	}
	~clist()
	{
		cnode *ptrav;
		ptrav = phead;
		while (ptrav != NULL)
		{
			phead = phead->pnext;
			delete ptrav;
			ptrav = phead;
		}
	}
	void attach(cnode *pnn)
	{
		if (phead == NULL)
		{
			phead = pnn;
			ptail = pnn;
		}
		else
		{
			ptail->pnext = pnn;
			ptail = pnn;
		}
	}
	void DispAll()
	{
		cnode *ptrave = phead;
		while (ptrave != '\0')
		{
			cout << "'" << ptrave->letter << "': " << ptrave->code << endl;
			ptrave = ptrave->pnext;
		}
		cout << endl;
	}
};




class clistsorted
{
public:
	cnode * phead;
	cnode * ptail;
	clistsorted()
	{
		phead = '\0';
		ptail = '\0';
	}
	~clistsorted()
	{
		cnode *ptrav;
		ptrav = phead;
		while (ptrav != NULL)
		{
			phead = phead->pnext;
			delete ptrav;
			ptrav = phead;
		}
	}
	void attach(cnode *pnn)
	{
		cnode *pb;
		pb = NULL;
		cnode *ptrave;
		ptrave = phead;
		while (ptrave != NULL)
		{
			if (ptrave->lenum > pnn->lenum)
			{
				break;

			}
			pb = ptrave;
			ptrave = ptrave->pnext;
		}
		if (pb != NULL)
		{
			pb->pnext = pnn;
		}
		else
		{
			phead = pnn;
		}
		pnn->pnext = ptrave;


	}
};
class CCList
{
public:
	CCNode *pHead;
	CCNode *pTail;

	CCList()
	{
		pHead = '\0';
		pTail = '\0';
	}

	~CCList()
	{
		CCNode *pTrav = pHead;
		while (pTrav != '\0')
		{
			pHead = pHead->pNext;
			delete pTrav;
			pTrav = pHead;
		}
	}

	void Attach(CCNode *pnn)
	{
		if (pHead == '\0')
		{
			pHead = pnn;
			pTail = pnn;
		}
		else
		{
			pTail->pNext = pnn;
			pTail = pnn;
		}
	}
	void DispAll()
	{
		CCNode *pTrav = pHead;
		while (pTrav != '\0')
		{
			cout << "'" << pTrav->x << "': " << pTrav->code << endl;
			pTrav = pTrav->pNext;
		}
		cout << endl;
	}
};

void GenerateCode(ctnode *pTrav, char CodeTemp[], int i, CCList &Code)
{
	if (pTrav == '\0')
	{
		return;
	}
	if (pTrav->pleft == '\0' && pTrav->prght == '\0')
	{
		int z;
		CCNode *pnn = new CCNode;
		pnn->x = pTrav->letter;
		pnn->N = pTrav->info;
		for (z = 0; CodeTemp[z] != '\0'; z++)
		{
			pnn->code[z] = CodeTemp[z];
		}
		pnn->code[z] = '\0';
		Code.Attach(pnn);
		pnn->pNext = '\0';
		for (z = 0; CodeTemp[z] != '\0'; z++)
		{
		}
		CodeTemp[z - 1] = '\0';
		return;
	}
	CodeTemp[i] = '0';
	GenerateCode(pTrav->pleft, CodeTemp, i + 1, Code);
	CodeTemp[i] = '1';
	GenerateCode(pTrav->prght, CodeTemp, i + 1, Code);
}




int main()
{
	char input[1000];
	char CodeTemp[1000];
	char y[1000];
	int i, j, ct;
	clistsorted l;
	clist l1;
	CCList code;
	cnode *pnn;
	cnode *pnn2;
	cnode *ptrave;
	cnode *pcatch;
	ctnode *pnn3;
	ctnode * pnn4;
	ctnode *pnn5;
	ctree  t;
	CCNode *phase2;
	char z = NULL, m = 1;
	
	gets_s(input);
	
	for (i = 0; input[i] != '\0'; i++)
	{
		ct = 0;
		int ctch = 0;
		ptrave = l1.phead;
		while (ptrave != NULL)
		{
			if (ptrave->letter == input[i])
			{
				ctch++;
			}
			ptrave = ptrave->pnext;
		}
		if (ctch == 0)
		{
			for (j = 0; input[j] != '\0'; j++)
			{
				if (input[i] == input[j])
				{
					ct++;


				}
			}

			pnn = new cnode;
			pnn->lenum = ct;
			pnn->letter = input[i];

			pnn->pnext = NULL;
			pnn->pd = NULL;
			l.attach(pnn);
			pnn2 = new cnode;
			pnn2->letter = input[i];
			pnn2->lenum = 0;
			pnn2->pd = NULL;
			pnn2->pnext = NULL;
			l1.attach(pnn2);
		}
	}



	ptrave = l.phead;
	while (ptrave != NULL)
	{
		cout << ptrave->letter;
		cout << "     " << ptrave->lenum;
		cout << endl;
		ptrave = ptrave->pnext;
	}


	pcatch = l.phead;

	while (l.phead->pnext != NULL)
	{
		pcatch = l.phead;
		l.phead = pcatch->pnext->pnext;
		pcatch->pnext->pnext = NULL;
		pnn = new cnode;
		pnn->lenum = pcatch->lenum + pcatch->pnext->lenum;
		pnn->pnext = NULL;
		pnn->pd = NULL;

		if (pcatch->pd == NULL && pcatch->pnext->pd == NULL)
		{
			pnn3 = new ctnode;
			pnn3->info = pnn->lenum;

			pnn4 = new ctnode;
			pnn4->info = pcatch->lenum;
			pnn4->pleft = NULL;
			pnn4->prght = NULL;
			pnn4->letter = pcatch->letter;

			pnn5 = new ctnode;
			pnn5->info = pcatch->pnext->lenum;
			pnn5->pleft = NULL;
			pnn5->prght = NULL;
			pnn5->letter = pcatch->pnext->letter;

			pnn3->prght = pnn5;
			pnn3->pleft = pnn4;
			pnn->pd = pnn3;
		}
		if (pcatch->pd != NULL && pcatch->pnext->pd != NULL)
		{
			pnn3 = new ctnode;
			pnn3->info = pnn->lenum;
			pnn3->prght = pcatch->pnext->pd;
			pnn3->pleft = pcatch->pd;
			pnn->pd = pnn3;

		}
		if (pcatch->pd == NULL && pcatch->pnext->pd != NULL)
		{
			pnn3 = new ctnode;
			pnn3->info = pnn->lenum;
			pnn3->prght = pcatch->pnext->pd;

			pnn4 = new ctnode;
			pnn4->info = pcatch->lenum;
			pnn4->letter = pcatch->letter;
			pnn4->pleft = NULL;
			pnn4->prght = NULL;

			pnn3->pleft = pnn4;
			pnn->pd = pnn3;
		}
		if (pcatch->pd != NULL && pcatch->pnext->pd == NULL)
		{
			pnn3 = new ctnode;
			pnn3->info = pnn->lenum;
			pnn3->pleft = pcatch->pd;

			pnn4 = new ctnode;
			pnn4->info = pcatch->pnext->lenum;
			pnn4->letter = pcatch->pnext->letter;
			pnn4->pleft = NULL;
			pnn4->prght = NULL;

			pnn3->prght = pnn4;
			pnn->pd = pnn3;
		}


		l.attach(pnn);
	}

	for (int i = 0; i < 1000; i++)
	{
		CodeTemp[i] = '\0';
	}
	GenerateCode(l.phead->pd, CodeTemp, 0, code);
	cout << endl;
	code.DispAll();

	system("pause");

	int ph2 = 0;
	int q = 7;
	for (i = 0; input[i] != '\0'; i++)
	{
		phase2 = code.pHead;
		while (1)
		{
			if (phase2->x == input[i])
			{
				break;

			}
			phase2 = phase2->pNext;
		}
		for (j = 0; phase2->code[j] != '\0'; j++)
		{
			if (phase2->code[j] == '1')
			{
				z = z | (m << q);




			}
			q--;
			if (q == (-1))
			{
				y[ph2] = z;
				z = NULL;
				q = 7;
				ph2++;
			}
		}

		if (q > -1 && phase2->code[j] == '\0'&&input[i + 1] == '\0'&&q != 7)
		{
			y[ph2] = z;
			z = NULL;
			q = 7;
			ph2++;
		}


	}
	y[ph2] = '\0';
	ct = 0;
	for (i = 0; y[i] != '\0'; i++)
	{
		cout << y[i] << endl;
		ct++;
	}
	cout << ct;
	system("pause");
	char res = 0;
	z = '@';
	clist pl;

	for (i = 0; y[i] != '\0'; i++)
	{
		z = y[i];
		for (j = 7; j > -1; j--)
		{
			res = 0;
			res = z & (m << j);
			if (res != 0)
			{
				pnn = new cnode;
				pnn->letter = '1';
				pnn->pnext = NULL;

				pl.attach(pnn);
			}
			else
			{
				pnn = new cnode;
				pnn->letter = '0';
				pnn->pnext = NULL;
				pl.attach(pnn);
			}
			phase2 = code.pHead;
			while (phase2 != NULL)
			{
				ptrave = pl.phead;
				int ct = 0, ct1 = 0;
				for (q = 0; phase2->code[q] != '\0'; q++)
				{
					ct++;
				}





				for (q = 0; phase2->code[q] != '\0'&&ptrave != NULL; q++)
				{


					if (ptrave->letter == phase2->code[q])
					{
						ct1++;
					}



					ptrave = ptrave->pnext;
				}

				if (ct == ct1)
				{
					cout << phase2->x;
					while (pl.phead != NULL)
					{
						pnn2 = pl.phead;
						pl.phead = pnn2->pnext;
						delete pnn2;
					}

					break;
				}
				phase2 = phase2->pNext;

			}



		}


	}





	system("pause");



}
