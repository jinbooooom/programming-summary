# executable files for this directory
OBJECTS = Animal.exe book.exe class.exe \
		  ex-over.exe inherit.exe mi-scope.exe\
          over.exe over2.exe spec.exe \
          usingDirective.exe virt-inherit.exe

# tells make to use the file "..\MS_makefile_template", which
# defines general rules for making .obj and .exe files
include ..\MS_makefile_template

LOCFLAGS = /I..\16

Animal.o: Animal.h
book.o: ../16/Sales_data.h bookexcept.h
virt-inherit.o: Animal_virtual_baseVers.h

book.exe: book.obj bookexcept.h Sales_data.obj
	$(CPP) $(CPPFLAGS) book.obj Sales_data.obj 
