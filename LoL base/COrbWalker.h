#pragma once
#include "CObject.h"
#include "Engine.h"
#include <chrono>
#include <vector>
#include <algorithm>

class COrbWalker {
private:
	CObject* m_pTarget;
	int m_nLastAttackCmdTick;
	int m_nLastMoveCmdTick;
	std::chrono::milliseconds m_lastMoveClickTime;
	bool autoMove;
	bool preferHarassOverFarm;

private:
	CObject* GetNearestToMouseMinion();
	std::vector<CObject*> GetObjects();

public:
	bool lastHitOnly;
	COrbWalker::COrbWalker() : m_pTarget(nullptr), m_nLastAttackCmdTick(0), m_nLastMoveCmdTick(0), m_lastMoveClickTime(0),
		lastHitOnly(false), autoMove(true), preferHarassOverFarm(true)
	{
	}

public:
	void tryFindTarget();
	void drawEvent();
};