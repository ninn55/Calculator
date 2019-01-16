#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "../../include/tinyexpr/tinyexpr.h"
#include "../../src/Gen/Generate.h"

int main()
{
	using namespace Generate;
	srand((unsigned)time(NULL)); 
	Pol pol = getRandomPol(rand() % 5 + 1);
	int error;
	const char *cstr = pol._str.c_str();
	double c = te_interp(cstr, &error);
	
	for(int i = 0; i < 1000; ++i)
	{
		if(abs(c - pol._num) > 0.0001)
			goto END;
	}
	printf("Check");
	
	END:
	return 0;
}