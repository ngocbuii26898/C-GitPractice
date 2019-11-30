#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <list>


using namespace std;
class virus
{
private:
	char* m_dna;
	int m_resistance;
public:
	virus();
	virus(const virus& virus);
	virtual ~virus();
	void SetDNA(const char* m_dna);
	char* GetDNA();
	void SetResistance(int m_resistance);
	int GetResistance();
	void LoadADNInformation();
	bool ReduceResistace(int medicine_Resistance);
	virtual void DoBorn() = 0;
	virtual std::list<virus*> DoClone() = 0;
	virtual void DoDie() = 0;
	virtual void InitResistance() = 0;

};

class Fluvirus:
	public virus
{
private:
	int m_color;
public:
	Fluvirus();
	Fluvirus(const Fluvirus& v);
	~Fluvirus();
	void DoBorn();
	list<virus*>DoClone();
	void DoDie();
	void InitResistance();
};

class Dengue :
	public virus
{
protected:
	char* m_protein;
public:
	Dengue();
	~Dengue();
	Dengue(const Dengue& v);
	void SetProtein(const char* protein);
	char* GetProtein();
	void DoBorn();
	list<virus*> DoClone();
	void DoDie();
	void InitResistance();

};

