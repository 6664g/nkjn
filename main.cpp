#include<iostream>
#include<vector>
using namespace std;
typedef struct node//�ڵ�
{
	int x,y;
	double g, h,f;
	node* parent;
};
bool isinv(node* np, vector<node*>* vp, int si)//�ж��������Ƿ������Ԫ��
{
	for (vector<node*>::iterator i = (*vp).begin(); i < (*vp).begin() + si; i++)
	{
		if (np == *i)
			return true;
	}
	return false;
}
int main()
{

	int wid = 15;
	vector<node*> oL, cL;
	node start,end;//��� �յ�
	vector<vector<node>> map;//��ͼ
					
							 
							 //�˴�Ϊ��ͼ����㣬�յ������




	start.f = 0;
	start.parent = NULL;
	oL.push_back(&start);


	double minC;
	int next=0;
	node* pn,*check;
	double g;
	while (!oL.empty())
	{
		for (int i = 0; i < oL.size(); i++)
		{
			if (oL[i]->f <= minC)
			{
				next = i;
				minC = oL[i]->f;
			}
		}
		minC = 1000;//abs(start.x - end.x) + abs(start.y - end.y);
		if (oL[next]->x == end.x && oL[next]->y == end.y)
		{

			
			//date back
			//��shu
			node* date=oL[next];
			while (date == NULL)
			{
				cout << "[" << date->x << "," << date->y << "]" << " ";
				date = date->parent;
			}
			return 0;
			//..................
		}
		else
		{
			pn = oL[next];
			cL.push_back(oL[next]);
			oL.erase(oL.begin() + next);
			//������Χ�˸�
			for (int i = 0; i < 2; i++)
			{
				check = &map[(*pn).x+i%2][(*pn).y+(i+1)%2];
				if (isinv(check, &oL, oL.size()))
				{
					if (pn->g + 1 < check->g)
					{
						check->parent = pn;
						check->g = pn->g + 1;
					}
				}
				else if (!(isinv(check, &oL, oL.size())) && !isinv(check, &cL, cL.size()))
				{
					check->parent = pn;
					check->g = pn->g + 1;
					check->h = abs(check->x - end.x) + abs(check->y - end.y);
					check->f = check->g + check->h;
					oL.push_back(check);

				}
			}

			for (int i = 0; i < 2; i++)
			{
				check = &map[(*pn).x - i % 2][(*pn).y - (i + 1) % 2];
				if (isinv(check, &oL, oL.size()))
				{
					if (pn->g + 1 < check->g)
					{
						check->parent = pn;
						check->g = pn->g + 1;
					}
				}
				else if (!(isinv(check, &oL, oL.size())) && !isinv(check, &cL, cL.size()))
				{
					check->parent = pn;
					check->g = pn->g + 1;
					check->h = abs(check->x - end.x) + abs(check->y - end.y);
					check->f = check->g + check->h;
					oL.push_back(check);

				}
			}

			for (int i = 0; i < 2; i++)
			{
				check = &map[(*pn).x - i % 2][(*pn).y + (i + 1) % 2];
				if (isinv(check, &oL, oL.size()))
				{
					if (pn->g + 1 < check->g)
					{
						check->parent = pn;
						check->g = pn->g + 1;
					}
				}
				else if (!(isinv(check, &oL, oL.size())) && !isinv(check, &cL, cL.size()))
				{
					check->parent = pn;
					check->g = pn->g + 1;
					check->h = abs(check->x - end.x) + abs(check->y - end.y);
					check->f = check->g + check->h;
					oL.push_back(check);

				}
			}

			for (int i = 0; i < 2; i++)
			{
				check = &map[(*pn).x + i % 2][(*pn).y - (i + 1) % 2];
				if (isinv(check, &oL, oL.size()))
				{
					if (pn->g + 1 < check->g)
					{
						check->parent = pn;
						check->g = pn->g + 1;
					}
				}
				else if (!(isinv(check, &oL, oL.size())) && !isinv(check, &cL, cL.size()))
				{
					check->parent = pn;
					check->g = pn->g + 1;
					check->h = abs(check->x - end.x) + abs(check->y - end.y);
					check->f = check->g + check->h;
					oL.push_back(check);

				}
			}

		}
	}
}
