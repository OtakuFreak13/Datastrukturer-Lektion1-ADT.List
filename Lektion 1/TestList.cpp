#include "List.h"




int main()
{
	//test 1
	List<int> nrList;//Tom lista
	nrList.insertAt(100, 0);//listan inneh�ller 100
	nrList.insertAt(80, 0);//listan inneh�ller 80 100
	nrList.printAll();//skriver ut 80 100

	//test 2
	nrList.insertAt(90, 1);//80 90 100
	nrList.printAll();//skriver ut 80 90 100

	//test 3
	nrList.insertAt(110, 3);//80 90 100 110
	nrList.printAll();//skriver ut 80 90 100 110




	getchar();
	return 0;
}