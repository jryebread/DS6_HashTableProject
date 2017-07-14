#ifndef PAIR_H
#define PAIR_H
#include "LinkedList.h"
#include <sstream>
#include <iostream>
//=============Class PAIR=============//
// A complex Pair value that holds two different types, a key and a value
template<class F, class S>
class Pair
{
private:
	F key;
	S value;
	bool equals(Pair &value);
public:
	//Constructors
	Pair();
	Pair(F pair1, S pair2);
	//Accessors
	F getFirst() const;
	S getSecond() const;
	//Mutator
	void setFirst(F value);
	void setSecond(S value);
	//overloaded op
	bool operator==(Pair &value);
	bool operator!=(Pair &value);
};
//Default constructor
template<class F, class S>
Pair<F, S>::Pair()
{}
//Overloaded constructor - sets key and value to the passed in Pair
template<class F, class S>
Pair<F, S>::Pair(F pair1, S pair2)
{
	this->key = pair1;
	this->value = pair2;
}
//======================ACCESSORS======================//
/*Function: getFirst
Author:	James Riback
Description: Returns a key
Outputs: key (pair 1)
*/
template<class F, class S>
F Pair<F, S>::getFirst() const
{
	return this->key;
}
/*Function: getSecond
Author:	James Riback
Description: Returns a value
Outputs: value (pair 2)
*/
template<class F, class S>
S Pair<F, S>::getSecond() const
{
	return this->value;
}

//======================MUTATORS======================//

/*Function: setFirst
Author:	James Riback
Description: sets the key = passed in value
Inputs: user value
*/
template<class F, class S>
void Pair<F, S>::setFirst(F value)
{
	this->key = value;
}
/*Function: setSecond
Author:	James Riback
Description: sets the value = passed in value.
Inputs: user value
*/
template<class F, class S>
void Pair<F, S>::setSecond(S value)
{
	this->value = value;
}
/*Function: equals
Author:	James Riback
Description: helper function that returns true if pairs are equal, else false.
Inputs: a Pair value
Outputs: a boolean true or false
*/
template<class F, class S>
bool Pair<F, S>::equals(Pair &value) {
	return (value.getFirst() == this->getFirst() && value.getSecond() == this->getSecond());
}

/*Function: ==
Author:	James Riback
Description: overloaded operator==
Inputs: a Pair value
Outputs: a boolean true or false
*/
template<class F, class S>
bool Pair<F, S>::operator==(Pair &value)
{
	return equals(value);
}
/*Function: !=
Author:	James Riback
Description: overloaded operator!=
Inputs: a Pair value
Outputs: a boolean true or false
*/
template<class F, class S>
bool Pair<F, S>::operator!=(Pair &value)
{
	return !equals(value);
}
#endif