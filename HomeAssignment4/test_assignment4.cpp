/*
 *   Yarkin Makar
 *   st141442@student.spbu.ru
 *   Assignment 4
 */
#include <gtest/gtest.h>
#include <vector>
#include <sstream>
#include <memory>

#include "Alliance.h"
#include "Weapon.h"
#include "Transformer.h"
#include "Autobot.h"
#include "Decepticon.h"
#include "Dinobot.h"

using namespace std;


TEST(Assignment4Test, OperatorOutput) {
    Alliance alliance("Autobots", "Optimus Prime");
    Weapon weapon("Energy sword", 90);
    
    stringstream ss;
    
    ss << alliance;
    string allianceOutput = ss.str();
    EXPECT_NE(allianceOutput.find("Autobots"), string::npos);
    EXPECT_NE(allianceOutput.find("Optimus Prime"), string::npos);
    
    ss.str("");
    
    ss << weapon;
    string weaponOutput = ss.str();
    EXPECT_NE(weaponOutput.find("Energy sword"), string::npos);
    EXPECT_NE(weaponOutput.find("90"), string::npos);
}

TEST(Assignment4Test, ConstructorOverloading) {
    
    Autobot a1("Bumblebee");
    EXPECT_EQ(a1.GetName(), "Bumblebee");
    EXPECT_EQ(a1.GetVehicleForm(), "car"); 
    
    Autobot a2("Jazz", "sports car");
    EXPECT_EQ(a2.GetName(), "Jazz");
    EXPECT_EQ(a2.GetVehicleForm(), "sports car");
    
    Autobot a3 = a2;
    EXPECT_EQ(a3.GetName(), a2.GetName() + " (copy)");
    EXPECT_EQ(a3.GetVehicleForm(), "sports car");
}

TEST(Assignment4Test, VirtualMethodsDirectCall) {
    Autobot autobot("Optimus", 15, 8, 200, nullptr, nullptr, "truck", 95);
    Decepticon decepticon("Megatron", 14, 9, 180, nullptr, nullptr, "airplane", true);
    Dinobot dinobot("Grimlock", 12, 10, 220, nullptr, nullptr, "tyrannosaurus", 150);
    
    testing::internal::CaptureStdout();
    
    autobot.ShowInfo();
    string output1 = testing::internal::GetCapturedStdout();
    EXPECT_NE(output1.find("Autobot::ShowInfo()"), string::npos);
    EXPECT_NE(output1.find("Optimus"), string::npos);
    
    testing::internal::CaptureStdout();
    decepticon.ShowInfo();
    string output2 = testing::internal::GetCapturedStdout();
    EXPECT_NE(output2.find("Decepticon::ShowInfo()"), string::npos);
    
    testing::internal::CaptureStdout();
    dinobot.ShowInfo();
    string output3 = testing::internal::GetCapturedStdout();
    EXPECT_NE(output3.find("Dinobot::ShowInfo()"), string::npos);
}

TEST(Assignment4Test, PureVirtualMethod) {
    
    Autobot autobot("Test", 10, 5, 100, nullptr, nullptr, "form", 50);
    Decepticon decepticon("Test", 10, 5, 100, nullptr, nullptr, "form", true);
    Dinobot dinobot("Test", 10, 5, 100, nullptr, nullptr, "form", 80);
    

    testing::internal::CaptureStdout();
    autobot.SpecialAbility();
    string output1 = testing::internal::GetCapturedStdout();
    EXPECT_NE(output1.find("Autobot::SpecialAbility()"), string::npos);
    
    testing::internal::CaptureStdout();
    decepticon.SpecialAbility();
    string output2 = testing::internal::GetCapturedStdout();
    EXPECT_NE(output2.find("Decepticon::SpecialAbility()"), string::npos);
    
    testing::internal::CaptureStdout();
    dinobot.SpecialAbility();
    string output3 = testing::internal::GetCapturedStdout();
    EXPECT_NE(output3.find("Dinobot::SpecialAbility()"), string::npos);
}

TEST(Assignment4Test, VirtualMethodsThroughPointers) {
    Autobot autobot("Optimus", "truck");
    Decepticon decepticon("Megatron", "airplane");
    Dinobot dinobot("Grimlock", "tyrannosaurus");
    
    Transformer* army[3] = {&autobot, &decepticon, &dinobot};
    
    for (int i = 0; i < 3; i++) {
        testing::internal::CaptureStdout();
        army[i]->ShowInfo();
        string output = testing::internal::GetCapturedStdout();
        
        if (i == 0) {
            EXPECT_NE(output.find("Autobot::ShowInfo()"), string::npos);
        }
        if (i == 1) {
            EXPECT_NE(output.find("Decepticon::ShowInfo()"), string::npos);
        }
        if (i == 2) {
            EXPECT_NE(output.find("Dinobot::ShowInfo()"), string::npos);
        }   
    }
}

TEST(Assignment4Test, VectorOfNineObjects) {
    vector<Transformer*> bigArmy;
    
    bigArmy.push_back(new Autobot("A1", "car"));
    bigArmy.push_back(new Autobot("A2", "truck"));
    bigArmy.push_back(new Autobot("A3", "sports car"));
    
    bigArmy.push_back(new Decepticon("D1", "airplane"));
    bigArmy.push_back(new Decepticon("D2", "tank"));
    bigArmy.push_back(new Decepticon("D3", "helicopter"));
    
    bigArmy.push_back(new Dinobot("DN1", "tyrannosaurus"));
    bigArmy.push_back(new Dinobot("DN2", "triceratops"));
    bigArmy.push_back(new Dinobot("DN3", "sabertooth"));
    
    EXPECT_EQ(bigArmy.size(), 9);
    
    for (size_t i = 0; i < bigArmy.size(); i++) {
        EXPECT_NE(bigArmy[i]->GetName(), "");
        
        testing::internal::CaptureStdout();
        bigArmy[i]->BattleCry();
        string output = testing::internal::GetCapturedStdout();
        EXPECT_FALSE(output.empty());
    }
    
    for (auto soldier : bigArmy) {
        delete soldier;
    }
}

TEST(Assignment4Test, AllMethodsFromAssignment3) {
    
    Alliance* alliance = new Alliance("Autobots", "Optimus");
    Weapon* weapon = new Weapon("Sword", 80);
    
    Autobot autobot("Test", 10, 5, 100, weapon, alliance, "form", 70);
    
    EXPECT_EQ(autobot.GetName(), "Test");
    EXPECT_EQ(autobot.GetHeight(), 10);
    EXPECT_EQ(autobot.GetWeight(), 5);
    EXPECT_EQ(autobot.GetPowerLevel(), 100);
    EXPECT_EQ(autobot.GetVehicleForm(), "form");
    EXPECT_EQ(autobot.GetCourageLevel(), 70);
    
    autobot.SetPowerLevel(150);
    EXPECT_EQ(autobot.GetPowerLevel(), 150);
    
    autobot.SetVehicleForm("new form");
    EXPECT_EQ(autobot.GetVehicleForm(), "new form");
    /*
    string protectResult = autobot.ProtectHumans();
    EXPECT_NE(protectResult.find("protects"), string::npos);
    */
    EXPECT_EQ(autobot.GetWeapon()->GetName(), "Sword");
    EXPECT_EQ(autobot.GetAlliance()->GetName(), "Autobots");
    
    delete alliance;
    delete weapon;
}

TEST(Assignment4Test, DeepCopy) {
    Weapon* originalWeapon = new Weapon("Original weapon", 100);
    Alliance* alliance = new Alliance("Alliance", "Leader");
    
    Autobot original("Original", 10, 5, 200, originalWeapon, alliance, "form", 80);
    
    Autobot copy = original;
    
    EXPECT_EQ(copy.GetName(), original.GetName() + " (copy)");
    EXPECT_EQ(copy.GetVehicleForm(), "form");
    EXPECT_EQ(copy.GetCourageLevel(), 80);
    
    EXPECT_NE(copy.GetWeapon(), original.GetWeapon());
    EXPECT_EQ(copy.GetWeapon()->GetName(), "Original weapon");
    
    original.SetPowerLevel(999);
    EXPECT_EQ(copy.GetPowerLevel(), 200); 
    
    delete alliance;
    delete originalWeapon;
}

TEST(AllianceTest, Assignment4) {
    Alliance a("Test", "Leader");
    
    stringstream ss;
    ss << a;
    EXPECT_NE(ss.str().find("Test"), string::npos);
    
    a.SetName("New name");
    EXPECT_EQ(a.GetName(), "New name");
}

TEST(WeaponTest, Assignment4) {
    Weapon w("Sword", 50);
    
    stringstream ss;
    ss << w;
    EXPECT_NE(ss.str().find("Sword"), string::npos);
    EXPECT_NE(ss.str().find("50"), string::npos);
    
    w.SetDamage(75);
    EXPECT_EQ(w.GetDamage(), 75);
}

TEST(AutobotTest, Assignment4) {
    Autobot a("Test", "form");
    
    testing::internal::CaptureStdout();
    a.ShowInfo();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Autobot::ShowInfo()"), string::npos);
    
    testing::internal::CaptureStdout();
    a.SpecialAbility();
    output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Autobot::SpecialAbility()"), string::npos);
}

TEST(DecepticonTest, Assignment4) {
    Decepticon d("Test", "form");
    
    testing::internal::CaptureStdout();
    d.ShowInfo();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Decepticon::ShowInfo()"), string::npos);
}

TEST(DinobotTest, Assignment4) {
    Dinobot d("Test", "form");
    
    testing::internal::CaptureStdout();
    d.ShowInfo();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Dinobot::ShowInfo()"), string::npos);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);    
    return RUN_ALL_TESTS();
}