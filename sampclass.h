#ifndef _SAMPCLASS_H_
#define _SAMPCLASS_H_

#define NUM 2

#ifdef _CH_
#include <dlfcn.h>
void *g_sample_dlhandle = dlopen("libsampclass.dl", RTLD_LAZY);
if(g_sample_dlhandle == NULL) {
	fprintf(_stderr, "Error: dlopen(): %s\n", dlerror());
	fprintf(_stderr, "       cannot get g_sample_dlhandle in sampclass.h\n");
	exit(-1);
}
void _dlclose_sampclass(void) {
	dlclose(g_sample_dlhandle);
}
atexit(_dlclose_sampclass);

class Class1 {
public:
	Class1();
	~Class1();
	int memfun1(int i);
};

#pragma importf <sampclass.chf>

#else /************************* for C++ space ******************/

class Class1 {
private:
	int m_i1;
public:
	Class1();
	~Class1();
	int memfun1(int i);
};

#endif

#endif /* _SAMPCLASS_H_ */