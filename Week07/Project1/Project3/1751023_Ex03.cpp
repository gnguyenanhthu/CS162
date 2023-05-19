#include "Function.h"
 
int main()
{
	int a[10] = { 1,2,4,6,8,10,12,14,12,12 };
	output(a, 10); 
	cout << endl;
	
	outputreverse(a, 10, 0); 
	cout << endl;

	cout << "Sum of positive numbers: " << sumofposint(a, 10) << endl; 

	cout << countdistinct(a, 10) << endl;

	if (checkoddnumb(a, 10))
		cout << "No odd number." << endl;
	else
		cout << "There is odd number." << endl;

	cout << "Max value: " << maxvalue(a, 10) << endl;

	system("pause");
	return 0;
}