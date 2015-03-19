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
