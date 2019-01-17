#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string>

#include "pch.h"
#include "../../src/Gen/Generate.h"
#include "../../src/macro.h"

#ifndef _PCH
#error Missing precompiled header
#endif//_PCH

double trig_function(std::string expression_string)
{
	typedef exprtk::symbol_table<double> symbol_table_t;
	typedef exprtk::expression<double>     expression_t;
	typedef exprtk::parser<double>             parser_t;
	
	double x = double(1);

	symbol_table_t symbol_table;
	symbol_table.add_variable("x",x, true);

	expression_t expression;
	expression.register_symbol_table(symbol_table);

	parser_t parser;
	parser.compile(expression_string,expression);

	double y = expression.value();
	return y;
}

int main()
{
	using namespace Generate;

	srand((unsigned)time(NULL));
	Pol pol;
	double c;
	for(int i = 0; i < 1000; ++i)
	{
#ifdef TRACE_ON
		printf("Test No.%d:\n", i);
		pol = getRandomPol(3);
#else
		Pol pol = getRandomPol(rand() % 5 + 1);
#endif
		c = trig_function(pol._str);
		if(abs(c - pol._num)/c > 0.0001)
			goto END;
	}
	printf("Check");

	END:
	return 0;
}