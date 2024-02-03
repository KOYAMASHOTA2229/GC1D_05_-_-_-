#pragma once
#include"bullet.h"
class player
{
private:
	int posX_;
	int posY_;
	int speed_;
	int r_;
	int isAlive_;
	int playerImage_;

public:
	player(int posX, int posY, int speed);
	~player();
	void Update(char* keys, char* preKeys);
	void Draw();


	int GetPosX() { return posX_; };
	int GetPosY() { return posY_; };
	int GetSpeed() { return speed_; };
	void SetSpeed(int speed) { speed_ = speed; }
	int GetRadius() { return r_; };
	int GetIsAlive() { return isAlive_; }
	void SetPosition(int posX, int posY, int speed);
	void SetIsAlive(int isAlive) { isAlive_ = isAlive; }

	bullet* bullet_;
	int bulletSpeed_;
	int bulletR_;
	int isShot_;
};