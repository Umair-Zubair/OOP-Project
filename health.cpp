#include "health.hpp"

Health::Health() {
    maxHealth = 100;
    currentHealth = 100;
}

int Health::getCurrentHealth() const {

    return currentHealth;
}

void Health::decreaseEnemyHealth() {
    currentHealth -= 25;
    // Ensure currentHealth doesn't go below 0
    if (currentHealth < 0) {
        currentHealth = 0;
    }
}

void Health::decreasePlayerHealth() {
    currentHealth -= 15;
    // Ensure currentHealth doesn't go below 0
    if (currentHealth < 0) {
        currentHealth = 0;
    }
}

void Health::increaseHealth(int amount) {
    currentHealth += amount;

    // Ensure currentHealth doesn't exceed maxHealth
    if (currentHealth > maxHealth) {
        currentHealth = maxHealth;
    }
}
