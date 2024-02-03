#pragma once
class bullet
{

public:
	bullet(int bulletPosX, int bulletPosY, int bulletSpeed, int bulletR, int isShot);
	void Update();
	void Draw();


	int GetPosX() { return bulletPosX_; };
	int GetPosY() { return bulletPosY_; };
	int GetSpeed() { return bulletSpeed_; };
	int GetIsShot() { return isShot_; }
	void SetSpeed(int bulletSpeed) { bulletSpeed_ = bulletSpeed; }
	void SetIsShot(int isShot) { isShot_ = isShot; }
	int GetRadius() { return bulletR_; };
	void SetPosition(int bulletPosX, int bulletPosY, int bulletSpeed);


private:
	int bulletPosX_;
	int bulletPosY_;
	int bulletSpeed_;
	int bulletR_;
	int isShot_;


};


