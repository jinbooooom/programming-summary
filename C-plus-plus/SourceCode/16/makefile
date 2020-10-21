# executable files for this directory
OBJECTS = Array.exe array-parms4.exe \
		  compare.exe compareDef.exe compareSpec.exe \
		  debug.exe flip.exe multiset.exe \
		  overloaded.exe overSpec.exe qm.exe \
		  SP.exe special.exe specialized.exe \
		  trail-ret.exe useBlob.exe useChcking.exe \
		  Vecmain.exe
# These files use variadic templates, and cannot be compiled
# under Version 11.00.50522.1
#expansion.exe variadic.exe variadic3.exe 

# tells make to use the file "..\MS_makefile_template", which
# defines general rules for making .obj and .exe files
include ..\MS_makefile_template

LOCFLAGS = 

SP.obj: DebugDelete.h

compareDef.obj multiset.obj variadic.obj variadic3.obj Sales_data.obj: Sales_data.h

compareDef.exe: compareDef.obj Sales_data.obj
	$(CPP) $(CPPFLAGS) $(LOCFLAGS) compareDef.obj Sales_data.obj 

variadic.exe: variadic.obj Sales_data.obj
	$(CPP) $(CPPFLAGS) $(LOCFLAGS) variadic.obj Sales_data.obj 

variadic3.exe: variadic3.obj Sales_data.obj
	$(CPP) $(CPPFLAGS) $(LOCFLAGS) variadic3.obj Sales_data.obj 

multiset.exe: multiset.obj Sales_data.obj
	$(CPP) $(CPPFLAGS) $(LOCFLAGS) multiset.obj Sales_data.obj 

qm.exe: qm.obj build.obj 
	$(CPP) $(CPPFLAGS) $(LOCFLAGS) qm.obj build.obj 

specialized.exe: debug.cpp
	$(CPP) -D SPECIALIZED $(CPPFLAGS) $(LOCFLAGS) /Fespecialized debug.cpp 

overloaded.exe: debug.cpp
	$(CPP) -D OVERCHAR $(CPPFLAGS) $(LOCFLAGS) /Feoverloaded debug.cpp

debug.exe: debug.cpp
	$(CPP) -D DEBUG $(CPPFLAGS) $(LOCFLAGS) debug.cpp

