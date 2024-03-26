#pragma once

#include "API/AppCommand.hpp"
#include "API/AppDelegate.hpp"
#include "Core.hpp"

namespace CLIB {
	class CLIB_API App {
		API::AppDelegate* appDelegate;
		public:
			App(API::AppDelegate* appDelegate) 
			:appDelegate(appDelegate)
			{ }
			~App() { delete appDelegate; }

			int Run(int argc, char** argv);

			API::AppCommand AppCommand;
	};
}
