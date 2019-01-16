#ifndef CALCULATOR_GEN_GENERATE_H_
#define CALCULATOR_GEN_GENERATE_H_

//include

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

namespace Generate
{
	struct Pol
	{
		string _str;
		double _num;
		int _property;//+-:0  */:1  ():2

		void present()
		{
			cout << _str << "=" << _num << endl;
		}
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