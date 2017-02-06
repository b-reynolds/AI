#pragma once
#include "BlackboardType.h"
#include "Vector2.h"
#include <vector>
#include <cstdarg>

class BlackboardVectorList : public BlackboardType
{
public:

	explicit BlackboardVectorList(std::vector<Vector2<float>> vectorList) : vectorList(vectorList) {}
	explicit BlackboardVectorList(const Vector2<float> v, ...);
	// TODO: Variadic template?



	//std::vector<Vector2<T>>& get() { return vectorList; }

private:

	std::vector<Vector2<float>> vectorList;

};
