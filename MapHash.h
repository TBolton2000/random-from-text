/*
 * MapHash.h
 *
 *  Created on: Oct 26, 2019
 *      Author: TBolt
 */

#ifndef MAPHASH_H_
#define MAPHASH_H_
#include<vector>

template<typename K, class V>
class MapHash {
private:
	std::vector<V> table;
	int total;
	int findHashIndex(K key);
public:
	MapHash(): table(101,V()), total(0){};
	virtual ~MapHash();
	int size(){return total;};
	bool empty(){return (total == 0);};
	V find(K key);
	void put(K key, V value);
	void erase(K key);
	bool isIn(K key);
};

#endif /* MAPHASH_H_ */
