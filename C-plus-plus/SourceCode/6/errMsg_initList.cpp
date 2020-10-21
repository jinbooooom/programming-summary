/*
 * This file contains code from "C++ Primer, Fifth Edition", by Stanley B.
 * Lippman, Josee Lajoie, and Barbara E. Moo, and is covered under the
 * copyright and warranty notices given in that book:
 * 
 * "Copyright (c) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E. Moo."
 * 
 * 
 * "The authors and publisher have taken care in the preparation of this book,
 * but make no expressed or implied warranty of any kind and assume no
 * responsibility for errors or omissions. No liability is assumed for
 * incidental or consequential damages in connection with or arising out of the
 * use of the information or programs contained herein."
 * 
 * Permission is granted for this code to be used for educational purposes in
 * association with the book, given proper citation if and when posted or
 * reproduced.Any commercial use of this code requires the explicit written
 * permission of the publisher, Addison-Wesley Professional, a division of
 * Pearson Education, Inc. Send your request for permission, stating clearly
 * what code you would like to use, and in what specific way, to the following
 * address: 
 * 
 * 	Pearson Education, Inc.
 * 	Rights and Permissions Department
 * 	One Lake Street
 * 	Upper Saddle River, NJ  07458
 * 	Fax: (201) 236-3290
*/ 

#include "Version_test.h"  

#include <vector>
using std::vector;

#include <string>
using std::string; 

#include <iostream>
using std::cout; using std::endl;

#ifdef INITIALIZER_LIST
#include <initializer_list>
using std::initializer_list;
#endif

#include <sstream>
using std::ostringstream;

// chapter 7 will explain the code used in defining ErrCode
struct ErrCode { 
	ErrCode(int i) : num(i) { }  // initializes objects of type ErrCode
	string msg()                 // member function of ErrCode
	{ ostringstream s; s << "ErrCode " << num; return s.str(); }
	int num;  // data member, note uninitialized
};

#ifdef INITIALIZER_LIST
// version that takes an ErrCode and a list of strings
void error_msg(ErrCode e, initializer_list<string> il)
{
	cout << e.msg() << ": ";
	for (const auto &elem : il)
		cout << elem << " " ;
	cout << endl;
}
#else
// version that takes an ErrCode and pointers to a range of strings
void error_msg(ErrCode e, const string *beg, const string *end)
{
	cout << e.msg() << ": ";
	while (beg != end)
		cout << *beg++ << " ";
	cout << endl;
}
#endif

#ifdef INITIALIZER_LIST
// overloaded version takes only a list of strings
void error_msg(initializer_list<string> il)
{
	for (auto beg = il.begin(); beg != il.end(); ++beg)
		cout << *beg << " " ;
	cout << endl;
}
#else
// overloaded version that takes only pointers to a range of strings
void error_msg(const string *beg, const string *end)
{
	while (beg != end)
		cout << *beg++ << " " ;
	cout << endl;
}
#endif

// function to illustrate list initializing return value
vector<string> functionX()
{
	string expected = "description", actual = "some other case";
	// . . .
#ifdef INITIALIZER_LIST
	if (expected.empty())
		return {};  // return an empty vector
	else if (expected == actual)
		return {"functionX", "okay"}; // return list-initialized vector
	else 
		return {"functionX", expected, actual}; 
#else
	vector<string> retVals; // local variable that we'll return
	if (expected.empty())
		return retVals;  // return an empty vector
	else if (expected == actual) {
		retVals.push_back("functionX"); // build the vector 
		retVals.push_back("okay");
		return retVals;                 // and return it 
	} else {
		retVals.push_back("functionX");
		retVals.push_back(expected);
		retVals.push_back(actual);
		return retVals;  // return the vector
	}
#endif
}
	
int main()
{
	string expected = "description", actual = "some other case";
#ifdef INITIALIZER_LIST
	initializer_list<int> li = {0,1,2,3};
#else
	vector<int> li;
	for (int i = 0; i < 4; ++i)
		li.push_back(i);
#endif

	// expected, actual are strings 
	if (expected != actual)
#ifdef INITIALIZER_LIST
		error_msg({"functionX", expected, actual});
#else
		{ const string arr[] = {"functionX", expected, actual};
		  error_msg(begin(arr), end(arr)); }
#endif
	else
#ifdef INITIALIZER_LIST
		error_msg({"functionX", "okay"});
#else
		{ const string arr[] = {"functionX", "okay"};
		  error_msg(begin(arr), end(arr)); }
#endif

	// expected, actual are strings 
	if (expected != actual)
#ifdef INITIALIZER_LIST
		error_msg(ErrCode(42), {"functionX", expected, actual});
#else
		{ const string arr[] = {"functionX", expected, actual};
		  error_msg(ErrCode(42), begin(arr), end(arr)); }
#endif
	else
#ifdef INITIALIZER_LIST
		error_msg(ErrCode(0), {"functionX", "okay"});
#else
		{ const string arr[] = {"functionX", "okay"};
		  error_msg(ErrCode(0), begin(arr), end(arr)); }
#endif
	
	// can pass an empty list, calls second version of error_msg
#ifdef INITIALIZER_LIST
	error_msg({}); // prints blank line
#else
	error_msg(nullptr, nullptr);   // prints blank line
#endif

	// call function that list initializes its return value
	// results is a vector<string>
	auto results = functionX();
	for (auto i : results) 
		cout << i << " ";
	cout << endl;
}

