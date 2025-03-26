#ifndef BTPATHFINDER
#define BTPATHFINDER

#include <vector>

#include "Matrix.hpp"
#include "Position.hpp"
#include "Sequence.hpp"

#include "PathFinder.hpp"

class BTPathFinder : public PathFinder {
public:
	BTPathFinder(const Matrix &matrix, bool verbose = true);
	
	virtual int run() override;
	
private:
	void track(std::vector<Position> positions, std::vector<int> values, unsigned i, unsigned j);
	
	bool m_found;
	
	int m_bestScore;
};

#endif

