echo on
querymain.exe data/storyDataFile < data/Alice
allocPtr.exe < data/alloc
allocSP.exe < data/alloc
usealloc.exe < data/storyDataFile

for %%i in ( oknew.exe release.exe 
		   unique.exe UP.exe usealloc2.exe useBlob.exe weak.exe ) do %%i
