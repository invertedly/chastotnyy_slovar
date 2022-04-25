#include "pch.h"

#include "../chastotnyy-slovar/word_frequency.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

//TEST(TestCaseName, TestName) {
//  EXPECT_EQ(1, 1);
//  EXPECT_TRUE(true);
//}

using namespace word_frequency;
using namespace std;

int main()
{
	istringstream input("abcd abcd abc a a a 0");
	Dict* dict = Dict::create(input, container::map);
	dict->output(cout);
	dict->destroy();

	_CrtDumpMemoryLeaks();

	return EXIT_SUCCESS;
}