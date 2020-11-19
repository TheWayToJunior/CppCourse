#pragma once

class IShuffle
{
public:
	virtual ~IShuffle() {};

	void virtual shuffle() = 0;
	void virtual shuffle(size_t i, size_t j) = 0;
};

