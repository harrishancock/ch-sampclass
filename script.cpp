#include "sampclass.h"
int main() {
	class Class1 *pc2;

	//class Class1 ac[NUM]; // This line crashes in Windows

	pc2 = new Class1[2]; // This line crashes in Windows
	pc2[0].memfun1(10);
	pc2[1].memfun1(20);

#ifdef _CH_
	delete [2] pc2;
#else
	delete [] pc2;
#endif
	return 0;
}
