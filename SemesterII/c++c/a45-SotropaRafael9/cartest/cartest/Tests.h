#pragma once
#include "Repository.h"
#include <iostream>
#include <cassert>

class Test {
public:
	Test();
	void testAdd();
	void testRemove();
	void testSortColour();
	void testSortManufacturerandModel();
	void run_all_test();
};