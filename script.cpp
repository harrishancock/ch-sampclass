#include "sampclass.h"
int main() {
	class Class1 c1;
	class Class1 *pc1, *pc2, *pc3;
	class Class1 ac[NUM];
	class Class1 *apc[NUM];
	class Class2 b;
	int i;
	b.memfun1(&c1);
	pc1 = b.memfun2(20);
	pc2 = new Class1[2];
	pc2[0].memfun1(10);
	pc2[1].memfun1(20);
	pc3 = b.memfun3(1, &pc2);
	pc3->memfun1(100);

	for (i = 0; i < NUM; i++) {
		apc[i] = new Class1;
	}
	b.memfun4(apc);
	b.memfun5(NUM, ac);

	delete pc1;
#ifdef _CH_
	delete [2] pc2;
#else
	delete [] pc2;
#endif
	for (i = 0; i < NUM; i++) {
		delete apc[i];
	}
	return 0;
}
