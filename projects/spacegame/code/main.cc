//------------------------------------------------------------------------------
// main.cc
// (C) 2015-2018 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "config.h"
#include "spacegameapp.h"
#include <iostream>
#include "core/Memory_ass.h"
using namespace std;

int
main(int argc, const char** argv)
{
	
	Game::SpaceGameApp app;
	if (app.Open())
	{
		app.Run();
		app.Close();
	}
	main_memory->PrintMemoryUsage();
	app.Exit();
	return 0;
	
}
