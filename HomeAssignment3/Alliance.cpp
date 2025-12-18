#include "Alliance.h"
#include <iostream>

using namespace std;

Alliance::Alliance(const string& name, const string& leader): 
    name_(name), leader_(leader) {
        cout << "Альянс: " << name_ << endl;
    }

Alliance::~Alliance() {
    cout << "Альянс " << name_ << " распущен" << endl;
}

string Alliance::GetName() const {
    return name_;
}

string Alliance::GetLeader() const {
    return leader_;
}

void Alliance::SetName(const string& name) {
    name_ = name;
} 

void Alliance::SetLeader(const string& leader) {
    leader_ = leader;
}