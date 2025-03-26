#include "Position.hpp"

#include <iostream>

Position::Position(unsigned row, unsigned column) : m_row(row), m_column(column) {
}

unsigned Position::row() const {
	return m_row;
}

unsigned Position::column() const {
	return m_column;
}

bool Position::operator==(const Position &other) const {
	return m_row == other.m_row && m_column == other.m_column;
}

std::ostream &operator<<(std::ostream &stream, const Position &position) {
	return stream << "{" << position.m_row << ", " << position.m_column << "}";
}

