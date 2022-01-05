#ifndef BAR_DATA_H
#define BAR_DATA_H
#include <list>
#include <QtCharts>
#include<string>
class Bar_data
{
protected:
    std::vector<std::vector<int>> sets;
    std::string title;
    std::list<std::string> categories;
    int range[];
    friend class BarChartModel;
public:
    Bar_data(std::vector<std::vector<int>> m_sets, std::string m_title,  std::list<std::string> m_categories, int m_range[]);
};

#endif // BAR_DATA_H
