#include <iostream>
#include "Tests.h"
#include "UI.h"
#include <vector>
#include "UserRepo.h"



int main()
{
	test_all();
	std::vector<Dog> v1;
	std::vector<Dog> v2;
	Repository repo = Repository(&v1);
	UserRepo userRepo = UserRepo(&v2);
	Service service = Service(&repo);
	UserService userService = UserService(&userRepo);
	UI ui = UI(&service, &userService);
	ui.run_console();
}