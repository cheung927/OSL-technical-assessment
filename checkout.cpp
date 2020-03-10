/*
 * checkout.cpp
 *
 *  Created on: 2020¦~3¤ë9¤é
 *      Author: bobby
 */

#include "checkout.h"

checkout::checkout(string pricing_) {
	pricing = pricing_;
	total_amount = 0;

	// initialize the products in the shop
	products[0] = new product("ipd", "Super iPad", 549.99);
	products[1] = new product("mbp", "MacBook Pro", 1399.99);
	products[2] = new product("atv", "Apple TV", 109.50);
	products[3] = new product("vga", "VGA adapter", 30.00);
}

// call product destructor
checkout::~checkout(){
	for(int i = 0; i < 4; i++)
		delete products[i];
}

void checkout::scan(string sku_){

	// add to data member: amount
	for(int i = 0; i < 4; i++){
		if(products[i]->getSku() == sku_){
			products[i]->addAmount(1);
			return;
		}
	}
	cout << sku_ << " not found" << endl;
}

void checkout::total(){
	total_amount = 0;

	// regular means no discount and no specials, everything is amount*price
	if(pricing == "Regular"){
		for(int i = 0; i < 4; i++)
			total_amount += products[i]->getAmount()*products[i]->getPrice();
		cout << "Total expected: $" << total_amount << endl;
	}

	// there are 3 discount/specials as requested
	else if (pricing == "OpeningDay"){
		for(int i = 0; i < 4; i++){

			// 3 for 2 deal on Apple TVs, e.g. buy 4 TVs : (int)4*2/3 + 4%3 = 2 + 1 = 3 = pay 3 TVs * price
			if(products[i]->getSku() == "atv" && products[i]->getAmount() >= 3)
				total_amount += (int(products[i]->getAmount()*2/3) + products[i]->getAmount()%3)*products[i]->getPrice();

			// price drop if buy more than 4 iPads
			else if(products[i]->getSku() == "ipd" && products[i]->getAmount() > 4)
				total_amount += products[i]->getAmount()*499.99;

			// 1 free adapter of charge with every MacBook pro sold
			// e.g. 1 Macbook + 2 adapters : pay 2 - 1 = 1 adapter * price
			else if(products[i]->getSku() == "vga")
				total_amount += abs(products[i]->getAmount() - products[1]->getAmount())*products[i]->getPrice();

			// original price checkout
			else
				total_amount += products[i]->getAmount()*products[i]->getPrice();
		}
		cout << "Total expected: $" << total_amount << endl;
	}
	// can add more else if to provide other discount/specials
	// if no pricing method is matched, there should be some error in pricing parameter
	else
		cout << "Pricing method error" << endl;
}
