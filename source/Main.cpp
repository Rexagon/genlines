#include "EvolutionManager.h"

int main()
{
	srand(time(0));

	sf::RenderWindow window(sf::VideoMode(1000, 1000), "genlines");
	window.setView(sf::View(sf::FloatRect(-500, -500, 1000, 1000)));

	// 
	EvolutionManager manager;
	manager.init();

	// sphere of point
	sf::CircleShape area;
	area.setOutlineThickness(1.0f);
	area.setOutlineColor(sf::Color::Red);
	area.setFillColor(sf::Color::Black);
	area.setRadius(150);
	area.setPosition(manager.getTargetPoint() - sf::Vector2f(150.0f, 150.0f));

	// gen algorithm
	std::vector<Line> lines = manager.nextGeneration();

	// open the window
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
				lines = manager.nextGeneration();
			}

		}

		window.clear();

		// drawing sphere
		window.draw(area);

		// drawing lines
		for (Line& line : lines) {
			window.draw(line);
		}

		window.draw(manager.getTargetEntity());

		window.display();
	}

	return 0;
}