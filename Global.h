#pragma once
#include <iostream>
#include "clsUser.h"
#include "clsUserService.h"
clsUser CurrentUser = clsUserService::FindUser("", "");