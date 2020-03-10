/*
 * main.cpp
 *
 *  Created on: 2020¦~3¤ë9¤é
 *      Author: bobby
 */

// for printing out massage
#include <iostream>
#include "checkout.h"
using namespace std;

int main(){
	// Test case 1
	checkout *co = new checkout("OpeningDay");
	co->scan("atv");
	co->scan("atv");
	co->scan("atv");
	co->scan("vga");
	co->total();
	//co->debug_print();

	// Test case 2
	checkout *co2 = new checkout("OpeningDay");
	co2->scan("atv");
	co2->scan("ipd");
	co2->scan("ipd");
	co2->scan("atv");
	co2->scan("ipd");
	co2->scan("ipd");
	co2->scan("ipd");
	co2->total();
	//co2->debug_print();

	// Test case 3
	checkout *co3 = new checkout("OpeningDay");
	co3->scan("mbp");
	co3->scan("vga");
	co3->scan("ipd");
	co3->total();
	//co3->debug_print();

/*
	Total expected: $249
	Total expected: $2718.95
	Total expected: $1949.98
 */

	string input;
	checkout *co4 = new checkout("OpeningDay");
	cout << "please enter SKU or enter \"check\" to finish the checkout" << endl;
	while(cin >> input){
		if(input == "check")
			break;
		cout << "please enter SKU or enter \"check\" to finish the checkout" << endl;
		co4->scan(input);
	}
	co4->total();

	delete co;
	delete co2;
	delete co3;
	delete co4;
}
/*
	Total expected: $249
	Total expected: $2718.95
	Total expected: $1949.98
	please enter SKU or enter "check" to finish the checkout
	asd
	please enter SKU or enter "check" to finish the checkout
	asd not found
	atv
	please enter SKU or enter "check" to finish the checkout
	ipd
	please enter SKU or enter "check" to finish the checkout
	ipd
	please enter SKU or enter "check" to finish the checkout
	atv
	please enter SKU or enter "check" to finish the checkout
	ipd
	please enter SKU or enter "check" to finish the checkout
	ipd
	please enter SKU or enter "check" to finish the checkout
	ipd
	please enter SKU or enter "check" to finish the checkout
	check
	please enter SKU or enter "check" to finish the checkout
	Total expected: $2718.95
 */



