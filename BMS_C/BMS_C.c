// BMS_C.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "head.h"

addStockCnt = 0;
size = 0;
orderSize = 0;

int main(int argc, char *argv[]) {

	while (menuCode != 3) {
		menuCode = menu();
	}

	return 0;
}

