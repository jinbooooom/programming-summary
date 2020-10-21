# executable files for this directory
OBJECTS = FolderMain.exe HasPtrUseCount.exe \
		  HasPtrValueLike.exe copyNoMove.exe \
		  moveHP.exe serial.exe StrFolderMain.exe \
		  useStrVec.exe substr.exe 

# tells make to use the file "..\MS_makefile_template", which
# defines general rules for making .obj and .exe files
include ..\MS_makefile_template

LOCFLAGS = -I..\1 -I..\7

Folder.obj FolderMain.obj: Folder.h
StrFolder.obj StrFolderMain.obj: StrFolder.h String.h
String.obj: String.h
useStrVec.obj StrVec.obj: StrVec.h

useStrVec.exe: useStrVec.obj StrVec.obj 
	$(CPP) $(CPPFLAGS) useStrVec.obj StrVec.obj  

FolderMain.exe: FolderMain.obj Folder.obj
	$(CPP) $(CPPFLAGS) FolderMain.obj Folder.obj 

StrFolderMain.exe: StrFolderMain.obj StrFolder.obj String.obj
	$(CPP) $(CPPFLAGS) StrFolderMain.obj StrFolder.obj String.obj 

