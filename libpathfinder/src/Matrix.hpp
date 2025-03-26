#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>
#include <iostream>

#include "Position.hpp"

class Matrix {
public:
	Matrix(const std::vector<std::vector<int>> &values);

	unsigned rowCount() const;
	
	unsigned columnCount() const;

	int value(unsigned row, unsigned column) const;
	
	int value(const Position &position) const;

	// You can add your own class members here.

	friend std::ostream &operator<<(std::ostream &stream, const Matrix &matrix);

private:
	std::vector<std::vector<int>> m_values;
	
	unsigned m_rowCount;
	
	unsigned m_columnCount;
};

#endif

