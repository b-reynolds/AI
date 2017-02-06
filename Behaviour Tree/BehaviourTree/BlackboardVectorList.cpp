#include "BlackboardVectorList.h"

BlackboardVectorList::BlackboardVectorList(const Vector2<float> v, ...)
{
	int amoutn;
	Vector2<float> vector;
	va_list v1;
	va_start(v1, v);
	for(auto i = 0; i < v; ++i)
	{
		vector = va_arg(v1, Vector2<float>);
		vectorList.push_back(vector);
	}
	va_end(v1);
}
