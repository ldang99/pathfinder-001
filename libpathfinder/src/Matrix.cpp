#include "Matrix.hpp"

#include <vector>
#include <stdexcept>

Matrix::Matrix(const std::vector<std::vector<int>> &values)
	: m_values(values) {
	m_rowCount = static_cast<unsigned>(m_values.size());
	
	if (m_rowCount == 0) {
		m_columnCount = 0;
	} else {
		m_columnCount = static_cast<unsigned>(m_values[0].size());
		
		for (unsigned i = 1; i < m_values.size(); ++i) {
			if (static_cast<unsigned>(m_values[i].size()) > m_columnCount) {
				m_columnCount = static_cast<unsigned>(m_values[i].size());
			} // for
		} // for
	} // if-else
}

unsigned Matrix::rowCount() const {
	return m_rowCount;
}

unsigned Matrix::columnCount() const {
	return m_columnCount;
}

int Matrix::value(unsigned row, unsigned column) const {
	if ((row >= m_rowCount) || (column >= m_columnCount)) {
		throw std::out_of_range("Index out of bounds.");
	} // if
	
	if (column >= m_values[row].size()) {
		return 0;
	} // if
	
	return m_values[row][column];
}

int Matrix::value(const Position &position) const {
	return m_values[position.row()][position.column()];
}

std::ostream &operator<<(std::ostream &stream, const Matrix &matrix) {
	for (unsigned i = 0; i < matrix.m_values.size(); ++i) {
		const std::vector<int> &rowValues = matrix.m_values[i];
		
		if (rowValues.size() > 0) {
			stream << rowValues[0];
			
			for (unsigned j = 1; j < rowValues.size(); ++j) {
				stream << ", " << rowValues[j];
			} // for
		} // if
		
		stream << std::endl;
	} // for
	
	return stream;
}

