# generated from catkin/cmake/template/pkgConfig.cmake.in

# append elements to a list and remove existing duplicates from the list
# copied from catkin/cmake/list_append_deduplicate.cmake to keep pkgConfig
# self contained
macro(_list_append_deduplicate listname)
  if(NOT "${ARGN}" STREQUAL "")
    if(${listname})
      list(REMOVE_ITEM ${listname} ${ARGN})
    endif()
    list(APPEND ${listname} ${ARGN})
  endif()
endmacro()

# append elements to a list if they are not already in the list
# copied from catkin/cmake/list_append_unique.cmake to keep pkgConfig
# self contained
macro(_list_append_unique listname)
  foreach(_item ${ARGN})
    list(FIND ${listname} ${_item} _index)
    if(_index EQUAL -1)
      list(APPEND ${listname} ${_item})
    endif()
  endforeach()
endmacro()

# pack a list of libraries with optional build configuration keywords
# copied from catkin/cmake/catkin_libraries.cmake to keep pkgConfig
# self contained
macro(_pack_libraries_with_build_configuration VAR)
  set(${VAR} "")
  set(_argn ${ARGN})
  list(LENGTH _argn _count)
  set(_index 0)
  while(${_index} LESS ${_count})
    list(GET _argn ${_index} lib)
    if("${lib}" MATCHES "^(debug|optimized|general)$")
      math(EXPR _index "${_index} + 1")
      if(${_index} EQUAL ${_count})
        message(FATAL_ERROR "_pack_libraries_with_build_configuration() the list of libraries '${ARGN}' ends with '${lib}' which is a build configuration keyword and must be followed by a library")
      endif()
      list(GET _argn ${_index} library)
      list(APPEND ${VAR} "${lib}${CATKIN_BUILD_CONFIGURATION_KEYWORD_SEPARATOR}${library}")
    else()
      list(APPEND ${VAR} "${lib}")
    endif()
    math(EXPR _index "${_index} + 1")
  endwhile()
endmacro()

# unpack a list of libraries with optional build configuration keyword prefixes
# copied from catkin/cmake/catkin_libraries.cmake to keep pkgConfig
# self contained
macro(_unpack_libraries_with_build_configuration VAR)
  set(${VAR} "")
  foreach(lib ${ARGN})
    string(REGEX REPLACE "^(debug|optimized|general)${CATKIN_BUILD_CONFIGURATION_KEYWORD_SEPARATOR}(.+)$" "\\1;\\2" lib "${lib}")
    list(APPEND ${VAR} "${lib}")
  endforeach()
endmacro()


if(pid_CONFIG_INCLUDED)
  return()
endif()
set(pid_CONFIG_INCLUDED TRUE)

# set variables for source/devel/install prefixes
if("TRUE" STREQUAL "TRUE")
<<<<<<< HEAD
  set(pid_SOURCE_PREFIX /home/viki/octanis/Octanis1-ROS/catkin_ws/src/pid_lidar)
  set(pid_DEVEL_PREFIX /home/viki/octanis/Octanis1-ROS/catkin_ws/devel)
=======
  set(pid_SOURCE_PREFIX /home/rover/Octanis1-ROS/catkin_ws/src/pid_lidar)
  set(pid_DEVEL_PREFIX /home/rover/Octanis1-ROS/catkin_ws/devel)
>>>>>>> c48440ae05be0ae1df2b519a7a01c17dc28b8aaf
  set(pid_INSTALL_PREFIX "")
  set(pid_PREFIX ${pid_DEVEL_PREFIX})
else()
  set(pid_SOURCE_PREFIX "")
  set(pid_DEVEL_PREFIX "")
<<<<<<< HEAD
  set(pid_INSTALL_PREFIX /home/viki/octanis/Octanis1-ROS/catkin_ws/install)
=======
  set(pid_INSTALL_PREFIX /home/rover/Octanis1-ROS/catkin_ws/install)
>>>>>>> c48440ae05be0ae1df2b519a7a01c17dc28b8aaf
  set(pid_PREFIX ${pid_INSTALL_PREFIX})
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "WARNING: package 'pid' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  message("${_msg}")
endif()

# flag project as catkin-based to distinguish if a find_package()-ed project is a catkin project
set(pid_FOUND_CATKIN_PROJECT TRUE)

<<<<<<< HEAD
if(NOT "/home/viki/octanis/Octanis1-ROS/catkin_ws/devel/include;/home/viki/octanis/Octanis1-ROS/catkin_ws/src/pid_lidar/include " STREQUAL " ")
  set(pid_INCLUDE_DIRS "")
  set(_include_dirs "/home/viki/octanis/Octanis1-ROS/catkin_ws/devel/include;/home/viki/octanis/Octanis1-ROS/catkin_ws/src/pid_lidar/include")
=======
if(NOT "/home/rover/Octanis1-ROS/catkin_ws/devel/include;/home/rover/Octanis1-ROS/catkin_ws/src/pid_lidar/include " STREQUAL " ")
  set(pid_INCLUDE_DIRS "")
  set(_include_dirs "/home/rover/Octanis1-ROS/catkin_ws/devel/include;/home/rover/Octanis1-ROS/catkin_ws/src/pid_lidar/include")
>>>>>>> c48440ae05be0ae1df2b519a7a01c17dc28b8aaf
  foreach(idir ${_include_dirs})
    if(IS_ABSOLUTE ${idir} AND IS_DIRECTORY ${idir})
      set(include ${idir})
    elseif("${idir} " STREQUAL "include ")
      get_filename_component(include "${pid_DIR}/../../../include" ABSOLUTE)
      if(NOT IS_DIRECTORY ${include})
        message(FATAL_ERROR "Project 'pid' specifies '${idir}' as an include dir, which is not found.  It does not exist in '${include}'.  Ask the maintainer 'Andy Zelenak <andyz@utexas.edu>' to fix it.")
      endif()
    else()
<<<<<<< HEAD
      message(FATAL_ERROR "Project 'pid' specifies '${idir}' as an include dir, which is not found.  It does neither exist as an absolute directory nor in '/home/viki/octanis/Octanis1-ROS/catkin_ws/src/pid_lidar/${idir}'.  Ask the maintainer 'Andy Zelenak <andyz@utexas.edu>' to fix it.")
=======
      message(FATAL_ERROR "Project 'pid' specifies '${idir}' as an include dir, which is not found.  It does neither exist as an absolute directory nor in '/home/rover/Octanis1-ROS/catkin_ws/src/pid_lidar/${idir}'.  Ask the maintainer 'Andy Zelenak <andyz@utexas.edu>' to fix it.")
>>>>>>> c48440ae05be0ae1df2b519a7a01c17dc28b8aaf
    endif()
    _list_append_unique(pid_INCLUDE_DIRS ${include})
  endforeach()
endif()

set(libraries "")
foreach(library ${libraries})
  # keep build configuration keywords, target names and absolute libraries as-is
  if("${library}" MATCHES "^(debug|optimized|general)$")
    list(APPEND pid_LIBRARIES ${library})
  elseif(TARGET ${library})
    list(APPEND pid_LIBRARIES ${library})
  elseif(IS_ABSOLUTE ${library})
    list(APPEND pid_LIBRARIES ${library})
  else()
    set(lib_path "")
    set(lib "${library}-NOTFOUND")
    # since the path where the library is found is returned we have to iterate over the paths manually
<<<<<<< HEAD
    foreach(path /home/viki/octanis/Octanis1-ROS/catkin_ws/devel/lib;/opt/ros/indigo/lib)
=======
    foreach(path /home/rover/Octanis1-ROS/catkin_ws/devel/lib;/opt/ros/kinetic/lib)
>>>>>>> c48440ae05be0ae1df2b519a7a01c17dc28b8aaf
      find_library(lib ${library}
        PATHS ${path}
        NO_DEFAULT_PATH NO_CMAKE_FIND_ROOT_PATH)
      if(lib)
        set(lib_path ${path})
        break()
      endif()
    endforeach()
    if(lib)
      _list_append_unique(pid_LIBRARY_DIRS ${lib_path})
      list(APPEND pid_LIBRARIES ${lib})
    else()
      # as a fall back for non-catkin libraries try to search globally
      find_library(lib ${library})
      if(NOT lib)
        message(FATAL_ERROR "Project '${PROJECT_NAME}' tried to find library '${library}'.  The library is neither a target nor built/installed properly.  Did you compile project 'pid'?  Did you find_package() it before the subdirectory containing its code is included?")
      endif()
      list(APPEND pid_LIBRARIES ${lib})
    endif()
  endif()
endforeach()

<<<<<<< HEAD
set(pid_EXPORTED_TARGETS "pid_gencfg;pid_generate_messages_cpp;pid_generate_messages_lisp;pid_generate_messages_py")
=======
set(pid_EXPORTED_TARGETS "pid_gencfg;pid_generate_messages_cpp;pid_generate_messages_eus;pid_generate_messages_lisp;pid_generate_messages_nodejs;pid_generate_messages_py")
>>>>>>> c48440ae05be0ae1df2b519a7a01c17dc28b8aaf
# create dummy targets for exported code generation targets to make life of users easier
foreach(t ${pid_EXPORTED_TARGETS})
  if(NOT TARGET ${t})
    add_custom_target(${t})
  endif()
endforeach()

set(depends "roscpp;std_msgs;message_runtime;dynamic_reconfigure;diagnostic_updater")
foreach(depend ${depends})
  string(REPLACE " " ";" depend_list ${depend})
  # the package name of the dependency must be kept in a unique variable so that it is not overwritten in recursive calls
  list(GET depend_list 0 pid_dep)
  list(LENGTH depend_list count)
  if(${count} EQUAL 1)
    # simple dependencies must only be find_package()-ed once
    if(NOT ${pid_dep}_FOUND)
<<<<<<< HEAD
      find_package(${pid_dep} REQUIRED)
=======
      find_package(${pid_dep} REQUIRED NO_MODULE)
>>>>>>> c48440ae05be0ae1df2b519a7a01c17dc28b8aaf
    endif()
  else()
    # dependencies with components must be find_package()-ed again
    list(REMOVE_AT depend_list 0)
<<<<<<< HEAD
    find_package(${pid_dep} REQUIRED ${depend_list})
=======
    find_package(${pid_dep} REQUIRED NO_MODULE ${depend_list})
>>>>>>> c48440ae05be0ae1df2b519a7a01c17dc28b8aaf
  endif()
  _list_append_unique(pid_INCLUDE_DIRS ${${pid_dep}_INCLUDE_DIRS})

  # merge build configuration keywords with library names to correctly deduplicate
  _pack_libraries_with_build_configuration(pid_LIBRARIES ${pid_LIBRARIES})
  _pack_libraries_with_build_configuration(_libraries ${${pid_dep}_LIBRARIES})
  _list_append_deduplicate(pid_LIBRARIES ${_libraries})
  # undo build configuration keyword merging after deduplication
  _unpack_libraries_with_build_configuration(pid_LIBRARIES ${pid_LIBRARIES})

  _list_append_unique(pid_LIBRARY_DIRS ${${pid_dep}_LIBRARY_DIRS})
  list(APPEND pid_EXPORTED_TARGETS ${${pid_dep}_EXPORTED_TARGETS})
endforeach()

set(pkg_cfg_extras "pid-msg-extras.cmake")
foreach(extra ${pkg_cfg_extras})
  if(NOT IS_ABSOLUTE ${extra})
    set(extra ${pid_DIR}/${extra})
  endif()
  include(${extra})
endforeach()
