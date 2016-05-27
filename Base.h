#include <string>

#pragma once

class Printable
{
public:
	virtual std::string GetInfo() const = 0;
	~Printable() {}
};

class Named : public Printable
{
public:
	
	Named(std::string name)
	{
		m_name = name;
	}
	
	
	virtual std::string GetInfo() const { return this->m_name; }

private:
	std::string m_name;
};