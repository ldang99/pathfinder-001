#include "ReCurPathFinder.hpp"

#include <iostream>

ReCurPathFinder::ReCurPathFinder(const Matrix &matrix, bool verbose) : PathFinder(matrix, verbose) {
}

int ReCurPathFinder::run() {
	m_found = false;
	
	// std::cout << "Size of the matrix: " << m_matrix.rowCount() << " X " << m_matrix.columnCount() << std::endl;
	
	if ((m_matrix.rowCount() == 0) || (m_matrix.columnCount() == 0)) {
		return 0;
	} // if
	
	std::vector<Position> positions;
	std::vector<int> values;
	
	track(positions, values, 0, 0);
	
	return 0;
}

void ReCurPathFinder::track(const std::vector<Position> &positions, const std::vector<int> &values, unsigned i, unsigned j) {
	std::vector<Position> newPositions = positions;
	std::vector<int> newValues = values;
	
	newPositions.push_back(Position(i, j));
	newValues.push_back(m_matrix.value(i, j));
	
	if (i == m_matrix.rowCount() - 1) {
		int score = m_matrix.value(newPositions[0]);
		
		for (unsigned k = 1; k < newPositions.size(); ++k) {
			score *= m_matrix.value(newPositions[k]);
		} // for
		
		if (!m_found) {
			if (m_verbose) {
				std::cout << "Current score: " << score << std::endl;
			} // if
			
			m_found = true;
			
			m_bestScore = score;
			m_positions = newPositions;
			m_sequence = Sequence(newValues, score);
		} else {
			if (m_verbose) {
				std::cout << "Current score: " << score << ", " << "Best score: " << m_bestScore << std::endl;
			} // if
			
			if (score > m_bestScore) {
				m_bestScore = score;
				m_positions = newPositions;
				m_sequence = Sequence(newValues, score);
			} // if
		} // if-else
		
		return;
	} // if
	
	++i;
	
	track(newPositions, newValues, i, j);
	
	if (j < m_matrix.columnCount() - 1) {
		track(newPositions, newValues, i, j + 1);
	} // if
}

