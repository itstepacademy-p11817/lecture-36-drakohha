#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>



int main() {
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	int flag_menu = 0;
	char temp = NULL;
	char str[10] = "153735";
	
	do {
		printf("\n Введите номер задания : \n");
		//while (getchar() != '\n');
		scanf_s("%d", &flag_menu);

		if (flag_menu == 1) {
			char mass_1[256] = { 0 };
			char mass_2[256] = { 0 };
			char mass_3[256] = { 0 };
			char str_2[100] = { 0 };
			char str_3[100] = { 0 };
			for (int i = 0; i < 256; i++) {
				mass_1[i] = i;
			}
			int tmp = 255;
			for (int i = 0; i<255; i++) { 
				int t = rand() % tmp;
				mass_2[i] = mass_1[t];
				mass_1[t] = mass_1[tmp - 1];
				--tmp;

			}
			for (int i = 0; i < 256; i++) {
				mass_3[(mass_1[i])] = i;
			}

			for (int i = 0; i < strlen(str); i++) {
				mass_2[i] = mass_1[(str[i])];
			}
			mass_2[(strlen(str))] = '\0';
			printf_s("%s", mass_2);
			FILE *fp;
			fopen_s(&fp, "file1.txt", "w+b");
			if (fp != NULL) {
				int id = 0;
				fseek(fp, 0, SEEK_SET);
				fwrite(mass_2, 1, strlen(mass_2), fp);
				fclose(fp);
			}
			else {
				printf("Файл не открылься");
			}

			fopen_s(&fp, "file1.txt", "rb");
			if (fp != NULL) {
				fseek(fp, 0, SEEK_SET);
				int id = 0;
				printf("\n после дешифрофки \n");
				fread(str_2, 1, strlen(mass_2), fp);
				for (int i = 0; i < strlen(str_2); i++) {
					str_3[i] = mass_3[(str_2[i])];
				}
				str_3[strlen(str_2)] = '\0';
				printf_s("%s", str_3);
				fclose(fp);
			}
			else {
				printf("Что то пошло не так");
			}
		}

		if (flag_menu == 2) {
			printf("Программа сотрудники :");
			struct human_t {
				char name[50];
				char age[2];
				char stage[2];
				char zarplata[10];

			};
			FILE *fp_2;
			fopen_s(&fp_2, "file2.txt", "w+");
			fclose(fp_2);
			char str_2[100] = { 0 };
			struct human_t sotrudniki[100];
			int kol_st = 0;
			int flag_de = 0;
			int id = 0;
			do {
				printf("\n Введите номер действия \n 1-Ввод данных \n 2- Редактирование \n 3-удаление \n 4-поиск \n 5-вывод данных всех \n 6- вывод по заданныи критериям \n");
				scanf_s("%d", &flag_de);
				
				if (flag_de == 1) {
					fopen_s(&fp_2, "file2.txt", "r+");
					fseek(fp_2, 0, SEEK_END);
					if (fp_2 != NULL) {
						
						printf("\n Введите имя сотрудника : ");
						scanf_s("%s", &sotrudniki[id].name);
						fprintf_s(fp_2, sotrudniki[id].name);
						fseek(fp_2, strlen(sotrudniki[id].name), SEEK_CUR);
						fprintf_s(fp_2, " ");
						fseek(fp_2, 1, SEEK_CUR);
						printf("\n Введите возраст сотрудника : ");
						scanf_s("%s", &sotrudniki[id].age);
						fprintf_s(fp_2, sotrudniki[id].age);
						fseek(fp_2, strlen(sotrudniki[id].age), SEEK_CUR);
						fprintf_s(fp_2, " ");
						fseek(fp_2, 1, SEEK_CUR);
						


						fclose(fp_2);
					}
					else {
						printf("файл не октрылься");
					}
					
				}



			} while (flag_de != 0);



		}





	} while (flag_menu != 0);

	return 0;
}