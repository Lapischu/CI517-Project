#ifndef __MY_ENGINE_H__
#define __MY_ENGINE_H__

#include "../EngineCommon.h"

class MyChasePatrolAI {
	friend class XCube2Engine;
	private:


	public:
		int x;
		int y;
		int width;
		int height;
		MyChasePatrolAI(int starting_x, int starting_y, int e_width,  int e_height);
		MyChasePatrolAI();
		double EuclideanDistance(int x1, int y1, int x2, int y2);
		void EnemyChase(int targetEntity_x, int targetEntity_y, int enemyRange);
		void EnemyPatrol(int maxPatrolRange_x, int maxPatrolRange_y, int minPatrolRange_x, int minPatrolRange_y);
		void PatrolMoveTo(int patrolLocation_x, int patrolLocation_y);
		bool targetReached = false;
		bool targetInRange = false;
		
};

#endif