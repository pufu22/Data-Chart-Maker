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
    int range[2];
    friend class BarChartModel;
    friend class BarChartTableModel;
public:
    Bar_data(std::vector<std::vector<int>> m_sets, std::string m_title,  std::list<std::string> m_categories, int m_range[]);
    Bar_data();
    bool operator !();
    bool operator==(Bar_data d);
    Bar_data& operator =(const Bar_data& other);
};

#endif // BAR_DATA_H
