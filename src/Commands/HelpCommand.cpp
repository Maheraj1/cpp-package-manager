#include "Commands/HelpCommand.hpp"
#include "API/Command.hpp"
#include <cstdlib>

namespace PkgM {
	HelpCommand::HelpCommand()
	:CLIB::API::Command(false, "-help") { }

	int HelpCommand::HandleRun(std::vector<std::string> args, CLIB::CommandOutput& out) {
		out << "C++ Package Manager. Here Are Commands:\n";
		return EXIT_SUCCESS;
	}
}
