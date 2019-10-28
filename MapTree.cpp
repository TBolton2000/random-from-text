/*
 * MapTree.cpp
 *
 *  Created on: Oct 26, 2019
 *      Author: TBolt
 */

#include "MapTree.h"
void MapTree::RecursiveDelete(Node* curr) {
	if (curr != nullptr) {
		RecursiveDelete(curr->left);
		RecursiveDelete(curr->right);
		delete curr;
	}
}

Node* MapTree::searchTree(std::string k, Node* curr) {
	if (curr->left == nullptr && curr->right == nullptr)
		return curr;
	else if (k < curr->pair.first)
		return searchTree(k,curr->left);
	else if (k > curr->pair.first)
		return searchTree(k,curr->right);
	return curr;
}

MapTree::MapTree(): root(nullptr), total(0){}

MapTree::~MapTree() {
	RecursiveDelete(root);
}

int MapTree::size() {
	return total;
}

bool MapTree::empty() {
	return (total == 0);
}

CharDistribution& MapTree::find(std::string k) {
	if (empty()) {
		throw std::runtime_error("Map is currently empty");
	}
	else {
		Node* found = searchTree(k,root);
		if (found->left == nullptr && found->right == nullptr)
			throw std::runtime_error("Key is not in map");
		else
			return found->pair.second;
	}
}

void MapTree::put(std::string k, CharDistribution V) {
	Node* toInsert = new Node(k);
	if (empty()) {
		root = toInsert;
	}
	else {
		Node* pos = searchTree(k,root);
		if (pos->left == nullptr && pos->right == nullptr) { //Insert here
			if (pos->parent->left == pos)
				pos->parent->left = toInsert;
			else
				pos->parent->right = toInsert;
			toInsert->parent = pos->parent;
			delete pos; //Made swap successfully and deleted dummy node
		}
		else
			throw std::runtime_error("Key is not unique.");
	}
	total++;
}

void MapTree::erase(std::string k) {
	Node* pos = searchTree(k,root);
	if (!(pos->left == nullptr && pos->right == nullptr)) { //Key does exist, remove it
		if (pos->left->left == nullptr && pos->left->right == nullptr) {//Left child of pos is external
			delete pos->left;
			if (pos->parent->left == pos)  //Check if pos is a left or right child
				pos->parent->left = pos->right;
			else
				pos->parent->right = pos->right;
		}
		else if (pos->right->left == nullptr && pos->right->right == nullptr) { //Right child of pos is external
			delete pos->right;
			if (pos->parent->left == pos)  //Check if pos is a left or right child
				pos->parent->left = pos->left;
			else
				pos->parent->right = pos->left;
		}
		else { //No external children
			Node* replaceWith = pos->left;
			while (replaceWith->right->left != nullptr && replaceWith->right->right != nullptr) { //Find the node to replace with
				replaceWith = replaceWith->right;
			}
			if (pos->parent->left == pos)  //Check if pos is a left or right child
				pos->parent->left = replaceWith;
			else
				pos->parent->right = replaceWith;
			replaceWith->parent = pos->parent; //replaceWith becomes pos
			delete replaceWith->left;
			replaceWith->left = pos->left;
			delete replaceWith->right;
			replaceWith->right = pos->right;
		}
		delete pos; //Actually remove pos for all cases
		total--;
	}
	//Else do nothing
}

bool MapTree::isIn(std::string k) {
	if(total == 0)
		return false;
	Node* pos = searchTree(k,root);
	if(pos->left == nullptr && pos->right == nullptr)
		return false;
	else
		return true;
}