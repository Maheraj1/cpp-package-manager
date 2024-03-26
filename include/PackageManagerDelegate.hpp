#pragma once

#include "CLIB/API/AppDelegate.hpp"

namespace PkgM {
	class PackageManagerDelegate: public ::CLIB::API::AppDelegate {
		
		virtual void Setup(::CLIB::API::AppCommand* appCommand) override;
		virtual void Cleanup() override;
	};
}