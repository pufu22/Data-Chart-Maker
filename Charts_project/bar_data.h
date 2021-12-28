#ifndef BAR_DATA_H
#define BAR_DATA_H
#include <list>
#include <QtCharts>
#include<string>
class Bar_data
{
protected:
    std::list<std::list<int>> sets;
    std::string title;
public:
    Bar_data(std::list<std::list<int>> m_sets, std::string);

};

#endif // BAR_DATA_H
