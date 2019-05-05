#pragma once

//pre define
class Ninja;
class NinjaState;

class NinjaData
{
public:
	NinjaData();
	~NinjaData();
	Ninja *ninja;
	NinjaState *ninjaState;

};

