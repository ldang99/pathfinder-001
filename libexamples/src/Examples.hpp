#ifndef EXAMPLES_HPP
#define EXAMPLES_HPP

#include "Matrix.hpp"
#include "Sequence.hpp"
#include "PathFinderCreator.hpp"

class Examples
{
public:
	Examples(PathFinderCreator *pathFinderCreator, bool verbose = true);
	
	int run();

private:
	PathFinderCreator *m_pathFinderCreator;
	
	void runExample(const Matrix &matrix, const Sequence &expectedSequence);
	
	void runExample1();
	
	void runExample2();
	
	void runExample3();
	
	void runExample4();
	
	void runExample5();
	
	bool m_verbose;
};

#endif

