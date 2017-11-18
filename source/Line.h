#pragma once

#include <array>

#include <SFML/Graphics.hpp>

class Line : public sf::Drawable
{
	static const size_t m_segmentCount = 30;
	static const float m_segmentLength;

public:
	typedef std::array<float, m_segmentCount> Genome;

	Line(const sf::Vector2f& origin, const Genome& genome = {});

	sf::Vector2f getHeadPosition() const;

	Genome getGenome() const;

	size_t getSegmentCount() const;

protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	sf::VertexArray m_vertices;

	Genome m_genome;
};

