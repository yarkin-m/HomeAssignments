/*
 *   Yarkin Makar
 *   st141442@student.spbu.ru
 *   Assignment 3
 */
#include <gtest/gtest.h>
#include <memory>
#include "Alliance.h"
#include "Weapon.h"
#include "Transformer.h"
#include "Autobot.h"
#include "Decepticon.h"
#include "Dinobot.h"
#include <vector>


//Alliance tests
TEST(AllianceTest, ConstructorAndGetters) {
    Alliance autobots("Autobots", "Optimus Prime");
    
    EXPECT_EQ(autobots.GetName(), "Autobots");
    EXPECT_EQ(autobots.GetLeader(), "Optimus Prime");
}

TEST(AllianceTest, Setters) {
    Alliance alliance("Name", "Leader");
    
    alliance.SetName("Decepticons");
    alliance.SetLeader("Megatron");
    
    EXPECT_EQ(alliance.GetName(), "Decepticons");
    EXPECT_EQ(alliance.GetLeader(), "Megatron");
}

TEST(AllianceTest, CompositionTest) {
    Alliance* alliance = new Alliance("Test", "Leader");
    EXPECT_NE(alliance, nullptr);
    
    delete alliance;
}

//Weapon tests
TEST(WeaponTest, ConstructorAndGetters) {
    Weapon sword("Energy sword", 90);
    
    EXPECT_EQ(sword.GetName(), "Energy sword");
    EXPECT_EQ(sword.GetDamage(), 90);
}

TEST(WeaponTest, Setters) {
    Weapon weapon("Sword", 50);
    
    weapon.SetName("Axe");
    weapon.SetDamage(80);
    
    EXPECT_EQ(weapon.GetName(), "Axe");
    EXPECT_EQ(weapon.GetDamage(), 80);
}

TEST(WeaponTest, DeepCopy) {
    Weapon original("Laser", 100);
    Weapon copy = original;
    
    EXPECT_EQ(copy.GetName(), "Laser");
    EXPECT_EQ(copy.GetDamage(), 100);
    
    original.SetDamage(200);
    EXPECT_EQ(copy.GetDamage(), 100);
}

// Transformer tests
TEST(TransformerTest, ConstructorAndGetters) {
    Alliance alliance("Autobots", "Optimus");
    auto weapon = std::make_unique<Weapon>("Sword", 80);
    
    Transformer optimus("Optimus", 15, 8, 200, std::move(weapon), &alliance);
    
    EXPECT_EQ(optimus.GetName(), "Optimus");
    EXPECT_EQ(optimus.GetHeight(), 15);
    EXPECT_EQ(optimus.GetWeight(), 8);
    EXPECT_EQ(optimus.GetPowerLevel(), 200);
    EXPECT_NE(optimus.GetWeapon(), nullptr);
    EXPECT_NE(optimus.GetAlliance(), nullptr);
}

TEST(TransformerTest, Setters) {
    Transformer t("Name", 10, 5, 100, nullptr, nullptr);
    
    t.SetName("New name");
    t.SetHeight(20);
    t.SetWeight(15);
    t.SetPowerLevel(300);
    
    EXPECT_EQ(t.GetName(), "New name");
    EXPECT_EQ(t.GetHeight(), 20);
    EXPECT_EQ(t.GetWeight(), 15);
    EXPECT_EQ(t.GetPowerLevel(), 300);
}

TEST(TransformerTest, Methods) {
    Transformer t("Bot", 10, 5, 100, nullptr, nullptr);
    
    std::string transformResult = t.Transform();
    std::string attackResult = t.Attack();
    std::string infoResult = t.GetInfo();
    
    EXPECT_FALSE(transformResult.empty());
    EXPECT_FALSE(attackResult.empty());
    EXPECT_FALSE(infoResult.empty());
    
    EXPECT_NE(infoResult.find("Bot"), std::string::npos);
}

TEST(TransformerTest, Composition) {
    auto weapon = std::make_unique<Weapon>("Cannon", 120);
    Alliance* alliance = new Alliance("Faction", "Leader");
    
    Transformer t("Test", 10, 5, 100, std::move(weapon), alliance);
    
    EXPECT_EQ(t.GetWeapon()->GetName(), "Cannon");
    EXPECT_EQ(t.GetAlliance()->GetName(), "Faction");
    
    delete alliance;
}

//Autobot tests
TEST(AutobotTest, ConstructorAndInheritance) {
    Autobot optimus("Optimus", 15, 8, 200, nullptr, nullptr, "truck", 95);
    
    EXPECT_EQ(optimus.GetName(), "Optimus");
    EXPECT_EQ(optimus.GetHeight(), 15);
    EXPECT_EQ(optimus.GetPowerLevel(), 200);
    
    EXPECT_EQ(optimus.GetVehicleForm(), "truck");
    EXPECT_EQ(optimus.GetCourageLevel(), 95);
}

TEST(AutobotTest, SpecificMethods) {
    Autobot autobot("Test", 10, 5, 100, nullptr, nullptr, "car", 80);
    
    std::string protectResult = autobot.ProtectHumans();
    std::string transformResult = autobot.Transform();
    
    EXPECT_FALSE(protectResult.empty());
    EXPECT_FALSE(transformResult.empty());
    
    EXPECT_NE(protectResult.find("protects"), std::string::npos);
    EXPECT_NE(transformResult.find("car"), std::string::npos);
}

TEST(AutobotTest, Setters) {
    Autobot autobot("Name", 10, 5, 100, nullptr, nullptr, "form", 50);
    
    autobot.SetVehicleForm("truck");
    autobot.SetCourageLevel(90);
    
    EXPECT_EQ(autobot.GetVehicleForm(), "truck");
    EXPECT_EQ(autobot.GetCourageLevel(), 90);
}

// Decepticon tests
TEST(DecepticonTest, ConstructorAndFields) {
    Decepticon megatron("Megatron", 14, 9, 180, nullptr, nullptr, "airplane", true);
    
    EXPECT_EQ(megatron.GetName(), "Megatron");
    EXPECT_EQ(megatron.GetFlyingForm(), "airplane");
    EXPECT_TRUE(megatron.GetHasWings());
}

TEST(DecepticonTest, TerrorizeMethod) {
    Decepticon decepticon("Test", 10, 5, 100, nullptr, nullptr, "form", false);
    
    std::string terrorResult = decepticon.Terrorize();
    EXPECT_FALSE(terrorResult.empty());
    EXPECT_NE(terrorResult.find("terror"), std::string::npos);
}

TEST(DecepticonTest, WingsLogic) {
    Decepticon withWings("With wings", 10, 5, 100, nullptr, nullptr, "airplane", true);
    Decepticon withoutWings("Without wings", 10, 5, 100, nullptr, nullptr, "tank", false);
    
    EXPECT_TRUE(withWings.GetHasWings());
    EXPECT_FALSE(withoutWings.GetHasWings());
}

// Dinobot tests
TEST(DinobotTest, ConstructorAndFields) {
    Dinobot grimlock("Grimlock", 12, 10, 220, nullptr, nullptr, "tyrannosaurus", 150);
    
    EXPECT_EQ(grimlock.GetName(), "Grimlock");
    EXPECT_EQ(grimlock.GetDinosaurForm(), "tyrannosaurus");
    EXPECT_EQ(grimlock.GetRoarPower(), 150);
}

TEST(DinobotTest, RoarMethod) {
    Dinobot dinobot("Test", 10, 5, 100, nullptr, nullptr, "form", 120);
    
    std::string roarResult = dinobot.Roar();
    EXPECT_FALSE(roarResult.empty());
    EXPECT_NE(roarResult.find("roars"), std::string::npos);
}

TEST(DinobotTest, PowerLevel) {
    Dinobot dinobot("Strong", 12, 10, 250, nullptr, nullptr, "T-Rex", 200);
    
    EXPECT_GT(dinobot.GetPowerLevel(), 200);
}

// Polymorphism tests
TEST(PolymorphismTest, PointerToBaseClass) {
    Autobot autobot("Autobot", 10, 5, 100, nullptr, nullptr, "car", 80);
    Decepticon decepticon("Decepticon", 10, 5, 100, nullptr, nullptr, "airplane", true);
    Dinobot dinobot("Dinobot", 12, 10, 150, nullptr, nullptr, "dinosaur", 120);
    
    Transformer* t1 = &autobot;
    Transformer* t2 = &decepticon;
    Transformer* t3 = &dinobot;
    
    EXPECT_EQ(t1->GetName(), "Autobot");
    EXPECT_EQ(t2->GetName(), "Decepticon");
    EXPECT_EQ(t3->GetName(), "Dinobot");
}

TEST(PolymorphismTest, VectorOfPointers) {
    std::vector<Transformer*> army;
    
    army.push_back(new Autobot("A1", 10, 5, 100, nullptr, nullptr, "car", 70));
    army.push_back(new Decepticon("D1", 10, 5, 100, nullptr, nullptr, "airplane", true));
    army.push_back(new Dinobot("DN1", 12, 10, 150, nullptr, nullptr, "dinosaur", 100));
    
    EXPECT_EQ(army.size(), 3);
    
    for (auto soldier : army) {
        EXPECT_FALSE(soldier->GetName().empty());
        EXPECT_FALSE(soldier->GetInfo().empty());
    }
    
    for (auto soldier : army) {
        delete soldier;
    }
}

TEST(PolymorphismTest, VirtualMethods) {
    Autobot autobot("Test", 10, 5, 100, nullptr, nullptr, "form", 50);
    Transformer* ptr = &autobot;
    
    std::string result = ptr->Transform();
    EXPECT_NE(result.find("form"), std::string::npos);
}