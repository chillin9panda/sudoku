#include "group.h"

// list group members assigned to the project from "group.txt"
void group::groupMembers() {
  std::ifstream file(groupMembersList);
  if (!file.is_open()) {
    std::cerr << "Unable to open file " << groupMembersList << std::endl;
    return;
  }

  std::cout << "Group Members" << "\t" << "\t" << "Id" << std::endl;
  std::cout << "_________________________________________________" << std::endl;
  std::string member;

  while (std::getline(file, member)) {
    std::cout << member << std::endl;
  }
  std::cout << "_________________________________________________" << std::endl;

  file.close();
}
