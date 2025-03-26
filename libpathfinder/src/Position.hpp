#ifndef POSISION_HPP
#define POSISION_HPP

#include <iostream>

class Position {
public:
	Position(unsigned row, unsigned column);

	unsigned row() const;
	unsigned column() const;

	bool operator==(const Position &other) const;

	friend std::ostream &operator<<(std::ostream &stream, const Position &position);

private:
	unsigned m_row;
	
	unsigned m_column;
};

#endif

