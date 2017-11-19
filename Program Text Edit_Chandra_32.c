#include <stdio.h>
#include <stdlib.h>


typedef struct data
{
	char huruf;
	struct data *next;
	struct data *prev;
}node;
node *baru, *head=NULL, *tail=NULL, *temp, *hapus, *cetak, *move;

int pil,jmlh, x=0, in=0,maks,status=0;
int main()
{
	printf(" PROGRAM TEXT EDIT\n\n\n");
	while(x<1)
	{
		printf("Masukkan Maksimal Karakter : ");
		scanf("%d",&maks);x++;
		system("cls");
	}
	printf("Pilih Menu Di Bawah :\n\t1. Printf\n\t2. Add Text\n\t3. Delete Text\n\t4. Shift Left\n\t5. Shift Right");
	printf("\nKetik Pilihan : "); scanf("%d",&pil);
	switch(pil)
	{
		case 1 :
			{
				system("cls");
				printf("\tCETAK KARAKTER");
				icetak();
			}
			break;
		case 2 :
			{
				system("cls");
				printf("\tINPUT KARAKTER");
				tambah();

			}
			break;
		case 3 :
			{
				system("cls");
			if(head != NULL)
				ihapus();
				else
				{
					printf("Data Kosong !!");
					getch();
					system("cls");
				}
				main();
			}
			break;
		case 4 :
			{
				system("cls");
				if(head != NULL)
				kiri();
				else
				{
					printf("Data Kosong !!");
					getch();
					system("cls");
				}
				main();
			}
			break;
		case 5 :
			{
				system("cls");
				if(head != NULL)
				kanan();
				else
				{
					printf("Data Kosong !!");
					getch();
					system("cls");
				}
				main();

			}
			break;
		default :
			{
				printf(" INPUTAN SALAH !! ");
				system("cls"); getch ();
				main();
			}
	}
	return 0;
}

tambah()
{
	if(in<maks)
	{
		baru = (node *)malloc(sizeof(node));
		printf("\nMasukkan Karakter :"); fflush(stdin);
		scanf("%c",&baru->huruf);
		baru->next=NULL;
		baru->prev = NULL;
		if(head==NULL)
		{
			head=baru;
			move=baru;
		}
		else
		{
			if(status == 0)
			{
				if(move->next != NULL)
				{
					move->next->prev = baru;
				}
				baru->next = move->next;
				move->next = baru;
				baru->prev = move;
				move = move->next;
			}
			else
			{
				if(move->prev != NULL)
				{
					move->prev->next = baru;
				}
				else
				{
					head = baru;
				}
				baru->next = move;
				baru->prev = move->prev;
				move->prev = baru;
			}
		}
		in++;
	}
		system("cls");
		main();
}

kiri()
{
	if(status == 0)
	status = 1;
	else if(move->prev!=NULL)
	{
		move = move->prev;
	}
	system("cls");
	getch();
}

kanan ()
{

	if(status == 1)
	status = 0;
	else if(move->next != NULL)
	{
		move = move->next;
	}
	system("cls");
	getch();
}

icetak()
{
	cetak=head;
	if(head==NULL)
	{
		printf("\n\nDATA KARAKTER KOSONG !!");
		getch(); system("cls");
		main();
	}
	printf("\n Kata : ");
	while(cetak!=NULL)
	{
		printf(" %c",cetak->huruf);
		cetak=cetak->next;
	}
	getch(); system("cls");
	main();
}

ihapus()
{
	if(status == 0)
	{
		hapus = move;
		printf("Karakter %c dihapus\n",hapus->huruf);
		getch();
		if(move == head)
		{
			move = move->next;
			hapus = head;
			head = move;
			if(head != NULL)
			head->prev = NULL;
		}
		else
		{
			move = move->prev;
			move->next = hapus->next;
			if(hapus->next != NULL)
			hapus->next->prev = move;
		}
		free(hapus);
	}
	else if(move != head)
	{
		hapus = move->prev;
		printf("Karakter %c dihapus\n",hapus->huruf);
		getch();
		{
			if(hapus->prev != NULL)
			{
				hapus->prev->next = move;
				move->prev = hapus->prev;
			}
			else
			{
				move->prev = NULL;
				head = move;
			}
		}
		free(hapus);
	}
	system("cls");
}
