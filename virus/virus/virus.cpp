#include "virus.h"
using namespace std;

virus::virus(const virus& virus)
{
	this->SetDNA(virus.m_dna);
	this->m_resistance = virus.m_resistance;
}
virus::virus()
{
	this->m_dna = new char[100]{ "" };
	this->m_resistance = 10;
}

virus::~virus()
{
	delete[] this->m_dna;

}
void virus::SetDNA(const char* m_dna)
{

	this->m_dna = new char[100];
	int i = 0;
	while (m_dna[i] != NULL) {
		this->m_dna[i] = m_dna[i];

	}
}

char* virus::GetDNA()
{
	return this->m_dna;
}

void virus::SetResistance(int m_resistance)
{
	this->m_resistance = m_resistance;
}

int virus::GetResistance()
{
	return this->m_resistance;
}

void virus::LoadADNInformation()
{
	fstream f;
	f.open("ATGX.bin");
	string nu;
	getline(f, nu);
	for (int i = 0; i < nu.length() + 1; i++)
	{
		this->m_dna[i] = nu[i];
	}
}

bool virus::ReduceResistace(int medicine_Resistance)
{
	return (this->m_resistance - medicine_Resistance) <= 0;
}


Fluvirus::Fluvirus()
{
	DoBorn();
	InitResistance();
}

Fluvirus::Fluvirus(const Fluvirus& v) : virus(v)
{
	this->m_color = v.m_color;
}

void Fluvirus::DoBorn()
{
	this->LoadADNInformation();
	int color[2] = { 0x0000ff, 0xff0000 };
	this->m_color = color[rand() % 2];
}

list<virus*> Fluvirus::DoClone()
{
	list<virus*> listVirus;
	Fluvirus* fl = new Fluvirus(*this);
	listVirus.push_back(fl);
	
	return listVirus;
}

void Fluvirus::DoDie()
{
	this->m_color = NULL;
	this->SetResistance(NULL);
}

void Fluvirus::InitResistance()
{
	if (this->m_color == 0x0000ff)
	{
		this->SetResistance(rand() % 6 + 10);
	}
	else
	{
		this->SetResistance(rand() % 11 + 10);
	}
}

Fluvirus::~Fluvirus()
{
	this->DoDie();

}

Dengue::Dengue()
{
	DoBorn();
	InitResistance();
}

Dengue::~Dengue()
{
	DoDie();
	delete[] m_protein;
}

Dengue::Dengue(const Dengue& vdengue) :virus(vdengue)
{
	this->SetProtein(vdengue.m_protein);
}

void Dengue::SetProtein(const char* protein)
{
	this->m_protein = new char[100];
	int i = 0;
	while (protein[i] != NULL) {
		this->m_protein[i] = protein[i];
		i++;
	}
}

char* Dengue::GetProtein()
{
	return this->m_protein;
}

void Dengue::DoBorn()
{
	this->LoadADNInformation();
	
	int pr = rand() % 2 + 1;
	if (pr == 0) {
		SetProtein("NS3");
		

	}
	else if (pr == 1) {
		SetProtein("NS5");
		
	}
	else
	{
		SetProtein("VTE");
		
	}

}

list<virus*> Dengue::DoClone()
{
	list<virus*> listVirus;
	Dengue* den = new Dengue(*this);
	listVirus.push_back(den);
	den = NULL;
	delete den;
	den = new Dengue(*this);
	listVirus.push_back(den);
	den = NULL;
	delete den;
	return listVirus;
}

void Dengue::DoDie()
{
	this->SetResistance(NULL);
	delete[] m_protein;
}

void Dengue::InitResistance()
{
	if (this->m_protein[2] == '3')
	{
		this->SetResistance(rand() % 10 + 1);
	}
	else if (this->m_protein[2] == '5')
	{
		this->SetResistance(rand() % 21 + 10);
	}
	else
	{
		this->SetResistance(rand() % 31 + 20);
	}
}