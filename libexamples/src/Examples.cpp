#include "Examples.hpp"

#include <cassert>

#include "Matrix.hpp"
#include "Sequence.hpp"
#include "PathFinder.hpp"
#include "PathFinderCreator.hpp"

Examples::Examples(PathFinderCreator *pathFinderCreator, bool verbose) : m_pathFinderCreator(pathFinderCreator), m_verbose(verbose) {
}

int Examples::run() {
	std::cout << "Example 1:" << std::endl;
	runExample1();
	std::cout << std::endl;
	
	std::cout << "Example 2:" << std::endl;
	runExample2();
	std::cout << std::endl;
	
	std::cout << "Example 3:" << std::endl;
	runExample3();
	std::cout << std::endl;
	
	std::cout << "Example 4:" << std::endl;
	runExample4();
	std::cout << std::endl;
	
	std::cout << "Example 5:" << std::endl;
	runExample5();
	std::cout << std::endl;
	
	return 0;
}

void Examples::runExample(const Matrix &matrix, const Sequence &expectedSequence) {
	std::cout << "The matrix: "  << std::endl << matrix << std::endl;
	
	PathFinder *pPathFinder = m_pathFinderCreator->createPathFinder(matrix, m_verbose);
	pPathFinder->run();
	
	Sequence sequence = pPathFinder->getSequence();
	
	assert(expectedSequence.values() == sequence.values());
	assert(expectedSequence.score() == sequence.score());
	
	std::cout << "The sequence: " << sequence << std::endl;
	std::cout << "The score: " << sequence.score() << std::endl;
	
	delete pPathFinder;
}

void Examples::runExample1() {
	const Matrix matrix =
	{{
		{17},
	}};
	
	Sequence expectedSequence = {{17}, 17};
	
	runExample(matrix, expectedSequence);
}

void Examples::runExample2() {
	const Matrix matrix =
	{{
		{5},
		{-4, -7}
	}};
	
	Sequence expectedSequence = {{5, -4}, -20};
	
	runExample(matrix, expectedSequence);
}

void Examples::runExample3() {
	const Matrix matrix =
	{{
		{4},
		{3, 5},
		{5, 4, 2},
	}};
	
	Sequence expectedSequence = {{4, 5, 4}, 80};
	
	runExample(matrix, expectedSequence);
}

void Examples::runExample4() {
	const Matrix matrix =
	{{
		{4},
		{3, 5},
		{5, 4, 2},
		{2, 4, 5},
	}};
	
	Sequence expectedSequence = {{4, 5, 4, 5}, 400};
	
	runExample(matrix, expectedSequence);
}

void Examples::runExample5() {
	const Matrix matrix =
	{{
		{7},
		{3, 8},
		{8, 1, 0},
		{2, 7, 4, 4},
		{4, 5, -2, 6, 5}
	}};
	
	Sequence expectedSequence = {{7, 3, 8, 7, 5}, 5880};
	
	runExample(matrix, expectedSequence);
}

