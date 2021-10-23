#include"Head1.h"

void MENU(tree &t)
{
	while(true)
	{
		system("cls");
		int x;
		printf("\n<===========================TUY CHON===========================>");
		printf("\n| 1 : Them 1 NODE");
		printf("\n| 2 : Duyet cay (6 cach duyet)");
		printf("\n| 3 : Dung chuong trinh");
		printf("\n| 4 : Tim cac so nguyen to");
		printf("\n| 5 : Tao cay tu dong trong khoang [a, b]");
		printf("\n| 6 : Tim kiem 1 Node trong cay");
		printf("\n| 7 : Tim cac Node theo dieu kien (3 dieu kien)");
		printf("\n| 8 : Tim Max - Min trong cay (4 tuy chon)");
		printf("\n| 9 : Xoa (2 tuy chon)");
		printf("\n<==============================================================>");
		
		printf("\n\n<====================THONG TIN CAY=============================>");
		printf("\n|\t- Dia chi con tro (ROOT): |%p|",&t);
		printf("\n|\t- Dia chi con tro tro toi (ROOT): |%p|",t);
		printf("\n|\t- Chieu cao cua cay: %d",maxHeight(t));
		printf("\n|\t- Size cua cay: %d",sizeTree(t));
		printf("\n<==============================================================>");
		printf("\n\n\t=> |Nhap tuy chon|: ");
		scanf("%d",&x);
		printf("\n\n\t=> |Ket qua|: ");
		while(x < 1 || x > 9)
		{
			printf("\nNhap sai, nhap lai:");
			scanf("%d",&x);
		}
		switch (x)
		{
			case 1:
				int a;
				printf("\nNhap gia tri muon them:");
				scanf("%d",&a);
				addNode(t,a);
				break;
			
			case 2:
				{
					while(true)
					{
						printf("\n<=================>");
						printf("\n1 : NRL");
						printf("\n2 : NLR - PreOrder");
						printf("\n3 : RNL");
						printf("\n4 : LNR - InOrder - Tang dan");
						printf("\n5 : RLN - Giam dan");
						printf("\n6 : LRN - PostOrder");
						printf("\n7 : Thoat tim kiem");
						printf("\n<=================>");
						
						int x1;
						printf("\nNhap tuy chon: ");
						scanf("%d",&x1);
						printf("\n");
						switch (x1)
						{
							case 1:
								traversalNRL(t);
								if (t == NULL)
								{
									printf("\nCay rong!");
								}
								printf("\n");
								system("pause");
								break;
							case 2:
								traversalNLR(t);
								if (t == NULL)
								{
									printf("\nCay rong!");
								}
								printf("\n");
								system("pause");
								break;
							case 3:
								traversalRNL(t);
								if (t == NULL)
								{
									printf("\nCay rong!");
								}
								printf("\n");
								system("pause");
								break;
							case 4:
								traversalLNR(t);
								if (t == NULL)
								{
									printf("\nCay rong!");
								}
								printf("\n");
								system("pause");
								break;
							case 5:
								traversalRLN(t);
								if (t == NULL)
								{
									printf("\nCay rong!");
								}
								printf("\n");
								system("pause");
								break;
							case 6:
								traversalLRN(t);
								if (t == NULL)
								{
									printf("\nCay rong!");
								}
								printf("\n");
								system("pause");
								break;
						}
						if (x1 == 7)
						{
							break;
						}
						system("cls");
					}
				}
				break;
			
			case 3:
				printf("\nThoat chuong trinh . . . ");
				exit(0);
			
			case 4:
				traversalNLR_Prime(t);
				printf("\n");
				system("pause");
				break;
			
			case 5:
				inputRange(t);
				break;
				
			case 6:
				int xSearch;
				printf("\nNhap gia tri Node ban muon tim: ");
				scanf("%d",&xSearch);
				if (searchNode(t,xSearch) == NULL)
				{
					printf("\nKhong co trong cay !");
				}
				else
				{
					printf("\nTim thay ! Node o dia chi %p \nCau tao Node: |%p|%d|%p|\n",searchNode(t,xSearch),searchNode(t,xSearch)->childLeft,searchNode(t,xSearch)->data,searchNode(t,xSearch)->childRight);
				}
				system("pause");
				break;
				
			case 7:
				{
					while(true)
					{
						printf("\n<======================================>");
						printf("\n| 1: Node co 2 con");
						printf("\n| 2: Node co 1 con");
						printf("\n| 3: Node la Node la (khong co con nao)");
						printf("\n| 4: Thoat tuy chon Dieu kien");
						printf("\n<======================================>");
						int xCondition;
						printf("\nNhap tuy chon: ");
						scanf("%d",&xCondition);
						
						switch (xCondition)
						{
							case 1:
								printf("\nDanh sach Node co 2 con\n");
								fullNode(t);
								printf("\n");
								system("pause");
								break;
							
							case 2:
								printf("\nDanh sach Node co 1 con\n");
								semiNode(t);
								printf("\n");
								system("pause");
								break;
								
							case 3:
								printf("\nDanh sach Node la Node la\n");
								leafNode(t);
								printf("\n");
								system("pause");
								break;
						}
						
						if (xCondition == 4)
						{
							break;
						}
						system("cls");
					}
				}
				break;
				
			case 8:
				{
					while(true)
					{
						printf("\n<================================>");
						printf("\n| 1: Tim Max theo bien cuc bo");
						printf("\n| 2: Tim Max theo tong quat");
						printf("\n| 3: Tim Min theo bien cuc bo");
						printf("\n| 4: Tim Min theo tong quat");
						printf("\n| 5: Thoat tim Max - Min");
						printf("\n<================================>");
						
						int xMM;
						printf("\nNhap tuy chon: ");
						scanf("%d",&xMM);
						
						switch(xMM)
						{
							case 1:
								max(t);
								printf("\nGia tri lon nhat la: %d",Max);
								printf("\n");
								system("pause");
								break;
								
							case 2:
								printf("\nGia tri lon nhat la: %d",anotherMax(t));
								printf("\n");
								system("pause");
								break;
							
							case 3:
								min(t);
								printf("\nGia tri nho nhat la: %d",Min);
								printf("\n");
								system("pause");
								break;
							
							case 4:
								printf("\nGia tri nho nhat la: %d",anotherMin(t));
								printf("\n");
								system("pause");
								break;
						}			
						if (xMM == 5)
						{
							break;	
						}
						system("cls");
					}
				}
				break;
				
			case 9:
				{
					while(true)
					{
						printf("\n<=======================>");
						printf("\n| 1: Xoa ca cay");
						printf("\n| 2: Xoa Node tuy chon");
						printf("\n| 3: Thoat xoa");
						printf("\n<=======================>");
						int xDel;
						printf("\nNhap tuy chon: ");
						scanf("%d",&xDel);
						
						switch (xDel)
						{
							case 1:
								deleteTREE(t);
								if (t == NULL)
								{
									printf("\nXoa thanh cong . . .");
								}
								else
								{
									printf("\nXoa khong thanh cong");
								}
								printf("\n");
								system("pause");
								break;
								
							case 2:
								int xWANT;
								printf("\nNhap gia tri cua Node ban muon xoa: ");
								scanf("%d",&xWANT);
								deleteNODE(t,xWANT);
								if(searchNode(t,xWANT) == NULL)
								{
									printf("\nXoa thanh cong . . .");
								}
								else
								{
									printf("\nXoa khong thanh cong");
								}
								printf("\n");
								system("pause");
								break;
						}
						if (xDel == 3)
						{
							break;
						}
						system("cls");
					}
				}
				break;
		}
	}
}

int main()
{
	tree t;
	createTree(t);
	MENU(t);
	return 0;
}
