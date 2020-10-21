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

#ifndef SALES_DATA_H
#define SALES_DATA_H

#include "Version_test.h"

#include <string>

struct Sales_data {
	std::string bookNo;
#ifdef IN_CLASS_INITS
	unsigned units_sold = 0;
	double revenue = 0.0;
#else
	unsigned units_sold;  
	double revenue;
#endif
};
#endif
