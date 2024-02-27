#pragma once
#include "Code/Clear.h"
#include "Code/Ending.h"
#include "Code/NotClear.h"
#include "Code/Title.h"
#include "Code/Ui.h"

class Clear;
class Ending;
class NotClear;
class Title;
class Ui;

enum class SpriteClass
{
	CLEAR,
	ENDING,
	NOTCLEAR,
	TITLE,
	UI
};

class GameSprite : public IGameObject
{
public:
	void SpriteNewGO(SpriteClass Class)
	{
		switch (Class)
		{
		case SpriteClass::CLEAR:
			P_Clear =
			NewGO<Clear>
			(0, "clear");
			break;
		case SpriteClass::ENDING:
			P_Ending =
			NewGO<Ending>
			(0, "ending");
			break;
		case SpriteClass::NOTCLEAR:
			P_NotClear =
			NewGO<NotClear>
			(0, "notclear");
			break;
		case SpriteClass::TITLE:
			P_Title =
			NewGO<Title>
			(0, "title");
			break;
		case SpriteClass::UI:
			P_Ui =
			NewGO<Ui>
			(0, "ui");
			break;
		}
	}

	void SpriteFindGO()
	{
		P_Clear =
		FindGO<Clear>
		("clear");

		P_Ending =
		FindGO<Ending>
		("ending");

		P_NotClear =
		FindGO<NotClear>
		("notclear");

		P_Title =
		FindGO<Title>
		("title");

		P_Ui =
		FindGO<Ui>
		("ui");
	}

	void SpriteDeleteGO()
	{
		DeleteGO(P_Clear);
		DeleteGO(P_Ending);
		DeleteGO(P_NotClear);
		DeleteGO(P_Title);
		DeleteGO(P_Ui);
	}
	void SpriteDeleteGO(SpriteClass Class)
	{
		switch (Class)
		{
		case SpriteClass::CLEAR:
			DeleteGO(P_Clear);
			break;
		case SpriteClass::ENDING:
			DeleteGO(P_Ending);
			break;
		case SpriteClass::NOTCLEAR:
			DeleteGO(P_NotClear);
			break;
		case SpriteClass::TITLE:
			DeleteGO(P_Title);
			break;
		case SpriteClass::UI:
			DeleteGO(P_Ui);
			break;
		}
	}
public:
	Clear* P_Clear = nullptr;
	Ending* P_Ending = nullptr;
	NotClear* P_NotClear = nullptr;
	Title* P_Title = nullptr;
	Ui* P_Ui = nullptr;
};