#include "bar_data.h"
#include<string>
Bar_data::Bar_data(std::vector<std::vector<int>> m_sets, std::string m_title, std::list<std::string> m_categories, int m_range[2]):sets(m_sets),title(m_title),
    categories(m_categories){};


Bar_data::Bar_data():sets({{3},{1}}),title("riempi"),categories({"w ","e"}),range({-10,15}){};
Bar_data& Bar_data::operator =(const Bar_data& other){
    if (this == &other)
            return *this;
    this->categories=other.categories;
    this->sets=other.sets;
    this->title=other.title;
    for(int i=0;i<sizeof(this->range)/this->range[0];++i)
    {
        this->range[i]=other.range[i];
    }
    return *this;
}
//int const Bar_data::numero_categorie(){
//    int count=0;
//    for(unsigned int i=0;i<categories.size();++i){
//        count++;
//    }
//    return count;
//};
//int const Bar_data::numero_set(){
//    int count=0;
//    for(unsigned int i=0;i<sets.size();++i){
//        count++;
//    }
//    return count;
//}
