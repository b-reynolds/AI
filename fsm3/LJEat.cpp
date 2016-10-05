#include "LJEat.h"

void LJEat::Enter(Lumberjack* _LJ) {
	std::cout << "Entering Eat" << std::endl;
}

void LJEat::Update(Lumberjack* _LJ) {

	if (_LJ->Path == &_LJ->Path_Walk) { // We're still looking for the entrance node
		if (_LJ->Path->at(_LJ->Target_Node) == _LJ->Path_Eat[0]) { // Current node is entrance node
			_LJ->Path = &_LJ->Path_Eat; // Change path to destination path
			_LJ->Target_Node = 1; // Change target node to destination
		} 
		else {
			_LJ->Target_Node = _LJ->Target_Node == _LJ->Path->size() - 1 ? 0 : _LJ->Target_Node + 1; // Keep looking, restart if at the end
		}
	}
	else { // We are at the destination
		_LJ->Hunger -= 1;
		if (_LJ->Hunger <= 0) {
			_LJ->Change_State(_LJ->Harvest);
		}
	}

}

void LJEat::Exit(Lumberjack* _LJ) {
	_LJ->Path = &_LJ->Path_Walk; // Change path to patrol path
	for (int i = 0; i < _LJ->Path->size(); ++i) { 
		if (_LJ->Path_Walk[i] == _LJ->Path_Eat[0]) { // Find the exit/entrance  
			_LJ->Target_Node = i;
			break;
		}
	}
}


