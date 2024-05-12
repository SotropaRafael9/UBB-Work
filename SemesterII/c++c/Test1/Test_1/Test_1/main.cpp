#include "Domain.h"
#include "Repository.h"
#include "Service.h"
#include "UI.h"
#include <iostream>

using namespace std;

int main()
{
	Repo repository{};
	Service service{ repository };
	UI ui{ service };
	ui.run_menu();
}