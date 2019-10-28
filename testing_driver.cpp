#include"CharDistribution.h"
#include<iostream>
#include"testing_driver.h"
#include"MapHash.h"
#include"MapTree.h"

int testing_dist(){
	//TESTING CharDistribution Class for Accuracy
	CharDistribution dist;
	//std::cout << (int)dist.getRandomChar() << std::endl;
	//dist.occurs('a');
	//std::cout << dist.getRandomChar() << std::endl;
	for(char c = 'a'; c <= 'z'; c++)
		dist.occurs(c);
	CharDistribution dist2;
	for(int i = 0; i < 1000000; i++)
		dist2.occurs(dist.getRandomChar());
	std::cout << "Distribution 2: should be uniform with no spaces" << std::endl;
	dist2.printCounts(); //If this is approximately uniform for all letters then getRandomChar should work
	CharDistribution dist3;
	for(int i = 0; i < 100; i++)
		dist.occurs(' ');
	for(int i = 0; i < 1000000; i++)
		dist3.occurs(dist.getRandomChar());
	std::cout << "Distribution 3: should be 100x more spaces" << std::endl;
	dist3.printCounts();

	//TESTING MapHash
		MapHash<CharDistribution> myMap;
	myMap.put("aaaa",CharDistribution());
	myMap.find("aaaa").occurs('b');
	std::cout << myMap.find("aaaa").getRandomChar() << std::endl;
	myMap.erase("a");
	myMap.erase("aaaa");
	try{
		std::cout << "Error: " << myMap.find("aaaa").getRandomChar() << std::endl;
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
	std::cout << myMap.size();

	//TESTING MapTree
	MapTree myMap1;
	std::cout << "Size: " << myMap1.size() << std::endl;
	myMap1.put("aa",CharDistribution());
	myMap1.find("aa").occurs('w');
	myMap1.find("aa").printCounts();
	std::cout << "Size: " << myMap1.size() << std::endl;
	return 0;
}



