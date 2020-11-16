#include <iostream>
#include "graphyRestService.h"
#include "graphyJsonModule.h"
#include "graphyFileSelector.h"
#include "graphyQMLEngine.h"

int main()
{
    std::cout << "Module test: " << graphyRestService::test() << " " << graphyJsonModule::test() <<
                 " " << graphyFileSelector::test() << " " << graphyQMLEngine::test() <<std::endl;
	return 0;
}
