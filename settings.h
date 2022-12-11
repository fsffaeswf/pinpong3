#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "settings.h"
#include <ctime>

const float FPS = 60.f;
const float size = 800;
const float ax = 20.f;
const float ay = 80.f;
const float r = 15.f;
const float Bat_Ofset = 50.f;
float speedx = rand() % 20 - 10;
float speedy = rand() % 20 - 10;
const float BatDy = 10.f;

const sf::Color Left_Bat_Color{ sf::Color::Magenta };
const sf::Color Right_Bat_Color{ sf::Color::Red };
const sf::Color Circle_Color{ sf::Color::Yellow };