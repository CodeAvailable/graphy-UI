#include "graphyFileSelector.h"
#include "graphyJsonModule.h"
#include "graphyQMLEngine.h"
#include "graphyRestService.h"
#include "window.h"

#include <QApplication>
#include <iostream>

int main(int argc, char** argv)
{
	QApplication app(argc, argv);
	Window window;

	std::cout << "Module test: " << graphyRestService::test() << " " << graphyJsonModule::test() << " " << graphyFileSelector::test() << " " << graphyQMLEngine::test()
	          << std::endl;

	window.show();
	return app.exec();
}
