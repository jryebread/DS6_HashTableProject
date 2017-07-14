#ifndef PAIRLIST_H
#define PAIRLIST_H
#include "LinkedList.h"
#include "Pair.h"
using std::cout;
using std::endl;
//=============Class PAIRLIST=============//
//Can hold a list of pair objects, using multiple inheritance from LinkedList and Pair
template<class F, class S>
class PairList : public LinkedList<Pair<F, S>>, public Pair<F, S>
{
private:
public:
	PairList();
	void printPairs();
	F getKeyFromValue(S value);
	S getValueFromKey(F key);
	void pushPair(F key, S value);
	void deletePair(F key, S value);
};
#endif
//Default Constructor
template<class F, class S>
PairList<F, S>::PairList()
{}

/*Function: overriden printList for PairList
Author:	James Riback
Description:  prints out the PairList
Outputs: list of pairs
*/
template<class F, class S>
void PairList<F, S>::printPairs()
{
	if (isEmpty())
	{
		cout << "List is empty." << endl;
	}
	Node<Pair<F, S>> *p = this->Head;
	while (p != nullptr)
	{
		cout << p->data.getFirst() << ", " << p->data.getSecond() << endl;
		p = p->next;
	}
}

/*Function: getValueFromKey
Author:	James Riback
Description: function inputs a key(pair 1) and it searches and finds+returns its value(pair 2).
Inputs: a key (pair 1)
Outputs:  value (pair 2)
*/
template<class F, class S>
S PairList<F, S>::getValueFromKey(F key)
{
	Node<Pair<F, S>> *p = this->Head;
	while (p != nullptr)
	{
		if (p->data.getFirst() == key)
		{
			return p->data.getSecond();
		}
		p = p->next;
	}
}
/*Function: getKeyFromValue
Author:	James Riback
Description: Returns a key from an inputted value
Inputs: value (pair 2)
Outputs: key (pair 1)
*/
template<class F, class S>
F PairList<F, S>::getKeyFromValue(S value)
{
	Node<Pair<F, S>> *p = this->Head;
	while (p != nullptr)
	{
		if (p->data.getSecond() == value)
		{
			return p->data.getFirst();
		}
		p = p->next;
	}
}
/*Function: pushPair
Author:	James Riback
Description: adds a new pair to the PairList
Inputs: a key and a value for that key to access
*/
template<class F, class S>
void PairList<F, S>::pushPair(F key, S value)
{
	this->addBack(Pair<F, S>(key, value));
}
/*Function: deletePair
Author:	James Riback
Description: deletes a pair from the PairList
Inputs: a key and a value
*/
template<class F, class S>
void PairList<F, S>::deletePair(F key, S value)
{
	this->deleteElement(Pair<F, S>(key, value));
}

