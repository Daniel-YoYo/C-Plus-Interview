/*
 * @Author: your name
 * @Date: 2020-07-09 14:29:32
 * @LastEditTime: 2020-07-10 10:07:54
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /C++/C++Note/C++Base(Tedu)/salaryCalc.cpp
 */ 

/***       薪资计算小项目
１框架结构
        普通员工            
      /   ｜    \      
 技术员　经理   销售员
    　\  /   \  /
  技术主管   销售主管

2　共有信息和特有信息

所有员工：　名字　工号  职位等级
技术员：　研发津贴( 元/ 小时 )
销售员:   提成比例( 百分比 )
经理：    绩效奖金

薪资 = 基本工资 + 绩效工资
基本工资　= 等级额度 * 出勤率( 输入出勤天数/23.0 )

绩效工资( 计算方式因职务而异 )
普通员：　基本工资一半
技术员: 工作小时数 * 研发津贴 ＊ 进度因数( 输入 )
销售员: 销售额度( 输入 ) * 提成比例
经理：　绩效奖金*绩效因数(输入)
技术主管: (技术员绩效 + 经理绩效 )/2
销售主管: ( 销售员绩效 + 经理绩效 )/2

需求：　打印员工信息　输入必要数据 计算工资

 * 
 * 
 */

#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

#define BASE_AttendanceDays 23.0
#define BASE_ResearchGrant  43.5
#define BASE_ManagerMonthlyPerfor  3000.0
#define BASE_SalesCommissionPer 0.1

enum JobRank
{
    EM_JobRank_GeneralStaff,
    EM_JobRank_Technician,
    EM_JobRank_Sales,
    EM_JobRank_Manager,
    EM_JobRank_TechnicalDirector,
    EM_JobRank_SakesDirector,

    EM_JobRank_Other = -1,
};

const double rankQuotaArr[ 6 ] = { 4000.0, 8000.0, 5000.0, 5000.0, 10000.0, 10000.0 };

// 员工基类
class Base
{
protected:
    
    // 名字
    string name;
    // 工号
    string id;
    // 职位等级
    JobRank jobRank;
    // 出勤天数
    double attendanceDays;
    // 出勤率
    double attendanceRatio;
    // 基本工资
    double baseWage;
    // 绩效
    double performanceWage;
    // 等级配额
    double rankQuota;
    // 工资总额
    double totalSalary;
    
public:

    Base( const string& nameIn, const string& idIn, const JobRank& jonRankIn )
    :name( nameIn ), id( idIn ), jobRank( jonRankIn ), attendanceDays( 0.0 ), attendanceRatio( 0.0 ), baseWage( 0.0 ), performanceWage( 0 ), rankQuota(0), totalSalary(0)
    {
        rankQuota = rankQuotaArr[ jobRank ];
    }
    
    ~Base(){}

    void getInfo()
    {   
        cout << "\nName : " << name << "\tID : " << id  << "\tRank : " << jobRank << endl;
        cout << "出勤天数(天) : " << attendanceDays << "\t出勤率 :" << attendanceRatio << endl;
        cout << "等级配额(元) : " << rankQuota << "\t基本工资(元) : " << getBaseWage() << "\t绩效工资(元) : " << getPerformanceWage() << endl;
        cout << "薪资合计(元) : " << getSalary() << endl;
        cout << "**************************************************************************************************" << endl;

    }

    double getBaseWage()
    { 
        return baseWage;
    }

    const double& getRankQuota()
    {
        return rankQuota;
    }

    void setName( const string& nameIn )
    {
        name = nameIn;
    }

    void setId( const string& idIn )
    {
        id = idIn;
    }

    void setJobRank( const JobRank& jobRankIn )
    {
        jobRank = jobRankIn;
        rankQuota = rankQuotaArr[ jobRankIn ];
    }

    const double& getSalary()
    {
        return totalSalary;
    }

    //　获取出勤天数和基本工资
    virtual void setAttendanceDays() = 0;

protected:

    virtual double getPerformanceWage() = 0;
};


// 普通员工类
class GeneralStaff : public Base
{
public:

    GeneralStaff( const string& nameIn, const string& idIn ):Base( nameIn, idIn, EM_JobRank_GeneralStaff ){}
    ~GeneralStaff(){}

    void setAttendanceDays()
    {
        cout << "Name : " << name << "\tID : " << id << "\tRank : " << jobRank << "\t输入出勤天数:";
        cin >> attendanceDays;
        attendanceRatio = attendanceDays / BASE_AttendanceDays;
        baseWage = rankQuota * attendanceRatio;
    }
    
protected:

    double getPerformanceWage()
    {
        //cout << "GeneralStaff::getPerformanceWage()" << endl;
        performanceWage = baseWage / 2.0;
        totalSalary = baseWage + performanceWage;
        return performanceWage;
    }
};


// 技术员类
class Technician : virtual public Base
{
private:
    // 项目考核
    double proAssessment;
    // 研发津贴时长
    double proOvertime;
    
public:
    
    Technician( const string& nameIn, const string& idIn )
    :Base( nameIn, idIn, EM_JobRank_Technician ),proAssessment( 0.0 ), proOvertime( 0.0  )
    {}
    ~Technician(){}

    void setAttendanceDays()
    {
        cout << "Name : " << name << "\tID : " << id << "\tRank : " << jobRank << "\t输入出勤天数:";
        cin >> attendanceDays;
        attendanceRatio = attendanceDays / BASE_AttendanceDays;
        baseWage = rankQuota * attendanceRatio;

        cout << "输入项目考核 : ";
        cin >> proAssessment;
        cout << "输入加班时长 : ";
        cin >> proOvertime;
    }
    
protected:
    
    double getPerformanceWage()
    {
        // 绩效 = 工作小时数＊研发津贴＊项目评估
        performanceWage = proOvertime*BASE_ResearchGrant*proAssessment;
        totalSalary = baseWage + performanceWage;
        return performanceWage;
    }

};

// 经理类
class Manager : virtual public Base
{

private:
    // 月度绩效
    double monthlyPerfor;
    // 项目进度因素
    double proAssessment;

public:

    Manager( const string& nameIn, const string& idIn )
    :Base( nameIn, idIn, EM_JobRank_Manager ), monthlyPerfor( BASE_ManagerMonthlyPerfor )
    {}

    ~Manager(){}

    void setAttendanceDays()
    {
        cout << "Name : " << name << "\tID : " << id << "\tRank : " << jobRank << "\t输入出勤天数:";
        cin >> attendanceDays;
        attendanceRatio = attendanceDays / BASE_AttendanceDays;
        baseWage = rankQuota * attendanceRatio;

        cout << "输入项目考核 : ";
        cin >> proAssessment;
    }

protected:

    double getPerformanceWage()
    {
        // 绩效 = 月度绩效＊项目评估
        performanceWage = proAssessment * monthlyPerfor;
        totalSalary = baseWage + performanceWage;
        return performanceWage;
    }
};

// 销售
class Seller : virtual public Base
{

private:
    // 月销售额
    double monthSales;
    // 提成比例
    double commissionPer;

public:

    Seller( const string& nameIn, const string& idIn )
    :Base( nameIn, idIn, EM_JobRank_Sales ), commissionPer( BASE_SalesCommissionPer )
    {}

    ~Seller(){}

    void setAttendanceDays()
    {
        cout << "Name : " << name << "\tID : " << id << "\tRank : " << jobRank << "\t输入出勤天数:";
        cin >> attendanceDays;
        attendanceRatio = attendanceDays / BASE_AttendanceDays;
        baseWage = rankQuota * attendanceRatio;

        cout << "输入月销售总额 : ";
        cin >> monthSales;
    }
    
protected:

    double getPerformanceWage()
    {
        // 绩效 = 月度绩效＊项目评估
        performanceWage = monthSales * commissionPer;
        totalSalary = baseWage + performanceWage;
        return performanceWage;
    }
};

// 技术主管
class TechnicalDirector : public Technician, public Manager
{
public:

    TechnicalDirector( const string& nameIn, const string& idIn, const Technician& t, const Manager& m )
    :Base( nameIn, idIn, EM_JobRank_TechnicalDirector ), Technician( t ), Manager( m )
    {}

    ~TechnicalDirector(){}

    void setMember( const Base& baseIn )
    {
        if( typeid( baseIn ) == typeid( Technician ) )
        {

        }
        else if( typeid( baseIn ) == typeid( Manager ) )
        {
            
        }

    }

    void setAttendanceDays()
    {
        cout << "Name : " << name << "\tID : " << id << "\tRank : " << jobRank << "\t输入出勤天数:";
        cin >> attendanceDays;
        attendanceRatio = attendanceDays / BASE_AttendanceDays;
        baseWage = rankQuota * attendanceRatio;
    }
    
protected:

    double getPerformanceWage()
    {
        // 绩效 = 月度绩效＊项目评估
        performanceWage = ( Technician::getPerformanceWage() + this->Manager::getPerformanceWage() ) / 2;
        totalSalary = baseWage + performanceWage;
        return performanceWage;
    }

};

// 销售主管
class SalesDirector : public Seller, public Manager
{
public:

    SalesDirector( const string& nameIn, const string& idIn, const Seller& s, const Manager& m )
    :Base( nameIn, idIn, EM_JobRank_TechnicalDirector ), Seller( s ), Manager( m )
    {}

    ~SalesDirector(){}

    void setAttendanceDays()
    {
        cout << "Name : " << name << "\tID : " << id << "\tRank : " << jobRank << "\t输入出勤天数:";
        cin >> attendanceDays;
        attendanceRatio = attendanceDays / BASE_AttendanceDays;
        baseWage = rankQuota * attendanceRatio;
    }
    
protected:

    double getPerformanceWage()
    {
        // 绩效 = 月度绩效＊项目评估
        performanceWage = ( Seller::getPerformanceWage() + Manager::getPerformanceWage() ) / 2;
        totalSalary = baseWage + performanceWage;
        return performanceWage;
    }

};

int main()
{
    // GeneralStaff g1( "YoYo", "10086" );
    // g1.setAttendanceDays();
    // g1.getInfo();

    // Technician t1("张三", "100000");
    // t1.setAttendanceDays();
    // t1.getInfo();

    Manager m1( "唐僧", "999999" );
    m1.setAttendanceDays();
    m1.getInfo();

    Seller s1( "八戒", "123456" );
    s1.setAttendanceDays();
    s1.getInfo();

    // TechnicalDirector t2( "如来", "0000001", t1, m1 );
    // t2.setAttendanceDays();
    // t2.getInfo();

    SalesDirector s2( "观音", "0000003", s1, m1 );
    s2.setAttendanceDays();
    s2.getInfo();

    return 0;
}