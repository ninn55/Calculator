#ifndef CALCULATOR_GEN_GENERATE_H_
#define CALCULATOR_GEN_GENERATE_H_

//include
#include <vector>
#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>

using std::string;
namespace Generate
{
	struct Pol
	{
		string _str;
		double _num;
		int _property;//+-:0  */:1  ():2
	};

	enum class Oper
	{
		Add,
		Sub,
		Mul,
		Dev,

		MAX_OPER

	};

	Pol getRandomPol(int depth);
}
#endif //CALCULATOR_GEN_GENERATE_H_