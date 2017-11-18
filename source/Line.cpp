#include "Line.h"

#include <cmath>
#include <iostream>

const float Line::m_segmentLength = 25.0f;

Line::Line(const sf::Vector2f& origin, const Genome& genome) :
	m_genome(genome)
{
	m_vertices.append(sf::Vertex(origin));

	sf::Vector2f lastPosition = origin;
	float currentAngle = 0.0f;
	for (size_t i = 0; i < genome.size(); ++i) {		
		float angle = genome[i] * 3.14159265358979323846f / 180.0f;
		currentAngle = currentAngle + angle;
				
		sf::Vector2f currentPosition(lastPosition.x - m_segmentLength * sin(currentAngle),
									 lastPosition.y + m_segmentLength * cos(currentAngle));

		m_vertices.append(sf::Vertex(currentPosition));

		lastPosition = currentPosition;
	}
}

sf::Vector2f Line::getHeadPosition() const
{
	return m_vertices[m_vertices.getVertexCount() - 1].position;
}

Line::Genome Line::getGenome() const
{
	return m_genome;
}

size_t Line::getSegmentCount() const
{
	return m_segmentCount;
}

void Line::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(&m_vertices[0], m_vertices.getVertexCount(), sf::PrimitiveType::LinesStrip, states);
}