// Copyright (C) 2010 Florent Lamiraux, Thomas Moulard, JRL, CNRS/AIST.
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef ROBOPTIM_CORE_PLUGIN_CMINPACK_CONFIG_HH
# define ROBOPTIM_CORE_PLUGIN_CMINPACK_CONFIG_HH

// Package version (header).
# define ROBOPTIM_CORE_PLUGIN_CMINPACK_VERSION "1.0"

// Handle portable symbol export.
// Defining manually which symbol should be exported is required
// under Windows whether MinGW or MSVC is used.
//
// The headers then have to be able to work in two different modes:
// - dllexport when one is building the library,
// - dllimport for clients using the library.
//
// On Linux, set the visibility accordingly. If C++ symbol visibility
// is handled by the compiler, see: http://gcc.gnu.org/wiki/Visibility
# if defined _WIN32 || defined __CYGWIN__
// On Microsoft Windows, use dllimport and dllexport to tag symbols.
#  define ROBOPTIM_CORE_PLUGIN_CMINPACK_DLLIMPORT __declspec(dllimport)
#  define ROBOPTIM_CORE_PLUGIN_CMINPACK_DLLEXPORT __declspec(dllexport)
#  define ROBOPTIM_CORE_PLUGIN_CMINPACK_DLLLOCAL
# else
// On Linux, for GCC >= 4, tag symbols using GCC extension.
#  if __GNUC__ >= 4
#   define ROBOPTIM_CORE_PLUGIN_CMINPACK_DLLIMPORT __attribute__ ((visibility("default")))
#   define ROBOPTIM_CORE_PLUGIN_CMINPACK_DLLEXPORT __attribute__ ((visibility("default")))
#   define ROBOPTIM_CORE_PLUGIN_CMINPACK_DLLLOCAL  __attribute__ ((visibility("hidden")))
#  else
// Otherwise (GCC < 4 or another compiler is used), export everything.
#   define ROBOPTIM_CORE_PLUGIN_CMINPACK_DLLIMPORT
#   define ROBOPTIM_CORE_PLUGIN_CMINPACK_DLLEXPORT
#   define ROBOPTIM_CORE_PLUGIN_CMINPACK_DLLLOCAL
#  endif // __GNUC__ >= 4
# endif // defined _WIN32 || defined __CYGWIN__

# ifdef ROBOPTIM_CORE_PLUGIN_CMINPACK_STATIC
// If one is using the library statically, get rid of
// extra information.
#  define ROBOPTIM_CORE_PLUGIN_CMINPACK_DLLAPI
#  define ROBOPTIM_CORE_PLUGIN_CMINPACK_LOCAL
# else
// Depending on whether one is building or using the
// library define DLLAPI to import or export.
#  ifdef roboptim_core_plugin_cminpack_EXPORTS
#   define ROBOPTIM_CORE_PLUGIN_CMINPACK_DLLAPI ROBOPTIM_CORE_PLUGIN_CMINPACK_DLLEXPORT
#  else
#   define ROBOPTIM_CORE_PLUGIN_CMINPACK_DLLAPI ROBOPTIM_CORE_PLUGIN_CMINPACK_DLLIMPORT
#  endif // ROBOPTIM_CORE_PLUGIN_CMINPACK_EXPORTS
#  define ROBOPTIM_CORE_PLUGIN_CMINPACK_LOCAL ROBOPTIM_CORE_PLUGIN_CMINPACK_DLLLOCAL
# endif // ROBOPTIM_CORE_PLUGIN_CMINPACK_STATIC
#endif //! ROBOPTIM_CORE_PLUGIN_CMINPACK_CONFIG_HH
