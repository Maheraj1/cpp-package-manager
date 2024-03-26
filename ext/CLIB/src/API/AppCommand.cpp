#include "API/AppCommand.hpp"
#include "Core/CommandOutput.hpp"
#include <cstdlib>

namespace CLIB::API {
	AppCommand::AppCommand() 
	:Command(true, "")
	{ }

	int AppCommand::HandleRun(std::vector<std::string> args, CommandOutput& out) {
		if (globalCommand) 
			return globalCommand(args, out);
		else
			return EXIT_FAILURE;
	}
}
