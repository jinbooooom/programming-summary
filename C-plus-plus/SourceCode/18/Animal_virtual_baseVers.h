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

#include <string>
#include <iostream>

class Endangered {
public:
    enum Status { critical, environment, improving };
    Endangered(Status stat = improving): animal_status(stat) { }
    virtual ~Endangered() 
		{std::cout << "Endangered::~Endangered" << std::endl; }
    virtual std::ostream& print(std::ostream&) const
		{ return std::cout << "Endangered::print" << std::endl; }
    virtual void highlight() const
		{std::cout << "Endangered::highlighted" << std::endl; }
    // . . .
private:
    Status animal_status;
};

class ZooAnimal;
extern std::ostream&
operator<<(std::ostream&, const ZooAnimal&);

class ZooAnimal {
public:
#if defined(IN_CLASS_INITS) && defined(DEFAULT_FCNS)
    ZooAnimal() = default;
#else
	ZooAnimal(): exhibit_stat(false) { }
#endif
    ZooAnimal(std::string animal, bool exhibit,
              std::string family): nm(animal), 
                                   exhibit_stat(exhibit), 
                                   fam_name(family) { } 
    virtual ~ZooAnimal()
		{std::cout << "ZooAnimal::~ZooAnimal" << std::endl; }

    virtual std::ostream& print(std::ostream&) const
		{ return std::cout << "ZooAnimal::print" << std::endl; }
    virtual int population() const
		{std::cout << "ZooAnimal::population" << std::endl;  return 0;}

    // accessors
    std::string name() const { return nm; }
    std::string family_name() const { return fam_name; }
    bool onExhibit() const { return exhibit_stat; }
    // . . .
protected:
    std::string nm;
#ifdef IN_CLASS_INITS
    bool exhibit_stat = false;
#else
    bool exhibit_stat;
#endif
    std::string fam_name;
    // . . .
private:
};

// the order of the keywords public and virtual is not significant
class Raccoon : public virtual ZooAnimal {
public:
#if defined(IN_CLASS_INITS) && defined(DEFAULT_FCNS)
    Raccoon() = default;
#else
	Raccoon(): pettable_flag(false) { }
#endif
    Raccoon(std::string name, bool onExhibit=true);

    virtual std::ostream& print(std::ostream&) const
		{ return  std::cout << "Raccoon::print" << std::endl; }

    bool pettable() const {return pettable_flag;  }
    void pettable(bool petval) {pettable_flag = petval;}
    // . . .

protected:
#ifdef IN_CLASS_INITS
    bool pettable_flag = false;
#else
    bool pettable_flag;
#endif
    // . . .
};

class Bear : virtual public ZooAnimal {
public:
    // when the most derived class
    Bear(std::string name, bool onExhibit=true);
protected:
    // when an intermediate derived class
    Bear() : dance_flag(two_left_feet) { }

public:
    enum DanceType { two_left_feet, macarena, fandango };

    virtual std::ostream &print(std::ostream&) const
		{ return  std::cout << "Bear::print" << std::endl; }
    virtual std::string isA() const
		{ std::cout << "Bear::isA" << std::endl; return "Bear"; }
    int mumble(int)
		{ std::cout << "Bear::mumble" << std::endl; return 0; }
    void dance(DanceType) const
		{ std::cout << "Bear::dance" << std::endl; }

	virtual ~Bear() { std::cout << "Bear::~Bear" << std::endl; }
private:
    std::string name;
    DanceType dance_flag;
};

class Panda : public Bear,
              public Raccoon, public Endangered {
public:
#if defined(IN_CLASS_INITS) && defined(DEFAULT_FCNS)
    Panda() = default;
#else
	Panda(): sleeping_flag(false) { }
#endif
    Panda(std::string name, bool onExhibit=true);
    virtual std::ostream& print(std::ostream&) const
		{ return  std::cout << "Panda::print" << std::endl; }

    bool sleeping() const {return sleeping_flag;}
    void sleeping(bool newval) {sleeping_flag = newval;}
    // . . .

protected:
#ifdef IN_CLASS_INITS
    bool sleeping_flag = false;
#else
    bool sleeping_flag;
#endif
    // . . .
};


Bear::Bear(std::string name, bool onExhibit):
         ZooAnimal(name, onExhibit, "Bear") { }
#ifdef IN_CLASS_INITS
Raccoon::Raccoon(std::string name, bool onExhibit)
       : ZooAnimal(name, onExhibit, "Raccoon") { }
#else
Raccoon::Raccoon(std::string name, bool onExhibit)
       : ZooAnimal(name, onExhibit, "Raccoon"), pettable_flag(false) { }
#endif

Panda::Panda(std::string name, bool onExhibit)
      : ZooAnimal(name, onExhibit, "Panda"),
        Bear(name, onExhibit),
        Raccoon(name, onExhibit),
        Endangered(Endangered::critical),
        sleeping_flag(false)   { }

