#pragma once

#include <vector>

#include <SFML/Graphics.hpp>

class Line : public sf::Drawable, public sf::Transformable
{
public:
	struct Segment
	{
		Segment(float l, float a) :
			length(l), angle(a)
		{}

		float length;
		float angle;
	};

	Line(const std::vector<Segment>& segments = {});

	sf::Vector2f getHeadPosition() const;

	std::vector<Segment> getParameters() const;

protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	static sf::Vertex createVertex(const sf::Vector2f& position);

	std::vector<Segment> m_segments;
	sf::VertexArray m_vertices;
};

