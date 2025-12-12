#include "transformers/Alliance.h"

namespace transformers {

Alliance::Alliance(const std::string& name, const std::string& leader,
                   int member_count)
    : name_(name), leader_(leader), member_count_(member_count) {}

Alliance::~Alliance() {}

const std::string& Alliance::GetName() const { return name_; }
const std::string& Alliance::GetLeader() const { return leader_; }
int Alliance::GetMemberCount() const { return member_count_; }

void Alliance::SetName(const std::string& name) { name_ = name; }
void Alliance::SetLeader(const std::string& leader) { leader_ = leader; }
void Alliance::SetMemberCount(int member_count) { member_count_ = member_count; }

std::string Alliance::GetInfo() const {
  return name_ + " led by " + leader_ + " with " +
         std::to_string(member_count_) + " members";
}

bool Alliance::IsLarge() const { return member_count_ > 100; }

}