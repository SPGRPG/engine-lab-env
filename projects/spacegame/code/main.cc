//------------------------------------------------------------------------------
// main.cc
// (C) 2015-2018 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "config.h"
#include "spacegameapp.h"
#include <iostream>
#include "core/Memory_ass.h"
#include "core/Arena_Allocator.h"

using namespace std;
void some_function(Arena& arena)
{
	auto* ptr = arena.allocate(sizeof(random_class), alignof(random_class));
	auto* random_class_ptr = new(ptr) random_class({ 3,4 });
	arena.print_block_adress();
	arena.print_offset();
	arena.provide_capacity();
	arena.print_remaining_space();
	arena.reset();
	std:: cout << "arena has been reset\n";
	arena.print_offset();
	arena.print_remaining_space();

}
void some_parent_funct()
{
	Arena test_arena(1024);
	test_arena.provide_capacity();
	some_function(test_arena);
}


int
main(int argc, const char** argv)
{
	some_parent_funct();

	Game::SpaceGameApp app;
	if (app.Open())
	{
		app.Run();
		app.Close();
	}
	
	app.Exit();
	Memory::GetInstance().PrintMemoryUsage();
	return 0;
	
}
