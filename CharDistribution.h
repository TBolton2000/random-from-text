/*
 * CharDistribution.h
 *
 *  Created on: Oct 25, 2019
 *      Author: TBolt
 */

#ifndef CHARDISTRIBUTION_H_
#define CHARDISTRIBUTION_H_
#include<vector>
#include<experimental/random>
#include<iostream>

class CharDistribution {
private:
	std::vector<int> counts;
	int total;
public:
	CharDistribution();
	virtual ~CharDistribution();
	void occurs(char c);
	char getRandomChar();
	void printCounts();
};

#endif /* CHARDISTRIBUTION_H_ */
