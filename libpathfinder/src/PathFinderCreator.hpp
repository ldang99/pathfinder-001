#ifndef PẠTHFINDERCREATOR_HPP
#define PẠTHFINDERCREATOR_HPP

#include "Matrix.hpp"
#include "PathFinder.hpp"

class PathFinderCreator {
public:
	virtual PathFinder *createPathFinder(const Matrix &matrix, bool verbose = true) = 0;
};

#endif

