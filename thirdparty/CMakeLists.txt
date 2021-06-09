include(ExternalProject)

ExternalProject_Add(
  GTEST
  PREFIX GTEST
  SOURCE_DIR ${PROJECT_SOURCE_DIR}/thirdparty/googletest
  INSTALL_COMMAND "")
