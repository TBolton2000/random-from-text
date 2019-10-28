/*
 * MapHash.h
 *
 *  Created on: Oct 26, 2019
 *      Author: TBolt
 */

#ifndef MAPHASH_H_
#define MAPHASH_H_
#include<vector>
#include<stdexcept>
#include<string>
#include<utility>


template<class V>
class MapHash {
private:
	std::vector<std::vector<std::pair<std::string,V>>> table;
	int total;
	int findHashIndex(std::string key){
		int toInt = 0;
		for(size_t i = 0; i < key.size(); i++){
			toInt += key[i]*3;
		}
		return (toInt%101);
	};
public:
	MapHash(): table(101,std::vector<std::pair<std::string,V>>()), total(0){};
	virtual ~MapHash() {};
	int size() {
		return total;
	};
	bool empty() {
		return (total == 0);
	};
	V& find(std::string key) {
		int index = findHashIndex(key);
		for (size_t i = 0; i < table.at(index).size(); i++){
			if (table.at(index).at(i).first == key)
				return table.at(index).at(i).second;
		}
		throw std::runtime_error("Key does not exist");
	};
	void put(std::string key, V value){
		int index = findHashIndex(key);
		if(isIn(key))
			throw std::runtime_error("Key is not unique.");
		else {
			table.at(index).push_back(std::make_pair(key,value));
			total++;
		}
	};
	void erase(std::string key) {
		int index = findHashIndex(key);
		int out;
		for (size_t i = 0; i < table.at(index).size(); i++){
			if (table.at(index).at(i).first == key) {
				out = i;
			}
		}
		if (isIn(key)){
			table.at(index).erase(table.at(index).begin()+out);
			total--;
		}
	};
	bool isIn(std::string key) {
		int index = findHashIndex(key);
		for (size_t i = 0; i<table.at(index).size(); i++) {
			if (table.at(index).at(i).first == key)
				return true;
		}
		return false;
	};
};

#endif /* MAPHASH_H_ */
