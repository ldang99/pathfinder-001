#ifndef PATHFINDER
#define PATHFINDER

#include "Matrix.hpp"
#include "Position.hpp"
#include "Sequence.hpp"

class PathFinder {
public:
	PathFinder(const Matrix &matrix, bool verbose = true);
	
	virtual ~PathFinder();
	
	std::vector<Position> getPositions() const;
	
	Sequence getSequence() const;
	
	void setVerbose(bool verbose);
	
	bool getVerbose() const;
	
	virtual int run() = 0;
	
protected:
	Matrix m_matrix;
	
	std::vector<Position> m_positions;
	
	Sequence m_sequence;
	
	bool m_verbose;
};

#endif

