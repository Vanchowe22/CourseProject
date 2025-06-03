#include "CommandFactory.h"
#include "CommandPrint.h"
#include "CommandValidate.h"
#include "CommandSearch.h"
#include "CommandSet.h"
#include "CommandCreate.h"
#include "CommandDelete.h"
#include "CommandMove.h"
#include "CommandSave.h"
#include "CommandSaveAs.h"

Command *CommandFactory::createCommand(const MyString &name)
{
    if (name == "print")
        return new CommandPrint();
    if (name == "validate")
        return new CommandValidate();
    if (name == "search")
        return new CommandSearch();
    if (name == "set")
        return new CommandSet();
    if (name == "create")
        return new CommandCreate();
    if (name == "delete")
        return new CommandDelete();
    if (name == "move")
        return new CommandMove();
    if (name == "save")
        return new CommandSave();
    if (name == "saveas")
        return new CommandSaveAs();
    return nullptr;
};