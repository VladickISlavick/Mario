#pragma once
#include "GameLib.h"

class Enemy {
public:
	float dx, dy;
	int number;
	FloatRect rect;
	Sprite sprite;
	float currentFrame;
	bool life;

	Enemy();
	
	void set(Texture &image, int x, int y);
	void update(float time);
	void Collision();


	~Enemy();
};

