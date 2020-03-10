/*
 * checkout.h
 *
 *  Created on: 2020¦~3¤ë9¤é
 *      Author: bobby
 */

#include <iostream>
using namespace std;

class product {

private:
	string sku;
	string name;
	double price;
	int amount;

public:
	// constructor, destructor
	product(string sku_, string name_, double price_);
	~product();

	// mutator, accessor
	string getSku() const;
	string getName() const;
	double getPrice() const;
	int getAmount() const;
	void addAmount(int a);

	// helper function
	void debug_print() const {
		cout << "sku: " << sku << endl;
		cout << "name: " << name << endl;
		cout << "price: " << price << endl;
		cout << "amount: " << amount << endl;
	}
};
