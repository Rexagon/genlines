#include "Line.h"

Line::Line(const std::vector<Segment>& segments) :
	m_segments(segments)
{
	sf::Vector2f origin(0.0f, 0.0f);
	m_vertices.append(createVertex(origin));

	for (const Segment& s : segments) {
		sf::Vector2f vec(0.0f, s.length);

		sf::Vector2f temp = vec;
		float angle = s.angle * 3.14159265f / 180.0f;
		vec.x = temp.x * cos(angle) - temp.y * sin(angle);
		vec.y = temp.x * sin(angle) + temp.y * cos(angle);
		
		origin += vec;
		m_vertices.append(createVertex(origin));
	}
}

sf::Vector2f Line::getHeadPosition() const
{
	return m_vertices[m_vertices.getVertexCount() - 1].position;
}

std::vector<Line::Segment> Line::getParameters() const
{
	return m_segments;
}

void Line::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(&m_vertices[0], m_vertices.getVertexCount(), sf::PrimitiveType::LinesStrip, states);
}

sf::Vertex Line::createVertex(const sf::Vector2f & position)
{
	return sf::Vertex(position, sf::Color::White);
}
