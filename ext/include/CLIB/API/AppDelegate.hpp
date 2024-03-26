#pragma once

#include "API/AppCommand.hpp"
#include "Core/Core.hpp"

namespace CLIB::API {
	class CLIB_API AppDelegate {
		public:
			AppDelegate() = default;
			virtual ~AppDelegate() = default;

			virtual void Setup(API::AppCommand* appCommand) = 0;
			virtual void Cleanup() = 0;
	};
}
