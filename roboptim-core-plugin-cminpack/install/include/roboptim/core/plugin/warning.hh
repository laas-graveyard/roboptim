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

#ifndef ROBOPTIM_CORE_PLUGIN_CMINPACK_WARNING_HH
# define ROBOPTIM_CORE_PLUGIN_CMINPACK_WARNING_HH

// Emits a warning in a portable way.
//
// To emit a warning, one can insert:
//
// #pragma message ROBOPTIM_CORE_PLUGIN_CMINPACK_WARN("your warning message here")
//
// The use of this syntax is required as this is /not/ a standardized
// feature of C++ language or preprocessor, even if most of the
// compilers support it.

# define ROBOPTIM_CORE_PLUGIN_CMINPACK_WARN_STRINGISE_IMPL(x) #x
# define ROBOPTIM_CORE_PLUGIN_CMINPACK_WARN_STRINGISE(x) \
         ROBOPTIM_CORE_PLUGIN_CMINPACK_WARN_STRINGISE_IMPL(x)
# ifdef __GNUC__
#   define ROBOPTIM_CORE_PLUGIN_CMINPACK_WARN(exp) ("WARNING: " exp)
# else
#  ifdef _MSC_VER
#   define FILE_LINE_LINK __FILE__ "(" \
           ROBOPTIM_CORE_PLUGIN_CMINPACK_WARN_STRINGISE(__LINE__) ") : "
#   define ROBOPTIM_CORE_PLUGIN_CMINPACK_WARN(exp) (FILE_LINE_LINK "WARNING: " exp)
#  else
// If the compiler is not recognized, drop the feature.
#   define ROBOPTIM_CORE_PLUGIN_CMINPACK_WARN(MSG) /* nothing */
#  endif // __MSVC__
# endif // __GNUC__

#endif //! ROBOPTIM_CORE_PLUGIN_CMINPACK_WARNING_HH
