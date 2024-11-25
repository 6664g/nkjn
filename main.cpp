#include<iostream>
#include<vector>
using namespace std;
typedef struct node//节点
{
	int x,y;
	double g, h,f;
	node* parent;
};
bool isinv(node* np, vector<node*>* vp, int si)//判断数组里是否有这个元素
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
	node start,end;//起点 终点
	vector<vector<node>> map;//地图
					
							 
							 //此处为地图，起点，终点的生成




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
			//回shu
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
			//遍历周围八格
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
