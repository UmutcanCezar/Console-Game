#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>

FILE *fpr, *fpw;
int max;

void gotoxy(int x, int y);
void hidecursor();
void kaybettin()//hedefi tutamayýnca gerçekleþecek olay
{
	system("cls");
	printf("Kaybettin!");
}


void cerceve() {//çerçeveyi oluþturduðumuz yer
    int i, j;
    for (i = 0; i < 15; i++) {
        printf("%c", 219);
        if (i == 0 || i == 14)
            for (j = 0; j <15 ; j++) printf("%c", 219);
        else
            for (j = 0; j <15 ; j++)
                printf(" ");
        printf("%c", 219);
        printf("\n");
    }
}

int main() {
    cerceve();
    int karx = 7, kary = 12;//karakterin baþlangýç noktalarý
    int hedx = 2 + rand() % 15, hedy = 2;//hedefin baþlangýç noktalarý
    int tus,i=1;
    int puan = 0,can=5;

    gotoxy(karx, kary);
    printf("_");

    hidecursor();

    while (1) {//oyun baþlýyor
        fpr = fopen("max.txt", "r");//max puaný kaydediyoruz
        fscanf(fpr, "%d", &max);//max puaný oyuna yansýtýyoruz
        fclose(fpr);

        gotoxy(hedx, hedy);
        printf("  ");

        // Hedefin sürekli olarak aþaðý doðru hareket etmesi
        hedy++;

         if  (hedy == kary && hedx == karx) {
            if (hedy == kary && hedx == karx) 
			{
			puan++;
			
			}
            // Yeni hedefin rastgele konumlandýrýlmasý
            hedx = 2 + rand() % 13;
            hedy = 2;
        }if(hedy>13)
        {can = can-1;
        hedx = 2 + rand() % 13;
        hedy = 2;
		}if(can<0) {
		
			kaybettin();
		
			break;
		}

        if (puan > max) {
            fpw = fopen("max.txt", "w");
            fprintf(fpw, "%d", puan);
            fclose(fpw);
        }

        gotoxy(hedx, hedy);
        printf("|");

        gotoxy(20, 1);
        printf("Puan: %d", puan);
        gotoxy(20, 2);
        printf("Max Puan : %d", max);
		gotoxy(20, 3);
        printf("can : %d", can);
		

        Sleep(110);  // oyun hýzýný ayarlýyoruz
        tus = kbhit();  //hedefin sürekli düþmesini saðlayan bekleme iþlemi olmadan klavyeyi denetleyen satýr

        if (tus) {
            tus = getch();  //basacaðýmýz tuþlarýn hangi iþlemi gerçekleþtireceðini belirliyoruz
            switch (tus) {
                case 97:  // 'a' tuþu
                    if (karx != 2) {
                        gotoxy(karx, kary);
                        printf(" ");
                        gotoxy(--karx, kary);
                        printf("_");
                    }
                    break;
                case 100:  // 'd' tuþu
                    if (karx != 15) {
                        gotoxy(karx, kary);
                        printf(" ");
                        gotoxy(++karx, kary);
                        printf("_");
                    }
                    break;
            }
        }
    }
    return 0;
}

void hidecursor() {
    CONSOLE_CURSOR_INFO cursor_info = {1, 0};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void gotoxy(int x, int y) {
    COORD Pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
