#include "head.h"

int stockManagement() {
	system("cls");
	printf("==========================================\n");
	printf("Yeon's 몰 관리 시스템에 오신걸 환영합니다.\n");
	printf("==========================================\n");
	printf("메뉴를 선택하시오.\n");
	printf("1. 재고조회\n");
	printf("2. 재고정보추가\n");
	printf("3. 재고정보수정\n");
	printf("4. 재고정보삭제\n");
	printf("5. 이전메뉴\n");
	printf("==========================================\n");
	printf(">");
	scanf_s("%d", &menuCode);

	if(menuCode == 1) { while(menuCode != 0){ menuCode = stockCheck(); }}
	else if(menuCode == 2){ while(menuCode != 0){ menuCode = stockAdd(); }}
	else if(menuCode == 3){ while(menuCode != 0){ stockEdit(); }}
	else if(menuCode == 4){ while(menuCode != 0){ stockDelete(); } }
	else if(menuCode == 5){ return 5; }

	return 0;
}

int stockCheck(){
	system("cls");
	printf("==========================================\n");
	printf("Yeon's 몰 관리 시스템에 오신걸 환영합니다.\n");
	printf("==========================================\n");

	if (strlen(item[0].name) != 0) {
		int i = 0;   
		while(strlen(item[i].name) != 0){
			printf("번호   : %d\n", (i+1));
			printf("상품명 : %s\n", item[i].name);
			printf("가격   : %d\n", item[i].price);
			printf("수량   : %d\n", item[i].stock);
			printf("==========================================\n");
			i++;
		}
	}
	else {
		printf("재고가 없습니다.\n");
		printf("==========================================\n");
	}
	
	printf("돌아가기 : 0\n>");
	scanf_s("%d", &menuCode);
	
	return menuCode;
}

int stockAdd(){
	system("cls");
	printf("==========================================\n");
	printf("Yeon's 몰 관리 시스템에 오신걸 환영합니다.\n");
	printf("==========================================\n");
	printf("상품명을 입력하시오\n>");
	scanf_s("%s",&item[addStockCnt].name,sizeof(item[addStockCnt].name));
	printf("\n가격을 입력하시오\n>");
	scanf_s("%d",&item[addStockCnt].price);
	printf("\n재고을 입력하시오\n>");
	scanf_s("%d",&item[addStockCnt].stock);
	printf("==========================================\n");
	printf("돌아가기 : 0\n>");
	scanf_s("%d", &menuCode);
	addStockCnt++;
	size++;
	return menuCode;
}

int stockEdit(){
	system("cls");
	printf("==========================================\n");
	printf("Yeon's 몰 관리 시스템에 오신걸 환영합니다.\n");
	printf("==========================================\n");
	if (size > 0) {
		int i = 0;   
		int stockCode = 0;
		while(strlen(item[i].name) != 0){
			printf("번호   : %d\n", (i+1));
			printf("상품명 : %s\n", item[i].name);
			printf("가격   : %d\n", item[i].price);
			printf("수량   : %d\n", item[i].stock);
			printf("==========================================\n");
			i++;
		}
		printf("수정하실 상품의 번호를 입력하십시오.\n>");
		scanf_s("%d", &stockCode);
		
		if(stockCode <= i){
			stockCode--;
			printf("\n상품명을 입력하시오\n>");
			scanf_s("%s",&item[stockCode].name,sizeof(item[stockCode].name));
			printf("\n가격을 입력하시오\n>");
			scanf_s("%d",&item[stockCode].price);
			printf("\n재고을 입력하시오\n>");
			scanf_s("%d",&item[stockCode].stock);	
			
			printf("\n번호   : %d\n", (stockCode+1));
			printf("상품명 : %s\n", item[stockCode].name);
			printf("가격   : %d\n", item[stockCode].price);
			printf("수량   : %d\n", item[stockCode].stock);
			printf("수정되었습니다.");
		}else{
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

int stockDelete(){
	system("cls");
	printf("==========================================\n");
	printf("Yeon's 몰 관리 시스템에 오신걸 환영합니다.\n");
	printf("==========================================\n");
	if (size > 0) {
		int i = 0;   
		int stockCode = 0;
		while(strlen(item[i].name) != 0){
			printf("번호   : %d\n", (i+1));
			printf("상품명 : %s\n", item[i].name);
			printf("가격   : %d\n", item[i].price);
			printf("수량   : %d\n", item[i].stock);
			printf("==========================================\n");
			i++;
		}
		printf("size : %d\n",size);
		printf("삭제하실 상품의 번호를 입력하십시오.\n>");
		scanf_s("%d", &stockCode);
		
		if(stockCode <= i){
			stockCode--;
			do{
				strcpy_s(item[stockCode].name,sizeof(item[stockCode].name), item[(stockCode + 1)].name);
				item[stockCode].price=item[(stockCode+1)].price;
				item[stockCode].stock=item[(stockCode+1)].stock;
				stockCode++;
			}while(stockCode<size);
			size--;
			
			printf("삭제되었습니다.");
		}else{
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
