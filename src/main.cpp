#include "Gen/Generate.h"
#include "macro.h"

int main(void)
{
	using Generate::getRandomPol;
	using std::cout;
	using std::endl;
	using Generate::Pol;
#ifdef TRACE_ON
	Pol pol = getRandomPol(2);
#else
	Pol pol = getRandomPol(rand() % 5 + 1);
#endif
	cout << pol._str << endl;
	cout << "Expect:" << pol._num << endl;
	
	return 0;
}