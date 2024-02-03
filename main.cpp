#include <Novice.h>
#include"player.h"
#include"enemy.h"

const char kWindowTitle[] = "GC1D_05_コヤマ_ショウタ";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	enemy* enemy1 = new enemy(640, 150, 5);
	player* player1 = new player(640, 550, 7);

	int titleImage = Novice::LoadTexture("./TITLE.PNG");
	int clearImage = Novice::LoadTexture("./CLEAR.PNG");
	int backImage = Novice::LoadTexture("./Back.png");


	//敵と弾用
	float distanceX;
	float distanceY;
	float distance;
	int r;

	//敵と自機用
	float distanceX2;
	float distanceY2;
	float distance2;
	int r2;

	int enemyRespawnTimer = 30;
	int playerRespawnTimer = 30;
	int enemyHP = 2;

	enum Scene {

		TITLE,
		GAME,
		CLEAR,

	};

	int scene = TITLE;
	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		switch (scene)
		{
		case TITLE:
			if (keys[DIK_SPACE]&&preKeys[DIK_SPACE]==0) {
				scene = GAME;
				enemyHP = 2;
				enemy1->SetIsAlive(1);
			}
			break;
		case GAME:



			//敵と弾
			distanceX = float(enemy1->GetPosX() - player1->bullet_->GetPosX());
			distanceY = float(enemy1->GetPosY() - player1->bullet_->GetPosY());
			distance = (distanceX * distanceX) + (distanceY * distanceY);
			r = enemy1->GetRadius() + player1->bullet_->GetRadius();
			if (distance <= r * r && player1->bullet_->GetIsShot() == 1) {
				player1->bullet_->SetIsShot(0);
				enemyRespawnTimer = 30;
				enemy1->SetIsAlive(0);
				enemyHP -= 1;
			}
			if (enemyRespawnTimer > 0) {
				enemyRespawnTimer--;
				if (enemyRespawnTimer == 0) {
					enemy1->SetIsAlive(1);

				}
			}
			//敵と自機
			distanceX2 = float(enemy1->GetPosX() - player1->GetPosX());
			distanceY2 = float(enemy1->GetPosY() - player1->GetPosY());
			distance2 = (distanceX2 * distanceX2) + (distanceY2 * distanceY2);
			r2 = enemy1->GetRadius() + player1->GetRadius();

			if (distance2 <= r2 * r2) {
				playerRespawnTimer = 50;
				player1->SetIsAlive(0);
			}
			if (playerRespawnTimer > 0) {
				playerRespawnTimer--;
				if (playerRespawnTimer == 0) {
					player1->SetIsAlive(1);

				}
			}

			enemy1->Update();
			player1->Update(keys, preKeys);

			if (enemyHP == 0) {
				scene = CLEAR;
				enemyRespawnTimer = 30;
			}
			break;
		case CLEAR:
			if (keys[DIK_SPACE]) {
				scene = TITLE;
			}
			break;
		
		}
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		switch (scene)
		{
		case TITLE:
			Novice::DrawSprite(0,0,titleImage, 1, 1, 0.0f, WHITE);
			break;
		case GAME:
			Novice::DrawSprite(0, 0, backImage, 1, 1, 0.0f, WHITE);
			enemy1->Draw();
			player1->Draw();

			break;
		case CLEAR:
			Novice::DrawSprite(0, 0, clearImage, 1, 1, 0.0f, WHITE);

			break;
		}
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
