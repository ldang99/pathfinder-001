#include "Sequence.hpp"

#include <vector>
#include <iostream>

Sequence::Sequence() {
}

Sequence::Sequence(const std::vector<int> &values, int score)
	: m_values(values), m_score(score)
{
}

const std::vector<int> &Sequence::values() const {
	return m_values;
}

int Sequence::score() const {
	return m_score;
}

std::ostream &operator<<(std::ostream &stream, const Sequence &sequence) {
	stream << "{";
	
	if (sequence.m_values.size() > 0) {
		stream << sequence.m_values[0];
		
		for (size_t i = 1; i < sequence.m_values.size(); ++i) {
			stream << ", " << sequence.m_values[i];
		} // for
	} // if
	
	stream << "}";

	return stream;
}

