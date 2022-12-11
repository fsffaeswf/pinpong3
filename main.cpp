#include <SFML/Graphics.hpp>
#include <iostream>
#include "settings.h"
using namespace sf;

int main()
{
	srand(time(nullptr));
	speedx = rand() % 20 - 10;
	speedy = rand() % 20 - 10;
	RectangleShape rect(Vector2f(ax, ay));
	RectangleShape rect1(Vector2f(ax, ay));
	CircleShape circle(r);

	rect.setFillColor(Left_Bat_Color);
	rect1.setFillColor(Right_Bat_Color);
	circle.setFillColor(Circle_Color);

	rect.setPosition(Bat_Ofset, size / 2 - ay / 2);
	rect1.setPosition(size - Bat_Ofset - ax, size / 2 - ay / 2);
	circle.setPosition(size / 2 - r, size / 2 - r);

	// Объект, который, собственно, является главным окном приложения
	RenderWindow window(VideoMode(size, size), "SFML Works!");
	window.setFramerateLimit(FPS);

	int leftScore = 0;
	int rightScore = 0;

	Font font,font1;
	font.loadFromFile("DS-DIGIB.ttf");
	Text leftScoreText(std::to_string(leftScore), font, 64);

	font1.loadFromFile("DS-DIGIB.ttf");
	Text rightScoreText(std::to_string(rightScore), font1, 64);
	leftScoreText.setPosition(200, 10);
	rightScoreText.setPosition(580, 10);
	// Главный цикл приложения. Выполняется, пока открыто окно
	while (window.isOpen())
	{
		// Обрабатываем очередь событий в цикле
		Event event;
		while (window.pollEvent(event))
		{
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed)
				// тогда закрываем его
				window.close();
		}
		//обновление объектов игры
		/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		float midLeftx = circle.getPosition().x, 
			  midLefty = circle.getPosition().y+r;
		float midRightx = circle.getPosition().x+2*r,
			midRighty = circle.getPosition().y + r;
		!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/



		circle.move(speedx, speedy);
		if (circle.getPosition().x + 2 * r > size) 
		{
			speedx = -speedx;
			rightScore++; 
			rightScoreText.setString(std::to_string(rightScore));
		}

		if (circle.getPosition().x < 0) {
			speedx = -speedx;
			leftScore++;
			leftScoreText.setString(std::to_string(leftScore));
		}

		if (circle.getPosition().y + 2 * r > size ||
			circle.getPosition().y < 0) {
			speedy = -speedy;
		}
		//двигаем ракетки
		//правая
		if (Keyboard::isKeyPressed(Keyboard::Up)) {
			rect1.move(0, -BatDy);
		}
		if (Keyboard::isKeyPressed(Keyboard::Down)) {
			rect1.move(0, BatDy);
		}
		//левая
		if (Keyboard::isKeyPressed(Keyboard::W)) {
			rect.move(0, -BatDy);
		}
		if (Keyboard::isKeyPressed(Keyboard::S)) {
			rect.move(0, BatDy);
		}

		//границы ракетки
		//левая
		if (rect.getPosition().y + ay > size) {
			rect.move(0, -BatDy);
		}
		if (rect.getPosition().y < 0) {
			rect.move(0, BatDy);
		}

		//правая
		if (rect1.getPosition().y + ay > size) {
			rect1.move(0, -BatDy);
		}
		if (rect1.getPosition().y < 0) {
			rect1.move(0, BatDy);
		}



		//отскок от ракеток
		//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		/*if ((circle.getPosition().x == rect.getPosition().x+ax) &&
			(circle.getPosition().y+2*r >= rect.getPosition().y && circle.getPosition().y<= rect.getPosition().y+ay)) {
			speedx = -speedx;
		}
		if ((circle.getPosition().x+2*r == rect1.getPosition().x ) && 
			(circle.getPosition().y + 2 * r >= rect1.getPosition().y && circle.getPosition().y   <= rect1.getPosition().y + ay)) {
			speedx = -speedx;
		}*/


		/*if ((midLeftx == rect.getPosition().x + ax) &&
			(midLefty + r >= rect.getPosition().y && midLefty <= rect.getPosition().y + ay)) {
			speedx = -speedx;
		}
		if ((circle.getPosition().x + 2 * r == rect1.getPosition().x) &&
			(circle.getPosition().y + 2 * r >= rect1.getPosition().y && circle.getPosition().y <= rect1.getPosition().y + ay)) {
			speedx = -speedx;
		}*/
		//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

		// Отрисовка объектов и окна 
		window.clear();
		window.draw(rect);
		window.draw(rect1);
		window.draw(circle);
		window.draw(rightScoreText);
		window.draw(leftScoreText);
		window.display();

	}

	return 0;
}
