#pragma once
#include "Code/Collision3D.h"

class Collision3D;

enum class Data3DClass
{
	COLLISION,
};

class Data3D : public IGameObject
{
public:
	void Data3DNewGO()
	{
		P_Collision3D =
		NewGO<Collision3D>
		(0, "collision3d");
	}
	void Data3DNewGO(Data3DClass Class)
	{
		switch (Class)
		{
		case Data3DClass::COLLISION:
			P_Collision3D =
			NewGO<Collision3D>
			(0, "collision3d");
			break;
		}
	}

	void Data3DFindGO()
	{
		P_Collision3D =
		FindGO<Collision3D>
		("collision3d");
	}

	void Data3DDeleteGO()
	{
		DeleteGO(P_Collision3D);
	}
	void Data3DDeleteGO(Data3DClass Class)
	{
		switch (Class)
		{
		case Data3DClass::COLLISION:
			DeleteGO(P_Collision3D);
			break;
		}
	}
public:
	Collision3D* P_Collision3D = nullptr;
};