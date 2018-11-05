#include "Test.h"

Test::Test()
{

}

void Test::run()
{
	length();
	search();
	contents();
}

void Test::PassFail(bool b)
{
	if(b)
	{
		std::cout << "PASS\n";
	}
	else
	{
		std::cout << "FAIL\n";
	}
}

void Test::length()
{
	std::cout << "\n*---Length---*\n";
	LinkedListOfInts* ls = new LinkedListOfInts();
	std::cout << "isEmpty recognizes empty list: ";
	PassFail(ls->isEmpty());
	std::cout << "size init to 0: ";
	PassFail(ls->size()==0);

	std::cout << "size updated after 1 addFront: ";
	ls->addFront(1);
	PassFail(ls->size()==1);
	std::cout << "isEmpty recognizes non-empty list: ";
	PassFail(!ls->isEmpty());

	std::cout << "size updated after removeFront: ";
	ls->removeFront();
	PassFail(ls->size()==0);

	delete ls;
	ls = new LinkedListOfInts();
	std::cout << "---\nsize updated after 1 addBack: ";
	ls->addBack(1);
	PassFail(ls->size()==1);

	std::cout << "size updated after removeBack: ";
	ls->removeBack();
	PassFail(ls->size()==0);

	delete ls;
	ls = new LinkedListOfInts();
	std::cout << "---\nsize after 50 addFront's: ";
	for(int i = 49;i>=0;i--)
	{
		ls->addFront(i);
	}
	std::vector<int> v = ls->toVector();
	PassFail(v.size()==ls->size());

	delete ls;
	ls = new LinkedListOfInts();
	std::cout << "---\nsize after 50 addBack's: ";
	for(int i = 49;i>=0;i--)
	{
		ls->addBack(i);
	}
	v = ls->toVector();
	PassFail(v.size()==ls->size());

	delete ls;
	ls = new LinkedListOfInts();
	std::cout << "---\nRemoveBack throws exception on empty list: ";
	try
	{
		ls->removeBack();
		PassFail(false);
	}
	catch(std::exception e)
	{
		PassFail(true);
	}

	delete ls;
	ls = new LinkedListOfInts();
	std::cout << "---\nRemoveFront throws exception on empty list: ";
	try
	{
		ls->removeFront();
		PassFail(false);
	}
	catch(std::exception e)
	{
		PassFail(true);
	}

	delete ls;
	ls = nullptr;
}

void Test::search()
{
	std::cout << "\n*---Search---*\n";
	LinkedListOfInts* ls = new LinkedListOfInts();
	std::cout << "Search empty list returns false: ";
	PassFail(!ls->search(1));
	std::cout << "Search after addFront w/out value: ";
	ls->addFront(0);
	PassFail(!ls->search(1));

	delete ls;
	ls = new LinkedListOfInts();
	std::cout << "---\nSearch after addFront w/ value: ";
	ls->addFront(1);
	PassFail(ls->search(1));
	std::cout << "Search after removeFront: ";
	ls->removeFront();
	PassFail(!ls->search(1));

	std::cout << "Search with duplicate: ";
	ls->addFront(1);
	PassFail(ls->search(1));

	delete ls;
	ls = new LinkedListOfInts();
	std::cout << "---\nSearch after addBack w/out value: ";
	ls->addBack(0);
	PassFail(!ls->search(1));

	delete ls;
	ls = new LinkedListOfInts();
	std::cout << "---\nSearch after addBack w/ value: ";
	ls->addBack(1);
	PassFail(ls->search(1));
	std::cout << "Search after removeBack: ";
	ls->removeBack();
	PassFail(!ls->search(1));

	delete ls;
	ls = new LinkedListOfInts();
	std::cout << "---\nSearch after 50 addBack's w/out value: ";
	for(int i = 1;i<=50;i++)
	{
		ls->addBack(i);
	}
	PassFail(!ls->search(0));

	delete ls;
	ls = new LinkedListOfInts();
	std::cout << "---\nSearch after 50 addFront's w/out value: ";
	for(int i = 1;i<=50;i++)
	{
		ls->addFront(i);
	}
	PassFail(!ls->search(0));

	delete ls;
	ls = new LinkedListOfInts();
	std::cout << "---\nSearch after 50 addBack's w/ value: ";
	for(int i = 1;i<=50;i++)
	{
		ls->addBack(i);
	}
	PassFail(ls->search(1));

	delete ls;
	ls = new LinkedListOfInts();
	std::cout << "---\nSearch after 50 addFront's w/ value: ";
	for(int i = 1;i<=50;i++)
	{
		ls->addFront(i);
	}
	PassFail(ls->search(1));

}

void Test::contents()
{
	std::cout << "\n*---contents---*\n";
	LinkedListOfInts* ls = new LinkedListOfInts();
	std::cout << "---\ncontents after 1 addBack: ";
	ls->addBack(1);
	std::vector<int> v = ls->toVector();
	PassFail(v[0]==1);

	delete ls;
	ls = new LinkedListOfInts();
	std::cout << "---\ncontents after 1 addFront: ";
	ls->addFront(1);
	v = ls->toVector();
	PassFail(v[0]==1);

	delete ls;
	ls = new LinkedListOfInts();
	std::cout << "---\ncontents after 50 addBack's: ";
	for(int i = 0;i<50;i++)
	{
		ls->addBack(i);
	}
	v = ls->toVector();
	bool match = true;
	for(int i = 0;i<50;i++)
	{
		if(v[i]!=i)
		{
			match = false;
			break;
		}
	}
	PassFail(match);

	delete ls;
	ls = new LinkedListOfInts();
	std::cout << "---\ncontents after 50 addFront's: ";
	for(int i = 49;i>=0;i--)
	{
		ls->addFront(i);
	}
	v = ls->toVector();
	match = true;
	for(int i = 0;i<50;i++)
	{
		if(v[i]!=i)
		{
			match = false;
			break;
		}
	}
	PassFail(match);
}