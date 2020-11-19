#pragma once

class ITaxPayments 
{
public:
	virtual ~ITaxPayments()
	{
	};

	virtual void payTax() = 0;
};