#ifndef TEST_H
#define TEST_H

#include <iostream>
#include "LinkedListOfInts.h"

class Test 
{
public:
	Test();
	void run();

private:
	void PassFail(bool b);
	void length();
	void search();
	void contents();

};

#endif