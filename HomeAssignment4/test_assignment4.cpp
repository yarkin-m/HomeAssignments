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
    Alliance alliance("Автоботы", "Оптимус Прайм");
    Weapon weapon("Энерго-меч", 90);
    
    stringstream ss;
    
    ss << alliance;
    string allianceOutput = ss.str();
    EXPECT_NE(allianceOutput.find("Автоботы"), string::npos);
    EXPECT_NE(allianceOutput.find("Оптимус Прайм"), string::npos);
    
    ss.str("");
    
    ss << weapon;
    string weaponOutput = ss.str();
    EXPECT_NE(weaponOutput.find("Энерго-меч"), string::npos);
    EXPECT_NE(weaponOutput.find("90"), string::npos);
}

TEST(Assignment4Test, ConstructorOverloading) {
    
    Autobot a1("Бамблби");
    EXPECT_EQ(a1.GetName(), "Бамблби");
    EXPECT_EQ(a1.GetVehicleForm(), "автомобиль"); 
    
    Autobot a2("Джаз", "спорткар");
    EXPECT_EQ(a2.GetName(), "Джаз");
    EXPECT_EQ(a2.GetVehicleForm(), "спорткар");
    
    Autobot a3 = a2;
    EXPECT_EQ(a3.GetName(), a2.GetName() + " (копия)");
    EXPECT_EQ(a3.GetVehicleForm(), "спорткар");
}

TEST(Assignment4Test, VirtualMethodsDirectCall) {
    Autobot autobot("Оптимус", 15, 8, 200, nullptr, nullptr, "грузовик", 95);
    Decepticon decepticon("Мегатрон", 14, 9, 180, nullptr, nullptr, "самолет", true);
    Dinobot dinobot("Гримлок", 12, 10, 220, nullptr, nullptr, "тираннозавр", 150);
    
    testing::internal::CaptureStdout();
    
    autobot.ShowInfo();
    string output1 = testing::internal::GetCapturedStdout();
    EXPECT_NE(output1.find("Autobot::ShowInfo()"), string::npos);
    EXPECT_NE(output1.find("Оптимус"), string::npos);
    
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
    
    Autobot autobot("Тест", 10, 5, 100, nullptr, nullptr, "форма", 50);
    Decepticon decepticon("Тест", 10, 5, 100, nullptr, nullptr, "форма", true);
    Dinobot dinobot("Тест", 10, 5, 100, nullptr, nullptr, "форма", 80);
    

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
    Autobot autobot("Оптимус", "грузовик");
    Decepticon decepticon("Мегатрон", "самолет");
    Dinobot dinobot("Гримлок", "тираннозавр");
    
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
    
    bigArmy.push_back(new Autobot("A1", "машина"));
    bigArmy.push_back(new Autobot("A2", "грузовик"));
    bigArmy.push_back(new Autobot("A3", "спорткар"));
    
    bigArmy.push_back(new Decepticon("D1", "самолет"));
    bigArmy.push_back(new Decepticon("D2", "танк"));
    bigArmy.push_back(new Decepticon("D3", "вертолет"));
    
    bigArmy.push_back(new Dinobot("DN1", "тираннозавр"));
    bigArmy.push_back(new Dinobot("DN2", "трицератопс"));
    bigArmy.push_back(new Dinobot("DN3", "саблезуб"));
    
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
    
    Alliance* alliance = new Alliance("Автоботы", "Оптимус");
    Weapon* weapon = new Weapon("Меч", 80);
    
    Autobot autobot("Тест", 10, 5, 100, weapon, alliance, "форма", 70);
    
    EXPECT_EQ(autobot.GetName(), "Тест");
    EXPECT_EQ(autobot.GetHeight(), 10);
    EXPECT_EQ(autobot.GetWeight(), 5);
    EXPECT_EQ(autobot.GetPowerLevel(), 100);
    EXPECT_EQ(autobot.GetVehicleForm(), "форма");
    EXPECT_EQ(autobot.GetCourageLevel(), 70);
    
    autobot.SetPowerLevel(150);
    EXPECT_EQ(autobot.GetPowerLevel(), 150);
    
    autobot.SetVehicleForm("новая форма");
    EXPECT_EQ(autobot.GetVehicleForm(), "новая форма");
    /*
    string protectResult = autobot.ProtectHumans();
    EXPECT_NE(protectResult.find("защищает"), string::npos);
    */
    EXPECT_EQ(autobot.GetWeapon()->GetName(), "Меч");
    EXPECT_EQ(autobot.GetAlliance()->GetName(), "Автоботы");
    
    delete alliance;
    delete weapon;
}

TEST(Assignment4Test, DeepCopy) {
    Weapon* originalWeapon = new Weapon("Оригинальное оружие", 100);
    Alliance* alliance = new Alliance("Альянс", "Лидер");
    
    Autobot original("Оригинал", 10, 5, 200, originalWeapon, alliance, "форма", 80);
    
    Autobot copy = original;
    
    EXPECT_EQ(copy.GetName(), original.GetName() + " (копия)");
    EXPECT_EQ(copy.GetVehicleForm(), "форма");
    EXPECT_EQ(copy.GetCourageLevel(), 80);
    
    EXPECT_NE(copy.GetWeapon(), original.GetWeapon());
    EXPECT_EQ(copy.GetWeapon()->GetName(), "Оригинальное оружие");
    
    original.SetPowerLevel(999);
    EXPECT_EQ(copy.GetPowerLevel(), 200); 
    
    delete alliance;
    delete originalWeapon;
}

TEST(AllianceTest, Assignment4) {
    Alliance a("Тест", "Лидер");
    
    stringstream ss;
    ss << a;
    EXPECT_NE(ss.str().find("Тест"), string::npos);
    
    a.SetName("Новое имя");
    EXPECT_EQ(a.GetName(), "Новое имя");
}

TEST(WeaponTest, Assignment4) {
    Weapon w("Меч", 50);
    
    stringstream ss;
    ss << w;
    EXPECT_NE(ss.str().find("Меч"), string::npos);
    EXPECT_NE(ss.str().find("50"), string::npos);
    
    w.SetDamage(75);
    EXPECT_EQ(w.GetDamage(), 75);
}

TEST(AutobotTest, Assignment4) {
    Autobot a("Тест", "форма");
    
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
    Decepticon d("Тест", "форма");
    
    testing::internal::CaptureStdout();
    d.ShowInfo();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Decepticon::ShowInfo()"), string::npos);
}

TEST(DinobotTest, Assignment4) {
    Dinobot d("Тест", "форма");
    
    testing::internal::CaptureStdout();
    d.ShowInfo();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Dinobot::ShowInfo()"), string::npos);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);    
    return RUN_ALL_TESTS();
}