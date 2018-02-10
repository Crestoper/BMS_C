
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

typedef struct item {
	char name[20];
	int price;
	int stock;
}Item;

typedef struct sell {
	char name[20];
	int stock;
}Sell;

Item item[100];
Sell sell[100];

int menuCode;
int addStockCnt;
int size;
int orderSize;

int menu();
int stockManagement();
int stockCheck();
int stockAdd();
int stockEdit();
int stockDelete();

int orderManagement();
int sellStock();
int retrunStock();
int orderInfo();
