#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string>

#include "../../include/exprtk/exprtk.hpp"
#include "../../src/Gen/Generate.h"

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
	Pol pol = getRandomPol(rand() % 5 + 1);
	
	double c = trig_function(pol._str);
	for(int i = 0; i < 1000; ++i)
	{
		if(abs(c - pol._num) > 0.0001)
			goto END;
	}
	printf("Check");
	
	END:
	return 0;
}