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
	
	T x = T(1);

	symbol_table_t symbol_table;
	symbol_table.add_variable("x",x, true);

	expression_t expression;
	expression.register_symbol_table(symbol_table);

	parser_t parser;
	parser.compile(expression_string,expression);

	T y = expression.value();
	return y;
}

int main()
{
	using namespace Generate;
	srand((unsigned)time(NULL)); 
	Pol pol = getRandomPol(rand() % 5 + 1);
	
	double c = trig_function(pol._str);
	if(abs(c - pol._num) < 0.0001) printf("Check");
	return 0;
}