/*
 * product.cpp

 *
 *  Created on: 2020¦~3¤ë9¤é
 *      Author: bobby
 */

#include "product.h"
using namespace std;

product::product(string sku_, string name_, double price_) :
		sku(sku_),name(name_), price(price_), amount(0) {}

product::~product(){}

string product::getSku() const {return sku;}

string product::getName() const {return name;}

double product::getPrice() const {return price;}

int product::getAmount() const {return amount;}

void product::addAmount(int a) {this->amount += a;}
