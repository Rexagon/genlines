#pragma once

#include <vector>

#include "Line.h"

class EvolutionManager
{
public:
	// Constructs manager, which will generate lines, starting from origin and will evolve them to
	// reach target. Generation size is a number of lines per generation
	EvolutionManager(const sf::Vector2f& origin, const sf::Vector2f& target, size_t generationSize = 10);

	// Returns lines array of current generation
	std::vector<Line> getCurrentGeneration();

	// Updates current generation and then returns it
	std::vector<Line> nextGeneration();

	// Returns starting point of all lines
	sf::Vector2f getOrigin() const;

	// Returns the aim of all lines
	sf::Vector2f getTarget() const;

private:
	// Starting point of all lines
	sf::Vector2f m_origin;

	// Aim of all lines
	sf::Vector2f m_target;

	// Line count per generation
	size_t m_generationSize;

	// Lines array of current generation
	std::vector<Line> m_currentGeneration;
};