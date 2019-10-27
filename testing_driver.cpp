#include"CharDistribution.h"
#include<iostream>
#include"testing_driver.h"

using namespace std;

int testing_dist(){
	//TESTING CharDistribution Class for Accuracy
	CharDistribution dist;
	//cout << (int)dist.getRandomChar() << endl;
	//dist.occurs('a');
	//cout << dist.getRandomChar() << endl;
	for(char c = 'a'; c <= 'z'; c++)
		dist.occurs(c);
	CharDistribution dist2;
	for(int i = 0; i < 1000000; i++)
		dist2.occurs(dist.getRandomChar());
	cout << "Distribution 2: should be uniform with no spaces" << endl;
	dist2.printCounts(); //If this is approximately uniform for all letters then getRandomChar should work
	CharDistribution dist3;
	for(int i = 0; i < 100; i++)
		dist.occurs(' ');
	for(int i = 0; i < 1000000; i++)
		dist3.occurs(dist.getRandomChar());
	cout << "Distribution 3: should be 100x more spaces" << endl;
	dist3.printCounts();
	return 0;
}



