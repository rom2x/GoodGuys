#include "pch.h"
#include <algorithm>
#include "../Employees/Employees.cpp"

class clientTest : public ::testing::Test
{
public:
    clientTest() {
        db = createEmployees();
    }

    ~clientTest() {
        delete db;
    }

protected:
    virtual void SetUp() override
    {
        Employee test_employees[] = {
            { "15123099", "VXIHXOTH", "JHOP", "CL3", "3112", "2609", "19771211", "ADV" },
            { "17112609", "FB", "NTAWR", "CL4", "5645", "6122", "19861203", "PRO" },
            { "18115040", "TTETHU", "HBO", "CL3", "4581", "2050", "20080718", "ADV"},
            { "88114052", "NQ", "LVARW", "CL4", "4528", "3059", "19911021", "PRO"},
            { "19129568", "SRERLALH", "HMEF", "CL2", "3091", "9521", "19640910", "PRO"},
            { "17111236", "VSID", "TVO", "CL1", "3669", "1077", "20120718", "PRO"},
            { "18117906", "TWU", "QSOLT", "CL4", "6672", "7186", "20030413", "PRO"},
            { "81235356", "WN", "XV", "CL1", "7986", "5047", "20100614", "PRO"},
            { "02117175", "SBILHUT", "LDEXRI", "CL4", "2814", "1699", "19950704", "ADV"},
        };

        for (auto t : test_employees) {
            db->add(t);
        }

        cout << "Client 생성" << endl;
    }

    virtual void TearDown() override
    {

    }

protected:
    Employees* db;
};

TEST(EmployeeTest, EmployeeOperator)
{
    Employee a = { "15123099", "VXIHXOTH", "JHOP", "CL3", "3112", "2609", "19771211", "ADV" };
    Employee b = { "18115040", "TTETHU", "HBO", "CL3", "4581", "2050", "20080718", "ADV" };

    EXPECT_TRUE(a < b);
    EXPECT_FALSE(a > b);

    Employee c = { "81235356", "WN", "XV", "CL1", "7986", "5047", "20100614", "PRO" };
    Employee d = { "02117175", "SBILHUT", "LDEXRI", "CL4", "2814", "1699", "19950704", "ADV" }; // 2000년 이 후 사번에 대한 케이스 테스트

    EXPECT_TRUE(c < d);
    EXPECT_FALSE(c > d);
}

TEST_F(clientTest, EmployeesTestSize)
{
    const employeeList* t = db->getEmployees();

    EXPECT_EQ(t->size(), 9);
}

TEST_F(clientTest, EmployeesTestAdd)
{
    const employeeList* t = db->getEmployees();

    Employee empl = { "12234575", "EOJOEI", "EWFWEF", "CL2", "5332", "6544", "20152623", "PRO" };
    db->add(empl);

    EXPECT_EQ(t->size(), 10);
}

TEST_F(clientTest, EmployeesTestDelete)
{
    const employeeList* t = db->getEmployees();

    Employee empl1 = { "17111236", "VSID", "TVO", "CL1", "3669", "1077", "20120718", "PRO" };
    db->del(empl1);
    EXPECT_EQ(t->size(), 8);

    Employee empl2 = { "19129568", "SRERLALH", "HMEF", "CL2", "3091", "9521", "19640910", "PRO" };
    db->del(empl2);
    EXPECT_EQ(t->size(), 7);

    Employee empl3 = { "32523452", "SRERLALH", "HMEF", "CL2", "3091", "9521", "19640910", "PRO" };
    EXPECT_ANY_THROW(db->del(empl3));
}

TEST_F(clientTest, EmployeesTestModify) {
    Employee target = { "15123099", "VXIHXOTH", "JHOP", "CL3", "3112", "2609", "19771211", "ADV" };

    db->modify(target, [](Employee& target) {target.lastName = "ABC"; });

    const employeeList* t = db->getEmployees();

    Employee modified = *std::find(t->begin(), t->end(), target);
    EXPECT_NE(modified.lastName, "JHOP");
    EXPECT_EQ(modified.lastName, "ABC");

    Employee nodata = { "23452212", "VXIHXOTH", "ABC", "CL3", "3112", "2609", "19771211", "ADV" };
    EXPECT_ANY_THROW(db->modify(nodata, [](Employee& target) {target.birth = 19730205; }));
}

TEST_F(clientTest, EmployeesTestSearch) {
    employeeList search_list;

    CERTI target_certi = CERTI::ADV;
    search_list = db->search([target_certi](Employee& t)->bool { return (t.certi == target_certi); });
    EXPECT_EQ(search_list.size(), 3);

    target_certi = CERTI::PRO;
    search_list = db->search([target_certi](Employee& t)->bool { return (t.certi == target_certi); });
    EXPECT_EQ(search_list.size(), 6);

    target_certi = CERTI::EX;
    search_list = db->search([target_certi](Employee& t)->bool { return (t.certi == target_certi); });
    EXPECT_EQ(search_list.size(), 0);

    CL target_cl = CL::CL1;
    search_list = db->search([target_cl](Employee& t)->bool { return (t.cl == target_cl); });
    EXPECT_EQ(search_list.size(), 2);

    target_cl = CL::CL2;
    search_list = db->search([target_cl](Employee& t)->bool { return (t.cl == target_cl); });
    EXPECT_EQ(search_list.size(), 1);

    target_cl = CL::CL3;
    search_list = db->search([target_cl](Employee& t)->bool { return (t.cl == target_cl); });
    EXPECT_EQ(search_list.size(), 2);

    target_cl = CL::CL4;
    search_list = db->search([target_cl](Employee& t)->bool { return (t.cl == target_cl); });
    EXPECT_EQ(search_list.size(), 4);

    string target_name = "HBO";
    search_list = db->search([&target_name](Employee& t)->bool { return (t.lastName == target_name); });
    EXPECT_EQ(search_list.size(), 1);

    target_name = "JIN";
    search_list = db->search([&target_name](Employee& t)->bool { return (t.lastName == target_name); });
    EXPECT_EQ(search_list.size(), 0);
}

TEST_F(clientTest, EmployeesTestSearchAndDel) {
    employeeList search_list;

    CERTI target_certi = CERTI::ADV;
    search_list = db->search([target_certi](Employee& t)->bool { return (t.certi == target_certi); });
    EXPECT_EQ(search_list.size(), 3);

    for (auto t : search_list)
        db->del(t);

    search_list = db->search([target_certi](Employee& t)->bool { return (t.certi == target_certi); });
    EXPECT_EQ(search_list.size(), 0);
}

TEST_F(clientTest, EmployeesTestSearchAndModify) {
    employeeList search_list;

    CL target_cl = CL::CL1;
    search_list = db->search([target_cl](Employee& t)->bool { return (t.cl == target_cl); });
    EXPECT_EQ(search_list.size(), 2);

    for (auto empl : search_list)
        db->modify(empl, [](Employee& t) { t.cl = CL::CL2; });

    target_cl = CL::CL1;
    search_list = db->search([target_cl](Employee& t)->bool { return (t.cl == target_cl); });
    EXPECT_EQ(search_list.size(), 0);

    target_cl = CL::CL2;
    search_list = db->search([target_cl](Employee& t)->bool { return (t.cl == target_cl); });
    EXPECT_EQ(search_list.size(), 3);
}
