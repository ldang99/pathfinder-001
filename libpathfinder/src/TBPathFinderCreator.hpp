#ifndef TBPẠTHFINDERCREATOR_HPP
#define TBPẠTHFINDERCREATOR_HPP

#include "Matrix.hpp"
#include "PathFinder.hpp"
#include "PathFinderCreator.hpp"

template<typename ConcretePathFinder>
class TBPathFinderCreator : public PathFinderCreator {
public:
	TBPathFinderCreator() {
	}
	
	PathFinder *createPathFinder(const Matrix &matrix, bool verbose = true) override {
		return static_cast<PathFinder *> (new ConcretePathFinder(matrix, verbose));
	}
};

#endif

