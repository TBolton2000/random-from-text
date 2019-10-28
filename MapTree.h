/*
 * MapTree.h
 *
 *  Created on: Oct 26, 2019
 *      Author: TBolt
 */

#ifndef MAPTREE_H_
#define MAPTREE_H_
#include"CharDistribution.h"
#include<utility>
#include<string>

struct Node{
	Node* left;
	Node* right;
	Node* parent;
	std::pair<std::string,CharDistribution> pair;
	Node(std::string key): parent(nullptr) {
		pair = std::make_pair(key,CharDistribution());
		left = new Node();
		right = new Node();
		left->parent = this;
		right->parent = this;
	};
	Node(): left(nullptr), right(nullptr), parent(nullptr) {
		pair = std::make_pair("",CharDistribution(1));
	};
};

class MapTree {
private:
	Node* root;
	int total;
	void RecursiveDelete(Node* curr);
	Node* searchTree(std::string k, Node* curr);
public:
	MapTree();
	virtual ~MapTree();
	int size();
	bool empty();
	CharDistribution& find(std::string k);
	void put(std::string k, CharDistribution V);
	void erase(std::string k);
	bool isIn(std::string k);
};

#endif /* MAPTREE_H_ */
