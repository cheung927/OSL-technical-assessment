/*
 * checkout.h
 *
 *  Created on: 2020¦~3¤ë9¤é
 *      Author: bobby
 */

#include <iostream>
#include "product.h"
using namespace std;

class checkout {
private:
	// pointer to array of products
	product *products[4];

	// pricing method
	string pricing;

	// expected total
	double total_amount;
public:

	// constructor, destructor
	checkout(string pricing_);
	~checkout();

	// scan and total function as requested
	void scan(string sku_);
	void total();

	// helper function
	void debug_print(){
		for(int i = 0; i < 4; i++)
			products[i]->debug_print();
	}
};

