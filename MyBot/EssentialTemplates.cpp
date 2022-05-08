#include "EssentialTemplates.h"
 
template<typename T> PlayerData* CreateInstance() 
{
	return new T; 
}