#include "head.h"

int stockManagement() {
	system("cls");
	printf("==========================================\n");
	printf("Yeon's �� ���� �ý��ۿ� ���Ű� ȯ���մϴ�.\n");
	printf("==========================================\n");
	printf("�޴��� �����Ͻÿ�.\n");
	printf("1. �����ȸ\n");
	printf("2. ��������߰�\n");
	printf("3. �����������\n");
	printf("4. �����������\n");
	printf("5. �����޴�\n");
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
	printf("Yeon's �� ���� �ý��ۿ� ���Ű� ȯ���մϴ�.\n");
	printf("==========================================\n");

	if (strlen(item[0].name) != 0) {
		int i = 0;   
		while(strlen(item[i].name) != 0){
			printf("��ȣ   : %d\n", (i+1));
			printf("��ǰ�� : %s\n", item[i].name);
			printf("����   : %d\n", item[i].price);
			printf("����   : %d\n", item[i].stock);
			printf("==========================================\n");
			i++;
		}
	}
	else {
		printf("��� �����ϴ�.\n");
		printf("==========================================\n");
	}
	
	printf("���ư��� : 0\n>");
	scanf_s("%d", &menuCode);
	
	return menuCode;
}

int stockAdd(){
	system("cls");
	printf("==========================================\n");
	printf("Yeon's �� ���� �ý��ۿ� ���Ű� ȯ���մϴ�.\n");
	printf("==========================================\n");
	printf("��ǰ���� �Է��Ͻÿ�\n>");
	scanf_s("%s",&item[addStockCnt].name,sizeof(item[addStockCnt].name));
	printf("\n������ �Է��Ͻÿ�\n>");
	scanf_s("%d",&item[addStockCnt].price);
	printf("\n����� �Է��Ͻÿ�\n>");
	scanf_s("%d",&item[addStockCnt].stock);
	printf("==========================================\n");
	printf("���ư��� : 0\n>");
	scanf_s("%d", &menuCode);
	addStockCnt++;
	size++;
	return menuCode;
}

int stockEdit(){
	system("cls");
	printf("==========================================\n");
	printf("Yeon's �� ���� �ý��ۿ� ���Ű� ȯ���մϴ�.\n");
	printf("==========================================\n");
	if (size > 0) {
		int i = 0;   
		int stockCode = 0;
		while(strlen(item[i].name) != 0){
			printf("��ȣ   : %d\n", (i+1));
			printf("��ǰ�� : %s\n", item[i].name);
			printf("����   : %d\n", item[i].price);
			printf("����   : %d\n", item[i].stock);
			printf("==========================================\n");
			i++;
		}
		printf("�����Ͻ� ��ǰ�� ��ȣ�� �Է��Ͻʽÿ�.\n>");
		scanf_s("%d", &stockCode);
		
		if(stockCode <= i){
			stockCode--;
			printf("\n��ǰ���� �Է��Ͻÿ�\n>");
			scanf_s("%s",&item[stockCode].name,sizeof(item[stockCode].name));
			printf("\n������ �Է��Ͻÿ�\n>");
			scanf_s("%d",&item[stockCode].price);
			printf("\n����� �Է��Ͻÿ�\n>");
			scanf_s("%d",&item[stockCode].stock);	
			
			printf("\n��ȣ   : %d\n", (stockCode+1));
			printf("��ǰ�� : %s\n", item[stockCode].name);
			printf("����   : %d\n", item[stockCode].price);
			printf("����   : %d\n", item[stockCode].stock);
			printf("�����Ǿ����ϴ�.");
		}else{
			printf("�߸��� �Է��Դϴ�.\n");
		}
				
	}else {
		printf("��� �����ϴ�.\n");
		printf("==========================================\n");
	}
	
	printf("���ư��� : 0\n>");
	scanf_s("%d", &menuCode);
	
	return menuCode;
}

int stockDelete(){
	system("cls");
	printf("==========================================\n");
	printf("Yeon's �� ���� �ý��ۿ� ���Ű� ȯ���մϴ�.\n");
	printf("==========================================\n");
	if (size > 0) {
		int i = 0;   
		int stockCode = 0;
		while(strlen(item[i].name) != 0){
			printf("��ȣ   : %d\n", (i+1));
			printf("��ǰ�� : %s\n", item[i].name);
			printf("����   : %d\n", item[i].price);
			printf("����   : %d\n", item[i].stock);
			printf("==========================================\n");
			i++;
		}
		printf("size : %d\n",size);
		printf("�����Ͻ� ��ǰ�� ��ȣ�� �Է��Ͻʽÿ�.\n>");
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
			
			printf("�����Ǿ����ϴ�.");
		}else{
			printf("�߸��� �Է��Դϴ�.\n");
		}
				
	}else {
		printf("��� �����ϴ�.\n");
		printf("==========================================\n");
	}
	
	printf("���ư��� : 0\n>");
	scanf_s("%d", &menuCode);
	
	return menuCode;
}
