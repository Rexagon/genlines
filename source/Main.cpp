#include "EvolutionManager.h"
#include "Stuff.h"

int main()
{
	// seeding random
	srand(static_cast<unsigned int>(time(nullptr)));

	// creating window
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "genlines");
	window.setVerticalSyncEnabled(true);

	// centering 2D camera
	window.setView(sf::View(sf::FloatRect(-500, -500, 1000, 1000)));

	// creating manager
	EvolutionManager manager(sf::Vector2f(200.0f, -250.0f), sf::Vector2f(-250.0f, -250.0f));
	std::vector<Line> lines = manager.getCurrentGeneration();

	// creating circle around target point
	sf::CircleShape area;
	area.setOutlineThickness(1.0f);
	area.setOutlineColor(sf::Color::Red);
	area.setFillColor(sf::Color::Black);
	area.setRadius(50.0f);
	area.setPosition(manager.getTarget() - sf::Vector2f(50.0f, 50.0f));

	// starting main application looop
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Key::Escape) {
					window.close();
				}
				else if (event.key.code == sf::Keyboard::Key::Space) {
					lines = manager.nextGeneration();
				}
				else if (event.key.code == sf::Keyboard::Key::R) {
					manager = EvolutionManager(sf::Vector2f(randomFloat(-400.0f, 400.0f), randomFloat(-400.0f, 400.0f)),
											   sf::Vector2f(randomFloat(-400.0f, 400.0f), randomFloat(-400.0f, 400.0f)));
					lines = manager.getCurrentGeneration();
					area.setPosition(manager.getTarget() - sf::Vector2f(50.0f, 50.0f));
				}
				break;

			default:
				break;
			}
		}

		window.clear();

		// drawing sphere
		window.draw(area);

		// drawing lines
		for (Line& line : lines) {
			window.draw(line);
		}

		window.display();
	}

	return 0;
}