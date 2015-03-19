#include <stdio.h>
#include "sampclass.h"

/****** member functions of Class1 ******/

Class1::Class1() {
	m_i1 = 1;
	printf("m_i1 in Class1::Class1() = %d\n", m_i1);
}

Class1::~Class1() {
	printf("m_i1 in Class1::~Class1() = %d\n", m_i1);
}

int Class1::memfun1(int i) {
	m_i1 += i;
	printf("m_i1 = %d\n", m_i1);
	return m_i1;
}

/****** member functions of Class2 ******/

Class2::Class2() {
	printf("Class2::Class2() called\n");
}

Class2::~Class2() {
	printf("Class2::~Class2() called\n");
}

void Class2::memfun1(Class1 *pc) {
	pc->memfun1(10); //set m_i1 to 10
}

Class1 *Class2::memfun2(int i) {
	Class1 *retval;
	retval = new Class1();
	retval->memfun1(i);
	return retval;
}

Class1 *Class2::memfun3(int i, Class1 **ppc) {
	Class1 *pc;
	pc = *ppc;
	return &pc[i];
}

int Class2::memfun4(Class1 *apc[NUM]) {
	int i;
	for (i = 0; i < NUM; i++) {
		if(apc[i]) {
			apc[i]->memfun1(i);
		}
	}
	return 0;
}

int Class2::memfun5(int num, Class1 *pc) {
	int i;
	for(i=0; i<num; i++) {
		pc[i].memfun1(1000+i);
	}
	return 0;
}
