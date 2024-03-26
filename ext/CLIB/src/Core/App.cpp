#include "Core/App.hpp"
#include "API/Command.hpp"

#include <cstdlib>
#include <iostream>

namespace CLIB {

	int RunCommand(std::vector<std::string> args, API::Command* command, CommandOutput &out) {
		
		if (command->subcommands.empty()) {
			return command->HandleRun(args, out);
		}

		for (auto&& cmd: command->subcommands) {
			
			if (cmd->name != args[1]) continue;

			auto args_cmd = args;
			args_cmd.erase(args_cmd.begin());

			if (cmd->HasHeirarchyOfCommands) {
				return RunCommand(args_cmd, cmd, out);
			} else {
				return cmd->HandleRun(args_cmd, out);
			}
			
			break;
		}
		
		return EXIT_FAILURE;
	}

	int App::Run(int argc, char **argv) {
		appDelegate->Setup(&AppCommand);
		AppCommand.name = argv[0];

		std::vector<std::string> argv_vs;

		for (int i = 0; i < argc; i++) {
			argv_vs.emplace_back(argv[i]);
		}

		CommandOutput out;
		int status = RunCommand(argv_vs, &AppCommand, out);

		std::cout << out.str() << std::endl;

		return status;
	}
}
