#include "EvolutionManager.h"

#include <iostream>

EvolutionManager::EvolutionManager() :
	m_targetPoint(450.0f, 300.0f)
{
}

void EvolutionManager::init()
{
	size_t segmentCount = 1;

	std::vector<Line::Segment> segments;
	for (size_t i = 0; i < segmentCount; ++i) {
		segments.push_back(generateSegment(Line::Segment(50, 0)));
	}
	m_targetEntity = Line(segments);
	m_currentLines.push_back(m_targetEntity);
}

sf::Vector2f EvolutionManager::getTargetPoint() const
{
	return m_targetPoint;
}

Line EvolutionManager::getTargetEntity() const
{
	return m_targetEntity;
}

std::vector<Line> EvolutionManager::nextGeneration()
{
	if (m_currentLines.empty()) {
		return {};
	}

	std::pair<size_t, float> min = std::make_pair(0, getTargetDiff(m_currentLines[0]));
	for (size_t i = 1; i < m_currentLines.size(); ++i) {
		//std::cout << m_currentLines[i] << ' ' << diff << std::endl;
		float diff = getTargetDiff(m_currentLines[i]);
		std::cout << i << ' ' << diff << std::endl;
		if (min.second < diff) {
			min = std::make_pair(i, diff);
		}
	}

	m_targetEntity = m_currentLines[min.first];
	std::cout << "Current diff = " << getTargetDiff(m_targetEntity) << std::endl;

	sf::Vector2f v = m_targetPoint - m_targetEntity.getHeadPosition();
	std::cout << std::sqrt(v.x * v.x + v.y * v.y) << "\n\n";
	if (std::sqrt(v.x * v.x + v.y * v.y) < 150.0f) {
		return {};
	}

	m_currentLines.clear();
	for (size_t i = 0; i < 10; ++i) {
		m_currentLines.push_back(generateLine(m_targetEntity));
	}

	return m_currentLines;
}

Line::Segment EvolutionManager::generateSegment(const Line::Segment& segment)
{
	Line::Segment result(segment);

	result.angle += -45 + rand() % 91;
	result.length += -25 + rand() % 51;

	return result;
}

Line EvolutionManager::generateLine(const Line & line)
{
	const std::vector<Line::Segment>& segments = line.getParameters();

	std::vector<Line::Segment> newSegments;

	size_t nextSegmentsCount = segments.size() + rand() % 2 - 1;
	for (size_t i = 0; i < segments.size() && i < nextSegmentsCount; ++i) {
		Line::Segment segment = generateSegment(segments[i]);
		newSegments.push_back(segment);
	}

	for (size_t i = newSegments.size() - 1; i < nextSegmentsCount; ++i) {
		newSegments.push_back(generateSegment(Line::Segment(50, 0)));
	}

	return Line(newSegments);
}

float EvolutionManager::getTargetDiff(const Line & line)
{
	sf::Vector2f v = m_targetPoint + line.getHeadPosition();
	return std::sqrt(v.x * v.x + v.y * v.y);
}