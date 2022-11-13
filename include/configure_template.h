#pragma once

#cmakedefine USE_MYMATH;

namespace ertb{
constexpr int VERSION_MAJOR = ${${PROJECT_NAME}_VERSION_MAJOR};
constexpr int VERSION_MINOR = ${${PROJECT_NAME}_VERSION_MINOR};
}