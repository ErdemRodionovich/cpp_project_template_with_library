include("release/CPackConfig.cmake")

#use the CPACK_INSTALL_CMAKE_PROJECTS variable to specify which projects to install
set(CPACK_INSTALL_CMAKE_PROJECTS
    "debug;projectTemplate;ALL;/"
    "release;projectTemplate;ALL;/"
)
