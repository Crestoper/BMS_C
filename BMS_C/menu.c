#include "head.h"

int menu() {
	system("cls");
	printf("==========================================\n");
	printf("Yeon's �� ���� �ý��ۿ� ���Ű� ȯ���մϴ�.\n");
	printf("==========================================\n");
	printf("�޴��� �����Ͻÿ�.\n");
	printf("1. ������\n");
	printf("2. �ֹ�����\n");
	printf("3. ����\n");
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
