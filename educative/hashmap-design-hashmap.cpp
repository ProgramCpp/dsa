#include "Bucket.cpp"
#include <array>


class MyHashMap {
	array<int,1000001> store;
public:
	// Use the constructor below to initialize the 
    // hash map based on the keyspace
	MyHashMap(int newkeySpace) {
		// note: keyspace is not considered.
		// hash keys must be 0 <= key <= keyspace . hash slot = key % large_prime
		// handle collisions with linked list in each hash slot
		// use vector for dynamic keyspace
		store.fill(-1);
	}

	void Put(int key, int value) {
		store[key] = value;
	}
 
	int Get(int key) {
		return store[key];
	}

	void Remove(int key) {
		store[key] = -1;
	}
};
