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
    Alliance autobots("Автоботы", "Оптимус Прайм");
    
    EXPECT_EQ(autobots.GetName(), "Автоботы");
    EXPECT_EQ(autobots.GetLeader(), "Оптимус Прайм");
}

TEST(AllianceTest, Setters) {
    Alliance alliance("Имя", "Лидер");
    
    alliance.SetName("Десептиконы");
    alliance.SetLeader("Мегатрон");
    
    EXPECT_EQ(alliance.GetName(), "Десептиконы");
    EXPECT_EQ(alliance.GetLeader(), "Мегатрон");
}

TEST(AllianceTest, CompositionTest) {
    Alliance* alliance = new Alliance("Тест", "Лидер");
    EXPECT_NE(alliance, nullptr);
    
    delete alliance;
}

//Weapon tests
TEST(WeaponTest, ConstructorAndGetters) {
    Weapon sword("Энерго-меч", 90);
    
    EXPECT_EQ(sword.GetName(), "Энерго-меч");
    EXPECT_EQ(sword.GetDamage(), 90);
}

TEST(WeaponTest, Setters) {
    Weapon weapon("Меч", 50);
    
    weapon.SetName("Топор");
    weapon.SetDamage(80);
    
    EXPECT_EQ(weapon.GetName(), "Топор");
    EXPECT_EQ(weapon.GetDamage(), 80);
}

TEST(WeaponTest, DeepCopy) {
    Weapon original("Лазер", 100);
    Weapon copy = original;
    
    EXPECT_EQ(copy.GetName(), "Лазер");
    EXPECT_EQ(copy.GetDamage(), 100);
    
    original.SetDamage(200);
    EXPECT_EQ(copy.GetDamage(), 100);
}

// Transformer tests
TEST(TransformerTest, ConstructorAndGetters) {
    Alliance alliance("Автоботы", "Оптимус");
    auto weapon = std::make_unique<Weapon>("Меч", 80);
    
    Transformer optimus("Оптимус", 15, 8, 200, std::move(weapon), &alliance);
    
    EXPECT_EQ(optimus.GetName(), "Оптимус");
    EXPECT_EQ(optimus.GetHeight(), 15);
    EXPECT_EQ(optimus.GetWeight(), 8);
    EXPECT_EQ(optimus.GetPowerLevel(), 200);
    EXPECT_NE(optimus.GetWeapon(), nullptr);
    EXPECT_NE(optimus.GetAlliance(), nullptr);
}

TEST(TransformerTest, Setters) {
    Transformer t("Имя", 10, 5, 100, nullptr, nullptr);
    
    t.SetName("Новое имя");
    t.SetHeight(20);
    t.SetWeight(15);
    t.SetPowerLevel(300);
    
    EXPECT_EQ(t.GetName(), "Новое имя");
    EXPECT_EQ(t.GetHeight(), 20);
    EXPECT_EQ(t.GetWeight(), 15);
    EXPECT_EQ(t.GetPowerLevel(), 300);
}

TEST(TransformerTest, Methods) {
    Transformer t("Бот", 10, 5, 100, nullptr, nullptr);
    
    std::string transformResult = t.Transform();
    std::string attackResult = t.Attack();
    std::string infoResult = t.GetInfo();
    
    EXPECT_FALSE(transformResult.empty());
    EXPECT_FALSE(attackResult.empty());
    EXPECT_FALSE(infoResult.empty());
    
    EXPECT_NE(infoResult.find("Бот"), std::string::npos);
}

TEST(TransformerTest, Composition) {
    auto weapon = std::make_unique<Weapon>("Пушка", 120);
    Alliance* alliance = new Alliance("Фракция", "Лидер");
    
    Transformer t("Тест", 10, 5, 100, std::move(weapon), alliance);
    
    EXPECT_EQ(t.GetWeapon()->GetName(), "Пушка");
    EXPECT_EQ(t.GetAlliance()->GetName(), "Фракция");
    
    delete alliance;
}

//Autobot tests
TEST(AutobotTest, ConstructorAndInheritance) {
    Autobot optimus("Оптимус", 15, 8, 200, nullptr, nullptr, "грузовик", 95);
    
    EXPECT_EQ(optimus.GetName(), "Оптимус");
    EXPECT_EQ(optimus.GetHeight(), 15);
    EXPECT_EQ(optimus.GetPowerLevel(), 200);
    
    EXPECT_EQ(optimus.GetVehicleForm(), "грузовик");
    EXPECT_EQ(optimus.GetCourageLevel(), 95);
}

TEST(AutobotTest, SpecificMethods) {
    Autobot autobot("Тест", 10, 5, 100, nullptr, nullptr, "машина", 80);
    
    std::string protectResult = autobot.ProtectHumans();
    std::string transformResult = autobot.Transform();
    
    EXPECT_FALSE(protectResult.empty());
    EXPECT_FALSE(transformResult.empty());
    
    EXPECT_NE(protectResult.find("защищает"), std::string::npos);
    EXPECT_NE(transformResult.find("машина"), std::string::npos);
}

TEST(AutobotTest, Setters) {
    Autobot autobot("Имя", 10, 5, 100, nullptr, nullptr, "форма", 50);
    
    autobot.SetVehicleForm("грузовик");
    autobot.SetCourageLevel(90);
    
    EXPECT_EQ(autobot.GetVehicleForm(), "грузовик");
    EXPECT_EQ(autobot.GetCourageLevel(), 90);
}

// Decepticon tests
TEST(DecepticonTest, ConstructorAndFields) {
    Decepticon megatron("Мегатрон", 14, 9, 180, nullptr, nullptr, "самолет", true);
    
    EXPECT_EQ(megatron.GetName(), "Мегатрон");
    EXPECT_EQ(megatron.GetFlyingForm(), "самолет");
    EXPECT_TRUE(megatron.GetHasWings());
}

TEST(DecepticonTest, TerrorizeMethod) {
    Decepticon decepticon("Тест", 10, 5, 100, nullptr, nullptr, "форма", false);
    
    std::string terrorResult = decepticon.Terrorize();
    EXPECT_FALSE(terrorResult.empty());
    EXPECT_NE(terrorResult.find("террор"), std::string::npos);
}

TEST(DecepticonTest, WingsLogic) {
    Decepticon withWings("С крыльями", 10, 5, 100, nullptr, nullptr, "самолет", true);
    Decepticon withoutWings("Без крыльев", 10, 5, 100, nullptr, nullptr, "танк", false);
    
    EXPECT_TRUE(withWings.GetHasWings());
    EXPECT_FALSE(withoutWings.GetHasWings());
}

// Dinobot tests
TEST(DinobotTest, ConstructorAndFields) {
    Dinobot grimlock("Гримлок", 12, 10, 220, nullptr, nullptr, "тираннозавр", 150);
    
    EXPECT_EQ(grimlock.GetName(), "Гримлок");
    EXPECT_EQ(grimlock.GetDinosaurForm(), "тираннозавр");
    EXPECT_EQ(grimlock.GetRoarPower(), 150);
}

TEST(DinobotTest, RoarMethod) {
    Dinobot dinobot("Тест", 10, 5, 100, nullptr, nullptr, "форма", 120);
    
    std::string roarResult = dinobot.Roar();
    EXPECT_FALSE(roarResult.empty());
    EXPECT_NE(roarResult.find("рычит"), std::string::npos);
}

TEST(DinobotTest, PowerLevel) {
    Dinobot dinobot("Сильный", 12, 10, 250, nullptr, nullptr, "Т-Рекс", 200);
    
    EXPECT_GT(dinobot.GetPowerLevel(), 200);
}

// Polymorphysm tests
TEST(PolymorphismTest, PointerToBaseClass) {
    Autobot autobot("Автобот", 10, 5, 100, nullptr, nullptr, "машина", 80);
    Decepticon decepticon("Десептикон", 10, 5, 100, nullptr, nullptr, "самолет", true);
    Dinobot dinobot("Динобот", 12, 10, 150, nullptr, nullptr, "динозавр", 120);
    
    Transformer* t1 = &autobot;
    Transformer* t2 = &decepticon;
    Transformer* t3 = &dinobot;
    
    EXPECT_EQ(t1->GetName(), "Автобот");
    EXPECT_EQ(t2->GetName(), "Десептикон");
    EXPECT_EQ(t3->GetName(), "Динобот");
}

TEST(PolymorphismTest, VectorOfPointers) {
    std::vector<Transformer*> army;
    
    army.push_back(new Autobot("A1", 10, 5, 100, nullptr, nullptr, "машина", 70));
    army.push_back(new Decepticon("D1", 10, 5, 100, nullptr, nullptr, "самолет", true));
    army.push_back(new Dinobot("DN1", 12, 10, 150, nullptr, nullptr, "динозавр", 100));
    
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
    Autobot autobot("Тест", 10, 5, 100, nullptr, nullptr, "форма", 50);
    Transformer* ptr = &autobot;
    
    std::string result = ptr->Transform();
    EXPECT_NE(result.find("форма"), std::string::npos);
}