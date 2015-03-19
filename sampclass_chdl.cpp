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
