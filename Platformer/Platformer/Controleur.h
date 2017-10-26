#pragma once
class Controleur
{
public:
	static Controleur *getInstance();
	static void release();
	

private:
	Controleur();
	static Controleur *instance;
	
};