#pragma once
#include "virus.h"
class Patent
{
private:
	int m_resistance;
	int m_state;
	list<virus*> m_virusList;
public:
	Patent();
	Patent(int m_resistance, int m_state, list<virus*> m_virusList);
	~Patent();
	int GetState();
	void InitResistance();
	void DoStart();
	void TakeMedicine(int medicine_resistance);
	void DoDie();
};
