#include "Gen/Generate.h"

int main(void)
{
	using Generate::getRandomPol;
	using std::cout;
	using std::endl;
	using Generate::Pol;
	
	Pol pol = getRandomPol(rand() % 5 + 1);
	cout << pol._str << endl;
	cout << "Expect:" << pol._num << endl;
	
	return 0;
}