
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

    int main() {
int num, c;
	srand(time(NULL));

	for (int i= 0;i<50; i++)
	{
		num = 10 + rand() % (120 - 10);
		std::cout << num << " " ;
	}
    std::cout<<"\n";
    for (int i= 0;i<50; i++)
	{
		num = 10 + rand() % (120 - 10);
		std::cout << num << " " ;
	}
    return 0;
}