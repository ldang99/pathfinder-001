#include <cstring>

#include "BTPathFinder.hpp"
#include "TBPathFinderCreator.hpp"
#include "Examples.hpp"

int main(int argc, char* argv[]) {
	bool verbose = false;
	
	for (int i = 0; i < argc; ++i) {
		if (strcmp(argv[i], "verbose") == 0) {
			verbose = true;
		} // if
	} // if
	
	TBPathFinderCreator<BTPathFinder> pathFinderCreator;
	
	return Examples(&pathFinderCreator, verbose).run();
}

