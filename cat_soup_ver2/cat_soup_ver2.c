#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

#define ROOM_WIDTH 10
#define HME_POS 1
#define BWL_PO (ROOM_WIDTH -2)

int main() {

	printf("****�߿��̿� ����****\n");
	printf("         /\\_/\\\n");
	printf("  /\\\    / o o \\\n");
	printf(" //\\\\\   \\~(*)~/\n");
	printf(" `   \\/    ^ /\n");
	printf("     |  \\|| ||\n");
	printf("     \\ ' || ||\n");
	printf("      \\) ()-())\n");

	printf("�߿����� �̸��� �˶��Դϴ�\n");

	Sleep(500); // 2.5�� ���
	system("cls");

	int soup = 0; //������ ����
	int cp = 0; // CP ����Ʈ
	int feel = 3; // �˶��� ���
	int feel_tmp = 0; // �˶��� ��� �ӽ�����
	int relationship = 2;// ģ�е�
	int cat = 1;// �����
	int dice;//�ֻ���
	int foot; // ���ڱ�
	int choose ;
	int turn = 0;
	int s = 0; // ��ũ��ó ��ġ
	int tower = 0; // Ÿ�� ��ġ
	int up, down; // ����� �Ÿ� �Ǻ��ϴ� ����
	

	srand((unsigned int)time(NULL));

	while (1) {
		turn++;
		printf("==================== �������===================\n");
		printf("������� ���� ����: %d��\n", soup);
		printf("CP: %d����Ʈ\n", cp);
		printf("�˶��� ���(0~3): %d\n", feel);
		if (feel == 0) {
			printf("����� �ſ� ���޴ϴ�.\n");
		}
		else if (feel == 1) {
			printf("�ɽ����մϴ�.\n");
		}
		else if (feel == 2) {
			printf("�Ļ��� �����ϴ�.\n");
		}
		else if (feel == 3) {
			printf("  ������ �θ��ϴ�.\n");
		}
		printf("������� ����(0~4): %d\n", relationship);


		if (relationship == 0) {
			printf("�翡 ���� ������ �Ⱦ��մϴ�.\n");
		}
		else if (relationship == 1) {
			printf("���� ���Ǳ� ����Դϴ�.\n");
		}
		else if (relationship == 2) {
			printf("  �׷����� ������ �����Դϴ�.\n");
		}
		else if (relationship == 3) {
			printf("�Ǹ��� ����� ���� �ް� �ֽ��ϴ�.\n");
		}
		else if (relationship == 4) {
			printf("���� �������Դϴ�.\n");
		}

		printf("================================================\n");
		
		if (turn== 3) {
			printf("���� ����Ʈ �߻�!\n");
			printf("12 X 12 = ?\n");
			printf("'?'�� ���ü��ڸ� �����ÿ�.");
			scanf_s("%d", &choose);
			
			if (choose == 144) {
				printf("�����Դϴ�.\n");
				printf("CP�� 5�ö󰩴ϴ�.\n");
				cp += 5;
			}
			else
				printf("Ʋ�Ƚ��ϴ�.\n������ 144�Դϴ�.\n");

		}







		printf("6-%d: �ֻ��� ���� %d �����̸� �׳� ����� �������ϴ�. \n", relationship, 6 - relationship);
		printf("�ֻ����� �����ϴ�. �Ǹ���...\n");

		dice = rand() % 6 + 1;
		printf("%d(��)�� ���Խ��ϴ�.\n", dice);

		foot = cat;

		if (dice <= 6 - relationship) {
			feel_tmp = feel;
			if (feel > 0) {
				feel--;
			}
			printf("�˶��� ����� �������ϴ�: %d->%d\n", feel_tmp, feel);

		}


		if (feel == 0) {
			printf("����� �ſ� ���� ������(��) ������ ���մϴ�.\n");
			if (cat > 1) {
				cat--;
			}
		}
		else if (feel == 1) {
			if (s != 0 && tower != 0) {
				if (cat != s && cat != tower) {
					if (cat - s > 0 && cat - tower > 0)
						cat--;
					else if (cat - s < 0 && cat - tower < 0)
						cat++;
					else {
						if (tower > s) {
							up = tower;
							down = s;
							choose = 1;
						}
						else {
							up = s;
							down = tower;
							choose = 0;
						}

						up = up - cat;
						down = cat - down;

						if (up < down) {
							cat++;
							if (choose == 1)
								printf("������(��) �ɽ��ؼ� Ÿ�������� �̵��մϴ�.\n");
							else
								printf("������(��) �ɽ��ؼ� ��ũ��ó������ �̵��մϴ�.\n");
						}
						else if (down < up) {
							cat--;
							if (choose == 0)
								printf("������(��) �ɽ��ؼ� Ÿ�������� �̵��մϴ�.\n");
							else
								printf("������(��) �ɽ��ؼ� ��ũ��ó������ �̵��մϴ�.\n");
						}
						else {
							cat++;
							printf("������(��) �ɽ��ؼ� �̵��մϴ�.\n");
						}
					}
				}

			}
			else if (tower != 0) {
				if (cat > tower)
					cat--;
				else if (cat < tower)
					cat++;
				printf("������(��) �ɽ��ؼ� Ÿ�������� �̵��մϴ�.\n");
			}
			else if (s != 0) {
				if (cat > s)
					cat--;
				else if (cat < s)
					cat++;
				printf("������(��) �ɽ��ؼ� ��ũ��ó������ �̵��մϴ�.\n");
			}
			else {
				printf("��Ÿ��� ��� ����� �ſ� �������ϴ�.\n");
				if (feel > 0)
					feel--;
			}
		}
		else if (feel == 2) {
			printf("���Ĵ� ������� �Ļ��� ���� �ֽ��ϴ�.\n");
		}
		else if (feel == 3) {
			printf("���Ĵ� ������ �θ��� ������ ���鷯 ���ϴ�.\n");
			if (cat < BWL_PO) {
				cat++;
			}
		}
		

			if (cat == BWL_PO) {
				soup++;
				dice = rand() % 3 + 1;
				switch (dice) {

				case 1:
					printf("���İ� ���ڼ����� ��������ϴ�.\n");
					break;
				case 2:
					printf("���İ� ����̼����� ��������ϴ�.\n");
					break;
				case 3:
					printf("���İ� ����ݸ������� ��������ϴ�.\n");
					break;
				}
				printf("������� ���� ����: %d\n", soup);
			}
			if (cat == HME_POS) {

			}

			for (int i = 0; i < ROOM_WIDTH; i++) {
				printf("#");
			}

			printf("\n");

			for (int i = 0; i < ROOM_WIDTH; i++) {
				if (i == 1)
					printf("H");
				else if (i == 0)
					printf("#");
				else if (ROOM_WIDTH - 1 == i)
					printf("#");
				else if (i == BWL_PO)
					printf("B");
				else
					printf(" ");
			}

			printf("\n");

			for (int i = 0; i < ROOM_WIDTH; i++) {
				if (i == 0)
					printf("#");
				else if (ROOM_WIDTH - 1 == i)
					printf("#");
				else if (i == cat)
					printf("C");
				else if (i == foot)
					printf(".");
				else
					printf(" ");
			}

			printf("\n");

			for (int i = 0; i < ROOM_WIDTH; i++) {
				printf("#");
			}

			printf("\n");



			Sleep(500); //0.5�� ���

			printf("� ��ȣ�ۿ��� �Ͻðڽ��ϱ�?    0. �ƹ��͵� ���� ����    1. �ܾ��ֱ�\n>> ");
			scanf_s("%d", &choose);

			while (choose != 0 && choose != 1) {
				printf(">> ");
				scanf_s("%d", &choose);
			}

			switch (choose) {
			case 0:
				printf("�ƹ��͵� ���� ����\n");
				printf("4/6�� Ȯ���� ģ�е��� �������ϴ�.\n");
				printf("�ֻ����� �����ϴ�. �Ǹ���...\n");
				dice = rand() & 6 + 1;
				printf("%d�� ���Խ��ϴ�.\n", dice);
				if (dice <= 4) {
					printf("ģ�е��� �������ϴ�.\n");
					if (relationship > 0) {
						relationship--;
					}
				}
				else {
					printf("�����̵� ģ�е��� �������� �ʾҽ��ϴ�.\n");
				}
				break;
			case 1:
				printf("�˶��� ���� �ܾ��־����ϴ�.\n");
				printf("2/6�� Ȯ���� ģ�е��� �������ϴ�.\n");
				printf("�ֻ����� �����ϴ�. �Ǹ���...\n");
				dice = rand() % 6 + 1;
				printf("%d�� ���Խ��ϴ�.\n", dice);
				if (dice >= 5) {
					printf("ģ�е��� �������ϴ�\n");
					if (relationship <= 3) {
						relationship++;
					}
				}
				else {
					printf("ģ�е��� �״���Դϴ�.\n");
				}
				break;
			}
			printf("���� ģ�е� : %d\n", relationship);
			Sleep(2500);
			system("cls");
		}

		return 0;
	}