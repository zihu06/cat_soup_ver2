#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

#define ROOM_WIDTH 10
#define HME_POS 1
#define BWL_PO (ROOM_WIDTH -2)

int main() {
	int soup = 0; //수프의 개수
	int CP = 0; // CP 포인트
	int feel = 3; // 쫀떡이 기분
	int feel_tmp = 0; // 쫀떡이 기분 임시저장
	int relationship = 2;// 친밀도
	int cat = 1;// 고양이
	int dice;//주사위
	int foot; // 발자국
	int choose = 5; // 선택지
	int turn = 0; // 턴 수
	int S_POS = 0; // 스크래처 위치
	int T_POS = 0; // 캣타워 위치
	int up, down; // 거리 비교 변수
	int answer = 0; // 돌발퀘스트 정답
	int rat = 0;
	int laser = 0;
	int scratcher = 0;
	int tower = 0;



	srand((unsigned int)time(NULL));

	printf("****야옹이와 수프****\n");
	printf("         /\\_/\\\n");
	printf("  /\\\    / o o \\\n");
	printf(" //\\\\\   \\~(*)~/\n");
	printf(" `   \\/    ^ /\n");
	printf("     |  \\|| ||\n");
	printf("     \\ ' || ||\n");
	printf("      \\) ()-())\n");
	printf("야옹이의 이름은 쫀떡입니다\n");

	Sleep(500); 
	system("cls");

	
	

	while (1) {
		turn++;
		printf("==================== 현재상태===================\n");
		printf("현재까지 만든 수프: %d개\n", soup);
		printf("CP: %d포인트\n", CP);
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
		
		if (turn == 3) {
			printf("돌발퀘스트 발생!\n");
			printf("12 X 12 = ?\n");
			printf("'?'에 들어올 수를 넣으세요\n");
			scanf_s("%d", &answer);
			if (answer == 144) {
				printf("정답입니다! CP가 10포인트 증가합니다.\n");
				CP += 10;
			}
			else {
				printf("틀렸습니다. CP가 5포인트 감소합니다.\n");
				if (CP >= 5) {
					CP -= 5;
				}
				else {
					CP = 0;
				}
			}
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

		switch (feel) {
		case 0:
			printf("기분이 매우나쁜 지후는 집으로향합니다.\n");
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
								printf("지후은(는) 심심해서 타워쪽으로 이동합니다.\n");
							else
								printf("지후은(는) 심심해서 스크래처쪽으로 이동합니다.\n");
						}
						else if (down > up) {
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
			else if (T_POS != 0) {
				if (cat > T_POS)
					cat--;
				else if (cat < T_POS)
					cat++;
				printf("지후은(는) 심심해서 타워쪽으로 이동합니다.\n");
			}
			else if (S_POS != 0) {
				if (cat > S_POS)
					cat--;
				else if (cat < S_POS)
					cat++;
				printf("지후은(는) 심심해서 스크래처쪽으로 이동합니다.\n");
			}
			else {
				printf("놀거리가 없어서 기분이 매우 나빠집니다.\n");
				if (feel > 0)
					feel--;
			}
			break;
		case 2:
			printf("지후은(는) 기분좋게 식빵을 굽고있습니다.\n");
			break;
		case 3:
			printf("지후은(는) 골골송을 부르며 수프를 만들러갑니다.\n");
			cat++;
			break;
		}

		if (cat == HME_POS && cat == foot && turn != 1) {
			printf("지후은(는) 자신의 집에서 편안함을 느낍니다.\n");
			if (feel < 3)
				feel++;
		}

		if (cat == BWL_PO) {
			soup++;
			dice = rand() % 3 + 1;
			if (dice == 1)
				printf("지후이(가) 감자 수프를 만들었습니다!\n");
			else if (dice == 2)
				printf("지후이(가) 양송이 수프를 만들었습니다!\n");
			else
				printf("지후이(가) 브로콜리 수프를 만들었습니다!\n");

			printf("현재까지 만든 수프: %d\n", soup);
		}
		
		if (cat == S_POS) {
			printf("지후은(는) 스크래처를 긁고 놀았습니다.\n");
			if (feel == 3)
				printf("기분이 조금 좋아졌습니다: %d->%d\n", feel, feel);
			else {
				feel++;
				printf("기분이 조금 좋아졌습니다: %d->%d\n", feel - 1, feel);
			}
		}
		else if (cat == T_POS) {
			printf("지후은(는) 캣타워를 뛰어다닙니다.\n");
			if (feel > 1) {
				printf("기분이 제법 좋아졌습니다: %d->3\n", feel);
				feel = 3;
			}
			else {
				feel += 2;
				printf("기분이제법좋아졌습니다: %d->%d\n", feel - 2, feel);
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



			Sleep(500); //0.5초 대기

			int interaction;

			printf("어떤 상호작용을 하시겠습니까?\n");

			printf("0. 아무것도 하지 않음\n");
			printf("1. 긁어주기\n");
			if (rat == 1 && laser == 0) {
			printf("2. 장난감 쥐로 놀아주기");
			}
			if (laser == 1 && rat == 0) {
				printf("2. 레이저 포인터로 놀아주기\n");
			}
			if (rat == 1 && laser == 1) {
				printf("2. 장난감 쥐로 놀아주기\n");
				printf("3. 레이저 포인터로 놀아주기\n");
			}

			while (1) {
				printf(">>");
				scanf_s("%d", &interaction);
				getchar();

				if (interaction == 0) {
					printf("아무 것도 하지 않습니다.\n");
					if (feel > 0) {
						printf("지후의 기분이 나빠졌습니다: %d->%d\n",feel - 1);
						feel--;
					}
					else {
						printf("기분이 최하입니다.\n");
					}
					printf("친밀도는 주사위를 던져서 눈이 5 이하이면 1 감소\n");

					int dice = (rand() % 6) + 1;
					printf("%d(이)가 나왔습니다!\n", dice);

					if (dice == 6) {
						printf("다행이 친밀도가 떨어지지 않았습니다.");
					}
					else {
						if (relationship > 0) {
							relationship--;
							printf("집사와의 관계가 나빠집니다.");
						}
						else {
							printf("친밀도가 최하입니다.");
						}
					}
					break;
				}
				else if (interaction == 1) {
					printf("지후의 턱을 긁어주었습니다.\n");
					printf("지후의 기분은 그대로입니다 : % d\n",feel);
					printf("친밀도는 주사위 5 이상이면 1 증가\n");

					int dice = (rand() % 6) + 1;
					printf("%d(이)가 나왔습니다!\n", dice);

					if (dice == 5 || dice == 6) {
						if (relationship < 4) {
							printf("친밀도가 높아집니다.");
							relationship++;
						}
						else {
							printf("친밀도가 최상입니다.");
						}
					}
					else {
						printf("친밀도는 그대로입니다.");
					}
					break;
				}
				else if (interaction == 2) {
					if ((rat == 1 && laser == 0) || (rat == 1 && laser == 1)) {
						printf("장난감 쥐로 지후와 놀아주었습니다.\n");
						if (feel < 3) {
							printf("지후의 기분이 조금 좋아졌습니다 : % d -> % d\n",feel,feel + 1);
							feel++;
						}
						else {
							printf("지후의 기분은 최상입니다 : % d\n",feel);
						}
						printf("친밀도는 주사위 4 이상이면 1 증가\n");

						int dice = (rand() % 6) + 1;
						printf("%d(이)가 나왔습니다!\n", dice);

						if (dice >= 4) {
							if (relationship < 4) {
								printf("친밀도가 높아집니다.");
								relationship++;
							}
							else {
								printf("친밀도가 최상입니다.");
							}
						}
						else {
							printf("친밀도는 그대로입니다.");
						}
						break;
					}
					else if (rat == 0 && laser == 1) {
						printf("레이저 포인터로 지후와 신나게 놀아 주었습니다.\n");
						if (feel == 3) {
							printf("지후의 기분은 최상입니다: %d\n", feel);
						}
						else if (feel == 2) {
							printf("지후의 기분이 꽤 좋아졌습니다: %d -> %d\n",feel, feel + 1);
							feel++;
						}
						else {
							printf("%s의 기분이 꽤 좋아졌습니다: %d -> %d\n", feel, feel + 2);
							feel += 2;
						}
						printf("친밀도는 주사위 2 이상이면 1 증가\n");
						int dice = (rand() % 6) + 1;
						printf("%d(이)가 나왔습니다!\n", dice);
						if (dice >= 2) {
							if (relationship < 4) {
								printf("친밀도가 높아집니다.");
								relationship++;
							}
							else {
								printf("친밀도가 최상입니다.");
							}
						}
						else {
							printf("친밀도는 그대로입니다.");
						}
						break;
					}
				}
				else if (interaction == 3) {
					if (laser == 0 || rat == 0) {
						continue;
					}
					printf("레이저 포인터로 지후와 신나게 놀아 주었습니다.\n");
					if (feel == 3) {
						printf("지후의 기분은 최상입니다: %d\n",feel);
					}
					else if (feel == 2) {
						printf("지후의 기분이 꽤 좋아졌습니다: %d -> %d\n", feel, feel + 1);
						feel++;
					}
					else {
						printf("지후의 기분이 꽤 좋아졌습니다: %d -> %d\n", feel, feel + 2);
						feel += 2;
					}
					printf("친밀도는 주사위 2 이상이면 1 증가\n");
					int dice = (rand() % 6) + 1;
					printf("%d(이)가 나왔습니다!\n", dice);
					if (dice >= 2) {
						if (relationship < 4) {
							printf("친밀도가 높아집니다.");
							relationship++;
						}
						else {
							printf("친밀도가 최상입니다.");
						}
					}
					else {
						printf("친밀도는 그대로입니다.");
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

			int cp_increase;
			if ((feel - 1) < 0) {
				cp_increase = 0;
			}
			else {
				cp_increase = (feel - 1) + relationship;
			}
			CP += cp_increase;
			printf("\n\n지후의 기분(0~3): %d\n", feel);
			printf("집사와의 친밀도(0~4): %d\n", relationship);
			printf("지후의 기분과 친밀도에 따라서 CP가 %d포인트 증가합니다.\n", cp_increase);
			printf("보유 CP: %d포인트\n\n", CP);

			printf("상점에서 물건을 살 수 있습니다.\n");
			printf("어떤 물건을 구매할까요?\n");
			printf("1. 장난감 쥐: 1 CP"); if (rat == 1) { printf(" (품절)"); } printf("\n");
			printf("2. 레이저 포인터: 2 CP"); if (laser == 1) { printf(" (품절)"); } printf("\n");
			printf("3. 스크래처: 3 CP"); if (scratcher == 1) { printf(" (품절)"); } printf("\n");
			printf("4. 캣타워: 4 CP"); if (tower == 1) { printf(" (품절)"); } printf("\n");
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
					printf("장난감 쥐를 구매했습니다.\n");
					printf("보유 CP: %d포인트\n", CP);
				}

				else if (rat == 1) {
					printf("장난감 쥐는 이미 구매했습니다.\n");
				}
				else {
					printf("CP가 부족합니다.\n");
				}
			}
			else if (buy == 2) {
				if (CP >= 2 && laser == 0) {
					CP -= 2;
					laser = 1;
					printf("레이저 포인터를 구매했습니다.\n");
					printf("보유 CP: %d포인트\n", CP);
				}
				else if (laser == 1) {
					printf("레이저 포인터는 이미 구매했습니다.\n");
				}
				else {
					printf("CP가 부족합니다.\n");
				}
			}
			else if (buy == 3) {
				if (CP >= 3 && scratcher == 0) {
					CP -= 3;
					scratcher = 1;
					S_POS = cat;
					printf("스크래처를 구매했습니다.\n");
					printf("보유 CP: %d포인트\n", CP);

					while (1) {
						S_POS = (rand() % (ROOM_WIDTH - 2)) + 1;
						if (S_POS != HME_POS && S_POS != BWL_PO && S_POS != T_POS) {
							break;
						}
					}
				}
				else if (scratcher == 1) {
					printf("스크래처는 이미 구매했습니다.\n");
				}
				else {
					printf("CP가 부족합니다.\n");
				}
			}
			else if (buy == 4) {
				if (CP >= 4 && tower == 0) {
					CP -= 4;
					tower = 1;
					T_POS = cat;
					printf("캣타워를 구매했습니다.\n");
					printf("보유 CP: %d포인트\n", CP);

					while (1) {
						T_POS = (rand() % (ROOM_WIDTH - 2)) + 1;
						if (T_POS != HME_POS && T_POS != BWL_PO && T_POS != S_POS) {
							break;
						}
					}
				}
				else if (tower == 1) {
					printf("캣타워는 이미 구매했습니다.\n");
				}
				else {
					printf("CP가 부족합니다.\n");
				}
			}
			else {
				printf("잘못된 입력입니다. 다시 입력해주세요.\n");
			}














			Sleep(2500);
			system("cls");
		}

		return 0;
	}