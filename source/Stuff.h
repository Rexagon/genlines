#pragma once

#include <random>
#include <SFML/System/Vector2.hpp>

// Returns squared difference between two vectors
float getDiff(const sf::Vector2f& a, const sf::Vector2f& b);

// Returns true with specified probability
bool randomBoolean(float probability);

// Returns an integer in range [min; max]
int randomInt(int min, int max);

// Returns float in range [min; max]
float randomFloat(float min, float max);

// Returns a pair of different indices of specified array
//! Array must be constructed in this way:
//!  [X1, X2, ...., XN], where Xi < Xi+1 and Xi is in range [0; 1] and XN = 1 
std::pair<size_t, size_t> randomPair(const std::vector<float>& chances);