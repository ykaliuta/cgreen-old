include(InstallRequiredSystemLibraries)

# For help take a look at:
# http://www.cmake.org/Wiki/CMake:CPackConfiguration

### general settings
set(CPACK_PACKAGE_NAME ${APPLICATION_NAME})
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "The simple unit testint framework")
set(CPACK_PACKAGE_DESCRIPTION_FILE "${CMAKE_SOURCE_DIR}/README")
set(CPACK_PACKAGE_VENDOR "The CGreen Development Team")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/COPYING")


### versions
set(CPACK_PACKAGE_VERSION_MAJOR ${APPLICATION_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${APPLICATION_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${APPLICATION_VERSION_PATCH})
set(CPACK_PACKAGE_VERSION_STATUS ${APPLICATION_VERSION_STATUS})
set(CPACK_PACKAGE_VERSION "${CPACK_PACKAGE_VERSION_MAJOR}.${CPACK_PACKAGE_VERSION_MINOR}.${CPACK_PACKAGE_VERSION_PATCH}${CPACK_PACKAGE_VERSION_STATUS}")


### source generator
set(CPACK_SOURCE_GENERATOR "TGZ")
set(CPACK_SOURCE_IGNORE_FILES "~$;[.]swp$;/[.]svn/;/[.]git/;.gitignore;/build/;tags;cscope.*")
set(CPACK_SOURCE_PACKAGE_FILE_NAME "${CPACK_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION}")

if (WIN32)
  ### nsis generator
  set(CPACK_GENERATOR "NSIS")
  set(CPACK_NSIS_DISPLAY_NAME "The simple unit testing framework")
  set(CPACK_NSIS_COMPRESSOR "/SOLID zlib")
  set(CPACK_NSIS_MENU_LINKS "http://www.lastcraft.com/cgreen.php" "cgreen homepage")
  set(CPACK_PACKAGE_INSTALL_DIRECTORY ${CPACK_PACKAGE_NAME})
else()
  set(CPACK_INCLUDE_TOPLEVEL_DIRECTORY 0)
  set(CPACK_GENERATOR "TGZ")
endif(WIN32)

set(CPACK_COMPONENTS_ALL_IN_ONE_PACKAGE 1)
set(CPACK_PACKAGE_FILE_NAME ${APPLICATION_NAME}-${CPACK_PACKAGE_VERSION})

set(CPACK_COMPONENT_LIBRARIES_DISPLAY_NAME "Libraries")
set(CPACK_COMPONENT_LIBRARIES_DESCRIPTION
  "Libraries used to build programs which use cgreen")

set(CPACK_COMPONENT_HEADERS_DISPLAY_NAME "C/C++ Headers")
set(CPACK_COMPONENT_HEADERS_DESCRIPTION
  "C/C++ header files for use with cgreen")
set(CPACK_COMPONENT_HEADERS_DEPENDS libraries)

set(CPACK_COMPONENT_APPLICATIONS_GROUP "Runtime")
set(CPACK_COMPONENT_LIBRARIES_GROUP "Development")
set(CPACK_COMPONENT_HEADERS_GROUP "Development")

include(CPack)