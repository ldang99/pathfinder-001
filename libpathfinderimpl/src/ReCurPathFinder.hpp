#ifndef RECURPATHFINDER
#define RECURPATHFINDER

#include <vector>

#include "Matrix.hpp"
#include "Position.hpp"
#include "Sequence.hpp"

#include "PathFinder.hpp"

class ReCurPathFinder : public PathFinder {
public:
	ReCurPathFinder(const Matrix &matrix, bool verbose = true);
	
	virtual int run();
	
private:
	void track(const std::vector<Position> &positions, const std::vector<int> &values, unsigned i, unsigned j);
	
	bool m_found;
	
	int m_bestScore;
};

#endif

