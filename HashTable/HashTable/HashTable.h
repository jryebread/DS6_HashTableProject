#ifndef HASH_H
#define HASH_H
#include "LinkedList.h"
#include "Pair.h"
#include <string>
#include <sstream>
#include <vector>
using std::string;
/* ====== Class HASH TABLE  ========*/
template<class T>
class HashTable
{
public:
	HashTable();
	HashTable(int tSize);
	void hash(double value);
	void hash(string value);
	void hash(Pair<string, string> pair);
	int search(T value);
	void printTable();
	//functions for phone book application
	string getIndexAndOffset(string key);
	string getVal(string key);
	int hashFunc(string key);
private:
	int hashFunc(double key); 
	unsigned tableSize;
	std::vector<LinkedList<T>> hTable; //array of lists
};
#endif

// Default constructor
//Sets TableSize to 53 a prime num
template<class T>
HashTable<T>::HashTable()
{
	LinkedList<T> newList;
	tableSize = 53;
	//assign all vector spaces an empty LL
	hTable.assign(tableSize, newList); //double vector
}
//Overloaded constructor,pass in table size
template<class T>
HashTable<T>::HashTable(int tSize)
{
	LinkedList<T> newList;
	tableSize = tSize;
	//assign all vector spaces an empty LL
	hTable.assign(tableSize, newList);

}
//Returns a index of where to place the key
template<class T>
int HashTable<T>::hashFunc(double key)
{
	return static_cast<int>(key) % tableSize;
	//returns the double as as an integer value
}

template<class T>
int HashTable<T>::hashFunc(string key)
{
	//int hashVal = 0;
	//for (int i = 0; i < key.size(); i++)
	//	hashVal = 37 * hashVal + static_cast<int>(key[i]);

	//hashVal = hashVal % tableSize;
	////if negative value bring it back positive
	//if (hashVal < 0)
	//	hashVal += tableSize;

	//return hashVal;
	//=======POOR HASH COLLISION TEST FUNCTION====//
	int sum = 0;
	for (int i = 0; i < key.size(); i++)
		sum += static_cast<int>(key[i]);
	return sum % tableSize;
}

//stores value in hash table
template<class T>
void HashTable<T>::hash(double value)
{
	int index = this->hashFunc(value); //location in vector to store key
	hTable.at(index).addBack(value); //at index location pushback the value to the List
}

template<class T>
void HashTable<T>::hash(string value)
{
	int index = hashFunc(value); //get the hashFunc index
	hTable.at(index).addBack(value);
}

template<class T>
void HashTable<T>::hash(Pair<string, string> pair)
{
	int index = hashFunc(pair.getFirst()); //get index for key
	hTable.at(index).addBack(pair); //store pair at index
}

//Returns number of occurences the value appears in the table
//To perform a search, we use the hash function to determine 
//which list to traverse. We then search the appropriate list.
template<class T>
int HashTable<T>::search(T value)
{
	int index = hashFunc(value); //get the hashFunc index
	//returns the # of instances of the value in the list at the particular index of the vector
	return hTable.at(index).instances(value);
}

template<class T>
string HashTable<T>::getIndexAndOffset(string key)
{
	std::stringstream ss;
	int index = hashFunc(key); //get the hashFunc index
	int c_offset = hTable.at(index).findKey(key);
	ss << key << " (" << index;
	c_offset >= 1 ? ss <<"-" <<  c_offset << ")" : ss << ")";
	return ss.str();
}

template<class T>
string HashTable<T>::getVal(string key)
{
	int index = hashFunc(key); //get the hashFunc index
	if (hTable.at(index).findKey(key) == -1)
		return "Key not found.";
	string value = hTable.at(index).getValFromKey(key);
	return value;
}

template<class T>
void HashTable<T>::printTable()
{
	for (int x = 0; x < hTable.size(); x++)
	{
		if (!hTable.at(x).isEmpty()) //if not empty
			hTable.at(x).printChain(); //print the LL at the vector space
	}
}


