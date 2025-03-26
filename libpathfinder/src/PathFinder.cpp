#include "PathFinder.hpp"

#include "Matrix.hpp"
#include "Position.hpp"
#include "Sequence.hpp"

PathFinder::PathFinder(const Matrix &matrix, bool verbose) : m_matrix(matrix), m_verbose(verbose) {
}

PathFinder::~PathFinder() {
}

std::vector<Position> PathFinder::getPositions() const {
	return m_positions;
}

Sequence PathFinder::getSequence() const {
	return m_sequence;
}

void PathFinder::setVerbose(bool verbose) {
	m_verbose = verbose;
}

bool PathFinder::getVerbose() const {
	return m_verbose;
}

