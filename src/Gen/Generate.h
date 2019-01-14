#ifndef CALCULATOR_GEN_GENERATE_H_
#define CALCULATOR_GEN_GENERATE_H_

//include
#include <vector>
#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>

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

#endif //CALCULATOR_GEN_GENERATE_H_