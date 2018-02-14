cmake_minimum_required(VERSION 3.0)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../include)
if(MSVC)
  link_directories(${CMAKE_BINARY_DIR}/Debug)
  link_directories(${CMAKE_BINARY_DIR}/Release)
endif()
link_directories(${CMAKE_BINARY_DIR})

file(COPY owl.raw FreeSans.ttf FreeSansBold.ttf FreeSansBoldOblique.ttf FreeSansOblique.ttf DESTINATION ${CMAKE_BINARY_DIR})
file(COPY owl.raw FreeSans.ttf FreeSansBold.ttf FreeSansBoldOblique.ttf FreeSansOblique.ttf DESTINATION ${CMAKE_BINARY_DIR}/examples/gui)

# All examples
add_executable(ExampleGuiAllWidgets guiallwidgets.cpp)
add_executable(ExampleGuiAlign guialign.cpp)

set(GRAPHICS_EXAMPLES ExampleGuiAllWidgets ExampleGuiAlign)

# Dependencies
foreach(exmpl ${GRAPHICS_EXAMPLES})
  if(APPLE)
    target_link_libraries(${exmpl} ${OPENGL_LIBRARY})
    target_link_libraries(${exmpl} debug finegraphics${CMAKE_DEBUG_POSTFIX} debug finegui${CMAKE_DEBUG_POSTFIX})
    target_link_libraries(${exmpl} optimized finegraphics optimized finegui)
  elseif(UNIX)
    target_link_libraries(${exmpl} GL X11 Xrandr Xi Xxf86vm Xcursor Xinerama)
    target_link_libraries(${exmpl} debug finegraphics${CMAKE_DEBUG_POSTFIX} debug finegui${CMAKE_DEBUG_POSTFIX})
	target_link_libraries(${exmpl} optimized finegraphics optimized finegui)
  else()
    target_link_libraries(${exmpl} opengl32)
    target_link_libraries(${exmpl} debug finegraphics${CMAKE_DEBUG_POSTFIX} debug finegui${CMAKE_DEBUG_POSTFIX})
	target_link_libraries(${exmpl} optimized finegraphics optimized finegui)
	if(MSVC)
	  set_target_properties(${exmpl} PROPERTIES LINK_FLAGS "/SUBSYSTEM:CONSOLE")
	endif()
  endif()
  
  # Compile with static stdlib ?
  if(STATIC_STDLIB)
    target_link_libraries(${exmpl} -static-libgcc -static-libstdc++)
  endif(STATIC_STDLIB)

  set_property(TARGET ${exmpl} PROPERTY FOLDER "fineframework/examples") 
endforeach(exmpl)