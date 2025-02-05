#include "StockGlasses.h"


int main() {
	StockGlasses stock;
	stock.add("ABC", 200, 12.2,"dubbleslipade");
	stock.add("ABC", 200, 12.2,"enkelslipade");
	stock.add("XYZ", 500,"blå");
	stock.add("XYZ", 500,"lila");

	stock.description();
	cout << stock.totalStockValue();




	return 0;
}
