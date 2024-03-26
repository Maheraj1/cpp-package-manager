#include "API/Command.hpp"
#include <cassert>

namespace CLIB::API {

	Command::Command(bool HasHeirarchyOfCommands, std::string name) 
	:HasHeirarchyOfCommands(HasHeirarchyOfCommands), name(name)
	{ }

	void Command::RegisterSubCommand(Command *subcommand) {
		if (HasHeirarchyOfCommands)
			subcommands.push_back(subcommand);
		else
			assert(false);
	}
}
