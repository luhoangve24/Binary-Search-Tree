#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
//-----------------------Khai bao thu vien------------------------------
/*Cau tao 1 NODE				Minh hoa:			(ROOT)
struct NODE									|05DAXc2|data|07xBMs9|
{												|     			\               
	int data;					(Left)	|NULL|data|09AB2x7|	   \NULL\data\NULL\ (Right)
	struct NODE *childLeft;						      \                                          
	struct NODE *childRight;                \NULL\data\NULL\ (Leaf)         
};*/
struct NODE
{              
	int data;				
	struct NODE *childLeft;                                       
	struct NODE *childRight;         
};
typedef struct NODE node;

typedef node * tree;
//Khoi tao Cay nhi phan
void createTree(tree &t)
{
	t = NULL;
}

//Them Node
void addNode(tree &t, int x)
{
	if (t == NULL)
	{
		node *p;
		p = (node*)malloc(sizeof(node));//Cap phat vung nho dong cho Node
		if (p == NULL)
		{
			printf("\nKhong thanh cong");
			return;
		}
		p->data = x;
		p->childLeft = p->childRight = NULL;
		t = p; //Cap nhat lai con tro toi Node
	}
	else
	{
		if (t->data > x)
		{
			addNode(t->childLeft,x);//De quy lai voi tham so 1 truyen vao la con tro tro toi cay ben trai bac n + 1
		}
		else if (t->data < x) //Khong duoc dung "=" vi trong cay Nhi phan, khong duoc luu cac phan tu trung nhau
		{
			addNode(t->childRight,x);//Tuong tu, de quy lai voi tham so truyen vao la con tro tro toi cay ben phai bac n + 1
		}
	}
}

//-------------------------------------------------------------------DUYET CAY----------------------------------------------------------------------------
void traversalNLR(tree t) //Duyet theo kieu Node - Left - Right - PreOrder
{
	if (t != NULL)
	{
		printf("%d ",t->data);
		traversalNLR(t->childLeft); //De quy
		traversalNLR(t->childRight);
	}
}

void traversalNRL(tree t)//Node - Right - Left
{
	if (t != NULL)
	{
		printf("%d ",t->data);
		traversalNRL(t->childRight);
		traversalNRL(t->childLeft);
	}
}

void traversalRNL(tree t)//Right - Node - Left | Xuat cac gia tri giam dan
{
	if (t != NULL)
	{
		traversalRNL(t->childRight);
		printf("%d ",t->data);
		traversalRNL(t->childLeft);
	}
}

void traversalLNR(tree t)//Left - Node - Right | Xuat cac gia tri tang dan
{
	if (t != NULL)
	{
		traversalLNR(t->childLeft);
		printf("\n|%p|%d|%p| , dia chi %p, con tro %p",t->childLeft,t->data,t->childRight,t,&t);
		traversalLNR(t->childRight);
	}
}

void traversalRLN(tree t)//Right - Left - Node
{
	if (t != NULL)
	{
		traversalRLN(t->childRight);
		traversalRLN(t->childLeft);
		printf("%d ",t->data);
	}
}

void traversalLRN(tree t)//Left - Right - Node
{
	if (t != NULL)
	{
		traversalLRN(t->childLeft);
		traversalLRN(t->childRight);
		printf("%d ",t->data);
	}
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------

//Tim kiem so Nguyen to
int isPrime(int x)
{
	if (x <= 1)
	{
		return 0;
	}
	else
	{
		if (x == 2 || x == 3)
		{
			return 1;
		}
		else
		{
			for (int i = 2; i <= sqrt(x); i++)
			{
				if (x % i == 0)
				{
					return 0;
				}
			}
			return 1;
		}
	}
}

void traversalNLR_Prime(tree t)//xuat so Nguyen to theo kieu Node - Left - Right
{
	if (t != NULL)
	{
		if(isPrime(t->data) == 1)
		{
			printf("%d ",t->data);
		}
		traversalNLR_Prime(t->childLeft);
		traversalNLR_Prime(t->childRight);
	}
}

void inputRange(tree &t)//tao cay tu mang so nguyen cho truoc trong khoang [a, b]
{
	int a, b;
	printf("\nNhap a, b cho khoang [a, b]: ");
	scanf("%d %d",&a,&b);
	for(int i = a; i <= b; i++)
	{
		addNode(t,i);
	}
}

node *searchNode(tree t, int x)//Tim kiem 1 Node
{
	if (t == NULL)
	{
		return NULL;	
	}
	else
	{
		if ( x == t->data )
		{
			return t;
		}
		else if ( x > t->data )
		{
			searchNode(t->childRight,x);
		}
		else
		{
			searchNode(t->childLeft,x);
		}
	}
}

void fullNode(tree t) //Xuat ra Node co 2 con theo kieu Node - Left - Right
{
	if (t != NULL)
	{
		if (t->childLeft != NULL && t->childRight != NULL)
		{
			printf("%d ", t->data);
		}
		fullNode(t->childLeft);
		fullNode(t->childRight);
	}
}

void semiNode(tree t) //Xuat ra cac Node co 1 con theo kieu Node - Left - Right
{
	if (t != NULL)
	{
		if (t->childLeft != NULL && t->childRight == NULL || t->childLeft == NULL && t->childRight != NULL)
		{
			printf("%d ", t->data);
		}
		semiNode(t->childLeft);
		semiNode(t->childRight);
	}
}

void leafNode(tree t) //Xuat ra cac Node la la cua cay theo kieu Node - Left - Right
{
	if (t != NULL)
	{
		if (t->childLeft == NULL && t->childRight == NULL)
		{
			printf("%d ", t->data);
		}
		leafNode(t->childLeft);
		leafNode(t->childRight);
	}
}

//------------------------------------------------------------------------------------------TIM MAX - MIN------------------------------------------------------------------
//Cach 1: Tim dua vao bien toan cuc (global variable), cach nay rat han che, chi dung cho cac kieu so
int Max = INT_MIN; //INT_MIN co trong thu vien limits.h
void max(tree t) //Xuat ra Node mang gia tri lon nhat, duyet theo kieu Node - Left - Right
{
	if (t != NULL)
	{
		if (t -> data > Max)
		{
			Max = t->data;
		}
		max(t->childLeft);
		max(t->childRight);
	}
}

int Min = INT_MAX;//tuong tu Max
void min(tree t)
{
	if(t != NULL)
	{
		if (t -> data < Min)
		{
			Min = t->data;
		}
		min(t->childLeft);
		min(t->childRight);
	}
}
//------------------------------------------//
//Cach 2: Lam tong quat
int anotherMax(tree t) // Tan dung tinh chat cua cay Nhi phan, Node co gia tri lon nhat se nam phia ben phai cung cua cay
{
	if (t == NULL)
	{
		return NULL;
	}
	else
	{
		if (t->childRight == NULL)
		{
			return t->data;
		}
		else
		{
			return anotherMax(t->childRight);
		}
	}
}

int anotherMin(tree t) // Tuong tu Min, gia tri nho nhat nam ben phia trai nhat cua cay
{
	if (t == NULL)
	{
		return NULL;
	}
	else
	{
		if (t->childLeft == NULL)
		{
			return t->data;
		}
		else
		{
			return anotherMin(t->childLeft);
		}
	}	
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------XOA NODE---------------------------------------------------------------------------------------------------

void deleteTREE(tree &t) //Xoa ca cay
{
	if (t == NULL)
	{
		return;
	}
	deleteTREE(t->childLeft);
	deleteTREE(t->childRight);
	printf("\nXoa gia tri %d",t->data);
	free(t); // Mac du xoa roi nhung con tro se chua dia chi cua no
	t = NULL; // Nen ta phai ep no bang NULL
}

void leftMostchild(tree &t, tree &sub) //Di tim Node ben trai nhat cua cay ben phai la con cua Node can xoa
{
	if (sub->childLeft != NULL) // Duyet den Node trai nhat cua cay ben phai la con cua Node can xoa
	{
		leftMostchild(t,sub->childLeft); // De quy cho den khi tim duoc Node trai nhat
	}
	else // Tim duoc Node trai nhat 
	{
		t->data = sub->data; // Tim duoc roi, cap nhat lai data Node can xoa
		t = sub; // Cho cho con tro node can xoa tro den Node thay the, thoat ra se xoa Node do
		sub = NULL; // Cap nhat lai lien ket giua cha va Node can xoa sau khi bi xoa (NULL)
	}
}

void deleteNODE(tree &t, int x) //Xoa 1 Node
{
	if (t == NULL) // Truong hop cay rong
	{
		return;
	}
	else // Truong hop cay khong rong
	{
		if (x > t->data) // Neu x lon hon Node hien tai, duyet sang cay con phai
		{
			deleteNODE(t->childRight,x);
		}
		else if (x < t->data) // Neu x nho hon Node hien tai, duyet sang cay con trai
		{
			deleteNODE(t->childLeft,x);
		}
		else // Neu x = Node hien tai
		{
			node *tmp_del = t;
			if (t->childRight == NULL) // Truong hop neu Node can xoa co 1 Node con ben trai
			{
				t = t->childLeft; // Cap nhat lai lien ket cho Node cha cua Node can xoa
			}
			else if (t->childLeft == NULL) // Truong hop neu Node can xoa co 1 Node con ben phai
			{
				t = t->childRight; // Tuong tu, cap nhat lai
			}
			else // truong hop la Node co ca 2 con, tuong tu (t->childLeft != NULL && t->childRight != NULL)
			{
				leftMostchild(tmp_del, t->childRight); // Tim ra Node trai nhat cua cay con phai
			}
			free(tmp_del); // Giai phong
		}
	}
		
}

// Mo rong
int maxHeight(tree t) // Tim chieu cao cua cay
{					// Y tuong : Tim do cao max cua cay con ben trai, max cua cay ben phai, so sanh 2 max roi + 1 (cho nut goc) 
	if (t == NULL) // Truong hop cay rong
	{
		return 0;
	}
	else
	{
		// Tim chieu dai lon nhat cho cac cay con
		int maxLeft = maxHeight(t->childLeft);
		int maxRight = maxHeight(t->childRight);
		// Tra ve ket qua
		if (maxLeft > maxRight)
		{
			return maxLeft + 1;
		}
		else
		{
			return maxRight + 1;
		}
	}
	// Tham khao: "geeksforgeeks.org"
}

int sizeTree(tree t) // Tim size cua cay
{
	if (t == NULL)
	{
		return 0;
	}
	else
	{
		return sizeTree(t->childLeft) + 1 + sizeTree(t->childRight);
	}
	// Tham khao: "geeksforgeeks.org"
}
