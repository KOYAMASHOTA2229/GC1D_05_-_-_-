#include "bullet.h"
#include"Novice.h"

bullet::bullet(int bulletPosX, int bulletPosY, int bulletSpeed, int bulletR, int isShot)
{
	bulletPosX_ = bulletPosX;
	bulletPosY_ = bulletPosY;
	bulletSpeed_ = bulletSpeed;
	bulletR_ = bulletR;
	isShot_ = isShot;

}


void bullet::SetPosition(int bulletPosX, int bulletPosY, int bulletSpeed)
{
	bulletPosX_ = bulletPosX;
	bulletPosY_ = bulletPosY;
	bulletSpeed_ = bulletSpeed;
}
void bullet::Update()
{
	if (isShot_ == 1) {
		bulletPosY_ -= bulletSpeed_;
	}

	if (bulletPosY_ < bulletR_ && isShot_ == 1) {
		isShot_ = 0;

	}
}

void bullet::Draw()
{
	if (isShot_ == 1) {

		Novice::DrawEllipse(bulletPosX_, bulletPosY_, bulletR_, bulletR_, 0.0f, RED, kFillModeSolid);
	}
}