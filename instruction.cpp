#include "instruction.hpp"
#include "command.hpp"
#include "path.hpp"

Instruction::Instruction(CommandName name, Path p) : Command(name,p) {}
