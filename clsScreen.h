#pragma once

#include <iostream>
#include <iomanip>
#include "clsUser.h"
#include "clsUserService.h"
#include "Global.h"

using namespace std;

class clsScreen
{
protected:
    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        cout << "\t\t\t\t      _________________________________________";
        cout << "\n\n\t\t\t\t       " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t       " << SubTitle;
        }
        cout << "\n\t\t\t\t      _________________________________________\n\n";
    }

    static bool CheckAccessRights(clsUser::enPermissions Permission) {
        if (!clsUserService::CheckAccessPermission(CurrentUser, Permission)) {
            cout << "\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t Access Denied! Contact your Admin";
            cout << "\n\t\t\t\t\t______________________________________\n";
            return false;
        }
        else {
            return true;
        }
    }
};