#include "head.h"

int orderManagement() {
	system("cls");
	printf("==========================================\n");
	printf("Yeon's �� ���� �ý��ۿ� ���Ű� ȯ���մϴ�.\n");
	printf("==========================================\n");
	printf("�޴��� �����Ͻÿ�.\n");
	printf("1. ��ǰ�Ǹ�\n");
	printf("2. ��ǰ��ǰ\n");
	printf("3. �Ǹ�����\n");
	printf("4. �����޴�\n");
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
	printf("Yeon's �� ���� �ý��ۿ� ���Ű� ȯ���մϴ�.\n");
	printf("==========================================\n");
	if (size > 0) {
		int i = 0;
		int stockCode = 0;
		int stock = 0;
		while (strlen(item[i].name) != 0) {
			printf("��ȣ   : %d\n", (i + 1));
			printf("��ǰ�� : %s\n", item[i].name);
			printf("����   : %d\n", item[i].price);
			printf("����   : %d\n", item[i].stock);
			printf("==========================================\n");
			i++;
		}
		printf("�Ǹ��Ͻ� ��ǰ�� ��ȣ�� �Է��Ͻʽÿ�.\n>");
		scanf_s("%d", &stockCode);
		
		if (stockCode <= i) {
			stockCode--;

			printf("\n�Ǹż����� �Է��Ͻÿ�\n>");
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
				printf("������ �����մϴ�.");
			}
			printf("==========================================\n");
		}
		else {
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

int retrunStock() {
	system("cls");
	printf("==========================================\n");
	printf("Yeon's �� ���� �ý��ۿ� ���Ű� ȯ���մϴ�.\n");
	printf("==========================================\n");
	if (orderSize > 0) {
		int i = 0;
		int stockCode = 0;
		int stock = 0;
		while (orderSize > i) {
			printf("��ȣ   : %d\n", (i + 1));
			printf("��ǰ�� : %s\n", sell[i].name);
			printf("����   : %d\n", sell[i].stock);
			printf("==========================================\n");
			i++;
		}
		printf("��ǰ�Ͻ� ��ǰ�� ��ȣ�� �Է��Ͻʽÿ�.\n>");
		scanf_s("%d", &stockCode);

		if (stockCode <= i) {
			stockCode--;
			
			printf("\n��ǰ������ �Է��Ͻÿ�\n>");
			scanf_s("%d", &stock);
			
			if (-sell[stockCode].stock >= stock) {
				for(int x = 0; x < size; x++){
					if (strcmp(item[x].name, sell[stockCode].name) == 0) {
						item[x].stock += stock;
						sell[stockCode].stock += stock;
					}
				}
			}else {
				printf("������ �����մϴ�.\n");
			}
			printf("==========================================\n");
		}
		else {
			printf("�߸��� �Է��Դϴ�.\n");
		}
	}
	else {
		printf("�Ǹ������� �����ϴ�.\n");
		printf("==========================================\n");
	}

	printf("���ư��� : 0\n>");
	scanf_s("%d", &menuCode);

	return menuCode;

}

int orderInfo() {
	system("cls");
	printf("==========================================\n");
	printf("Yeon's �� ���� �ý��ۿ� ���Ű� ȯ���մϴ�.\n");
	printf("==========================================\n");
	if (orderSize > 0) {
		int i = 0;
		while (orderSize > i) {
			printf("��ȣ   : %d\n", (i + 1));
			printf("��ǰ�� : %s\n", sell[i].name);
			printf("����   : %d\n", sell[i].stock);
			printf("==========================================\n");
			i++;
		}
	}
	else {
		printf("�Ǹ������� �����ϴ�.\n");
		printf("==========================================\n");
	}

	printf("���ư��� : 0\n>");
	scanf_s("%d", &menuCode);

	return menuCode;
}
