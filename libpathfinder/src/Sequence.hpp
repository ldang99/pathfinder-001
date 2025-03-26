#ifndef SEQUENCE_HPP
#define SEQUENCE_HPP

#include <vector>
#include <iostream>

class Sequence {
public:
	Sequence();
	
	Sequence(const std::vector<int> &values, int score);

	const std::vector<int> &values() const;

	int score() const;

	friend std::ostream &operator<<(std::ostream &stream, const Sequence &sequence);

private:
	std::vector<int> m_values;
	
	int m_score;
};

#endif

