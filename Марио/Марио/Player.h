#pragma once
#include "GameLib.h"

class Player {
public:
	float dx, dy;
	FloatRect rect;
	bool onGround;
	Sprite sprite;
	float currentFrame;

	Player();
	Player(Texture &image);
	
	void update(float time);
	void collision(int num);

	~Player();
};

