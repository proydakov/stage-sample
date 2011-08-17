###############################################################################
# Copyright (c) 2011 Evgeny Proydakov <lord.tiran@gmail.com>
###############################################################################

MESSAGE(STATUS "Configuration files of the world polygon")

SET(PLAYER_POLYGON_WORLD_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/robot.inc
        ${CMAKE_CURRENT_SOURCE_DIR}/polygon.cfg
        ${CMAKE_CURRENT_SOURCE_DIR}/polygon.inc
        ${CMAKE_CURRENT_SOURCE_DIR}/polygon.world
        ${CMAKE_CURRENT_SOURCE_DIR}/polygon.png
        ${CMAKE_CURRENT_SOURCE_DIR}/simple.cfg
        ${CMAKE_CURRENT_SOURCE_DIR}/simple.world
        CACHE PATH "Player world file include in project") 
