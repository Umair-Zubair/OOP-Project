// Enemy.cpp

#include "Enemy.hpp"
#include <cmath>
#include <iostream>
#include "health.hpp"
#include "Entity.hpp"

Enemy::Enemy(float _x, float _y, SDL_Texture* _ptr) : Entity(_x, _y, _ptr), speed(1.0f), attackRange(50), enemy_hp(100), lastAnimationTime(SDL_GetTicks()){
    change_src(16, 12, 24, 29);
    animationDelay = 100;
    currentDirection = "Up";
}

int Enemy::getCurrentHealth() {
    return enemyHealth.getCurrentHealth();
}

void Enemy::decreaseHealth() {
    enemyHealth.decreaseEnemyHealth();
}

std::string Enemy::getWeaponType() const {
    return weaponType;
}

void Enemy:: moveTowardsPlayer(Player& player, maze& gameMaze, std::vector<Entity>& wall, std::vector<Entity>& checkObstacles) {
    float dx = player.GetX() - x;
    float dy = player.GetY() - y;
    float distance = std::sqrt(dx * dx + dy * dy);

    if (distance != 0) {
        dx /= distance;
        dy /= distance;
    }

    if (std::abs(dx) > std::abs(dy)) {
        currentDirection = (dx > 0) ? "Right" : "Left";
    } else {
        currentDirection = (dy > 0) ? "Down" : "Up";
    }

    float nextX = x + dx * speed;
    float nextY = y + dy * speed;

    if (!checkCollision(player)) {
        if (currentDirection == "Left") {
            for (int i = 0; i < wall.size(); i++) {
                if (x < wall[i].GetX() + 75 && x + 75 > wall[i].GetX() &&
                    y + 75 > wall[i].GetY() && y < wall[i].GetY() + 75) {
                    nextY = y;
                    cout << "left enter";
                }
            }
            for (int i = 0; i < checkObstacles.size(); i++) {
                if (x < checkObstacles[i].GetX() + 75 && x + 75 > checkObstacles[i].GetX() &&
                    y + 75 > checkObstacles[i].GetY() && y < checkObstacles[i].GetY() + 75) {
                    nextX = checkObstacles[i].GetX() + 75;
                }
            }
            x = nextX; 
            y = nextY;
        }

        else if (currentDirection == "Right"){
            for (int i = 0; i < wall.size(); i++) {
                if (x + 75 > wall[i].GetX() && x < wall[i].GetX() + 75 &&
                    y + 75 > wall[i].GetY() && y < wall[i].GetY() + 75) {
                    nextY = y;
                    cout << "Right enter";
                }
            }

            for (int i = 0; i < checkObstacles.size(); i++) {
                if (x + 75 > checkObstacles[i].GetX() && x < checkObstacles[i].GetX() + 75 &&
                    y + 75 > checkObstacles[i].GetY() && y < checkObstacles[i].GetY() + 75) {
                    nextX = checkObstacles[i].GetX() - 75;
                }
            }

            x = nextX;
            y = nextY;
        }

        else if (currentDirection == "Up"){
            for (int i=0;i<wall.size();i++){
                if (y < (wall[i].GetY() + 75) && (y + 75) > wall[i].GetY() &&
                    x < (wall[i].GetX() + 75) && (x + 75) > wall[i].GetX()) {
                    nextX = x;
                    cout << "Up enter";
                }
            }
            for (int i=0;i<checkObstacles.size();i++){
                if (y < (checkObstacles[i].GetY() + 75) && (y + 75) > checkObstacles[i].GetY() &&
                    x < (checkObstacles[i].GetX() + 75) && (x + 75) > checkObstacles[i].GetX()) {
                    nextY = checkObstacles[i].GetY() + 77;
                }
            }

            x = nextX;
            y = nextY;
        }

        else if (currentDirection == "Down"){
            for (int i = 0; i < wall.size(); i++) {
                if (y + 75 > wall[i].GetY() && y < wall[i].GetY() + 75 &&
                    x + 75 > wall[i].GetX() && x < wall[i].GetX() + 75) {
                    nextX = x;
                    cout << "Down enter";
                    cout << x << " " << y << endl;
                }
            }

            for (int i = 0; i < checkObstacles.size(); i++) {
                if (y + 75 > checkObstacles[i].GetY() && y < checkObstacles[i].GetY() + 75 &&
                    x + 75 > checkObstacles[i].GetX() && x < checkObstacles[i].GetX() + 75) {
                    nextY = checkObstacles[i].GetY() - 77;
                }
            }

            x = nextX;
            y = nextY;
        }
    }

    if (distance < attackRange) {
        if (player.getCurrentHealth() > 0) {
            if (currentDirection == "Up") {
                AttackUpAnimation(player);
                currentFrameUpIndex = (currentFrameUpIndex + 1) % 6;
                cout << "in Up attack!";
            } 
            else if (currentDirection == "Down") {
                AttackDownAnimation(player);
                currentFrameDownIndex = (currentFrameDownIndex + 1) % 6;
                cout << "in Down attack!";
            } 
            else if (currentDirection == "Left") {
                AttackLeftAnimation(player);
                currentFrameLeftIndex = (currentFrameLeftIndex + 1) % 6;
                cout << "in Left attack!";
            } 
            else if (currentDirection == "Right") {
                AttackRightAnimation(player);
                currentFrameRightIndex = (currentFrameRightIndex + 1) % 6;
                cout << "in right attack!";
            }
        }
    }

    else{
        int currentTime = SDL_GetTicks();
        int deltaTime = currentTime - lastAnimationTime;

        if (deltaTime >= animationDelay) {
            if (currentDirection == "Up") {
                updateUpAnimation(currentFrameUpIndex);
                currentFrameUpIndex = (currentFrameUpIndex + 1) % 6;
            } else if (currentDirection == "Down") {
                updateDownAnimation(currentFrameDownIndex);
                currentFrameDownIndex = (currentFrameDownIndex + 1) % 6;
            } else if (currentDirection == "Left") {
                updateLeftAnimation(currentFrameLeftIndex);
                currentFrameLeftIndex = (currentFrameLeftIndex + 1) % 6;
            } else if (currentDirection == "Right") {
                updateRightAnimation(currentFrameRightIndex);
                currentFrameRightIndex = (currentFrameRightIndex + 1) % 6;
            }

            lastAnimationTime = currentTime;
        }
    }
}

void Enemy::updateUpAnimation(int currentFrameIndex) {

    if (currentFrameIndex == 0) {
        change_src(16,204,24,29);
    } else if (currentFrameIndex == 1) {
        change_src(64,204,23,28);
    } else if(currentFrameIndex == 2){
        change_src(112,203,22,28);
    } else if (currentFrameIndex == 3) {
        change_src(160,204,24,29);
    } else if (currentFrameIndex == 4) {
        change_src(209,204,23,28);
    } else if (currentFrameIndex == 5) {
        change_src(257,203,23,28);
    }
}

void Enemy:: updateDownAnimation(int currentFrameIndex){

    if (currentFrameIndex == 0) {
        change_src(8, 252, 24, 29);
    } else if (currentFrameIndex == 1) {
        change_src(56,252,24,28);
    } else if(currentFrameIndex == 2){
        change_src(105,251,23,28);
    } else if (currentFrameIndex == 3) {
        change_src(125,252,24,29);
    } else if (currentFrameIndex == 4) {
        change_src(199,252,24,28);
    } else if (currentFrameIndex == 5) {
        change_src(247,251,24,28);
    }
}

void Enemy:: updateLeftAnimation(int currentFrameIndex){

    if (currentFrameIndex == 0) {
        change_src(9, 348, 24, 29);
    } else if (currentFrameIndex == 1) {
        change_src(55,348,27,28);
    } else if(currentFrameIndex == 2){
        change_src(103,347,28,26);
    } else if (currentFrameIndex == 3) {
        change_src(153,348,24,29);
    } else if (currentFrameIndex == 4) {
        change_src(203,348,21,28);
    } else if (currentFrameIndex == 5) {
        change_src(251,347,21,26);
    }
}

void Enemy:: updateRightAnimation(int currentFrameIndex){

    if (currentFrameIndex == 0) {
        change_src(16, 300, 17, 29);
    } else if (currentFrameIndex == 1) {
        change_src(63,300,20,28);
    } else if(currentFrameIndex == 2){
        change_src(110,299,21,26);
    } else if (currentFrameIndex == 3) {
        change_src(160,300,17,29);
    } else if (currentFrameIndex == 4) {
        change_src(209,300,15,28);
    } else if (currentFrameIndex == 5) {
        change_src(257,299,17,26);
    }
}

void Enemy::AttackUpAnimation(Player& player) {

    static int currentFrameIndex = 0;

    if (currentFrameIndex == 0) {
        change_src(16, 12, 24, 29);
        currentFrameIndex++;
    } else if (currentFrameIndex == 1) {
        change_src(64,16,25,28);
        currentFrameIndex++;
    } else if(currentFrameIndex == 2) {
        change_src(112,17,25,27);
        currentFrameIndex++;
    } else if (currentFrameIndex == 3) {
        change_src(160,18,25,26);
        currentFrameIndex++;
    } else if (currentFrameIndex == 4) {
        change_src(208,18,25,26);
        currentFrameIndex++;
    } else if (currentFrameIndex == 5) {
        change_src(256,18,25,26);
        currentFrameIndex++;
    } else if (currentFrameIndex == 6) {
        change_src(300,4,30,36);
        currentFrameIndex++;
    } else {
        change_src(348,7,17,33);
        currentFrameIndex = 0;
        if (AttackCollision(player)) {
            player.decreaseHealth();
        }
    }
}

void Enemy::AttackDownAnimation(Player& player) {

    static int currentFrameIndex = 0;

    if (currentFrameIndex == 0) {
        change_src(8,60,24,29);
        currentFrameIndex++;
    } else if (currentFrameIndex == 1) {
        change_src(56,59,24,30);
        currentFrameIndex++;
    } else if(currentFrameIndex == 2) {
        change_src(104,60,24,29);
        currentFrameIndex++;
    } else if (currentFrameIndex == 3) {
        change_src(152,60,24,29);
        currentFrameIndex++;
    } else if (currentFrameIndex == 4) {
        change_src(200,60,24,29);
        currentFrameIndex++;
    } else if (currentFrameIndex == 5) {
        change_src(248,60,24,29);
        currentFrameIndex++;
    } else if (currentFrameIndex == 6) {
        change_src(294,65,28,27);
        currentFrameIndex++;
    } else {
        change_src(355,63,14,29);
        currentFrameIndex = 0;
        if (AttackCollision(player)) {
            player.decreaseHealth();
        }
    }
}

void Enemy::AttackLeftAnimation(Player& player) {


    static int currentFrameIndex = 0;

    if (currentFrameIndex == 0) {
        change_src(9,108,24,29);
        currentFrameIndex++;
    } else if (currentFrameIndex == 1) {
        change_src(58,109,26,29);
        currentFrameIndex++;
    } else if(currentFrameIndex == 2) {
        change_src(106,110,26,28);
        currentFrameIndex++;
    } else if (currentFrameIndex == 3) {
        change_src(154,110,26,28);
        currentFrameIndex++;
    } else if (currentFrameIndex == 4) {
        change_src(202,110,26,28);
        currentFrameIndex++;
    } else if (currentFrameIndex == 5) {
        change_src(201,105,25,33);
        currentFrameIndex++;
    } else if (currentFrameIndex == 6) {
        change_src(293,110,28,31);
        currentFrameIndex++;
    } else {
        change_src(351,110,18,31);
        currentFrameIndex = 0;
        if (AttackCollision(player)) {
            player.decreaseHealth();
        }
    }
}

void Enemy::AttackRightAnimation(Player& player) {

    static int currentFrameIndex = 0;

    if (currentFrameIndex == 0) {
        change_src(16,156,17,29);
        currentFrameIndex++;
    } else if (currentFrameIndex == 1) {
        change_src(61,157,19,29);
        currentFrameIndex++;
    } else if(currentFrameIndex == 2) {
        change_src(109,158,19,28);
        currentFrameIndex++;
    } else if (currentFrameIndex == 3) {
        change_src(157,158,19,28);
        currentFrameIndex++;
    } else if (currentFrameIndex == 4) {
        change_src(205,158,19,28);
        currentFrameIndex++;
    } else if (currentFrameIndex == 5) {
        change_src(253,158,19,28);
        currentFrameIndex++;
    } else if (currentFrameIndex == 6) {
        change_src(309,156,24,29);
        currentFrameIndex++;
    } else {
        change_src(357,157,23,28);
        currentFrameIndex = 0;
        if (AttackCollision(player)) {
            player.decreaseHealth();
        }
    }
}