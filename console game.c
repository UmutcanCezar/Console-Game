#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>

FILE *fpr, *fpw;
int max;

void gotoxy(int x, int y);
void hidecursor();
void kaybettin()//hedefi tutamay�nca ger�ekle�ecek olay
{
	system("cls");
	printf("Kaybettin!");
}


void cerceve() {//�er�eveyi olu�turdu�umuz yer
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
    int karx = 7, kary = 12;//karakterin ba�lang�� noktalar�
    int hedx = 2 + rand() % 15, hedy = 2;//hedefin ba�lang�� noktalar�
    int tus,i=1;
    int puan = 0,can=5;

    gotoxy(karx, kary);
    printf("_");

    hidecursor();

    while (1) {//oyun ba�l�yor
        fpr = fopen("max.txt", "r");//max puan� kaydediyoruz
        fscanf(fpr, "%d", &max);//max puan� oyuna yans�t�yoruz
        fclose(fpr);

        gotoxy(hedx, hedy);
        printf("  ");

        // Hedefin s�rekli olarak a�a�� do�ru hareket etmesi
        hedy++;

         if  (hedy == kary && hedx == karx) {
            if (hedy == kary && hedx == karx) 
			{
			puan++;
			
			}
            // Yeni hedefin rastgele konumland�r�lmas�
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
		

        Sleep(110);  // oyun h�z�n� ayarl�yoruz
        tus = kbhit();  //hedefin s�rekli d��mesini sa�layan bekleme i�lemi olmadan klavyeyi denetleyen sat�r

        if (tus) {
            tus = getch();  //basaca��m�z tu�lar�n hangi i�lemi ger�ekle�tirece�ini belirliyoruz
            switch (tus) {
                case 97:  // 'a' tu�u
                    if (karx != 2) {
                        gotoxy(karx, kary);
                        printf(" ");
                        gotoxy(--karx, kary);
                        printf("_");
                    }
                    break;
                case 100:  // 'd' tu�u
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
