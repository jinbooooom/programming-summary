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

/* This file uses list initialization, which is a feature that the
 * MS compiler may not yet support.  This file (and other source files)
 * uses preprocessor facilities to conditionally compile code that uses
 * list initialization or that uses a workaround instead.  
 *
 * Briefly, conditional compilation uses preprocessor variables
 * and #ifdef directives (see Section 2.6.3) to decide which code
 * to compile:
 *
 *     #ifdef VARIABLE_NAME
 *          code1
 *     #else
 *          code2
 *     #endif
 *
 * If there is a #define for VARIABLE_NAME then code1 will be compiled
 * and code2 is skipped.  Otherwise code1 is skipped and code2 is compiled.
 *
 * Depending on the version of the compiler that you are running,
 * the file ..\Version_test.h will either contain a #define for LIST_INIT
 * or not.  If it does #define LIST_INIT then the code that uses list
 * initialization will be compiled.  Otherwise, the workaround will be used.
 *
 * Section 6.5.3 covers conditional compilation in more detail. 
*/

#include "Version_test.h"  

#include "Sales_item.h"
#include <iostream>
#include <string>

int main() {

	int v1(1024);    // direct-initialization, functional form
#ifdef LIST_INIT
	int v2{1024};    // direct-initialization, list initializer form
#else
	int v2(1024);    // use parens if list-initialization not yet supported
#endif
	int v3 = 1024;   // copy-initialization
#ifdef LIST_INIT
	int v4 = {1024}; // copy-initialization, list initializer form
#else
    int v4 = 1024;
#endif

	// alternative ways to initialize string from a character string literal
	std::string titleA = "C++ Primer, 5th Ed.";
	std::string titleB("C++ Primer, 5th Ed.");
	std::string all_nines(10, '9');  // all_nines = "9999999999"

	return 0;
}
