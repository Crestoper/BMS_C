#include "head.h"

int menu() {
	system("cls");
	printf("==========================================\n");
	printf("Yeon's 몰 관리 시스템에 오신걸 환영합니다.\n");
	printf("==========================================\n");
	printf("메뉴를 선택하시오.\n");
	printf("1. 재고관리\n");
	printf("2. 주문관리\n");
	printf("3. 종료\n");
	printf("==========================================\n");
	printf(">");
	scanf_s("%d", &menuCode);

	if(menuCode == 1){
		while(menuCode != 5) { 
			menuCode = stockManagement();
		}
	}else if(menuCode == 2){
		while (menuCode != 4) {
			menuCode = orderManagement();
		}
	}else if(menuCode == 3){
		return 3;
	}
}
