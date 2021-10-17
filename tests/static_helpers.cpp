/* SPDX-License-Identifier: MIT */

#include <cstdio>
#include <cassert>
#include <WotoMd.h>

int main(void)
{
	assert(toBold("AAAAAA") == "*AAAAAA*");
	assert(toBold("*A*A*A*A*A*A") == "*\\*A\\*A\\*A\\*A\\*A\\*A*");

	assert(toBold("AAAAAA", true) == "*AAAAAA* ");
	assert(toBold("*A*A*A*A*A*A", true) == "*\\*A\\*A\\*A\\*A\\*A\\*A* ");

	assert(toUnderline("AAAAAA") == "-AAAAAA-");
	assert(toUnderline("-A-A-A-A-A-A") == "-\\-A\\-A\\-A\\-A\\-A\\-A-");

	assert(toUnderline("AAAAAA", true) == "-AAAAAA- ");
	assert(toUnderline("-A-A-A-A-A-A", true) == "-\\-A\\-A\\-A\\-A\\-A\\-A- ");

	return 0;
}
