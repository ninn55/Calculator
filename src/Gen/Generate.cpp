//include
#include <vector>
#include <stdio.h>
#include <sstream>
#include "Generate.h"
#include "../macro.h"

namespace Generate
{	
	Pol getRandomPol(int depth)
	{
		--depth;
		Pol ret;
		bool isNumber = depth <= 0;
	
		if (isNumber)//number
		{
			ret._property = 2;
			ret._num = rand() - RAND_MAX / 2;
			if (abs(ret._num) > 1000)
				ret._num /= 100;
			std::stringstream ss;
			ss << (ret._num < 0 ? "(" : "") << ret._num << (ret._num < 0 ? ")" : "");
			ret._str = ss.str();
		}
		else
		{
			Oper type = Oper(rand() % (int)Oper::MAX_OPER);
			Pol pol1 = getRandomPol(depth);
			Pol pol2 = getRandomPol(depth);
			if (type == Oper::Add || type == Oper::Sub)
				ret._property = 0;
			else
				ret._property = 1;
			if (type == Oper::Dev && abs(pol2._num - 0) < 0.0001)
				type = Oper::Mul;
			bool forceBracket1 = rand() % 10 == 0;
			forceBracket1 |= pol1._property < ret._property;
			bool forceBracket2 = rand() % 10 == 0;
			forceBracket2 |= pol2._property < ret._property;
			{
				bool cndtn1 = (type == Oper::Sub) & (ret._property == 0);
				bool cndtn2 = (type == Oper::Dev) & (ret._property == 1);
				if(cndtn1 | cndtn2) forceBracket2 |= true;
			}
			ret._str += (forceBracket1 ? "(" : "") + pol1._str + (forceBracket1 ? ")" : "");
		
			constexpr int randomSpaceNum = 3;
			ret._str += string(rand() % randomSpaceNum, ' ');
			switch (type)
			{
			case Oper::Add:
				ret._str += "+";
				ret._num = pol1._num + pol2._num;
				break;
			case Oper::Sub:
				ret._str += "-";
				ret._num = pol1._num - pol2._num;
				break;
			case Oper::Mul:
				ret._str += "*";
				ret._num = pol1._num * pol2._num;
				break;
			case Oper::Dev:
				ret._str += "/";
				ret._num = pol1._num / pol2._num;
				break;
			}
			ret._str += string(rand() % randomSpaceNum, ' ');
			ret._str += (forceBracket2 ? "(" : "") + string(rand() % randomSpaceNum, ' ') 
				+ pol2._str + string(rand() % randomSpaceNum, ' ')
				+(forceBracket2 ? ")" : "");
#ifdef TRACE_ON
		    printf("Depth:%d\n", depth);
			pol1.present();
			pol2.present();
			ret.present();
#endif
		}
		return ret;
	}
}


