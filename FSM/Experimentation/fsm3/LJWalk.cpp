#include "LJWalk.h"

void LJWalk::Enter(Lumberjack* _LJ) {
	std::cout << "Entering Walk" << std::endl;
}

void LJWalk::Update(Lumberjack* _LJ) {
	if (_LJ->Target_Node + 1 < _LJ->Path->size()) {
		_LJ->Target_Node++;
	} else {
		_LJ->Target_Node = 0;
		_LJ->Change_State(_LJ->Sleep);
	}
}

void LJWalk::Exit(Lumberjack* _LJ) {

}

