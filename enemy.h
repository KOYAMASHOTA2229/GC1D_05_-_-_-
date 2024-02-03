#pragma once
class enemy
{
private:
	int enemyPosX_;
	int enemyPosY_;
	int enemySpeed_;
	int enemyR_;
	int isAlive_;
	int enemyImage_;

public:
	enemy(int enemyPosX, int enemyPosY, int enemySpeed);
	~enemy();
	void Update();
	void Draw();


	int GetPosX() { return enemyPosX_; };
	int GetPosY() { return enemyPosY_; };
	int GetSpeed() { return enemySpeed_; };
	int GetIsAlive() { return isAlive_; }
	void SetSpeed(int enemySpeed) { enemySpeed_ = enemySpeed; }
	void SetIsAlive(int isAlive) { isAlive_ = isAlive; }
	int GetRadius() { return enemyR_; };
	void SetPosition(int enemyPosX, int enemyPosY, int enemySpeed);
};

