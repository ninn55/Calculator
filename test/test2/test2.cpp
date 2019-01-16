#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "../../include/tinyexpr/tinyexpr.h"
#include "../../src/Gen/Generate.h"
#include "../../src/macro.h"

int main()
{
	using namespace Generate;
	srand((unsigned)time(NULL)); 
	int error;
	
	for(int i = 0; i < 1000; ++i)
	{
#ifdef TRACE_ON
		printf("Test No.%d:\n", i);
		Pol pol = getRandomPol(3);
#else
		Pol pol = getRandomPol(rand() % 5 + 1);
#endif
		const char *cstr = pol._str.c_str();
		double c = te_interp(cstr, &error);

		if(abs(c - pol._num)/c > 0.0001)
			goto END;
	}
	printf("Check");
	
	END:
	return 0;
}