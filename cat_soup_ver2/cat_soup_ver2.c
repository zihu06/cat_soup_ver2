#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

#define ROOM_WIDTH 10
#define HME_POS 1
#define BWL_PO (ROOM_WIDTH -2)

int main() {
	int soup = 0; //������ ����
	int CP = 0; // CP ����Ʈ
	int feel = 3; // �˶��� ���
	int feel_tmp = 0; // �˶��� ��� �ӽ�����
	int relationship = 2;// ģ�е�
	int cat = 1;// �����
	int dice;//�ֻ���
	int foot; // ���ڱ�
	int choose = 5; // ������
	int turn = 0; // �� ��
	int S_POS = 0; // ��ũ��ó ��ġ
	int T_POS = 0; // ĹŸ�� ��ġ
	int up, down; // �Ÿ� �� ����
	int answer = 0; // ��������Ʈ ����
	int rat = 0;
	int laser = 0;
	int scratcher = 0;
	int tower = 0;



	srand((unsigned int)time(NULL));

	printf("****�߿��̿� ����****\n");
	printf("         /\\_/\\\n");
	printf("  /\\\    / o o \\\n");
	printf(" //\\\\\   \\~(*)~/\n");
	printf(" `   \\/    ^ /\n");
	printf("     |  \\|| ||\n");
	printf("     \\ ' || ||\n");
	printf("      \\) ()-())\n");
	printf("�߿����� �̸��� �˶��Դϴ�\n");

	Sleep(500); 
	system("cls");

	
	

	while (1) {
		turn++;
		printf("==================== �������===================\n");
		printf("������� ���� ����: %d��\n", soup);
		printf("CP: %d����Ʈ\n", CP);
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
		
		if (turn == 3) {
			printf("��������Ʈ �߻�!\n");
			printf("12 X 12 = ?\n");
			printf("'?'�� ���� ���� ��������\n");
			scanf_s("%d", &answer);
			if (answer == 144) {
				printf("�����Դϴ�! CP�� 10����Ʈ �����մϴ�.\n");
				CP += 10;
			}
			else {
				printf("Ʋ�Ƚ��ϴ�. CP�� 5����Ʈ �����մϴ�.\n");
				if (CP >= 5) {
					CP -= 5;
				}
				else {
					CP = 0;
				}
			}
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

		switch (feel) {
		case 0:
			printf("����� �ſ쳪�� ���Ĵ� ���������մϴ�.\n");
			cat--;
			break;
		case 1:
			if (S_POS != 0 && T_POS != 0) {
				if (cat != S_POS && cat != T_POS) {
					if (cat - S_POS > 0 && cat - T_POS > 0)
						cat--;
					else if (cat - S_POS < 0 && cat - T_POS < 0)
						cat++;
					else {
						if (T_POS > S_POS) {
							up = T_POS;
							down = S_POS;
							choose = 1;
						}
						else {
							up = S_POS;
							down = T_POS;
							choose = 0;
						}

						up = up - cat;
						down = cat - down;

						if (up > down) {
							cat++;
							if (choose == 1)
								printf("������(��) �ɽ��ؼ� Ÿ�������� �̵��մϴ�.\n");
							else
								printf("������(��) �ɽ��ؼ� ��ũ��ó������ �̵��մϴ�.\n");
						}
						else if (down > up) {
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
			else if (T_POS != 0) {
				if (cat > T_POS)
					cat--;
				else if (cat < T_POS)
					cat++;
				printf("������(��) �ɽ��ؼ� Ÿ�������� �̵��մϴ�.\n");
			}
			else if (S_POS != 0) {
				if (cat > S_POS)
					cat--;
				else if (cat < S_POS)
					cat++;
				printf("������(��) �ɽ��ؼ� ��ũ��ó������ �̵��մϴ�.\n");
			}
			else {
				printf("��Ÿ��� ��� ����� �ſ� �������ϴ�.\n");
				if (feel > 0)
					feel--;
			}
			break;
		case 2:
			printf("������(��) ������� �Ļ��� �����ֽ��ϴ�.\n");
			break;
		case 3:
			printf("������(��) ������ �θ��� ������ ���鷯���ϴ�.\n");
			cat++;
			break;
		}

		if (cat == HME_POS && cat == foot && turn != 1) {
			printf("������(��) �ڽ��� ������ ������� �����ϴ�.\n");
			if (feel < 3)
				feel++;
		}

		if (cat == BWL_PO) {
			soup++;
			dice = rand() % 3 + 1;
			if (dice == 1)
				printf("������(��) ���� ������ ��������ϴ�!\n");
			else if (dice == 2)
				printf("������(��) ����� ������ ��������ϴ�!\n");
			else
				printf("������(��) ����ݸ� ������ ��������ϴ�!\n");

			printf("������� ���� ����: %d\n", soup);
		}
		
		if (cat == S_POS) {
			printf("������(��) ��ũ��ó�� �ܰ� ��ҽ��ϴ�.\n");
			if (feel == 3)
				printf("����� ���� ���������ϴ�: %d->%d\n", feel, feel);
			else {
				feel++;
				printf("����� ���� ���������ϴ�: %d->%d\n", feel - 1, feel);
			}
		}
		else if (cat == T_POS) {
			printf("������(��) ĹŸ���� �پ�ٴմϴ�.\n");
			if (feel > 1) {
				printf("����� ���� ���������ϴ�: %d->3\n", feel);
				feel = 3;
			}
			else {
				feel += 2;
				printf("������������������ϴ�: %d->%d\n", feel - 2, feel);
			}
		}
		Sleep(500);

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
				else if (i == S_POS)
					printf("S");
				else if (i == T_POS)
					printf("T");
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

			int interaction;

			printf("� ��ȣ�ۿ��� �Ͻðڽ��ϱ�?\n");

			printf("0. �ƹ��͵� ���� ����\n");
			printf("1. �ܾ��ֱ�\n");
			if (rat == 1 && laser == 0) {
			printf("2. �峭�� ��� ����ֱ�");
			}
			if (laser == 1 && rat == 0) {
				printf("2. ������ �����ͷ� ����ֱ�\n");
			}
			if (rat == 1 && laser == 1) {
				printf("2. �峭�� ��� ����ֱ�\n");
				printf("3. ������ �����ͷ� ����ֱ�\n");
			}

			while (1) {
				printf(">>");
				scanf_s("%d", &interaction);
				getchar();

				if (interaction == 0) {
					printf("�ƹ� �͵� ���� �ʽ��ϴ�.\n");
					if (feel > 0) {
						printf("������ ����� ���������ϴ�: %d->%d\n",feel - 1);
						feel--;
					}
					else {
						printf("����� �����Դϴ�.\n");
					}
					printf("ģ�е��� �ֻ����� ������ ���� 5 �����̸� 1 ����\n");

					int dice = (rand() % 6) + 1;
					printf("%d(��)�� ���Խ��ϴ�!\n", dice);

					if (dice == 6) {
						printf("������ ģ�е��� �������� �ʾҽ��ϴ�.");
					}
					else {
						if (relationship > 0) {
							relationship--;
							printf("������� ���谡 �������ϴ�.");
						}
						else {
							printf("ģ�е��� �����Դϴ�.");
						}
					}
					break;
				}
				else if (interaction == 1) {
					printf("������ ���� �ܾ��־����ϴ�.\n");
					printf("������ ����� �״���Դϴ� : % d\n",feel);
					printf("ģ�е��� �ֻ��� 5 �̻��̸� 1 ����\n");

					int dice = (rand() % 6) + 1;
					printf("%d(��)�� ���Խ��ϴ�!\n", dice);

					if (dice == 5 || dice == 6) {
						if (relationship < 4) {
							printf("ģ�е��� �������ϴ�.");
							relationship++;
						}
						else {
							printf("ģ�е��� �ֻ��Դϴ�.");
						}
					}
					else {
						printf("ģ�е��� �״���Դϴ�.");
					}
					break;
				}
				else if (interaction == 2) {
					if ((rat == 1 && laser == 0) || (rat == 1 && laser == 1)) {
						printf("�峭�� ��� ���Ŀ� ����־����ϴ�.\n");
						if (feel < 3) {
							printf("������ ����� ���� ���������ϴ� : % d -> % d\n",feel,feel + 1);
							feel++;
						}
						else {
							printf("������ ����� �ֻ��Դϴ� : % d\n",feel);
						}
						printf("ģ�е��� �ֻ��� 4 �̻��̸� 1 ����\n");

						int dice = (rand() % 6) + 1;
						printf("%d(��)�� ���Խ��ϴ�!\n", dice);

						if (dice >= 4) {
							if (relationship < 4) {
								printf("ģ�е��� �������ϴ�.");
								relationship++;
							}
							else {
								printf("ģ�е��� �ֻ��Դϴ�.");
							}
						}
						else {
							printf("ģ�е��� �״���Դϴ�.");
						}
						break;
					}
					else if (rat == 0 && laser == 1) {
						printf("������ �����ͷ� ���Ŀ� �ų��� ��� �־����ϴ�.\n");
						if (feel == 3) {
							printf("������ ����� �ֻ��Դϴ�: %d\n", feel);
						}
						else if (feel == 2) {
							printf("������ ����� �� ���������ϴ�: %d -> %d\n",feel, feel + 1);
							feel++;
						}
						else {
							printf("%s�� ����� �� ���������ϴ�: %d -> %d\n", feel, feel + 2);
							feel += 2;
						}
						printf("ģ�е��� �ֻ��� 2 �̻��̸� 1 ����\n");
						int dice = (rand() % 6) + 1;
						printf("%d(��)�� ���Խ��ϴ�!\n", dice);
						if (dice >= 2) {
							if (relationship < 4) {
								printf("ģ�е��� �������ϴ�.");
								relationship++;
							}
							else {
								printf("ģ�е��� �ֻ��Դϴ�.");
							}
						}
						else {
							printf("ģ�е��� �״���Դϴ�.");
						}
						break;
					}
				}
				else if (interaction == 3) {
					if (laser == 0 || rat == 0) {
						continue;
					}
					printf("������ �����ͷ� ���Ŀ� �ų��� ��� �־����ϴ�.\n");
					if (feel == 3) {
						printf("������ ����� �ֻ��Դϴ�: %d\n",feel);
					}
					else if (feel == 2) {
						printf("������ ����� �� ���������ϴ�: %d -> %d\n", feel, feel + 1);
						feel++;
					}
					else {
						printf("������ ����� �� ���������ϴ�: %d -> %d\n", feel, feel + 2);
						feel += 2;
					}
					printf("ģ�е��� �ֻ��� 2 �̻��̸� 1 ����\n");
					int dice = (rand() % 6) + 1;
					printf("%d(��)�� ���Խ��ϴ�!\n", dice);
					if (dice >= 2) {
						if (relationship < 4) {
							printf("ģ�е��� �������ϴ�.");
							relationship++;
						}
						else {
							printf("ģ�е��� �ֻ��Դϴ�.");
						}
					}
					else {
						printf("ģ�е��� �״���Դϴ�.");
					}
					break;
				}
			}
			


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

			int cp_increase;
			if ((feel - 1) < 0) {
				cp_increase = 0;
			}
			else {
				cp_increase = (feel - 1) + relationship;
			}
			CP += cp_increase;
			printf("\n\n������ ���(0~3): %d\n", feel);
			printf("������� ģ�е�(0~4): %d\n", relationship);
			printf("������ ��а� ģ�е��� ���� CP�� %d����Ʈ �����մϴ�.\n", cp_increase);
			printf("���� CP: %d����Ʈ\n\n", CP);

			printf("�������� ������ �� �� �ֽ��ϴ�.\n");
			printf("� ������ �����ұ��?\n");
			printf("1. �峭�� ��: 1 CP"); if (rat == 1) { printf(" (ǰ��)"); } printf("\n");
			printf("2. ������ ������: 2 CP"); if (laser == 1) { printf(" (ǰ��)"); } printf("\n");
			printf("3. ��ũ��ó: 3 CP"); if (scratcher == 1) { printf(" (ǰ��)"); } printf("\n");
			printf("4. ĹŸ��: 4 CP"); if (tower == 1) { printf(" (ǰ��)"); } printf("\n");
			while (1) {
				int buy;
				printf(">>");
				scanf_s("%d", &buy);
				getchar();
			

			if (buy == 0) {
				break;
			}
			else if (buy == 1) {
				if (CP >= 1 && rat == 0) {
					CP -= 1;
					rat = 1;
					printf("�峭�� �㸦 �����߽��ϴ�.\n");
					printf("���� CP: %d����Ʈ\n", CP);
				}

				else if (rat == 1) {
					printf("�峭�� ��� �̹� �����߽��ϴ�.\n");
				}
				else {
					printf("CP�� �����մϴ�.\n");
				}
			}
			else if (buy == 2) {
				if (CP >= 2 && laser == 0) {
					CP -= 2;
					laser = 1;
					printf("������ �����͸� �����߽��ϴ�.\n");
					printf("���� CP: %d����Ʈ\n", CP);
				}
				else if (laser == 1) {
					printf("������ �����ʹ� �̹� �����߽��ϴ�.\n");
				}
				else {
					printf("CP�� �����մϴ�.\n");
				}
			}
			else if (buy == 3) {
				if (CP >= 3 && scratcher == 0) {
					CP -= 3;
					scratcher = 1;
					S_POS = cat;
					printf("��ũ��ó�� �����߽��ϴ�.\n");
					printf("���� CP: %d����Ʈ\n", CP);

					while (1) {
						S_POS = (rand() % (ROOM_WIDTH - 2)) + 1;
						if (S_POS != HME_POS && S_POS != BWL_PO && S_POS != T_POS) {
							break;
						}
					}
				}
				else if (scratcher == 1) {
					printf("��ũ��ó�� �̹� �����߽��ϴ�.\n");
				}
				else {
					printf("CP�� �����մϴ�.\n");
				}
			}
			else if (buy == 4) {
				if (CP >= 4 && tower == 0) {
					CP -= 4;
					tower = 1;
					T_POS = cat;
					printf("ĹŸ���� �����߽��ϴ�.\n");
					printf("���� CP: %d����Ʈ\n", CP);

					while (1) {
						T_POS = (rand() % (ROOM_WIDTH - 2)) + 1;
						if (T_POS != HME_POS && T_POS != BWL_PO && T_POS != S_POS) {
							break;
						}
					}
				}
				else if (tower == 1) {
					printf("ĹŸ���� �̹� �����߽��ϴ�.\n");
				}
				else {
					printf("CP�� �����մϴ�.\n");
				}
			}
			else {
				printf("�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���.\n");
			}














			Sleep(2500);
			system("cls");
		}

		return 0;
	}