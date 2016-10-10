#include "LJSleep.h"

void LJSleep::Enter(Lumberjack* _LJ) {
	std::cout << "Entering Sleep" << std::endl;
}

void LJSleep::Update(Lumberjack* _LJ) {

	if (_LJ->Path == &_LJ->Path_Walk) { // We're still looking for the entrance node
		if (_LJ->Path->at(_LJ->Target_Node) == _LJ->Path_Sleep[0]) { // Current node is entrance node
			_LJ->Path = &_LJ->Path_Sleep; // Change path to destination path
			_LJ->Target_Node = 1; // Change target node to destination
		} else {
			_LJ->Target_Node = _LJ->Target_Node == _LJ->Path->size() - 1 ? 0 : _LJ->Target_Node + 1; // Keep looking, restart if at the end
		}
	} else { // We are at the destination
		_LJ->Energy += 1;
		if (_LJ->Energy >= 100) {
			_LJ->Change_State(_LJ->Harvest);
		}
	}

}

void LJSleep::Exit(Lumberjack* _LJ) {
	_LJ->Path = &_LJ->Path_Walk;
	for(int i = 0; i < _LJ->Path->size(); ++i) {
		if(_LJ->Path_Walk[i] == _LJ->Path_Sleep[0]) {
			_LJ->Target_Node = i;
			break;
		}
	}
}