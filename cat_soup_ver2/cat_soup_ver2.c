#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

#define ROOM_WIDTH 10
#define HME_POS 1
#define BWL_PO (ROOM_WIDTH -2)

int main() {

	printf("****야옹이와 수프****\n");
	printf("         /\\_/\\\n");
	printf("  /\\\    / o o \\\n");
	printf(" //\\\\\   \\~(*)~/\n");
	printf(" `   \\/    ^ /\n");
	printf("     |  \\|| ||\n");
	printf("     \\ ' || ||\n");
	printf("      \\) ()-())\n");

	printf("야옹이의 이름은 쫀떡입니다\n");

	Sleep(500); // 2.5초 대기
	system("cls");

	int soup = 0; //수프의 개수
	int cp = 0; // CP 포인트
	int feel = 3; // 쫀떡이 기분
	int feel_tmp = 0; // 쫀떡이 기분 임시저장
	int relationship = 2;// 친밀도
	int cat = 1;// 고양이
	int dice;//주사위
	int foot; // 발자국
	int choose ;
	int turn = 0;
	int s = 0; // 스크래처 위치
	int tower = 0; // 타워 위치
	int up, down; // 가까운 거리 판별하는 변수
	

	srand((unsigned int)time(NULL));

	while (1) {
		turn++;
		printf("==================== 현재상태===================\n");
		printf("현재까지 만든 수프: %d개\n", soup);
		printf("CP: %d포인트\n", cp);
		printf("쫀떡이 기분(0~3): %d\n", feel);
		if (feel == 0) {
			printf("기분이 매우 나쁩니다.\n");
		}
		else if (feel == 1) {
			printf("심심해합니다.\n");
		}
		else if (feel == 2) {
			printf("식빵을 굽습니다.\n");
		}
		else if (feel == 3) {
			printf("  골골송을 부릅니다.\n");
		}
		printf("집사와의 관계(0~4): %d\n", relationship);


		if (relationship == 0) {
			printf("곁에 오는 것조차 싫어합니다.\n");
		}
		else if (relationship == 1) {
			printf("간식 자판기 취급입니다.\n");
		}
		else if (relationship == 2) {
			printf("  그럭저럭 쓸만한 집사입니다.\n");
		}
		else if (relationship == 3) {
			printf("훌륭한 집사로 인정 받고 있습니다.\n");
		}
		else if (relationship == 4) {
			printf("집사 껌딱지입니다.\n");
		}

		printf("================================================\n");
		
		if (turn== 3) {
			printf("돌발 퀘스트 발생!\n");
			printf("12 X 12 = ?\n");
			printf("'?'에 들어올숫자를 적으시오.");
			scanf_s("%d", &choose);
			
			if (choose == 144) {
				printf("정답입니다.\n");
				printf("CP가 5올라갑니다.\n");
				cp += 5;
			}
			else
				printf("틀렸습니다.\n정답은 144입니다.\n");

		}







		printf("6-%d: 주사위 눈이 %d 이하이면 그냥 기분이 나빠집니다. \n", relationship, 6 - relationship);
		printf("주사위를 굴립니다. 또르르...\n");

		dice = rand() % 6 + 1;
		printf("%d(이)가 나왔습니다.\n", dice);

		foot = cat;

		if (dice <= 6 - relationship) {
			feel_tmp = feel;
			if (feel > 0) {
				feel--;
			}
			printf("쫀떡이 기분이 나빠집니다: %d->%d\n", feel_tmp, feel);

		}


		if (feel == 0) {
			printf("기분이 매우 나쁜 지후은(는) 집으로 향합니다.\n");
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
								printf("지후은(는) 심심해서 타워쪽으로 이동합니다.\n");
							else
								printf("지후은(는) 심심해서 스크래처쪽으로 이동합니다.\n");
						}
						else if (down < up) {
							cat--;
							if (choose == 0)
								printf("지후은(는) 심심해서 타워쪽으로 이동합니다.\n");
							else
								printf("지후은(는) 심심해서 스크래처쪽으로 이동합니다.\n");
						}
						else {
							cat++;
							printf("지후은(는) 심심해서 이동합니다.\n");
						}
					}
				}

			}
			else if (tower != 0) {
				if (cat > tower)
					cat--;
				else if (cat < tower)
					cat++;
				printf("지후은(는) 심심해서 타워쪽으로 이동합니다.\n");
			}
			else if (s != 0) {
				if (cat > s)
					cat--;
				else if (cat < s)
					cat++;
				printf("지후은(는) 심심해서 스크래처쪽으로 이동합니다.\n");
			}
			else {
				printf("놀거리가 없어서 기분이 매우 나빠집니다.\n");
				if (feel > 0)
					feel--;
			}
		}
		else if (feel == 2) {
			printf("지후는 기분좋게 식빵을 굽고 있습니다.\n");
		}
		else if (feel == 3) {
			printf("지후는 골골송을 부르며 수프를 만들러 갑니다.\n");
			if (cat < BWL_PO) {
				cat++;
			}
		}
		

			if (cat == BWL_PO) {
				soup++;
				dice = rand() % 3 + 1;
				switch (dice) {

				case 1:
					printf("지후가 감자수프를 만들었습니다.\n");
					break;
				case 2:
					printf("지후가 양송이수프를 만들었습니다.\n");
					break;
				case 3:
					printf("지후가 브로콜리수프를 만들었습니다.\n");
					break;
				}
				printf("현재까지 만든 수프: %d\n", soup);
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



			Sleep(500); //0.5초 대기

			printf("어떤 상호작용을 하시겠습니까?    0. 아무것도 하지 않음    1. 긁어주기\n>> ");
			scanf_s("%d", &choose);

			while (choose != 0 && choose != 1) {
				printf(">> ");
				scanf_s("%d", &choose);
			}

			switch (choose) {
			case 0:
				printf("아무것도 하지 않음\n");
				printf("4/6의 확률로 친밀도가 떨어집니다.\n");
				printf("주사위를 돌립니다. 또르륵...\n");
				dice = rand() & 6 + 1;
				printf("%d가 나왔습니다.\n", dice);
				if (dice <= 4) {
					printf("친밀도가 떨어집니다.\n");
					if (relationship > 0) {
						relationship--;
					}
				}
				else {
					printf("다행이도 친밀도가 떨어지지 않았습니다.\n");
				}
				break;
			case 1:
				printf("쫀떡의 턱을 긁어주었습니다.\n");
				printf("2/6의 확률로 친밀도가 높아집니다.\n");
				printf("주사위를 돌립니다. 또르륵...\n");
				dice = rand() % 6 + 1;
				printf("%d가 나왔습니다.\n", dice);
				if (dice >= 5) {
					printf("친밀도가 높아집니다\n");
					if (relationship <= 3) {
						relationship++;
					}
				}
				else {
					printf("친밀도는 그대로입니다.\n");
				}
				break;
			}
			printf("현재 친밀도 : %d\n", relationship);
			Sleep(2500);
			system("cls");
		}

		return 0;
	}