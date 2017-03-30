#include "List.h"




int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//test 1
	List<int> nrList;//Tom lista
	nrList.insertAt(100, 0);//listan innehåller 100
	nrList.insertAt(80, 0);//listan innehåller 80 100
	nrList.printAll();//skriver ut 80 100

	//test 2
	nrList.insertAt(90, 1);//80 90 100
	nrList.printAll();//skriver ut 80 90 100

	//test 3
	nrList.insertAt(110, 3);//80 90 100 110
	nrList.printAll();//skriver ut 80 90 100 110

	//test4 - remove
	nrList.remove(3);
	nrList.printAll();//Bör skriva ut 80 90 100

	nrList.remove(1);
	nrList.printAll();//Bör kriva ut 80 100

	//TODO testa att adda fler och remova





	getchar();
	return 0;
}