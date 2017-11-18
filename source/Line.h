#pragma once

#include <array>

#include <SFML/Graphics.hpp>

class Line : public sf::Drawable
{
	static const size_t m_segmentCount = 30;
	static const float m_segmentLength;

public:
	// Line genome is a set of segments relative angles
	typedef std::array<float, m_segmentCount> Genome;

	// Constructs line, which will start from origin and have some segment angles
	Line(const sf::Vector2f& origin, const Genome& genome = {});

	// Returns the last segment's position
	sf::Vector2f getHeadPosition() const;

	// Returns line genome (angles)
	Genome getGenome() const;

	// Returns number of segments, which is the same for all objects of this type
	size_t getSegmentCount() const;

protected:
	// Inherited function of sf::Drawable, which allows to draw this line in common way
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	// Array of vertices, which is used to draw line segments
	sf::VertexArray m_vertices;

	// Array of angles
	Genome m_genome;
};

