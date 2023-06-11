#include "MyEngineSystem.h"

MyChasePatrolAI::MyChasePatrolAI(int starting_x, int starting_y, int e_width, int e_height) {

	std::cout << "Enemy spawned! x: " << starting_x << "y: " << starting_y << "\n";
	x = starting_x;
	y = starting_y;
	width = e_width;
	height = e_height;

};

MyChasePatrolAI::MyChasePatrolAI() {

}


double MyChasePatrolAI::EuclideanDistance(int x1, int y1, int x2, int y2) {

		int eDistance_x = x2 - x1;
		int eDistance_y = y2 - y1;
		double distance = std::sqrt(eDistance_x * eDistance_x + eDistance_y * eDistance_y);
		return distance;
}

void MyChasePatrolAI::PatrolMoveTo(int patrolLocation_x, int patrolLocation_y) {

	if (x < patrolLocation_x)
		x++;
	else if (x > patrolLocation_x)
		x--;

	if (y < patrolLocation_y)
		y++;
	else if (y > patrolLocation_y)
		y--;
}

void MyChasePatrolAI::EnemyPatrol(int maxPatrolRange_x, int maxPatrolRange_y, int minPatrolRange_x, int minPatrolRange_y) {
	
	// Seeds RNG
	std::srand(static_cast<unsigned int>(std::time(nullptr)));

	// Generates random x and y patrol coordinates
	int randPatrolLocation_x = std::rand() % (maxPatrolRange_x + 1 - minPatrolRange_x) + minPatrolRange_x;
	int randPatrolLocation_y = std::rand() % (maxPatrolRange_y + 1 - minPatrolRange_y) + minPatrolRange_y;
	
	PatrolMoveTo(randPatrolLocation_x, randPatrolLocation_y);

}

void MyChasePatrolAI::EnemyChase(int targetEntity_x, int targetEntity_y, int enemyRange) {

	int distanceFromPlayer = EuclideanDistance(x, y, targetEntity_x, targetEntity_y);

	if (distanceFromPlayer <= enemyRange)
	{
		targetInRange = true;

		if (x < targetEntity_x)
			x++;
		else if (x > targetEntity_x)
			x--;

		if (y < targetEntity_y)
			y++;
		else if (y > targetEntity_y)
			y--;

		if (x == targetEntity_x && y == targetEntity_y)
			targetReached = true;
		else
			targetReached = false;
	}

	else {

		EnemyPatrol(600, 300, 500, 200);
	}


}




