#include <iostream>
#include <fstream>
#include <string>
#include "Pair.h"
#include "HashTable.h"
using namespace std;

int main()
{
	cout << "=========LINKED LIST===========" << endl;
	LinkedList<int> mylist;
	mylist.addFront(33);
	mylist.addFront(37);
	mylist.addBack(24);
	mylist.addBack(33);
	mylist.insertAfter(24, 68);
	mylist.insertBefore(68, 77);
	mylist.printList();
	cout << endl;
	cout << "How many instances of 33 in list? : " << mylist.instances(33) << endl;
	cout << "33 is at position " << mylist.find(33) << " in our Linked List." << endl;
	cout << endl;
	cout << "Beggining index: " << mylist.indexBegin() << " Ending index: " << mylist.indexEnd() << endl;
	mylist.deleteElement(33);
	mylist.deleteElement(37);
	mylist.deleteElement(24);
	mylist.deleteElement(33);
	mylist.deleteElement(68);
	mylist.deleteElement(77);
	cout << endl;
	cout << "After Deleting element(s): " << endl;
	mylist.printList();
	cout << "=========HASH TABLE===========" << endl;
	HashTable<double> ht(50); //constructor sets the size
	ht.hash(75);
	ht.hash(375);
	ht.hash(5);
	ht.hash(15);
	ht.hash(20);
	ht.hash(25);
	ht.hash(45);
	cout << ht.search(5) << " instance(s) of 5." << endl;
	ht.printTable();
	cout << "=========HASH TABLE APPLCIATION===========\n";
	string line;
	ifstream myfile("hash.txt"); //input file
	HashTable<Pair<string, string>> phoneBook(53);
	if (myfile.is_open()) //if open
	{
		string number = " ";
		while (getline(myfile, line)) //get a line
		{
			string name = "";
			int j = 0;
			for (j; line[j] != ';'; j++)
			{
				name += line[j];
			}
			number = line.substr(j + 1, 15);
			Pair<string, string> nameNnumber(name, number); //use pair constructor to set key and value
			phoneBook.hash(nameNnumber); //hash that pair
		} 
	}
	else cout << "Unable to open file\n";
	myfile.close();
	string inputName;
	char input = 'Y';
	while (toupper(input) == 'Y')
	{
		cout << "Enter a name and I'll retrieve the phone number:\n";
		cin >> inputName;
		string pnumber = phoneBook.getVal(inputName);
		pnumber == "Key not found." ? cout << pnumber << endl : cout << phoneBook.getIndexAndOffset(inputName) << " Phone #: " << pnumber << endl;
		cout << "Look up another name? Y/N "; 
		cin >> input;
	}
	return 0;
}