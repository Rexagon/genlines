#pragma once

#include <vector>

#include "Line.h"

class EvolutionManager
{
public:
	EvolutionManager(const sf::Vector2f& origin, const sf::Vector2f& target, size_t generationSize = 10);

	std::vector<Line> nextGeneration();

	sf::Vector2f getOrigin() const;
	sf::Vector2f getTarget() const;

private:
	sf::Vector2f m_origin;
	sf::Vector2f m_target;

	size_t m_generationSize;
	std::vector<Line> m_currentGeneration;
};