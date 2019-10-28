/*
 * CharDistribution.h
 *
 *  Created on: Oct 25, 2019
 *      Author: TBolt
 */

#ifndef __CHARDISTRIBUTION_H_INCLUDED__   // if x.h hasn't been included yet...
#define __CHARDISTRIBUTION_H_INCLUDED__

#include<vector>
#include<experimental/random>
#include<iostream>

class CharDistribution {
private:
	std::vector<int> counts;
	int total;
public:
	CharDistribution();
	CharDistribution(int);
	virtual ~CharDistribution();
	void occurs(char c);
	char getRandomChar();
	void printCounts();
};

#endif