#pragma once
#include "Markup.h"

class File
{
	static int loggedUserID;

protected:
	CMarkup file;

	void setPositionToFirstElement();

public:
	virtual bool load() = 0;
	virtual void save() = 0;
	int getLoggedUserID();
	void setLoggedUserID(int ID);
};

