#include <stdio.h>
#include <ch.h>
#include "sampclass.h"

/****** member functions of Class1 ******/

EXPORTCH void Class1_Class1_chdl(void *varg) {
	ChInterp_t interp;
	ChVaList_t ap;
	class Class1 *c = new Class1();
	Ch_VaStart(interp, ap, varg);
	Ch_CppChangeThisPointer(interp, c, sizeof(Class1));
	Ch_VaEnd(interp, ap);
}

EXPORTCH void Class1_dClass1_chdl(void *varg) {
	ChInterp_t interp;
	ChVaList_t ap;
	class Class1 *c;
	Ch_VaStart(interp, ap, varg);
	c = Ch_VaArg(interp, ap, class Class1 *);
	if(Ch_CppIsArrayElement(interp))
		c->~Class1();
	else
		delete c;
	Ch_VaEnd(interp, ap);
	return;
}

EXPORTCH int Class1_memfun1_chdl(void *varg) {
	ChInterp_t interp;
	ChVaList_t ap;
	class Class1 *c;
	int i;
	int retval;
	Ch_VaStart(interp, ap, varg);
	c = Ch_VaArg(interp, ap, class Class1*);
	i = Ch_VaArg(interp, ap, int); /* get 1st arg */
	retval = c->memfun1(i);
	Ch_VaEnd(interp, ap);
	return retval;
}

/****** member functions of Class2 ******/

EXPORTCH void Class2_Class2_chdl(void *varg) {
	ChInterp_t interp;
	ChVaList_t ap;
	class Class2 *c = new Class2();
	Ch_VaStart(interp, ap, varg);
	Ch_CppChangeThisPointer(interp, c, sizeof(Class2));
	Ch_VaEnd(interp, ap);
}

EXPORTCH void Class2_dClass2_chdl(void *varg) {
	ChInterp_t interp;
	ChVaList_t ap;
	class Class2 *c;
	Ch_VaStart(interp, ap, varg);
	c = Ch_VaArg(interp, ap, class Class2 *);
	if(Ch_CppIsArrayElement(interp))
		c->~Class2();
	else
		delete c;
	Ch_VaEnd(interp, ap);
	return;
}

EXPORTCH void Class2_memfun1_chdl(void *varg) {
	ChInterp_t interp;
	ChVaList_t ap;
	class Class2 *c;
	class Class1 *pc;
	Ch_VaStart(interp, ap, varg);
	c = Ch_VaArg(interp, ap, class Class2*);
	pc = Ch_VaArg(interp, ap, class Class1*);
	c->memfun1(pc);
	Ch_VaEnd(interp, ap);
	return;
}

EXPORTCH class Class1 *Class2_memfun2_chdl(void *varg) {
	ChInterp_t interp;
	ChVaList_t ap;
	class Class2 *c;
	int i;
	class Class1 *retval;
	Ch_VaStart(interp, ap, varg);
	c = Ch_VaArg(interp, ap, class Class2*);
	i = Ch_VaArg(interp, ap, int);
	retval = c->memfun2(i);
	Ch_VaEnd(interp, ap);
	return retval;
}

EXPORTCH class Class1 *Class2_memfun3_chdl(void *varg) {
	ChInterp_t interp;
	ChVaList_t ap;
	class Class2 *c;
	int i;
	class Class1 **ppc;
	class Class1 *retval;
	Ch_VaStart(interp, ap, varg);
	c = Ch_VaArg(interp, ap, class Class2*);
	i = Ch_VaArg(interp, ap, int);
	ppc = Ch_VaArg(interp, ap, class Class1**);
	retval = c->memfun3(i, ppc);
	Ch_VaEnd(interp, ap);
	return retval;
}

EXPORTCH int Class2_memfun4_chdl(void *varg) {
	ChInterp_t interp;
	ChVaList_t ap;
	class Class2 *c;
	class Class1 **apc;
	int retval;
	Ch_VaStart(interp, ap, varg);
	c = Ch_VaArg(interp, ap, class Class2*);
	apc = Ch_VaArg(interp, ap, class Class1**);
	retval = c->memfun4(apc);
	Ch_VaEnd(interp, ap);
	return retval;
}

EXPORTCH int Class2_memfun5_chdl(void *varg) {
	ChInterp_t interp;
	ChVaList_t ap;
	class Class2 *c;
	class Class1 *pc;
	int num;
	int retval;
	Ch_VaStart(interp, ap, varg);
	c = Ch_VaArg(interp, ap, class Class2*);
	num = Ch_VaArg(interp, ap, int);
	pc = Ch_VaArg(interp, ap, class Class1*);
	retval = c->memfun5(num, pc);
	Ch_VaEnd(interp, ap);
	return retval;
}