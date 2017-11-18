#include "EvolutionManager.h"

#include <iostream>

#include "Stuff.h"

EvolutionManager::EvolutionManager(const sf::Vector2f& origin, const sf::Vector2f& target, size_t generationSize) :
	m_origin(origin), m_target(target), m_generationSize(generationSize)
{
	for (size_t i = 0; i < m_generationSize; ++i) {
		Line::Genome genome;
		for (size_t j = 0; j < genome.size(); ++j) {
			genome[j] = randomFloat(-90.0f, 90.0f);
		}

		m_currentGeneration.emplace_back(m_origin, genome);
	}
}

std::vector<Line> EvolutionManager::getCurrentGeneration()
{
	return m_currentGeneration;
}

std::vector<Line> EvolutionManager::nextGeneration()
{
	float chance = 0.0f;
	std::vector<float> survivalRates(m_generationSize);

	for (size_t i = 0; i < m_generationSize; ++i) {
		survivalRates[i] = 1.0f / getDiff(m_currentGeneration[i].getHeadPosition(), m_target);
		chance += survivalRates[i];
	}

	float total = 0.0f;
	for (size_t i = 0; i < m_generationSize; ++i) {
		survivalRates[i] = total = total + survivalRates[i] / chance;
	}

	std::vector<Line> newGeneration;
	for (size_t i = 0; i < m_generationSize; ++i) {
		std::pair<size_t, size_t> parents = randomPair(survivalRates);
		Line::Genome firstGenome = m_currentGeneration[parents.first].getGenome();
		Line::Genome secondGenome = m_currentGeneration[parents.second].getGenome();

		Line::Genome genome;
		for (size_t j = 0; j < genome.size(); ++j) {
			if (randomBoolean(0.008f)) {
				genome[j] = (firstGenome[j] + randomFloat(-45.0f, 45.0f)) / 2.0f;
			}
			else if (randomBoolean(0.008f)) {
				genome[j] = (secondGenome[j] + randomFloat(-45.0f, 45.0f)) / 2.0f;
			}
			else {
				genome[j] = (firstGenome[j] + secondGenome[j]) / 2.0f;
			}
		}
		newGeneration.emplace_back(m_origin, genome);
	}


	m_currentGeneration = newGeneration;
	return m_currentGeneration;
}

sf::Vector2f EvolutionManager::getOrigin() const
{
	return m_origin;
}

sf::Vector2f EvolutionManager::getTarget() const
{
	return m_target;
}
