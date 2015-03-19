target: libsampclass.dl script.exe

libsampclass.dl: sampclass.o sampclass_chdl.o
	ch dllink libsampclass.dl cplusplus sampclass.o sampclass_chdl.o

sampclass.o: sampclass.cpp
	ch dlcomp libsampclass.dl cplusplus sampclass.cpp

sampclass_chdl.o: sampclass_chdl.cpp
	ch dlcomp libsampclass.dl cplusplus sampclass_chdl.cpp

script.exe: script.o sampclass.o
	ch dllink script.exe cplusplus script.o sampclass.o

script.o: script.cpp
	ch dlcomp libsampclass.dl cplusplus script.cpp

test:
	script.exe > test1
	ch script.cpp > test2
	test1 test2

clean:
	rm -f *.o *.dl *.obj *.exp *.lib *.exe test1 test2