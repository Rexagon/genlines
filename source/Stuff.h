#pragma once

#include <random>
#include <SFML/System/Vector2.hpp>

float getDiff(const sf::Vector2f& a, const sf::Vector2f& b);

bool randomBoolean(float probability);

int randomInt(int min, int max);

float randomFloat(float min, float max);

std::pair<size_t, size_t> randomPair(const std::vector<float>& chances);