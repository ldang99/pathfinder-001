#include "BTPathFinder.hpp"

#include <iostream>

BTPathFinder::BTPathFinder(const Matrix &matrix, bool verbose) : PathFinder(matrix, verbose){
}

int BTPathFinder::run() {
	m_found = false;
	
	// std::cout << "Size of the matrix: " << m_matrix.rowCount() << " X " << m_matrix.columnCount() << std::endl;
	
	if ((m_matrix.rowCount() == 0) || (m_matrix.columnCount() == 0)) {
		return 0;
	} // if
	
	std::vector<Position> positions;
	std::vector<int> values;
	
	int score = 1;
	
	for (unsigned k = 0; k < m_matrix.rowCount(); ++k) {
		Position position(k, 0);
		int value = m_matrix.value(position);
		
		positions.push_back(position);
		values.push_back(value);
		score *= value;
	} // for
	
	if (m_verbose) {
		std::cout << "Current score: " << score << std::endl;
	} // if
	
	m_found = true;
	
	m_bestScore = score;
	m_positions = positions;
	m_sequence = Sequence(values, score);
	
	bool allCases = false;
	
	do {
		unsigned i = m_matrix.rowCount() - 1;
		
		do {
			if (positions[i].column() < positions[i].row()) {
				if (i == 0) {
					break; // found
				} else {
					if (positions[i].column() == positions[i - 1].column()) {
						break; // found
					} else {
						--i;
						continue;
					} // if-else
				} // if-else
			} else {
				if (i == 0) {
					allCases = true;
					break;  // found
				} else {
					--i;
					continue;
				} // if-else
			} // if
		} while (true);
		
		if (allCases) {
			break;
		} // if
		
		unsigned j = positions[i].column() + 1;
		
		do {
			positions[i] = Position(i, j);
			values[i] = m_matrix.value(positions[i]);
			
			++i;
		} while (i <  m_matrix.rowCount());
		
		int score = 1;
		
		for (unsigned k = 0; k < m_matrix.rowCount(); ++k) {
			score *= values[k];
		} // for
		
		if (m_verbose) {
			std::cout << "Current score: " << score << ", " << "Best score: " << m_bestScore << std::endl;
		} // if
		
		if (score > m_bestScore) {
			m_bestScore = score;
			m_positions = positions;
			m_sequence = Sequence(values, score);
		} // if
	} while (true);
	
	return 0;
}

