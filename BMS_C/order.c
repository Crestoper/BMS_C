#include "head.h"

int orderManagement() {
	system("cls");
	printf("==========================================\n");
	printf("Yeon's 몰 관리 시스템에 오신걸 환영합니다.\n");
	printf("==========================================\n");
	printf("메뉴를 선택하시오.\n");
	printf("1. 상품판매\n");
	printf("2. 상품반품\n");
	printf("3. 판매정보\n");
	printf("4. 이전메뉴\n");
	printf("==========================================\n");
	printf(">");
	scanf_s("%d", &menuCode);

	if (menuCode == 1) { while (menuCode != 0) { menuCode = sellStock(); } }
	else if (menuCode == 2) { while (menuCode != 0) { menuCode = retrunStock(); } }
	else if (menuCode == 3) { while (menuCode != 0) { menuCode = orderInfo(); } }
	else if (menuCode == 4) { return 4; }

	return 0;
}

int sellStock() {
	system("cls");
	printf("==========================================\n");
	printf("Yeon's 몰 관리 시스템에 오신걸 환영합니다.\n");
	printf("==========================================\n");
	if (size > 0) {
		int i = 0;
		int stockCode = 0;
		int stock = 0;
		while (strlen(item[i].name) != 0) {
			printf("번호   : %d\n", (i + 1));
			printf("상품명 : %s\n", item[i].name);
			printf("가격   : %d\n", item[i].price);
			printf("수량   : %d\n", item[i].stock);
			printf("==========================================\n");
			i++;
		}
		printf("판매하실 상품의 번호를 입력하십시오.\n>");
		scanf_s("%d", &stockCode);
		
		if (stockCode <= i) {
			stockCode--;

			printf("\n판매수량을 입력하시오\n>");
			scanf_s("%d", &stock);

			if (item[stockCode].stock >= stock) {
				item[stockCode].stock -= stock;

				if (orderSize != 0) {
					strcpy_s(sell[(orderSize)].name,sizeof(item[stockCode].name),item[stockCode].name);
					sell[(orderSize)].stock = -stock;
				}
				else {
					strcpy_s(sell[0].name, sizeof(item[stockCode].name), item[stockCode].name);
					sell[0].stock = -stock;
				}
				orderSize++;

			}else {
				printf("수량이 부족합니다.");
			}
			printf("==========================================\n");
		}
		else {
			printf("잘못된 입력입니다.\n");
		}

	}else {
		printf("재고가 없습니다.\n");
		printf("==========================================\n");
	}

	printf("돌아가기 : 0\n>");
	scanf_s("%d", &menuCode);
	
	return menuCode;
}

int retrunStock() {
	system("cls");
	printf("==========================================\n");
	printf("Yeon's 몰 관리 시스템에 오신걸 환영합니다.\n");
	printf("==========================================\n");
	if (orderSize > 0) {
		int i = 0;
		int stockCode = 0;
		int stock = 0;
		while (orderSize > i) {
			printf("번호   : %d\n", (i + 1));
			printf("상품명 : %s\n", sell[i].name);
			printf("수량   : %d\n", sell[i].stock);
			printf("==========================================\n");
			i++;
		}
		printf("반품하실 상품의 번호를 입력하십시오.\n>");
		scanf_s("%d", &stockCode);

		if (stockCode <= i) {
			stockCode--;
			
			printf("\n반품수량을 입력하시오\n>");
			scanf_s("%d", &stock);
			
			if (-sell[stockCode].stock >= stock) {
				for(int x = 0; x < size; x++){
					if (strcmp(item[x].name, sell[stockCode].name) == 0) {
						item[x].stock += stock;
						sell[stockCode].stock += stock;
					}
				}
			}else {
				printf("수량이 부족합니다.\n");
			}
			printf("==========================================\n");
		}
		else {
			printf("잘못된 입력입니다.\n");
		}
	}
	else {
		printf("판매정보가 없습니다.\n");
		printf("==========================================\n");
	}

	printf("돌아가기 : 0\n>");
	scanf_s("%d", &menuCode);

	return menuCode;

}

int orderInfo() {
	system("cls");
	printf("==========================================\n");
	printf("Yeon's 몰 관리 시스템에 오신걸 환영합니다.\n");
	printf("==========================================\n");
	if (orderSize > 0) {
		int i = 0;
		while (orderSize > i) {
			printf("번호   : %d\n", (i + 1));
			printf("상품명 : %s\n", sell[i].name);
			printf("수량   : %d\n", sell[i].stock);
			printf("==========================================\n");
			i++;
		}
	}
	else {
		printf("판매정보가 없습니다.\n");
		printf("==========================================\n");
	}

	printf("돌아가기 : 0\n>");
	scanf_s("%d", &menuCode);

	return menuCode;
}
