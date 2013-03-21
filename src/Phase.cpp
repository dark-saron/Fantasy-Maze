#include "Phase.h"

CPhase::CPhase(void)
{
}


CPhase::~CPhase(void)
{
}


    
CPhase::EPhase CPhase::GetPhase()
{
	return _phase;
}

void CPhase::SetPhase(CPhase::EPhase& newState)
{
	_phase = newState;
}