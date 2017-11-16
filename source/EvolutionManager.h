#pragma once

#include <vector>

#include "Line.h"

class EvolutionManager
{
public:
	EvolutionManager();

	void init();

	sf::Vector2f getTargetPoint() const;

	Line getTargetEntity() const;

	std::vector<Line> nextGeneration();

private:
	Line::Segment generateSegment(const Line::Segment& segment);
	Line generateLine(const Line& line);

	float getTargetDiff(const Line& line);

	size_t m_generation;

	Line m_targetEntity;
	sf::Vector2f m_targetPoint;
	std::vector<Line> m_currentLines;
};