#pragma once

#include "Core/CommandOutput.hpp"
#include "Core/Core.hpp"

#include <vector>
#include <functional>

namespace CLIB::API {
	class CLIB_API Command {
		public:
			Command(bool HasHeirarchyOfCommands, std::string name);
			virtual ~Command() = default;

			virtual int HandleRun(std::vector<std::string> args, CommandOutput& out) = 0;
			
			void RegisterSubCommand(Command* subcommand);
			std::vector<Command*> subcommands;
			
			const bool HasHeirarchyOfCommands;
			std::string name;
	};
}
