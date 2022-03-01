# executable files for this directory
OBJECTS = allocPtr.exe allocSP.exe \
		  oknew.exe querymain.exe release.exe \
		  unique.exe UP.exe usealloc.exe usealloc2.exe \
		  useBlob.exe weak.exe 

# tells make to use the file "..\MS_makefile_template", which
# defines general rules for making .obj and .exe files
include ..\MS_makefile_template

# 7 has Sales_data files, 6 has make_plural
LOCFLAGS = -I..\7 -I..\6

querymain.exe: querymain.obj TextQuery.obj
	$(CPP) $(CPPFLAGS) $(LOCFLAGS) querymain.obj TextQuery.obj 

