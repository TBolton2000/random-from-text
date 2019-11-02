/*
 * CharDistribution.cpp
 *
 *  Created on: Oct 25, 2019
 *      Author: TBolt
 */

#include "CharDistribution.h"

CharDistribution::CharDistribution(): counts(27,0), total(0) {
	// TODO Auto-generated constructor stub
	std::experimental::reseed(std::time(NULL));
}

CharDistribution::CharDistribution(int num): counts(0,0), total(0) {
	// TODO Auto-generated constructor stub

}

CharDistribution::~CharDistribution() {
	// TODO Auto-generated destructor stub
}

void CharDistribution::occurs(char c) {
	int num;
	if(c == ' ')
		num = 0;
	else
		num = c - 96;
	counts.at(num) += 1;
	total += 1;
}

char CharDistribution::getRandomChar() {
	int random = std::experimental::randint(1,total);
	int sum = counts.at(0);
	char c = ' ';
	int i = 1;
	while(sum < random){
		if (c == ' ')
			c = 'a';
		else
			c++;
		sum += counts.at(i);
		i++;
	}
	return c;
}

void CharDistribution::printCounts() {
	std::cout << "(space): " << counts.at(0) << std::endl;
	for(int i = 1; i <= 26; i++)
		std::cout << (char)(i+96) << ": " << counts.at(i) << std::endl;
}
