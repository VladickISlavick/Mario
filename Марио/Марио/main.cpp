#include "GameLib.h"
using namespace sf;

int main() {
	String nameGame = "Mario!";
	Font font;
	font.loadFromFile("Font\\playfair-display\\PlayfairDisplay-Black.ttf");

	Text text("Mario", font, 20);
	Text startText("Press F to Start", font, 20);
	Text exitText("Exit - Esc", font, 10);

	Texture tileSet;
	tileSet.loadFromFile("Mario_Tileset.png");

	Sprite tile(tileSet);

	Player Mario(tileSet);
	Enemy enemy1;
	enemy1.set(tileSet, 43 * 16, 13 * 16);

	RenderWindow windowStartGame(VideoMode(400, 250), nameGame);

	text.setPosition(windowStartGame.getSize().x / 2 - 45.5f, windowStartGame.getSize().y / 2 - 120.0f);
	startText.setPosition(windowStartGame.getSize().x / 2 - 50.5f, windowStartGame.getSize().y / 2 - 100.0f);
	exitText.setPosition(0, 200);

	Clock c;

	while (windowStartGame.isOpen()) {
		Event e;
		float time = c.getElapsedTime().asMicroseconds();
		time = time / 550;

		if (time > 20)time = 20;

		while (windowStartGame.pollEvent(e)) {
			if (Keyboard::isKeyPressed(Keyboard::Key::F)) {
				windowStartGame.close();
				text.setString("");
			}
			else if (Keyboard::isKeyPressed(Keyboard::Key::Escape) || e.type == Event::Closed) {
				windowStartGame.close();
				return 0;
			}
		}
		Mario.update(time);
		enemy1.update(time);

		windowStartGame.clear(Color(107, 140, 255));

		for (int i = 0; i < Height; i++) {
			for (int j = 0; j < Width; j++) {
				if (MenuMap[i][j] == 'P') {
					tile.setTextureRect(IntRect(143 - 16 * 3, 112, 16, 16));
				} if (MenuMap[i][j] == 'k') {
					tile.setTextureRect(IntRect(143, 112, 16, 16));
				} if (MenuMap[i][j] == 'c') {
					tile.setTextureRect(IntRect(143 - 16, 112, 16, 16));
				} if (MenuMap[i][j] == 't') {
					tile.setTextureRect(IntRect(0, 47, 32, 95 - 47));
				} if (MenuMap[i][j] == 'g') {
					tile.setTextureRect(IntRect(0, 16 * 9 - 5, 3 * 16, 16 * 2 + 5));
				} if (MenuMap[i][j] == 'G') {
					tile.setTextureRect(IntRect(145, 222, 222 - 145, 255 - 222));
				} if (MenuMap[i][j] == 'd') {
					tile.setTextureRect(IntRect(0, 106, 74, 127 - 106));
				} if (MenuMap[i][j] == 'w') {
					tile.setTextureRect(IntRect(99, 224, 140 - 99, 255 - 224));
				} if ((MenuMap[i][j] == ' ') || (MenuMap[i][j] == '0')) {
					continue;
				}

				tile.setPosition(j * 16 - offsetX, i * 16 - offsetY);
				windowStartGame.draw(tile);
			}
		}

		windowStartGame.draw(text);
		windowStartGame.draw(startText);
		windowStartGame.draw(exitText);

		windowStartGame.draw(Mario.sprite);
		windowStartGame.draw(enemy1.sprite);
		windowStartGame.display();
	}

	RenderWindow windowGame(VideoMode(400, 250), nameGame);


	SoundBuffer buffer;
	buffer.loadFromFile("Jump.ogg");
	Sound sound(buffer);

	Music music;
	music.openFromFile("Mario_Theme.ogg");
	music.play();

	while (windowGame.isOpen()) {
		Event event;
		float time = c.getElapsedTime().asMicroseconds();
		c.restart();

		time = time / 550; //SPEED GAME

		if (time > 20) {
			time = 20;
		}

		while (windowGame.pollEvent(event)) {
			if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Key::Escape)) {
				windowGame.close();
			}
		}
		//MOVE
		if (Keyboard::isKeyPressed(Keyboard::Key::Left) || Keyboard::isKeyPressed(Keyboard::Key::A)) {
			Mario.dx = -0.1;
		} if (Keyboard::isKeyPressed(Keyboard::Key::Right) || Keyboard::isKeyPressed(Keyboard::Key::D)) {
			Mario.dx = 0.1;
		}
		//JUMP
		if (Keyboard::isKeyPressed(Keyboard::Key::Up) || Keyboard::isKeyPressed(Keyboard::Key::Space) || Keyboard::isKeyPressed(Keyboard::Key::W)) {
			if (Mario.onGround) {
				Mario.dy = -0.27;
				Mario.onGround = false;
				sound.play();
			}
		}

		Mario.update(time);
		enemy1.update(time);

		if (Mario.rect.intersects(enemy1.rect)) {
			if (enemy1.life) {
				if (Mario.dy > 0) {
					enemy1.dx = 0;
					Mario.dy = -0.2;
					enemy1.life = false;
					windowGame.clear(Color::Green);
					//WIN
					text.setString("You win!");
					text.setFillColor(Color::Black);

					while (windowGame.isOpen()) {
						while (windowGame.pollEvent(event)) {
							if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Key::Escape)) {
								windowGame.close();
							}
						}

						windowGame.clear(Color::Green);
						windowGame.draw(text);
						windowGame.display();
					}

				}
				else {
					Mario.sprite.setColor(Color::Red);
					windowGame.clear(Color::Red);
					//LOSE
					text.setString("Game Over!");
					text.setFillColor(Color::Black);

					while (windowGame.isOpen()) {
						while (windowGame.pollEvent(event)) {
							if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Key::Escape)) {
								windowGame.close();
							}
						}

						windowGame.clear(Color::Red);
						windowGame.draw(text);
						windowGame.display();
					}
				}
			}
		} if (Mario.rect.left > 200) {
			offsetX = Mario.rect.left - 200;
		}
		windowGame.clear(Color(107, 140, 255));

		for (int i = 0; i < Height; i++) {
			for (int j = 0; j < Width; j++) {
				if (TileMap[i][j] == 'P') {
					tile.setTextureRect(IntRect(143 - 16 * 3, 112, 16, 16));
				} if (TileMap[i][j] == 'k') {
					tile.setTextureRect(IntRect(143, 112, 16, 16));
				} if (TileMap[i][j] == 'c') {
					tile.setTextureRect(IntRect(143 - 16, 112, 16, 16));
				} if (TileMap[i][j] == 't') {
					tile.setTextureRect(IntRect(0, 47, 32, 95 - 47));
				} if (TileMap[i][j] == 'g') {
					tile.setTextureRect(IntRect(0, 16 * 9 - 5, 3 * 16, 16 * 2 + 5));
				} if (TileMap[i][j] == 'G') {
					tile.setTextureRect(IntRect(145, 222, 222 - 145, 255 - 222));
				} if (TileMap[i][j] == 'd') {
					tile.setTextureRect(IntRect(0, 106, 74, 127 - 106));
				} if (TileMap[i][j] == 'w') {
					tile.setTextureRect(IntRect(99, 224, 140 - 99, 255 - 224));
				} if (TileMap[i][j] == 'r') {
					tile.setTextureRect(IntRect(143 - 32, 112, 16, 16));
				} if ((TileMap[i][j] == ' ') || (TileMap[i][j] == '0')) {
					continue;
				}

				tile.setPosition(j * 16 - offsetX, i * 16 - offsetY);
				windowGame.draw(tile);
			}
		}

		windowGame.draw(Mario.sprite);
		windowGame.draw(enemy1.sprite);
		windowGame.display();
	}

	return 0;
}