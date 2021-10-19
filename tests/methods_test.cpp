/* SPDX-License-Identifier: MIT */

#include <cstdio>
#include <cassert>
//#include "../WotoMd.h"
#include "../src/WotoMd.h"

int main(void)
{
	assert(mdparser::toBold("AAAAAA") == "*AAAAAA*");
	assert(mdparser::toBold("*A*A*A*A*A*A") == "*\\*A\\*A\\*A\\*A\\*A\\*A*");

	assert(mdparser::toBold("AAAAAA", true) == "*AAAAAA* ");
	assert(mdparser::toBold("*A*A*A*A*A*A", true) == "*\\*A\\*A\\*A\\*A\\*A\\*A* ");

	assert(mdparser::toUnderline("AAAAAA") == "-AAAAAA-");
	assert(mdparser::toUnderline("-A-A-A-A-A-A") == "-\\-A\\-A\\-A\\-A\\-A\\-A-");

	assert(mdparser::toUnderline("AAAAAA", true) == "-AAAAAA- ");
	assert(mdparser::toUnderline("-A-A-A-A-A-A", true) == "-\\-A\\-A\\-A\\-A\\-A\\-A- ");
	return 0;
}
