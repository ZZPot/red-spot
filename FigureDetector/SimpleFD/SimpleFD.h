#pragma once
#include "../FigureDetector.h"


class simple_fd: public figure_detector
{
public:
	figure_type Predict(Obj2d& obj);
protected:
	static std::vector<type_condition> _figure_conditions;
};