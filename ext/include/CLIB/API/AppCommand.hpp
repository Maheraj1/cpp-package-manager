#pragma once

#include "Core/CommandOutput.hpp"
#include "Command.hpp"

namespace CLIB::API {
	/* The Core Command from which all other commands inherit
		e.g. my_program
			AppCommand (my_program)
			 ↓		 ↓
HelpCommand (help)   DoSomethingCommand (do_something)
						↓			  ↓
			SomeSubCommand (some)	AnythingCommand (anything)
	
	*/
	class CLIB_API AppCommand: public Command {
		public:
			AppCommand();
			virtual int HandleRun(std::vector<std::string> args, CommandOutput& out) override;

			std::function<int(std::vector<std::string>, CommandOutput&)> globalCommand;
	};
}

