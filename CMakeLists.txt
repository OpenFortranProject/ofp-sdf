cmake_minimum_required(VERSION 2.6)
project(ofp-sdf)


IF (NOT ATERM_PATH)
   set (ATERM_PATH /opt/aterm/v2.5/bin)
ELSEIF (NOT SDF2_PATH)
   set (SDF2_PATH /opt/sdf2-bundle/v2.4/bin)
ELSEIF (NOT ST_PATH)
   set (ST_PATH /opt/strategoxt/v0.17/bin)
ENDIF()

configure_file (
  "${CMAKE_CURRENT_SOURCE_DIR}/cmake.inc"
  "${CMAKE_CURRENT_SOURCE_DIR}/make.inc"
)
