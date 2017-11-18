#include "Stuff.h"

float getDiff(const sf::Vector2f & a, const sf::Vector2f & b)
{
	sf::Vector2f v = a - b;
	return v.x * v.x + v.y * v.y;
}

bool randomBoolean(float probability)
{
	return randomFloat(0.0f, 1.0f) < probability;
}

int randomInt(int min, int max)
{
	return min + rand() % (max - min + 1);
}

float randomFloat(float min, float max)
{
	return min + static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * (max - min);
}

std::pair<size_t, size_t> randomPair(const std::vector<float>& chances)
{
	std::pair<size_t, size_t> result;

	float diff = 0.0f;
	float firstValue = randomFloat(0.0f, 1.0f);
	for (size_t i = 0; i < chances.size(); ++i) {
		float lowerBound = 0.0f;
		if (i != 0) {
			lowerBound = chances[i - 1];
		}

		if (firstValue >= lowerBound && firstValue <= chances[i]) {
			result.first = i;
			diff = chances[result.first] - lowerBound;
		}
	}

	float secondValue = randomFloat(0.0f, 1.0f - diff);
	for (size_t i = 0; i < chances.size(); ++i) {
		if (i == result.first) {
			secondValue += diff;
			continue;
		}

		float lowerBound = 0.0f;
		if (i != 0) {
			lowerBound = chances[i - 1];
		}

		if (secondValue >= lowerBound && secondValue <= chances[i]) {
			result.second = i;
		}
	}

	return result;
}
