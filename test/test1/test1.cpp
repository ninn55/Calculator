#include <cstdio>
#include <string>

#include "../../include/exprtk/exprtk.hpp"

template <typename T>
void trig_function()
{
   typedef exprtk::symbol_table<T> symbol_table_t;
   typedef exprtk::expression<T>     expression_t;
   typedef exprtk::parser<T>             parser_t;

   std::string expression_string = "1*10 + (-1)";

   T x = T(1);

   symbol_table_t symbol_table;
   symbol_table.add_variable("x",x, true);

   expression_t expression;
   expression.register_symbol_table(symbol_table);

   parser_t parser;
   parser.compile(expression_string,expression);

      T y = expression.value();
      printf("%19.15f\n", y);
}

int main()
{
   trig_function<double>();
   return 0;
}