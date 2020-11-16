#include <iostream>
#include "graphyRestService.h"
#include "graphyJsonModule.h"

int main()
{
    std::cout << "Module test: " << graphyRestService::test() << " " << graphyJsonModule::test() << std::endl;
	return 0;
}
