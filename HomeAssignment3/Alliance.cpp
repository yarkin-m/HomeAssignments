/*
 *   Yarkin Makar
 *   st141442@student.spbu.ru
 *   Assignment 4
 */
#include "Alliance.h"
#include <iostream>
#include <string>

using namespace std;

Alliance::Alliance(const string& name, const string& leader): 
    name_(name), leader_(leader) {
        cout << "Alliance: " << name_ << endl;
    }

Alliance::~Alliance() {
    cout << "Alliance " << name_ << " disbanded" << endl;
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

ostream& operator<<(ostream& os, const Alliance& alliance) {
    os << "Alliance: " << alliance.name_ << " (Leader: " << alliance.leader_ << ")";
    return os;
}