#include "CLIB/API/Command.hpp"

namespace PkgM {
	class HelpCommand: public CLIB::API::Command {
		 HelpCommand();
		~HelpCommand() = default;

		virtual int HandleRun(std::vector<std::string> args, CLIB::CommandOutput& out);
	};
}
