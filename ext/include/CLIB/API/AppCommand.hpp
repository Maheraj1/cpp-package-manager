#pragma once

#include "Core/CommandOutput.hpp"
#include "Command.hpp"

namespace CLIB::API {
	class CLIB_API AppCommand: public Command {
		public:
			AppCommand();
			virtual int HandleRun(std::vector<std::string> args, CommandOutput& out) override;

			std::function<int(std::vector<std::string>, CommandOutput&)> globalCommand;
	};
}

