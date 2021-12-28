#include "bar_data.h"

Bar_data::Bar_data(std::list<QBarSet> m_sets, QStringList m_categories, QBarCategoryAxis *m_axisX, QValueAxis *m_axisY):sets(m_sets)
{
this->series=m_sets;
}

