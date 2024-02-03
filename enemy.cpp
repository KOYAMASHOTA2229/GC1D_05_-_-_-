#include "enemy.h"
#include"Novice.h"

enemy::enemy(int enemyPosX, int enemyPosY, int enemySpeed)
{
	enemyPosX_ = enemyPosX;
	enemyPosY_ = enemyPosY;
	enemySpeed_ = enemySpeed;
	enemyR_ = 32;
	isAlive_ = 1;
	enemyImage_ = Novice::LoadTexture("./TEKI.PNG");
}

enemy::~enemy()
{
}

void enemy::SetPosition(int enemyPosX, int enemyPosY, int enemySpeed)
{
	enemyPosX_ = enemyPosX;
	enemyPosY_ = enemyPosY;
	enemySpeed_ = enemySpeed;
	enemyR_ = 32;
}

void enemy::Update()
{
	enemyPosX_ += enemySpeed_;

	if (enemyPosX_ > 1280 - enemyR_) {
		enemySpeed_ *= -1;
	}

	if (enemyPosX_ < 0 + enemyR_) {
		enemySpeed_ *= -1;

	}
}

void enemy::Draw()
{
	if (isAlive_ == 1) {
		Novice::DrawSprite(enemyPosX_-enemyR_,enemyPosY_ - enemyR_,enemyImage_,1,1,0.0f,WHITE);
	}
}

