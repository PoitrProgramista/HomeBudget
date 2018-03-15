#include "File.h"


int File::loggedUserID;

int File::getLoggedUserID()
{
	return loggedUserID;
}

void File::setLoggedUserID(int ID)
{
	loggedUserID = ID;
}

void File::setPositionToFirstElement()
{
	file.ResetPos();
	file.FindElem();
	file.IntoElem();
}
